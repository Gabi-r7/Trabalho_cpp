#include "Cadastrar.hpp"
#include "Admin.hpp"
#include "User.hpp"
#include "Logar.hpp"
#include "Livro.hpp"
#include <vector>
#include <iostream>
#define adminSenha 1230

void Cadastrar::Cadastrar(std::vector<Livro*>& livros, std::vector<User*>& users) {
    std::string login, password, email, phone;
    bool adm, existe;
    int admAux = 0;
    while (true) {
        existe = false;
        std::cout << "Faca seu cadastro!" << std::endl;
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
            break;
        }
        std::cout << "Digite sua senha: ";
        std::cin >> password;
        std::cout << "Digite seu email: ";
        std::cin >> email;
        //std::cout << "Digite seu telefone: ";
        //std::cin >> phone;
        std::cout << "Digite a senha de administrador caso voce seja: ";
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
    std::cout << "Cadastro realizado com sucesso!" << std::endl;
    newUser->setIdUser(users.size() - 1);
    Logar::Logar(livros,users);
};