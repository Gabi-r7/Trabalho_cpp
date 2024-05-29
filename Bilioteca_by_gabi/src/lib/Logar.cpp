#include "Logar.hpp"
#include "Acoes.hpp"
#include "User.hpp"
#include "Livro.hpp"
#include <iostream>
#include <vector>

void Logar::Logar(std::vector<Livro*>& livros, std::vector<User*>& users) {
    std::string login, password;
    bool aux = false;
    std::cout << "Faca seu login!" << std::endl;
    while (true) {
        std::cout << "Digite seu login: ";
        std::cin >> login;
        std::cout << "Digite sua senha: ";
        std::cin >> password;
        for (User* user : users) {
            if (login == user->getLogin() && password == user->getPassword()) {
                std::cout << "Login realizado com sucesso!" << std::endl;
                aux = true;
                Acoes::Acoes(user->getIdUser(),livros,users);
            }
        }
        if (aux) {
            break;
        }
        std::cout << "Login ou senha incorretos!" << std::endl;
    }
};