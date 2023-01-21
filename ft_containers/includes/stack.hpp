#pragma once

#include <vector> // POUR COMPILER A SUPPRIMER PAR LA SUITE

/*Stacks are a type of container adaptor, specifically designed to operate in a LIFO context 
(last-in first-out), 
where elements are inserted and extracted only from one end of the container.*/
namespace ft
{
	template <class T, class Container = std::vector<T> >  // A REMPLACER pour le notre
	class stack
	{
		protected :
			Container _container;
		
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;


		// constructor
			explicit stack (const container_type& ctnr = container_type()) : _container(ctnr) {};

		// methods
			bool empty() const { return this->_container.empty(); };
			
			size_type size() const { return this->_container.size(); };

			value_type& top() { return this->_container.back(); };
			const value_type& top() const { return this->_container.back(); };

			void push (const value_type& val) { this->_container.push_back(val); };

			void pop() { this->_container.pop_back(); };


		friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs._container == rhs._container;};

		friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs._container != rhs._container;};

		friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs._container < rhs._container;};

		friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs._container <= rhs._container;};

		friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs._container > rhs._container;};

		friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs._container >= rhs._container;};
		
	};

}