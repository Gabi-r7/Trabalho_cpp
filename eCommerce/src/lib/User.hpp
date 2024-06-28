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


    bool comprarProduto(int idUser, std::vector<User*>& users, std::vector<Anuncio*>& anuncios, int& contAnuncio, std::vector<Produto*>& produtos);

    void finalizarCompra(int idUser, std::vector<User*>& users, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos);

    void adicionar(std::vector<Anuncio*>& anuncios, int &contAnuncio, std::vector<User*>& users, int idUser, std::vector<Produto*>& produtos, int &contProduto);

    void adicionar(std::vector<Produto*>& produtos, int &contProduto, int idUser);

    void adicionar(int a, std::vector<Anuncio*>& anuncios, int &contAnuncio, std::vector<Produto*>& produtos);

    bool mostrar(std::vector<Anuncio*>& anuncios, int &contAnuncio, int idUser);

    bool mostrar(std::vector<Produto*>& produtos, int &contProduto, int idUser);

    void mostrar(int idUser, std::vector<User*>& users);

    bool mostrar(int a);

    void deletar(std::vector<Anuncio*>& anuncios, int &contAnuncio, int idUser);

    void deletar(std::vector<Produto*>& produtos, int &contProduto, std::vector<Anuncio*>& anuncios, int idUser);

    void deletar(int a);

    void editar(std::vector<Anuncio*>& anuncios, int &contAnuncio, int idUser);

    void editar(std::vector<Produto*>& produtos, int& contProduto, int idUser);

    void editar(int idUser, std::vector<User*>& users);

	
protected:
    std::string email = "a";
    std::string login = "a";
    std::string password = "a";
    int idUser = 0;
    bool adm, banido = false;
    std::vector<Anuncio*> carrinho;
    std::vector<Anuncio*> favoritos;
};
#endif