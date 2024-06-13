#ifndef USER_HPP
#define USER_HPP
#include <iostream>
#include <vector>
#include "Anuncio.hpp"
#include "Produto.hpp"

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

    void setBanido(bool _banido);

    bool getBanido();

    bool comprarProduto(int idUser, std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos);

    void mostrarSeusAnuncios(std::vector<Anuncio*>& anuncios, int idUser);

    void adicionarAnuncio(std::vector<Anuncio*>& anuncios, std::vector<User*>& users, int idUser, std::vector<Produto*>& produtos);


	
protected:
    std::string email = "a";
    std::string login = "a";
    std::string password = "a";
    int idUser = 0;
    bool adm, banido = false;
};
#endif