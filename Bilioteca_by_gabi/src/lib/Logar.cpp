#include "src/lib/Logar.hpp"
#include "src/lib/Acoes.hpp"
#include "src/lib/User.hpp"
#include <iostream>
#include <vector>

void Logar::Logar() {
    
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
                Acoes(user->getIdUser());
            }
        }
        if (aux) {
            break;
        }
        std::cout << "Login ou senha incorretos!" << std::endl;
    }
};