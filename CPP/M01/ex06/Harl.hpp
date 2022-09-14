#include <iostream>
#include <string>
class Harl {

    public:
        Harl();
        ~Harl();
        void complain( std::string level_spe);

    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};