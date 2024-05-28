#include <iostream>
#include <vector>
#include <string>
#include "Cadastrar.hpp"
#define senhaAdm = 12340

void Cadastrar::Cadastrar(std::vector<Usuario*>& usuarios, std::vector<Admin*>& admins, int& id) {
	int escolhaAdm = 0;
	bool existe = false;
	std::string login, senha, email;
	std::cout << "Bem-vindo ao sistema de cadastro\n";
	do {
		while (true) {
			std::cout << "Digite seu login: ";
			std::cin >> login;
			for (Usuario* usuario : usuarios) {
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
		std::cout << "Digite sua senha: ";
		std::cin >> senha;
		std::cout << "Digite seu email: ";
		std::cin >> email;
		do {
			std::cout << "Você deseja se cadastrar como Administrador?(0 - Nao, 1 - Sim):";
			std::cin >> escolhaAdm;
			if (escolhaAdm == 1) {
				std::cout << "Digite o codigo de administrador: ";
				std::cin >> senhaAdmDigitada;
				if (senhaAdmDigitada == senhaAdm) {
					Admin* admin = new Admin(login, senha, email, id);
					id += 1;
					admins.push_back(admin);
					std::cout << "Cadastro realizado com sucesso!" << std::endl;
				}
				else {
					std::cout << "Codigo de administrador incorreto!" << std::endl;
				}
			}
			else {
				Usuario* user = new Usuario();
				usuario->setLoginSenha(login, senha, email, id);
				id += 1;
				usuarios.push_back(usuario);
				std::cout << "Cadastro realizado com sucesso!" << std::endl;
				Logar();
			}
		} while (escolhaAdm == 1);
	} while (op != 0);
};