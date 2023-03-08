# pragma once

#include <memory>
#include "iterator/random_access_iterator.hpp"
#include "utils/utils.hpp"
#include "iterator/reverse_iterator.hpp"
#include <iostream>

namespace ft
{
	template<typename Iterator>
	std::ptrdiff_t distance(Iterator first, Iterator last) {
		std::ptrdiff_t dist = 0;
		while (first != last) {
			++dist;
			++first;
		}
		return (dist);
}
template < class T, class Allocator = std::allocator<T> > 
	class vector
	{
		public:
			typedef				T												value_type;
			typedef				Allocator										allocator_type;
			typedef typename	allocator_type::size_type						size_type;
			typedef typename	allocator_type::reference						reference;
			typedef typename	allocator_type::const_reference					const_reference;
			typedef typename	allocator_type::pointer							pointer;
			typedef typename	allocator_type::const_pointer					const_pointer;
			typedef typename	ft::random_access_iterator<pointer>				iterator;
			typedef typename	ft::random_access_iterator<const_pointer>		const_iterator;
			typedef typename	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename	ft::iterator_traits<iterator>::difference_type	difference_type;

		/* Constructors */
			vector(): _p(NULL), _size(0), _capacity(0), _alloc(allocator_type()) {};

			explicit vector(const allocator_type& alloc): _p(NULL), _size(0), _capacity(0), _alloc(alloc) {};

			explicit vector( size_type count,const value_type& value = value_type(),const allocator_type& alloc = allocator_type())
			{
				this->_p = NULL;
				this->_alloc = alloc;
				this->_size = 0;
				this->_capacity = 0;
				this->assign(count, value);
			};

			template< class InputIterator >
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				this->_p = NULL;
				this->_alloc = alloc;
				this->_size = 0;
				this->_capacity = 0;
				InputIterator temp = first;
				difference_type n = 0;
				
				for (; temp != last; temp++)
				++n;

				_p = _alloc.allocate(n);
				_capacity = n;

				for (; first != last; first++)
				push_back(*first);

				/*this->assign(first, last);*/
			};

			vector(const vector& x ): _p(NULL), _size(0), _capacity(0), _alloc(x._alloc)
			{
				this->assign(x.begin(), x.end());

				/**this = other;*/
			};

			/* Destructor */
			~vector()
			{
				this->clear();
				this->get_allocator().deallocate(this->_p, this->capacity());
			};
			// ~vector(){
			// 	for (size_type i = 0; i < _size; i++) {
			// 		_alloc.destroy(_p + i);
			// 	}
			// 	if (_capacity > 0) 
			// 		_alloc.deallocate(_p, _capacity);
			// };

			/* Operator */
			vector& operator= (const vector& x)
			{
				if (&x != this)
				{
					this->clear();
					this->assign(x.begin(), x.end());
				}
				return (*this);
			}
			// vector&	operator=(const vector& other){
			// 	if (this != &other){
			// 		clear();
			// 		reserve(other._size);
			// 		for (size_type i = 0; i < other.size(); i++){
			// 			_alloc.construct(_p + i, other[i]);
			// 			_size++;
			// 		}
			// 	}
			// 	return (*this);
			// };

			/* Modifiers */

