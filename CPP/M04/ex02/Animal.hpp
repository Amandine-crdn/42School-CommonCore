#ifndef ANIMAL_HPP
#   define ANIMAL_HPP

#   include <iostream>

class Animal {

    public:
       //ex02 suppression du constructeur
        virtual ~Animal(); //ex01
        Animal(Animal const &cpy);
        Animal& operator=(Animal const &op);

        void setType(std::string change);
        std::string getType() const;
        void makeSound() const;

    protected :
        std::string type;
};

#endif