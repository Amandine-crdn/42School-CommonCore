#pragma once

#include <iterator>
namespace ft
{
    typedef __PTRDIFF_TYPE__ ptrdiff_t;
   
    struct random_access_iterator_tag
    {
    };

    //iterators_traits
    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
    };

    template <class T>
    struct iterator_traits<T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef random_access_iterator_tag iterator_category;
        typedef T *pointer;
        typedef T &reference;
    };

    template <class T>
    struct iterator_traits<const T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef random_access_iterator_tag iterator_category;
        typedef const T *pointer;
        typedef const T &reference;
    };

    // enable if
    template<bool Cond, class T = void> struct enable_if {};

	template<class T> struct enable_if<true, T> { typedef T type; };
   
   // is integral
    template <typename T>
	struct is_integral { static const bool value = false; };

	template<>
	struct is_integral<bool> { static const bool value = true; };

	template<>
	struct is_integral<char> { static const bool value = true; };

	template<>
	struct is_integral<wchar_t> { static const bool value = true; };

	template<>
	struct is_integral<signed char> { static const bool value = true; };

	template<>
	struct is_integral<short int> { static const bool value = true; };

	template<>
	struct is_integral<int> { static const bool value = true; };

	template<>
	struct is_integral<long int> { static const bool value = true; };

	template<>
	struct is_integral<long long int> { static const bool value = true; };

	template<>
	struct is_integral<unsigned char> { static const bool value = true; };

	template<>
	struct is_integral<unsigned short int> { static const bool value = true; };

	template<>
	struct is_integral<unsigned int> { static const bool value = true; };

	template<>
	struct is_integral<unsigned long int> { static const bool value = true; };

	template<>
	struct is_integral<unsigned long long int> { static const bool value = true; };
	
    //less
    template <typename T>
    struct less : public std::binary_function<T, T, bool>
    {
        bool operator()(const T &x, const T &y) const
        {
            return (x < y);
        }
    };

    //pair
    template <typename T1, typename T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;

        pair() : first(), second() {};

        pair(const pair &p) : first(p.first), second(p.second) {};

        pair(const T1 &a, const T2 &b) : first(a), second(b) {};

        template <typename U1, typename U2>
        pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {};

        template <typename U1, typename U2>
        pair &operator=(const pair<U1, U2> &p)
        {
            first = p.first;
            second = p.second;
            return *this;
        };
        ~pair() {};
    };

        template <class T1, class T2>
        bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
        { return lhs.first == rhs.first && lhs.second == rhs.second; }

        template <class T1, class T2>
        inline bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
        { return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }
        
        template <class T1, class T2>
        bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
        { return !(lhs == rhs); }
       
        template <class T1, class T2>
        bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
        { return rhs < lhs; }

        template <class T1, class T2>
        bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
        { return !(rhs < lhs); }

        template <class T1, class T2>
        bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
        { return !(lhs < rhs); }


    //make pair
    template <class T1, class T2>
    ft::pair<T1,T2> make_pair (T1 x, T2 y) { return ( ft::pair<T1,T2>(x,y) ); };


    //lexico
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    template <typename InputIterator1, typename InputIterator2, typename Compare>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || comp(*first1,*first2) == false)
                return (false);
            else if (comp(*first1, *first2) == true)
                return (true);
            first1++;
            first2++;
        }
        return (first2 != last2);
    }

    //equal
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (pred(*first1, *first2) == false)
                return (false);
            first1++;
            first2++;
        }
        return (true);
    }
};