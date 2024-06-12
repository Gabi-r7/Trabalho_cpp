#include <iostream>
#include <vector>
#include "Acoes.hpp"	
#include "User.hpp"
#include "Anuncio.hpp"

void Acoes::Acoes(int idUser, std::vector<User*>& users, int &contUser, std::vector<Anuncio*>& anuncios) {
	Anuncio anuncio;
	bool adm = users.at(idUser)->getAdm();
	int aux = 0;
	while (true) {
		if (users.at(idUser)->getBanido()) {
			std::cout << "Voce foi banido do sistema!" << std::endl;
			break;
		}
		else {
			std::cout << "\nO que deseja fazer?" << std::endl;
			std::cout << "0 - Sair" << std::endl;
			std::cout << "1 - Anuncios disponiveis" << std::endl;
			std::cout << "2 - Seus anuncios" << std::endl;
			if (adm) {
				std::cout << "3 - Banir usuario" << std::endl;
				std::cout << "4 - Desbanir usuario" << std::endl;
				std::cout << "5 - Apagar anuncio" << std::endl;
			}
			std::cout << "Opção: ";
			std::cin >> aux;
			if (aux == 0) { // sair total
				break;
			}
			else if (aux == 1) {
				int aux1 = 0;
				while (true) { // menu de Anuncios
					std::cout << "O que deseja fazer?" << std::endl;
					std::cout << "0 - Voltar" << std::endl;
					std::cout << "1 - Ver todos os anuncios" << std::endl;
					std::cout << "2 - Realizar uma compra" << std::endl;
					std::cout << "Opção: ";
					std::cin >> aux1;
					if (aux1 == 0) { // sair op1
						break;
					}
					else if (aux1 == 1) { // todos anuncios
						anuncio.verAnuncios(anuncios);
					}
					else if (aux1 == 2) {
						// Realizar uma compra
					}
				}
			}
			else if (aux == 2) {
				int aux2 = 0;
				while (true) {
					std::cout << "O que deseja fazer?" << std::endl;
					std::cout << "0 - Voltar" << std::endl;
					std::cout << "1 - Ver seus anuncios" << std::endl;
					std::cout << "2 - Adicionar um anuncio" << std::endl;
					std::cout << "3 - Editar um anuncio" << std::endl;
					std::cout << "4 - Deletar um anuncio" << std::endl;
					std::cout << "Opção: ";
					std::cin >> aux2;
					if (aux2 == 0) { // sair op2
						break;
					}
					else if (aux2 == 1) {
						// Ver seus anuncios
					}
					else if (aux2 == 2) {
						// Adicionar um anuncio
					}
					else if (aux2 == 3) {
						// Editar um anuncio
					}
					else if (aux2 == 4) {
						// Deletar um anuncio
					}
				}
			}
			else if (!adm) {
				std::cout << "Opcao invalida" << std::endl;
			}
			if (adm) {
				if (aux == 3) {
					// Banir usuario
				}
				else if (aux == 4) {
					// Desbanir usuario
				}
				else if (aux == 5) {
					// Apagar anuncio
				}
			}
		}
	}