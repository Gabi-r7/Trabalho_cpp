#include "Cadastrar.hpp"
#include "Admin.hpp"
#include "User.hpp"
#include "User.cpp"
#include "Logar.hpp"
#include "Livro.hpp"
#include <vector>
#include <iostream>

void Cadastrar::Cadastrar(std::vector<Livro*>& livros, std::vector<User*>& users) {
    User user;
    std::string login, password, email, phone;
    bool adm, existe = false;
    int admAux = 0;
    while (true) {
        std::cout << "Faca seu cadastro!" << std::endl;
        std::cout << "Digite seu login: ";
        std::cin >> login;
        std::cout << "Digite sua senha: ";
        std::cin >> password;
        std::cout << "Digite seu email: ";
        std::cin >> email;
        //std::cout << "Digite seu telefone: ";
        //std::cin >> phone;
        std::cout << "Digite a senha de administrador caso voce seja: ";
        std::cin >> admAux;
        std::cout << "Valor de admAux: " << admAux << "\n"; //parei aqui
        if (admAux == 1230) {
            std::cout << "Voce e um administrador!" << std::endl;
            adm = true;
            user.setAdm(adm);
        }
        else {
            adm = false;
            user.setAdm(adm);
        }
        for (User* user : users) {
            if (login == user->getLogin()) {
                std::cout << "Login ja existente!" << std::endl;
                existe = true;
                break;
            }
        }
        if (!existe) {
            break;
        }
    }
    User* newUser = new User();
    newUser->setLoginSenha(login, password);
    users.push_back(newUser);
    std::cout << "Cadastro realizado com sucesso!" << std::endl;
    newUser->setIdUser(users.size() - 1);
    std::cout << "Seu id e: " << newUser->getIdUser() << std::endl;
    Logar::Logar(livros,users);
};