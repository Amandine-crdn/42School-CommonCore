#ifndef VECTOR_HPP
#   define VECTOR_HPP

#   include <iostream>
#   include <memory>

template<class T, class Allocator = std::allocator<T> >
class  Vector {

    public :

        typedef std::size_t size_type; //ok
        typedef typename Allocator::pointer pointer;
        typedef vector_iterator<value_type>				iterator;


        typedef T value_type;
        typedef Allocator allocator_type; // utilité ?

        Vector() : _size(0), _capacity(10), _first(0) {} //(1)  empty container constructor (default constructor)

        ~Vector() {}
        Vector(Vector const &cpy) {}
        Vector& operator=(Vector const &op) {}

        // member functions
        void push_back(const T&value)
        {
           /* if (this->_size != this->_capacity)
            {
                this->_alloc.construct(this->_start + this->_size, value);
                this->_size++;
            }
            else
            {
                std::cout << "coucou" << std::endl;
            }
            */
            std::cout << "value = " <<  value << std::endl;

            this->_size++;
            
        }
        
        /* iterators */
       
        typename T::iterator begin() { return }

   


    private:

    /*Member types std::allocator*/ //https://cplusplus.com/reference/memory/allocator/
        size_type _size;
        size_type _capacity;
        allocator_type _alloc;
        pointer _first;
        pointer _last;

        //typedef const void _value;


};

#endif