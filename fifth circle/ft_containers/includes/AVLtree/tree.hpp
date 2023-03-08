#pragma once

#include "../iterator/tree_iterator.hpp"
#include "../utils/utils.hpp" 
#include "../iterator/reverse_iterator.hpp"

namespace ft
{
    template <typename T>
    struct Node
    {
        public:
            typedef T       value_type;
            T               key;
            Node            *parent;
            Node            *left;
            Node            *right;
            int             height;

            Node() :        key(){};
            Node(T key) :   key(key){};
    };

    template <class T, class Compare, class Allocator>
    class AVLTree
    {
    public:
        typedef T                                                               value_type;
        typedef Compare                                                         key_compare;
        typedef Allocator                                                       allocator_type;

    private: 
        typedef typename allocator_type::template rebind<Node<T> >::other       node_allocator;
        typedef Node<value_type>                                                *node_pointer;

    public:
        typedef typename allocator_type::pointer                                pointer;
        typedef typename allocator_type::const_pointer                          const_pointer;
        typedef typename allocator_type::size_type                              size_type;
        typedef typename value_type::first_type                                 key_type;
        typedef typename value_type::second_type                                mapped_type;
        
        typedef ft::BinarySearchTreeIterator<pointer, node_pointer>             iterator;
        typedef ft::BinarySearchTreeIterator<const_pointer, node_pointer>       const_iterator;
        typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                            const_reverse_iterator;

    private:
        node_allocator  _alloc;
        key_compare     _comp;
        node_pointer    _root;
        node_pointer    _end;
        node_pointer    _rend;
        int             _size;

    public:

        // constructor:
            AVLTree(const key_compare &compare = key_compare(), const allocator_type &alloc = allocator_type())
                : _comp(compare), _size(0)
            {
                this->_alloc = alloc;
                _end = this->_create_node(value_type());
                _rend = this->_create_node(value_type());
                _end->left = _rend;
                _rend->parent = _end;
                _root = _end;
            };

        // destructor
            ~AVLTree()
            {
                this->_delete_node(_end);
                this->_delete_node(_rend);
            };

        //iterators
            iterator begin(){ return iterator(successor(this->_rend)); };
            const_iterator begin() const { return const_iterator(successor(this->_rend)); };
            
            iterator end() { return iterator(this->_end); };
            const_iterator end() const { return const_iterator(this->_end); };
        
