#ifndef SPAN_HPP
#   define SPAN_HPP

#   include <iostream>
#   include <string>
#   include <vector>
#   include <algorithm>
#   include <exception>
#include <list>

class Span {

    public :
        Span(unsigned int N);
        ~Span();
        Span(Span const &cpy);

        Span &operator=(Span const &op);

        //fonction membre
        void addNumber( unsigned int nbAdd );

        int longestSpan();
        int shortestSpan();

        void addLotof(std::vector<int> &p);

        //getters
        int getCount( void ) const;
        int getValueTab( int i ) const;

        //expetions
        class NoMoreException : public std::exception {
            public :
                const char * what() const throw();
        };
        class InconnuValue : public std::exception {
            public :
                const char * what() const throw();
        };
        class NoPossible : public std::exception {
            public :
                const char * what() const throw();
        };


    private :
        Span();
        unsigned int  _max;
        std::vector<int>    _tab;
        unsigned int        _count;


};

std::ostream &operator<<(std::ostream &os, Span const &sp);

#endif