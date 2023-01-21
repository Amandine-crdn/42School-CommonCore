#pragma once

#include <iostream> // necessaire ? pas sur
#include <memory> // pour choper le std::allocator
#include <stdexcept>
#include <algorithm>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include <vector> ///// A SUPPRIMER
namespace ft {

	// template < class T, class Alloc = std::allocator<T> > 
	// class vector
	// {
 	// 	public:

	// 		typedef T 																		value_type;
	// 		typedef Alloc 																	allocator_type;
	// 		typedef typename allocator_type::reference 										reference;
	// 		typedef typename allocator_type::const_reference 								const_reference;
	// 		typedef typename allocator_type::pointer 										pointer;
	// 		typedef typename allocator_type::const_pointer 									const_pointer;
	// 		typedef pointer																	iterator;
	// 		typedef const_pointer															const_iterator;
	// 		typedef	ft::reverse_iterator< iterator > 										reverse_iterator;
	// 		typedef	ft::reverse_iterator< const_iterator > 									const_reverse_iterator; 
	// 		typedef typename ft::iterator_traits< iterator >::difference_type 				difference_type;
	// 		typedef typename allocator_type::size_type 										size_type;
	

	// 	/* Constructor */

	// 		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _alloc(alloc), _p(NULL), _capacity(0) {}; //initialiser attributs priver si besoin ?
			
	// 		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(0) ,_alloc(alloc), _p(NULL), _capacity(0)
	// 		{
	// 			this->clear();
	// 			this->resize(n, val);//🌈
	// 		};
		

	// 		template <class InputIterator>
	// 		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _size(0), _alloc(alloc)
	// 		{
	// 			InputIterator temp = first;
	// 			difference_type n = 0;
				
	// 			for (; temp != last; temp++)
	// 			++n;

	// 			_p = _alloc.allocate(n);
	// 			_capacity = n;

	// 			for (; first != last; first++)
	// 			push_back(*first);
	// 		}
			
	// 		vector (const vector& x) : _size(0), _alloc(x._alloc), _p(NULL), _capacity(0)
	// 		{
	// 			this->assign(x.begin(), x.end());
	// 		}
		
			
	// 	/* Destructor */
	// 		~vector()
	// 		{
	// 			this->clear();
	// 			// this->get_allocator().deallocate(this->_p, this->capacity()); //si on commente cette ligne = leaks
	// 			// si on la laisse, trop de free A CREUSER 🌈
	// 			// _alloc.deallocate(this->_p, this->capacity());
	// 		};

	// 	/* Operator */
	// 		vector& operator= (const vector& x)
	// 		{
	// 			this->assign(x.begin(), x.end());
	// 			return (*this);
	// 		}

		// /* Modifiers */

		// 	//assign
		// 	template <class InputIterator>
		// 	void assign (InputIterator first, InputIterator last)
		// 	{
		// 		typename ft::vector<T> tempVector(first, last);
		// 		this->clear();
		// 		this->_capacity = tempVector.size();//
		// 		this->_p = _alloc.allocate(tempVector.size());//

		// 		for (typename ft::vector<T>::iterator it = tempVector.begin(); it != tempVector.end(); it++)
		// 		push_back(*it);
		// 	}
		
		// 	void assign (size_type n, const value_type& val)
		// 	{
		// 		this->clear();
		// 		this->resize(n, val);
		// 	}
			// //insert
			// iterator insert (iterator position, const value_type& val)
			// {
			// 	typename ft::vector<T> tempVector(this->begin(), this->end());
			// 	typename ft::vector<T>::iterator it = tempVector.begin();
			
			// 	size_type distance = std::distance(position, this->end());
				
			// 	if (distance == 0)
			// 		this->push_back(val);
			// 	else if (distance > 0 && distance <= tempVector.size())
			// 	{
			// 		this->clear();
			// 		for (; it != tempVector.end(); it++)
			// 		{
			// 			size_type tempDistance = tempVector.end() - it;	
			// 			if (tempDistance == distance)
			// 				this->push_back(val);
			// 			this->push_back(*it);
			// 		}
			// 	}
			// 	else
			// 		this->push_back(0);
			// 	return position;
			// }

			// void insert (iterator position, size_type n, const value_type& val)
			// {
			// 	typename ft::vector<T> tempVector(this->begin(), this->end());
			// 	typename ft::vector<T>::iterator it = tempVector.begin();
			
