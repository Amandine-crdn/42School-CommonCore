#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact {

public :

    Contact();
    ~Contact();
    std::string getFirstname() const;
    std::string getLastname() const;
    std::string getNickname() const;
    std::string getPhone() const;
    std::string getSecret() const;
    void setFirstname(std::string firstname);
    void setLastname(std::string lastname);
    void setNickname(std::string nickname);
    void setPhone(std::string phone);
    void setSecret(std::string secret);

private :

    std::string _firstname;
    std::string _lastname;
    std::string _nickname;
    std::string _phone;
    std::string _secret;

};

#endif