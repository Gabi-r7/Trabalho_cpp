#include "Cadastrar.hpp"
#include "Admin.hpp"
#include "User.hpp"
#include "InicializaSistema.hpp"
#include "Livro.hpp"
#include <vector>
#include <iostream>
#define adminSenha 1230

void Cadastrar::Cadastrar(std::vector<Livro*>& livros,int &contLivro, std::vector<User*>& users, int &contUser) {
    std::string login, password, email, phone;
    bool adm, existe;
    int admAux = 0;
    while (true) {
        existe = false;
        std::cout << "\nFaca seu cadastro!" << std::endl;
        std::cout << "Digite seu login: ";
        std::cin >> login;
        for (User* user : users) {
            if (login == user->getLogin()) {
                std::cout << "Login ja existente!" << std::endl;
                existe = true;
                break;
            }
        }
        if (existe) {
            continue;
        }
        std::cout << "Digite sua senha: ";
        std::cin >> password;
        std::cout << "Digite seu email: ";
        std::cin >> email;
        //std::cout << "Digite seu telefone: ";
        //std::cin >> phone;
        std::cout << "\nDigite a senha de administrador caso voce seja: ";
        std::cin >> admAux;
        if (admAux == adminSenha) {
            std::cout << "Voce e um administrador!" << std::endl;
            adm = true;
        }
        else {
            adm = false;
        }
        break;
    }
    User* newUser = new User();
    newUser->setLoginSenha(login, password);
    newUser->setAdm(adm);
    users.push_back(newUser);
    std::cout << "Cadastro realizado com sucesso!\n" << std::endl;
    newUser->setIdUser(contUser);
    contUser++;
    InicializaSistema::InicializaSistema(livros, contLivro, users, contUser);
};