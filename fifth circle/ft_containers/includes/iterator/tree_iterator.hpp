#pragma once

#include <iostream>
#include <iterator>
#include "../utils/utils.hpp"
#include "../iterator/reverse_iterator.hpp"

namespace ft
{
	template <class T, class Node_pointer>
	class BinarySearchTreeIterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		typedef T iterator_type;
		typedef std::bidirectional_iterator_tag 					iterator_category;
		typedef typename ft::iterator_traits<T *>::value_type 		value_type;
		typedef typename ft::iterator_traits<T>::pointer 			pointer;
		typedef typename ft::iterator_traits<T>::reference 			reference;
		typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
	
	private:
		Node_pointer _node;

	public:

		// constructors
			BinarySearchTreeIterator() : _node(NULL) {}

			explicit BinarySearchTreeIterator(Node_pointer node) : _node(node) {}

			template <class Iterator>
			BinarySearchTreeIterator(const BinarySearchTreeIterator<Iterator, Node_pointer> &obj) : _node(obj.base()) {}
		
		// operator
			BinarySearchTreeIterator &operator=(const BinarySearchTreeIterator &rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_node = rhs.node();
				return (*this);
			}
		
		// destuctor
			~BinarySearchTreeIterator() {}

		Node_pointer base() const { return this->_node; };
		reference operator*() const { return this->_node->key; }
		pointer operator->() const { return (&(operator*())); }
		Node_pointer node() const { return this->_node; }
		reference operator[](difference_type n) const { return (*(this->_node + n)); };


		bool operator==(const BinarySearchTreeIterator &obj){ return this->_node == obj._node; };
		bool operator!=(const BinarySearchTreeIterator &obj){ return this->_node != obj._node; };

		
		BinarySearchTreeIterator &operator++()
		{
			this->_node = successor(this->_node);
			return *this;
		}

		BinarySearchTreeIterator operator++(int)
		{
			BinarySearchTreeIterator<value_type, Node_pointer> tmp = *this;
			operator++();
			return tmp;
		}
		BinarySearchTreeIterator &operator--()
		{
			this->_node = predecessor(this->_node);
			return *this;
		}; // pre-decrement

		BinarySearchTreeIterator operator--(int)
		{
			BinarySearchTreeIterator<value_type, Node_pointer> tmp = *this;
			operator--();
			return tmp;
		}
	};

	
	template <class Node_pointer>
	Node_pointer successor(Node_pointer node)
	{
		Node_pointer temp = NULL;
		if (node->right)
		{
			temp = node->right;
			while (temp->left)
				temp = temp->left;
		}
		else if (node->parent)
		{
			temp = node->parent;
			while (temp && temp->right == node)
			{
				node = temp;
				temp = temp->parent;
			}
		}
		return temp;
	};

	template <class Node_pointer>
	Node_pointer predecessor(Node_pointer node)
	{
		Node_pointer temp = NULL;

		if (node->left)
		{
			temp = node->left;
			while (temp->right)
				temp = temp->right;
		}
		else if (node->parent)
		{
			temp = node->parent;
			while (temp && temp->left == node)
			{
				node = temp;
				temp = temp->parent;
			}
			if (temp == NULL)
				return node;
		}
		return temp;
	};

	template <class T, class Node_pointer>
	bool operator==( const BinarySearchTreeIterator<T, Node_pointer> &lhs, const BinarySearchTreeIterator<T, Node_pointer> &rhs)
	{ return lhs.base() == rhs.base(); }
	
	template <class T, class Node_pointer>
	bool operator!=( const BinarySearchTreeIterator<T, Node_pointer> &lhs, const BinarySearchTreeIterator<T, Node_pointer> &rhs)
	{ return !(lhs.base() == rhs.base()); }

}