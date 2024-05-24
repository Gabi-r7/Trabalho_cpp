#include <iostream>
#include <vector>
#ifndef USER_HPP
#define USER_HPP

class User {
    public:
        User() { adm = false; };
        ~User(){};
        std::string login;
        int idUser;
        
        void setEmail(std::string _email) {
			email = _email;
		};

        std::string getEmail() {
			return email;
		};

        void setStatus(bool _devedor) {
			devedor = _devedor;
		};

        



        bool getStatus() {
            return devedor;
        };

        std::string getLogin(){
            return login;
        };

        std::string getPassword(){
            return password;
        };

        int getIdUser(){
            return idUser;
        };

        void setAdm(bool _adm){
            adm = _adm;
        };

        bool getAdm(){
            return adm;
        };

        void setMulta(float _valorMulta){
            valorMulta = _valorMulta;
        };

        float getMulta(){
            return valorMulta;
        };

        void setIdUser(int _idUser){
            idUser = _idUser;
        };

        void setLoginSenha(std::string _login, std::string _senha){
            login = _login;
            password = _senha;
        };

    protected:
        std::string password, email, phone, senha;
        bool adm, devedor;
        float valorMulta;
};
#endif