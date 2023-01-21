#pragma once

#include <iostream> // necessaire ? pas sur
#include <memory> // pour choper le std::allocator
// #include <stdexcept>
#include <functional>
#include <algorithm>
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
#include <map> ///// A SUPPRIMER
#include "pair.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
	class map
	{
 		public:
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<const key_type, mapped_type>					value_type;
			typedef Compare													key_compare; //defaults to: less<key_type>
			typedef Allocator												allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer 					const_pointer;

			typedef pointer													iterator;
			typedef const_pointer											const_iterator;
			
			// typedef  ft::reverse_iterator<iterator>							reverse_iterator;
			// typedef  ft::reverse_iterator<const_iterator> 					const_reverse_iterator;
			
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type						size_type;


			// class value_compare : public binary_function<value_type,value_type,bool>
			// {
			// 	friend class map;

			// 	protected:
			// 		Compare comp;
			// 		value_compare(Compare c) : comp(c) {}
				
			// 	public:
			// 		bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
			// };

			/* Constructors */
				explicit map(const Compare& comp = Compare(), const allocator_type& alloc = allocator_type()) : _kcomp(comp) , _alloc(alloc) {}
				
				// template <class InputIterator>
				// map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator()) : _size(0), _alloc(alloc), _p(NULL), _capacity(0)
				// {

				// }

				map(const map<Key,T,Compare,Allocator>& x) : _alloc(0)
				{
					this->_kcomp = x._kcomp();
					this->_alloc = x.get_allocator();
				}
			
			/* Destructor */
				~map() { 
				};
	
			/* getter */
				allocator_type get_allocator() const { return this->_alloc; }

			/* Observers */
				key_compare key_comp() const { return this->_kcomp; }
			// 	value_compare value_comp() const { }

			// /* Operator */
				map<Key,T,Compare,Allocator>&operator=(const map<Key,T,Compare,Allocator>& x)
				{
					//clear
					this->_kcomp = x._kcomp();
					this->_alloc = x.get_allocator();
				}

		protected :
			key_compare	_kcomp;
			Allocator	_alloc;


			// /* Iterators */
			// 	iterator begin();
			// 	const_iterator begin() const;

			// 	iterator end();
			// 	const_iterator end() const;

			// 	reverse_iterator rbegin();
			// 	const_reverse_iterator rbegin() const;

			// 	reverse_iterator rend();
			// 	const_reverse_iterator rend() const;
				
			// /* Capacity */
			// 	bool empty() const;
			// 	size_type size() const;
			// 	size_type max_size() const;

			// /* Element access */
			// 	T& operator[](const key_type& x);

			// /* Modifiers */

			// 	// insert
			// 	pair<iterator, bool> insert(const value_type& x);

			// 	iterator insert(iterator position, const value_type& x);

			// 	template <class InputIterator>
			// 	void insert(InputIterator first, InputIterator last);
				
			// 	//erase
			// 	void erase(iterator position);
			// 	size_type erase(const key_type& x);
			// 	void erase(iterator first, iterator last);

			// 	void swap(map<Key,T,Compare,Allocator>&);
			// 	void clear();



			// /* Map operations */
			// 	//find
			// 	iterator find(const key_type& x);
			// 	const_iterator find(const key_type& x) const;
				
			// 	size_type count(const key_type& x) const;
				
			// 	//lower_bound
			// 	iterator lower_bound(const key_type& x);
			// 	const_iterator lower_bound(const key_type& x) const;
				
			// 	//upper_bound
			// 	iterator upper_bound(const key_type& x);
			// 	const_iterator upper_bound(const key_type& x) const;
				
			// 	//equal range
			// 	pair<iterator,iterator> equal_range(const key_type& x);
			// 	pair<const_iterator,const_iterator> equal_range(const key_type& x) const;
		

	};
			/* Non member functions */
				// template <class Key, class T, class Compare, class Allocator>
				// bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
				// {
					
				// 	return &x == &y ;
				// };

				// template <class Key, class T, class Compare, class Allocator>
				// bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y) { return &x != &y ; };

				// template <class Key, class T, class Compare, class Allocator>
				// bool operator< (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y) { return &x < &y ; };

				// template <class Key, class T, class Compare, class Allocator>
				// bool operator> (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y) { return &x > &y ; };

				// template <class Key, class T, class Compare, class Allocator>
				// bool operator>=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y) { return &x >= &y ; };

				// template <class Key, class T, class Compare, class Allocator>
				// bool operator<=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y) { return &x <= &y ; };

			/* Specialized algorithms */
				// template <class Key, class T, class Compare, class Allocator>
				// void swap(map<Key,T,Compare,Allocator>& x,map<Key,T,Compare,Allocator>& y) { };


}