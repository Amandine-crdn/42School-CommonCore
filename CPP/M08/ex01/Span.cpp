#include "Span.hpp"

Span::Span(unsigned int N)
: _max(N), _count(0) {
   
}

Span::~Span(){
    
}
// Span::Span(Span const &cpy){
    
// }

// Span &Span::operator=(Span const &op){
    
// }

void Span::addNumber( unsigned int nbAdd ){
    if (this->_count >= this->_max)
        throw Span::NoMoreException();
    else
    {
        this->_tab.push_back(nbAdd);
        this->_count++;
    }
}

int  Span::getCount( void ) const {
    return (this->_count);
}

int  Span::getValueTab( int i ) const {
    if (i >= this->getCount())
        throw Span::InconnuValue();
    return (this->_tab[i]);
}

//exeptions
const char* Span::NoMoreException::what() const throw(){
	return ("Span : NoMoreException: is full");
}
const char* Span::InconnuValue::what() const throw(){
	return ("Span : InconnuValue: sorry is not permissed");
}

//ostream surcharge operator
std::ostream &operator<<(std::ostream &os, Span const &sp){
    for (int i = 0; i < sp.getCount(); i++)
    os << "tab[" << i << "] = " << sp.getValueTab(i) << std::endl;
    return (os);
}