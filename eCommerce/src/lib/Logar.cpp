#include "Logar.hpp"
#include "User.hpp"
#include "Acoes.hpp"
#include <iostream>
#include <vector>

void Logar::Logar(std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos) {
    std::string login, password;
    bool aux = false;
    std::cout << "\nFaca seu login!" << std::endl;
    while (true) {
        std::cout << "Digite seu login: ";
        std::cin >> login;
        std::cout << "Digite sua senha: ";
        std::cin >> password;
        for (User* user : users) {
            if (login == user->getLogin() && password == user->getPassword()) {
                std::cout << "Login realizado com sucesso!" << std::endl;
                if (user->getAdm()) {
					std::cout << "Voce logou como administrador!" << std::endl;
				}
				else {
					std::cout << "Voce logou como um usuario comum!" << std::endl;
				}
                aux = true;
                Acoes::Acoes(user->getIdUser(), users, contUser); //arrumar
            }
        }
        if (aux) {
            break;
        }
        std::cout << "Login ou senha incorretos!" << std::endl;
    }
};