            reverse_iterator rbegin() { return reverse_iterator(this->end()); };
            const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); };
            
            reverse_iterator rend() { return reverse_iterator(this->begin()); };
            const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); };

    private:
     
        int _balance(node_pointer node)
        {
            if (!node)
                return 0;
            return this->_get_height(node->left) - this->_get_height(node->right);
        };

        int _get_height(node_pointer N)
        {
            if (!N)
                return 0;
            return N->height;
        };

        int _max(int a, int b) { return (a > b) ? a : b; };

        node_pointer _create_node(value_type key)
        {
            node_pointer node = this->_alloc.allocate(1);
            this->_alloc.construct(node, key);
            node->left = NULL;
            node->right = NULL;
            node->parent = NULL;
            node->height = 1;
            return node;
        };

        node_pointer _left_rotation(node_pointer x)
        {
            node_pointer y = x->right;
            node_pointer T2 = y->left;
            node_pointer p = x->parent;

            y->left = x;
            x->right = T2;
            if (p)
            {
                if (p->left == x)
                    p->left = y;
                else
                    p->right = y;
            }
            else
                this->_root = y;
            y->parent = x->parent;
            x->parent = y;

            if (T2)
                T2->parent = x;
            x->height = this->_max(_get_height(x->left), this->_get_height(x->right)) + 1;
            y->height = this->_max(_get_height(y->left), this->_get_height(y->right)) + 1;
            return y;
        };

        node_pointer _right_rotation(node_pointer x)
        {
            node_pointer y = x->left;
            node_pointer T2 = y->right;
            node_pointer p = x->parent;

            y->right = x;
            x->left = T2;
            if (p)
            {
                if (p->right == x)
                    p->right = y;
                else
                    p->left = y;
            }
            else
                this->_root = y;
            y->parent = x->parent;
            x->parent = y;

            if (T2)
                T2->parent = x;
            x->height = this->_max(_get_height(x->left), this->_get_height(x->right)) + 1;
            y->height = this->_max(_get_height(y->left), this->_get_height(y->right)) + 1;
            return y;
        };

        node_pointer _left_right_rotation(node_pointer node)
        {
            node->left = this->_left_rotation(node->left);
            return this->_right_rotation(node);
        };

        node_pointer _right_left_rotation(node_pointer node)
        {
            node->right = this->_right_rotation(node->right);
            return this->_left_rotation(node);
        };

        node_pointer _dispatch_rotation(node_pointer root)
        {
            int BL = this->_balance(root);
            if (BL > 1)
            {
                if (this->_balance(root->left) >= 0) 
                    return this->_right_rotation(root); // Left Left Case
                else 
                    return this->_left_right_rotation(root); // Left Right Case
            }
            else if (BL < -1)
            {
                if (this->_balance(root->right) <= 0) 
                    return this->_left_rotation(root); // Right Right Case
                else
                    return this->_right_left_rotation(root);  // Right Left Case
            }
            return root;
        };
      
       
        node_pointer _add_element(node_pointer temp, node_pointer newNode)
        {
            if (!temp)
                return newNode;

            if (this->_ft_compare(&temp->key, &newNode->key) == false)
            {
                temp->left = this->_add_element(temp->left, newNode);
                if (temp->left == newNode)
                    newNode->parent = temp;
            }
            else if (this->_ft_compare(&temp->key, &newNode->key) == true)
            {
                temp->right = this->_add_element(temp->right, newNode);
                if (temp->right == newNode)
                    newNode->parent = temp;
            }

            this->_calcul_height(temp);
            temp = this->_dispatch_rotation(temp);

            return temp;
        };



        int _ft_compare(const value_type *x, const value_type *y) const
        {
            // si root exist le compare apres
            if (x == &_rend->key || y == &_end->key)
                return 1;
            else if (x == &_end->key || y == &_rend->key)
                return 0;
            return this->_comp(x->first, y->first);
        };


        node_pointer _find_node(node_pointer node, key_type key) const 
        {
            ft::pair<key_type, mapped_type> temp = ft::make_pair(key, mapped_type());

            if (!node) // go create new node
                return this->_end;
            else if (node->key.first == key && node != this->_end && node != this->_rend) //existe deja
                return node;
            else if (this->_ft_compare(&temp, &node->key) == true) //si node == end go left
                return this->_find_node(node->left, key);
            else if (this->_ft_compare(&node->key, &temp) == true) //si node == rend go right
                return this->_find_node(node->right, key);
            return this->_end;
        };

        bool _delete_node(node_pointer node)
        {
            if (!node)
                return false;

            node_pointer parent = node->parent;

            if (!node->left && !node->right) // no child
            {
                if (parent)
                {
                    if (parent->left == node)
                        parent->left = NULL;
                    else
                        parent->right = NULL;
                }
                else
                    this->_root = NULL;

                this->_alloc.destroy(node);
                this->_alloc.deallocate(node, 1);
            }
            else if (!node->left || !node->right) // 1 child
            {
                node_pointer child;
                
                if (node->left)
                    child = node->left;
                else
                    child = node->right;

                if (parent)
                {
                    if (node == parent->left)
                        parent->left = child;
                    else
                        parent->right = child;

                    child->parent = parent;
                }
                else
                {
                    this->_root = child;
                    child->parent = NULL;
                }

                this->_alloc.destroy(node);
                this->_alloc.deallocate(node, 1);
            }
            else // 2 children
            {
                node_pointer temp = successor(node);
                // swap the deleting node with successor node, successor node in right subtree's smallest node
                this->_swapTwoNodes(temp, node);
                this->_delete_node(node);
            }
            this->_calcul_height(parent);
            this->_dispatch_rotation(parent);

            return true;
        };

        // swaping two nodes places. x:successor node, y:deleting node
        void _swapTwoNodes(node_pointer x, node_pointer y)
        {
            node_pointer xparent = x->parent;
            node_pointer xleft = x->left;
            node_pointer xright = x->right;

            node_pointer yparent = y->parent;
            node_pointer yleft = y->left;
            node_pointer yright = y->right;

            if (xparent)
            {
                if (xparent->left == x)
                    xparent->left = y;
                else
                    xparent->right = y;
            }
            if (xleft)
                xleft->parent = y;
            if (xright)
                xright->parent = y;

            if (yparent)
            {
                if (yparent->left == y)
                    yparent->left = x;
                else
                    yparent->right = x;
            }
            if (yleft)
                yleft->parent = x;
            if (yright)
                yright->parent = x;

            node_pointer tl = x->left;
            node_pointer tr = x->right;
            node_pointer tp = x->parent;

            int th = x->height;
            x->left = y->left;
            x->right = y->right;
            x->parent = y->parent;
            x->height = y->height;
            y->left = tl;
            y->right = tr;
            y->parent = tp;
            y->height = th;

            if (x == this->_root)
                this->_root = y;

            if (y == this->_root)
                this->_root = x;
        }

        void _destroy(node_pointer node)
        {
            if (node)
            {
                _destroy(node->left);
                _destroy(node->right);
                this->_alloc.destroy(node);
                this->_alloc.deallocate(node, 1);
            }
        }
        
        void _calcul_height(node_pointer node)
        {
            if (!node)
                return ;

            if (!node->left && !node->right)
                node->height = 1;
            else if (!node->left)
                node->height = 1 + node->right->height;
            else if (!node->right)
                node->height = 1 + node->left->height;
            else
                node->height = 1 + this->_max(node->right->height, node->left->height);

           this->_calcul_height(node->parent);
        };


    public:

    
        node_pointer search(key_type key) const
        {
            return this->_find_node(this->_root, key);
        };

        node_pointer insert_pos(node_pointer position, T key)
        {
            node_pointer newnode = this->_create_node(key);

            this->_size++;
            this->_add_element(position, newnode);

            return newnode;
        }

        node_pointer insert(const value_type &key)
        {
            node_pointer newNode = this->_create_node(key);

            this->_size++;
            this->_root = this->_add_element(this->_root, newNode);

            return newNode;
        };

        // remove/delete
        void remove(T key)
        {
            node_pointer n = this->_find_node(_root, key.first);

            if (n == _end)
                return;

            if (this->_delete_node(n))
                this->_size--;
        }

        void swap(AVLTree &x)
        {
            int temp_size = x._size;
            allocator_type temp_alloc = x._alloc;
            node_pointer temp_end = x._end;
            node_pointer temp_rend = x._rend;
            node_pointer temp_root = x._root;

            x._size = this->_size;
            _size = temp_size;

            x._alloc = this->_alloc;
            this->_alloc = temp_alloc;

            x._end = this->_end;
            this->_end = temp_end;

            x._rend = this->_rend;
            this->_rend = temp_rend;

            x._root = this->_root;
            this->_root = temp_root;
        }

        node_pointer lower_bound(const key_type &k) const
        {
            node_pointer curr_node = successor(_rend);

            while (curr_node->key.first < k)
            {
                if (curr_node->key.first == k)
                    break;

                curr_node = successor(curr_node);
                if (!curr_node || curr_node == this->_end)
                    return this->_end;
            }
            return curr_node;
        }

        node_pointer upper_bound(const key_type &k) const
        {
            node_pointer curr_node = successor(_rend);
            while (curr_node->key.first <= k)
            {
                curr_node = successor(curr_node);
                if (!curr_node || curr_node == this->_end)
                    return this->_end;
            }
            return curr_node;
        }

        bool empty() const
        {
            if (this->_size == 0)
                return 1;
            return 0;
        };

        size_type size() const { return this->_size; };

        size_type max_size() const { return this->_alloc.max_size(); };

        allocator_type get_allocator() const{ return this->_alloc; }
    };
};