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
			std::cout << "1 - Ver an�ncios" << std::endl;
			std::cout << "2 - Modificar seus an�ncios" << std::endl;
			if (adm) {
				std::cout << "3 - Banir usu�rio" << std::endl;
				std::cout << "4 - Desbanir usu�rio" << std::endl;
				std::cout << "5 - Apagar an�ncio" << std::endl;

			}
			std::cin << op1;
			if (op1 == 1) {
				// Ver an�ncios
			}
			else if (op1 == 2) {
				// Modificar an�ncios
			}
			if (adm) {
				if (op1 == 3) {
					// Banir usu�rio
				}
				else if (op1 == 4) {
					// Desbanir usu�rio
				}
				else if (op1 == 5) {
					// Apagar an�ncio
				}
			}
		}
	}