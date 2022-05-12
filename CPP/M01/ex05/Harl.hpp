#include <iostream>

class Harl
{
    public :
    Harl();
    ~Harl();

    void complain( std::string level );

    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

    private :
};