			// 	size_type distance = std::distance(position, this->end());

			// 	if (distance == 0)
			// 	{
			// 		for (; n > 0; n--)
			// 		this->push_back(val);
			// 	}
			// 	else if (distance > 0 && distance <= tempVector.size())
			// 	{
			// 		this->clear();
			// 		for (; it != tempVector.end(); it++)
			// 		{
			// 			size_type tempDistance = tempVector.end() - it;		
			// 			if (tempDistance == distance)
			// 			{
			// 				for (; n > 0; n--)
			// 				this->push_back(val);
			// 			}
			// 			this->push_back(*it);
			// 		}
			// 	}
			// 	else
			// 	{
			// 		for (; n > 0; n--)
			// 		this->push_back(val);
			// 	}
			// }
////////////////////////////////////////// icicicicciciici ////////////////////
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				typename ft::vector<T> tempVector(this->begin(), this->end());
				typename ft::vector<T>::iterator it = tempVector.begin();

				typename ft::vector<T>::iterator it_bfor_toInclude = first;
				typename ft::vector<T>::iterator it_efor_toInclude = last;
				typename ft::vector<T> to_include;

				for(; it_bfor_toInclude != it_efor_toInclude; it_bfor_toInclude++)
				to_include.push_back(*it_bfor_toInclude);
	
				size_type distance = std::distance(position, this->end());

				typename ft::vector<T>::iterator itb = to_include.begin();
				typename ft::vector<T>::iterator ite = to_include.end();
				
				if (distance == 0)
				{
					for (; itb != ite; itb++)
					this->push_back(*itb);
				}
				else if (distance > 0 && distance <= tempVector.size())
				{
					this->clear();
					for (; it != tempVector.end(); it++)
					{
						size_type tempDistance = tempVector.end() - it;	
						if (tempDistance == distance)
						{
							for (; itb != ite; itb++)
							this->push_back(*itb);
						}
						this->push_back(*it);
					}
				}
				else
				{
					for (; itb != ite; itb++)
					this->push_back(*itb);
				}
			}
