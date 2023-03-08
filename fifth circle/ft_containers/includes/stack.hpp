# pragma once

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		protected:
			Container	_container;

		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type; 
			typedef typename Container::size_type		size_type; 
			// typedef typename Container::reference		reference; 
			// typedef typename Container::const_reference	const_reference; 

		/* Constructor and destructor */
			explicit stack( const container_type& cont = container_type()): _container(cont){};

			stack( const stack& other ) : _container(other._container) {}

			~stack(){};
		/* Operator */
			stack& operator=( const stack& other )
			{
				if (this != &other)
					this->_container = other._container;
				return (*this);
			}
		/* Functions */
			// reference top(){ return (this->_container.back());}
			//const_reference top() const { return (this->_container.back());}
			value_type& top(){ return (this->_container.back());}
			const value_type& top() const { return (this->_container.back());}

			bool empty() const { return (this->_container.size() == 0);}

			size_type size() const { return (this->_container.size());}

			void push( const value_type& value ){ this->_container.push_back(value);}

			void pop(){ this->_container.pop_back();}

		friend bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return (lhs._cont == rhs._cont); }

		friend bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return (lhs._cont != rhs._cont); }

		friend bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return (lhs._cont < rhs._cont); }

		friend bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return (lhs._cont <= rhs._cont); }

		friend bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return (lhs._cont > rhs._cont); }

		friend bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return (lhs._cont >= rhs._cont); }
	};
}
