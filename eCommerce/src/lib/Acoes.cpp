#include "Acoes.hpp"	
#include <iostream>
#include <vector>

void Acoes::Acoes(int idUser, std::vector<User*>& users, int &contUser) {
	int op1, op2;
	while (true) {
		if (users.at(idUser)->getBanido()) {
			std::cout << "Voce foi banido do sistema!" << std::endl;
			break;
		}
		else {
			std::cout << "\nO que deseja fazer?" << std::endl;
			std::cout << "0 - Sair" << std::endl;
			std::cout << "1 - Ver anúncios" << std::endl;
			std::cout << "2 - Modificar seus anúncios" << std::endl;
			if (adm) {
				std::cout << "3 - Banir usuário" << std::endl;
				std::cout << "4 - Desbanir usuário" << std::endl;
				std::cout << "5 - Apagar anúncio" << std::endl;

			}
			std::cin << op1;
			if (op1 == 1) {
				// Ver anúncios
			}
			else if (op1 == 2) {
				// Modificar anúncios
			}
			if (adm) {
				if (op1 == 3) {
					// Banir usuário
				}
				else if (op1 == 4) {
					// Desbanir usuário
				}
				else if (op1 == 5) {
					// Apagar anúncio
				}
			}
		}
	}