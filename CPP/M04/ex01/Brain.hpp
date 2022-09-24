#ifndef BRAIN_HPP
#   define BRAIN_HPP

#   include <iostream>

class Brain {

    private:
        static const int _nb_ideas = 100; //prk static const
        
    public :
        Brain();
        ~Brain();
        Brain(Brain const &cpy);
        Brain& operator=(Brain const &op);
        std::string ideas[Brain::_nb_ideas];
};

#endif