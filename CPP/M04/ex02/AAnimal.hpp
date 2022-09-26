#ifndef AAnimal_HPP
#   define AAnimal_HPP

#   include <iostream>

class AAnimal {

    public:
        AAnimal();
        virtual ~AAnimal() = 0; //ex01
        AAnimal(AAnimal const &cpy);
        AAnimal& operator=(AAnimal const &op);

        void setType(std::string change);
        std::string getType() const;
        virtual void makeSound() const = 0; //ex02

    protected :
        std::string type;
};

#endif