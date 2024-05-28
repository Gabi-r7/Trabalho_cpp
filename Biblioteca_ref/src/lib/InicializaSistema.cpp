#include <iostream>
#include <vector>
#include "InicializaSistema.hpp"

void InicializaSistema::InicializaSistema(std::vector<Usuario*>& usuarios, std::vector<Admin*>& admins, int& id) {
	int op;
	std::cout << "\nBem-vindo ao sistema de biblioteca\n";

	do {
		std::cout << "\n1 - Cadastro\n2 - Login\n0 - Sair\nSua opção: ";
		std::cin >> op;
		
		switch (op)
		{
		case 0:
			std::cout << "Saindo do sistema...\n";
			break;
		case 1:
			Cadastro(usuarios, admins, id);
			break;
		case 2:
			Logar(usuarios, admins);
			break;
		default:
			std::cout << "Opção inválida\n";
			break;
		}
		
	} while (op != 0);
};