			//assign
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				this->clear();
				for (InputIterator it = first; it != last; ++it)
				push_back(*it);
				/* size_type	n = ft::distance(first, last);
				if (_size + n > _capacity && (_size) + n > _capacity * 2)
					this->reserve((_capacity - _size) + n);
				else if (_size + n > _capacity && (_size) + n < _capacity * 2)
					this->reserve(_capacity * 2);
				while (first != last)
					this->push_back(*(first++));*/
			};

			void assign(size_type n, const value_type& val)
			{
				this->clear();
				while (n) 
				{
					push_back(val);
					--n;
				}
				/*if (_capacity == _size)
				{
					if (_capacity + n > _capacity * 2)
						this->reserve(_capacity + n);

					else
						this->reserve(_capacity * 2);
				}
				while (n--)
				 	this->push_back(val);*/
			};

			//insert
			iterator	insert(iterator position, const value_type& val)
			{
				/*typename ft::vector<T> tempVector(this->begin(), this->end());
				typename ft::vector<T>::iterator it = tempVector.begin();
			
				size_type distance = std::distance(position, this->end());
				
				if (distance == 0)
					this->push_back(val);
				else if (distance > 0 && distance <= tempVector.size())
				{
					this->clear();
					for (; it != tempVector.end(); it++)
					{
						size_type tempDistance = tempVector.end() - it;	
						if (tempDistance == distance)
							this->push_back(val);
						this->push_back(*it);
					}
				}
				else
				{
					// this->push_back(val);
					this->push_back(0);
				}
				return position;*/
				size_type n = ft::distance(this->begin(), position);
				this->insert(position, 1, val);
				return (iterator(&_p[n]));
			};

			void	insert(iterator position, size_type n,const value_type& val)
			{
				/*typename ft::vector<T> tempVector(this->begin(), this->end());
				typename ft::vector<T>::iterator it = tempVector.begin();
			
				size_type distance = std::distance(position, this->end());

				if (distance == 0)
				{
					for (; n > 0; n--)
					this->push_back(val);
				}
				else if (distance > 0 && distance <= tempVector.size())
				{
					this->clear();
					for (; it != tempVector.end(); it++)
					{
						size_type tempDistance = tempVector.end() - it;		
						if (tempDistance == distance)
						{
							for (; n > 0; n--)
							this->push_back(val);
						}
						this->push_back(*it);
					}
				}
				else
				{
					for (; n > 0; n--)
					this->push_back(val);
				}*/
				size_type index = position - this->begin();

				if (n) 
				{
					if (_size + n  > _capacity) 
					{
						if (!_capacity)
							this->reserve(1);
						else
							this->reserve(_size * 2);
						if (_capacity < _size + n)
							this->reserve(_size + n);
					}
					for (size_type i = _size; i > index; i--) {
						_alloc.construct(_p + i + n - 1,*(_p + i - 1));
						_alloc.destroy(_p + i - 1);
					}
					for (size_type i = 0; i < n; i++) {
						_alloc.construct(_p + index + i, val);
						_size++;
					}
				}
			};

			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				/*typename ft::vector<T> tempVector(this->begin(), this->end());
				typename ft::vector<T>::iterator it = tempVector.begin();
				typename ft::vector<T> to_include;

				for (; first != last; first++)
				to_include.push_back(*first);
	
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
				}*/
				size_type count = ft::distance(first, last);
				ft::vector<value_type> tmp(first, last);
				size_type pos = position - this->begin();

				while (count--)
					this->insert(this->begin() + pos, tmp[count]);
			};

			//erase
			iterator	erase(iterator position)
			{
				/*if (this->empty())
					return (this->end());
				iterator it = this->begin();
				while (it != position)
					it++;
				this->_alloc.destroy(it);
				while (it + 1 != this->end())
				{
					this->_alloc.construct(it, *(it + 1));
					it++;
				}
				this->pop_back();
				return (position);*/
				iterator ret = position == this->end() ? this->end() : position;

				while (position + 1 != this->end()) {
					*position = *(position + 1);
					position++;
				}
				this->pop_back();
				return ret;
			};

			iterator erase(iterator first, iterator last)
			{
				/*if (this->empty())
					return (this->end());
				iterator it = this->begin();
				iterator save = first;
				difference_type dist = last - first;
				while (it != first)
					it++;
				for (; first != last; first++)
					this->_alloc.destroy(first);
				while (it + dist != this->end())
				{
					this->_alloc.construct(it, *(it + dist));
					it++;
				}
				while (dist-- > 0)
					this->pop_back();
				return (save);*/
				iterator start = first;
				iterator end = this->end();
				size_type count = last - first;

				if (count == 0)
					return last;

				while (first + count != this->end())
				{
					*(first) = *(first + count);
					first++;
				}

				while (count--)
					this->pop_back();

				if (last == end)
					return this->end();

				return iterator(start);
			};

			//push_back
			void	push_back(const value_type& val)
			{
				this->reserve(this->size() + 1);
				this->_alloc.construct(this->_p + this->size(), val);
				this->_size++;
				/*if (_size == _capacity)
					this->empty() ? this->reserve(1) : this->reserve(_size * 2);
				_alloc.construct(_p + _size, val);
				_size++;*/
			};

			//pop_back
			void	pop_back()
			{
				if (this->empty())
					return;
				this->_size--;
				this->_alloc.destroy(this->_p + this->size());
				/*if (_size > 0){
					_size--;
					_alloc.destroy(_p + _size);
				}*/
			};

			//clear
			void	clear()
			{
				/*	for (size_type i = 0; i < this->size(); i++)
					this->_alloc.destroy(this->_p + i);
					
					this->_size = 0;*/
				if (this->_p)
				{
					while (this->_size > 0)
						this->pop_back();
				}
			}

			//swap 
				void swap (vector& x)
				{
					std::swap(this->_p, x._p);
					std::swap(this->_size, x._size);
					std::swap(this->_capacity, x._capacity);
				}

			/*void	swap(vector& other)
			{
				allocator_type    tmp_alloc = _alloc;
				pointer           tmp_p = _p;
				size_type         tmp_capacity = _capacity;
				size_type         tmp_size = _size;

				_alloc = other._alloc;
				_p = other._p;
				_capacity = other._capacity;
				_size = other._size;

				other._alloc = tmp_alloc;
				other._p = tmp_p;
				other._capacity = tmp_capacity;
				other._size = tmp_size;
			}*/

		/* Capacity */

			//size()
			size_type size() const { return this->_size; }

			//max_size()
			size_type max_size() const { return this->_alloc.max_size(); };

			//empty()
			bool empty() const { return (this->_size == 0);};
			/*bool empty() const
				{
					if (this->_size == 0)
						return true;
					return false ;
				};*/

			//capacity
			size_type capacity() const { return (this->_capacity); }

			//resize
			void	resize(size_type n, value_type val = value_type())
			{
				if (n > this->_capacity)
					this->reserve(n);
				if (n < this->size())
				{
					for (size_type i = n; i < this->size(); i++)
					this->get_allocator().destroy(this->_p + i);
				}
				else if (n > this->size())
				{
					// for (size_type i = this->size() ; i <= n; ++i) // auparavant
					for (size_type i = this->size() ; i < n; i++)
					this->get_allocator().construct(this->_p + i, val);
				}
				this->_size = n;

				/*if (n < this->_size)
					this->erase(this->begin() + n, this->end());
				else 
					this->insert(this->end(), n - this->_size, val);*/
			}

			//reserve()
			void	reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n > this->_capacity){
					pointer tmp = this->_alloc.allocate(n);
					for (size_type i = 0; i < this->_size; i++){
						this->_alloc.construct(tmp + i, this->_p[i]);
						this->_alloc.destroy(this->_p + i);
					}
					if (this->_capacity > 0)
						this->_alloc.deallocate(this->_p, this->_capacity);
					this->_p = tmp;
					this->_capacity = n;
				}
				/*					
					if (n > this->max_size())
						throw std::length_error("vector::reserve");
			
					else if (n > this->_capacity)
					{
						size_type new_capacity = n * 2; // si on met ca reserve merde
						// si on met ca insert merde
						// size_type new_capacity = n;
						// if (new_capacity <= 64)
						// 	new_capacity = 64;
						if (this->capacity() > (new_capacity / 2))
							new_capacity = this->capacity() * 2;
						pointer new_p = this->_alloc.allocate(new_capacity);

						for (size_type i = 0; i < this->size(); i++)
						{
							this->_alloc.construct(new_p + i, this->_p[i]);
							this->_alloc.destroy(this->_p + i);
						}
						this->_alloc.deallocate(this->_p, this->capacity());
						this->_p = new_p;
						this->_capacity = new_capacity;
					}*/
			};

			/* Iterators*/
			//begin
			iterator begin() { return (iterator(this->_p));}
			const_iterator begin() const { return (const_iterator(this->_p));}
			//end
			iterator end() { return (iterator(this->_p + this->_size));}
			const_iterator end() const { return (const_iterator(this->_p + this->_size));}
			//rbegin
			reverse_iterator rbegin() { return (reverse_iterator(this->end()));}
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->end()));}
			//rend
			reverse_iterator rend() { return (reverse_iterator(this->begin()));}
			const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin()));}

		/*Element access*/
		//operator[]
		reference operator[] (size_type n) {return this->_p[n]; };
		const_reference operator[] (size_type n) const { return this->_p[n]; };
		//at
		reference at (size_type n)
		{
			if (n >= this->_size)
				throw std::out_of_range("vector::at");
			return this->_p[n];
		}
		const_reference at (size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("vector::at");
			return this->_p[n];
		}
		//front
		reference front() { return *(this->begin()); };
		const_reference front() const { return *(this->begin()); };
		//back
		reference back() { return *(this->rbegin()); };
		const_reference back() const { return *(this->rbegin()); };

			// reference front() {	return (_p[0]); };
			// const_reference front() const {	return (_p[0]); };
			// reference back() { return (_p[_size - 1]); };
			// const_reference back() const { return (_p[_size - 1]); };	

		/*getters and setters*/
			allocator_type	get_allocator()const { return (_alloc); }

		private:
			pointer 		_p;
			size_type 		_size;
			size_type 		_capacity;
			allocator_type 	_alloc;
		
	};

	/*Relational operators*/
	template <class T, class Alloc>
	bool operator==( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
	{
		// return (&lhs == &rhs) || (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator>( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
	{
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool operator<=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
	{
		//return ((lhs < rhs) || (lhs == rhs));
		return lhs == rhs || lhs < rhs;
	}

	template <class T, class Alloc>
	bool operator>=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
	{
		return (!(lhs < rhs));
		// return lhs == rhs || lhs > rhs;
	}
	
	/* swap non membre */
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){	x.swap(y); }
}
