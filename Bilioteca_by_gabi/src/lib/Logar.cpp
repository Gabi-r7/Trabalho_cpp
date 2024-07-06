#include "Logar.hpp"
#include "Acoes.hpp"
#include "User.hpp"
#include "Livro.hpp"
#include <iostream>
#include <vector>

void Logar::Logar(std::vector<Livro*>& livros, int &contLivro, std::vector<User*>& users, int &contUser) {
    std::string login, password;
    int tentativas = 0;
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
                Acoes::Acoes(user->getIdUser(),livros, contLivro, users, contUser);
            }
        }
        if (aux) {
            break;
        }
        std::cout << "Login ou senha incorretos!" << std::endl;
        tentativas++;
        if (tentativas == 3) {
			std::cout << "\nNumero de tentativas excedido!\n" << std::endl;
			break;
		}
    }
};