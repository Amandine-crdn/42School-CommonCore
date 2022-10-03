#ifndef ARRAY_HPP
#   define ARRAY_HPP

#   include <iostream>
#   include <iomanip>
#   include <string>
#   include <exception>

template<typename T>
class Array {

    public :

        Array() : _array(new T[0]()), _size(0) {};
        Array(unsigned int n) : _array(new T[n]), _size(n) {};
        ~Array() {delete [] this->_array;};

        Array(const Array& copy)
        : _array(new T[copy._size]), _size(copy._size)
        {
            for (unsigned int i = 0; i < this->size(); i++)
            this->_array[i] = copy._array[i];
        };

        unsigned int size() const { return(_size);}

        T& operator[](unsigned int i)
        {
            if (i > this->_size - 1)
                throw Array::ArrayAccess();
            return (this->_array[i]);
        };

        class ArrayAccess : public std::exception
		{
			public:
				const char* what() const throw() { return ("Watch out.."); };
		};

    private :

        T *_array;
        unsigned int _size;

};


#endif