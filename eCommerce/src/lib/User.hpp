#ifndef USER_HPP
#define USER_HPP
#include <iostream>

class User {
public:
	User();
	~User();

    void setEmail(std::string _email);

    std::string getEmail();

    std::string getLogin();

    std::string getPassword();

    int getIdUser();

    void setAdm(bool _adm);

    bool getAdm();

    void setIdUser(int _idUser);

    void setLoginSenha(std::string _login, std::string _senha);

	
protected:
    std::string email = "a";
    std::string login = "a";
    std::string password = "a";
    int idUser = 0;
    bool adm;
};
#endif