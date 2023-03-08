#pragma once

#include "../utils/utils.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    private:
        Iterator _iter;

    public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::reference reference;
        typedef typename iterator_traits<Iterator>::pointer pointer;
       
       // constructors
            reverse_iterator() : _iter(NULL) {};
        
            explicit reverse_iterator(Iterator x) : _iter(x) {};
    

            template <class U>
            reverse_iterator(const reverse_iterator<U> &u) : _iter(u.base()) {};
        
        // destructor
            ~reverse_iterator() {};
            
        Iterator base() const { return (this->_iter); }

      
        reference operator*() const
        {
            Iterator tmp = this->_iter;
            return *--tmp;
        }

        pointer operator->() const { return &(operator*()); }

        reverse_iterator &operator++()
        {
            --this->_iter;
            return *this;
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            --this->_iter;
            return tmp;
        }

        reverse_iterator &operator--()
        {
            ++this->_iter;
            return *this;
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++this->_iter;
            return tmp;
        }

        reverse_iterator operator+(typename reverse_iterator<Iterator>::difference_type n) const { return (reverse_iterator(this->_iter - n));  }

        reverse_iterator &operator+=(typename reverse_iterator<Iterator>::difference_type n)
        {
            this->_iter -= n;
            return *this;
        }

        reverse_iterator operator-(typename reverse_iterator<Iterator>::difference_type n) const { return (reverse_iterator(this->_iter + n)); }
 
        reverse_iterator &operator-=(typename reverse_iterator<Iterator>::difference_type n)
        {
            this->_iter += n;
            return *this;
        }

        reference operator[](typename reverse_iterator<Iterator>::difference_type n) const
        {
            return this->_iter[-n - 1];
        }
    };
    
////// No membres functions //////

	//  Relational operators 
  
    template< class Iterator1, class Iterator2 >
    bool operator==(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() == rhs.base(); }

    template< class Iterator1, class Iterator2 >
    bool operator!=(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() != rhs.base(); }

    template< class Iterator1, class Iterator2 >
    bool operator<(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() > rhs.base(); }

    template< class Iterator1, class Iterator2 >
    bool operator<=(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() >= rhs.base(); }

    template< class Iterator1, class Iterator2 >
    bool operator>(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() < rhs.base(); }

    template< class Iterator1, class Iterator2 >
    bool operator>=(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() <= rhs.base(); }

        // Addition and substraction operator
    template< class Iterator >
    reverse_iterator< Iterator > operator+(typename reverse_iterator< Iterator >::difference_type n, reverse_iterator< Iterator > const& rev_it) { return rev_it + n; }

    template< class Iterator1, class Iterator2 >
    typename reverse_iterator< Iterator1 >::difference_type operator-(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return rhs.base() - lhs.base(); }

};