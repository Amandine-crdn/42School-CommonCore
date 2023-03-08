#pragma once

#include "iterator/tree_iterator.hpp"
#include "iterator/reverse_iterator.hpp"
#include "AVLtree/tree.hpp"

namespace ft
{
    template <typename Key, typename T, typename Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
    public:

        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef ptrdiff_t difference_type;
        typedef typename allocator_type::size_type size_type;

    private:
        typedef Node<value_type> Node_type;
        typedef Node_type *Node_ptr;
        typedef AVLTree<value_type, key_compare, allocator_type>  Tree_type;
        typedef Tree_type *Tree_ptr;

    public:
        typedef typename Tree_type::iterator iterator;
        typedef typename Tree_type::const_iterator const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        class value_compare
        {
            friend class map;

            protected:
                Compare comp;
                value_compare(Compare c) : comp(c) {}

            public:
                typedef bool                                                        result_type;
                typedef value_type                                                  first_argument_type;
                typedef value_type                                                  second_argument_type;
                bool operator()(const value_type &x, const value_type &y) const     { return comp(x.first, y.first); }
        };
    
    private:
        Tree_type           _tree;
        allocator_type      _alloc;
        key_compare         _comp;

    public:
    
        // constructors
            explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            : _tree(comp, alloc), _alloc(alloc), _comp(comp) {}
                
            map(const map &x) { *this = x; }
            
        // range constructor
            template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            : _tree(comp, alloc), _alloc(alloc), _comp(comp)
            {
                this->insert(first, last);
            }

        // operator
        map &operator=(const map &x)
        { 
            if (this != &x)
            {
                this->clear();
                this->_comp = x._comp;
                this->_alloc = x._alloc;
                this->insert(x.begin(), x.end());
            }
            return (*this);
        };
        
        // destructor
            ~map()
            {
                clear();
            }
        
        // iterators:
            iterator begin() { return this->_tree.begin(); };
            const_iterator begin() const { return this->_tree.begin(); };
            iterator end() { return this->_tree.end(); };
            const_iterator end() const { return this->_tree.end(); };
            reverse_iterator rbegin() { return this->_tree.rbegin(); };
            const_reverse_iterator rbegin() const { return this->_tree.rbegin(); };
            reverse_iterator rend() { return this->_tree.rend(); };
            const_reverse_iterator rend() const { return this->_tree.rend(); };
       
        // capacity:
            bool empty() const { return this->_tree.empty(); };
            size_type size() const { return this->_tree.size(); };
            allocator_type get_allocator() const { return this->_tree.get_allocator(); };
            size_type max_size() const { return this->_tree.max_size(); };
       
        // element access:
            mapped_type &operator[](const key_type &k)
            {
                return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
            };

        // modifiers:
            ft::pair<iterator, bool> insert(const value_type &val)
            {
                iterator node = iterator(this->_tree.search(val.first));
                
                if (node != this->end())
                    return ft::pair<iterator, bool>(node, false);
                
                Node_ptr inserted_node = this->_tree.insert(val);
                
                return ft::pair<iterator, bool>(iterator(inserted_node), true);
            };

            iterator insert(iterator pos, const value_type &val)
            {
                if (pos == end())
                    return (insert(val).first);

                iterator it = iterator(this->_tree.search(val.first));
                if (it != end())
                    return (it);

                Node_ptr node = pos.base();
                if (val.first > predecessor(node)->key.first && val.first < successor(node)->key.first)
                    pos = iterator(this->_tree.insert_pos(node, val));
                else
                    pos = insert(val).first;
                return pos;
            };

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    iterator it = iterator(this->_tree.search(first->first));
                    //std::cout << RED << it.key << END << std::cout;
                    if (it == end())
                        this->_tree.insert(*first);

                    first++;
                };
            }

            void erase(iterator position) { this->_tree.remove(*position); }

            size_type erase(const key_type &k)
            {
                iterator it = find(k);
                if (it == end())
                    return (0);

                size_type res = size();
                this->_tree.remove(*it);
                return (res - size());
            }

            void erase(iterator first, iterator last)
            {
                iterator current;
                while (first != last)
                {
                    current = first;
                    first++;
                    erase(current);
                }
            }

            void swap(map &x)
            {
                this->_tree.swap(x._tree);
            };

            void clear()
            {
                iterator it = begin();
                while (it != end())
                    erase(it++);
            }

        // observers:
            key_compare key_comp() const { return _comp; };
            value_compare value_comp() const { return value_compare(_comp); };

        //map operations:
            iterator find(const key_type &k) { return (iterator(this->_tree.search(k))); };
            const_iterator find(const key_type &k) const { return (const_iterator(this->_tree.search(k))); };
            
            size_type count(const key_type &k) const { return (find(k)!=this->end()) ? 1 : 0; }
            
            iterator lower_bound(const key_type &k) { return (iterator(this->_tree.lower_bound(k))); };
            const_iterator lower_bound(const key_type &k) const { return (const_iterator(this->_tree.lower_bound(k))); };
            
            iterator upper_bound(const key_type &k) { return (iterator(this->_tree.upper_bound(k))); };
            const_iterator upper_bound(const key_type &k) const { return (const_iterator(this->_tree.upper_bound(k))); };
            
            pair<iterator, iterator> equal_range(const key_type &k) { return (ft::make_pair(lower_bound(k), upper_bound(k))); };
            pair<const_iterator, const_iterator> equal_range(const key_type &k) const { return (ft::make_pair(lower_bound(k), upper_bound(k))); };
            
            void printTree(void) { return (this->_tree.printPreOrder()); };
    };
    
    // Non membres functions
        template <class Key, class T, class Compare, class Allocator>
        bool operator==(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)     { return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); };
        
        template <class Key, class T, class Compare, class Allocator>
        bool operator!=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)     { return (!(lhs == rhs)); };
        
        template <class Key, class T, class Compare, class Allocator>
        bool operator<(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)      { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); };
        
        template <class Key, class T, class Compare, class Allocator>
        bool operator>=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)     { return (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); };
        
        template <class Key, class T, class Compare, class Allocator>
        bool operator>(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)      { return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())); };
        
        template <class Key, class T, class Compare, class Allocator>
        bool operator<=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)     { return (!(lhs > rhs)); };
    
    // specialized algorithms:
        template <class Key, class T, class Compare, class Allocator>
        void swap(map<Key, T, Compare, Allocator> &x, map<Key, T, Compare, Allocator> &y)                           { x.swap(y); };
};