////////////////////////////////////////// icicicicciciici ////////////////////
			// //erase 🌈
			// iterator erase (iterator position)
			// {
			// 	if (this->empty())
			// 		return (this->end());
			// 	iterator it = this->begin();
			// 	while (it != position)
			// 		it++;
			// 	this->_alloc.destroy(it);
			// 	while (it + 1 != this->end())
			// 	{
			// 		this->_alloc.construct(it, *(it + 1));
			// 		it++;
			// 	}
			// 	this->pop_back();
			// 	return (position);
			// }
			
			// iterator erase (iterator first, iterator last)
			// {
			// 	if (this->empty())
			// 		return (this->end());
			// 	iterator it = this->begin();
			// 	iterator save = first;
			// 	difference_type dist = last - first;
			// 	while (it != first)
			// 		it++;
			// 	for (; first != last; first++)
			// 		this->_alloc.destroy(first);
			// 	while (it + dist != this->end())
			// 	{
			// 		this->_alloc.construct(it, *(it + dist));
			// 		it++;
			// 	}
			// 	while (dist-- > 0)
			// 		this->pop_back();
			// 	return (save);
			// }
			
			
			// //push_back
			// 	void push_back (const value_type& val)
			// 	{
			// 		this->reserve(this->size() + 1);
			// 		this->_alloc.construct(this->_p + this->size(), val);
			// 		this->_size++;
			// 	}

			// //pop_back
			// 	void pop_back()
			// 	{
			// 		if (this->empty())
			// 			return;
			// 		this->_size--;
			// 		this->_alloc.destroy(this->_p + this->size());
				// }

			// //clear
			// 	void clear()
			// 	{
			// 		// if (this->_size)
			// 		// {
			// 		// 	// parcourir depuis iterator.begin() jusqua end() pour etre sur de bien tout free
			// 		// }
			// 		for (size_type i = 0; i < this->size(); i++)
			// 		this->_alloc.destroy(this->_p + i);
					
			// 		this->_size = 0;
			// 	}

			// //swap 
			// 	void swap (vector& x)
			// 	{
			// 		std::swap(this->_p, x._p);
			// 		std::swap(this->_size, x._size);
			// 		std::swap(this->_capacity, x._capacity);
			// 	}


	// 	/* Capacity */

	// 		//size()
	// 			size_type size() const { return this->_size; };

	// 		//max_size()
	// 			size_type max_size() const { return this->_alloc.max_size(); };

	// 		//empty()
	// 			bool empty() const
	// 			{
	// 				if (this->_size == 0)
	// 					return true;
	// 				return false ;
	// 			};

	// 		//capacity
	// 			size_type capacity() const { return this->_capacity; }
				
	// 		//resize
	// 			void resize (size_type n, value_type val = value_type())
	// 			{
	// 				if (n > this->_capacity)
	// 					this->reserve(n);
	// 				if (n < this->size())
	// 				{
	// 					for (size_type i = n; i < this->size(); i++)
	// 					this->get_allocator().destroy(this->_p + i);
	// 				}
	// 				else if (n > this->size())
	// 				{
	// 					for (size_type i = this->size() ; i <= n; i++)
	// 					this->get_allocator().construct(this->_p + i, val);
	// 				}
	// 				this->_size = n;
	// 			}
			
	// 		//reserve()
	// 			void reserve (size_type n)
	// 			{
	// 				if (n > this->max_size())
	// 					throw std::length_error("error reserve");
			
	// 				else if (n > this->_capacity)
	// 				{
	// 					size_type new_capacity = n * 2;

	// 					pointer new_p = this->_alloc.allocate(new_capacity);

	// 					for (size_type i = 0; i < this->size(); i++)
	// 					{
	// 						this->_alloc.construct(new_p + i, this->_p[i]);
	// 						this->_alloc.destroy(this->_p + i);
	// 					}
	// 					this->_alloc.deallocate(this->_p, this->capacity());
	// 					this->_p = new_p;
	// 					this->_capacity = new_capacity;
	// 				}
	// 			}
	// /* Iterators *///🌈

	// 	//begin
	// 	iterator begin() { return this->_p; }
	// 	const_iterator begin() const  { return this->_p; }
	// 	//end
	// 	iterator end() { return this->begin() + this->size(); }
	// 	const_iterator end() const { return this->begin() + this->size(); }
	// 	//rbegin
	// 	reverse_iterator rbegin() { return reverse_iterator(this->end()); }
	// 	const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
	// 	//rend
	// 	reverse_iterator rend() { return reverse_iterator(this->begin()); }
	// 	const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }
	
	// /*Element access*///🌈

	// 	//operator[]
	// 	reference operator[] (size_type n) {return this->_p[n]; };
	// 	const_reference operator[] (size_type n) const { return this->_p[n]; };
	// 	//at
	// 	//	throw std::out_of_range("vector::_M_range_check: __n (which is " + n + ") >= this->size() (which is " + this->_size);

	// 	reference at (size_type n)
	// 	{
	// 		if (n >= this->_size)
	// 			throw std::out_of_range("error at");
	// 		return this->_p[n];
	// 	};
	// 	const_reference at (size_type n) const
	// 	{
	// 		if (n >= this->_size)
	// 			throw std::out_of_range("error at");
	// 		return this->_p[n];
	// 	};
	// 	//front
	// 	reference front() {return *(this->begin()); };
	// 	const_reference front() const {return *(this->begin()); };
	// 	//back
	// 	reference back() {return *(this->rbegin()); };
	// 	const_reference back() const {return *(this->rbegin()); };


		// /*getters and setters*/
		// 	allocator_type get_allocator() const { return this->_alloc; }



	// 	/*Relational operators*/
	// 	friend bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) 
	// 	{
	// 		return (&lhs == &rhs) || (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	// 	};

	// 	friend bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// 	{
	// 		return !(lhs == rhs);
	// 	};

	// 	friend bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// 	{
	// 		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	// 	}

	// 	friend bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// 	{
	// 		// return lhs > rhs;
	// 		return rhs < lhs;
	// 	}

	// 	friend bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// 	{
	// 		// return !(lhs > rhs);
	// 		return lhs == rhs || lhs < rhs;
	// 	}


	// 	friend bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// 	{
	// 		// return !(lhs < rhs);
	// 		return lhs == rhs || lhs > rhs;
	// 	}

  	// 	friend void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {	x.swap(y); }

	// 	protected :
	// 		size_type 	_size;
	// 		Alloc 		_alloc;
	// 		pointer		_p;
	// 		size_type	_capacity;
	// };


}
