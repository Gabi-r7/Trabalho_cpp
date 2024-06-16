#include "Admin.hpp"
#include <vector>
#include <iostream>
#include "User.hpp"

Admin::Admin() {};
Admin::~Admin() {};

void Admin::setAdm(bool _adm) {
	adm = _adm;
};

bool Admin::getAdm() {
	return adm;
};

void Admin::verUsuarios(std::vector<User*>& users) {
	for (int i = 0; i < users.size(); i++) {
		std::cout << "------------------------------------" << std::endl;
		std::cout << "ID: " << i << std::endl;
		std::cout << "Login: " << users.at(i)->getLogin() << std::endl;
		std::cout << "Email: " << users.at(i)->getEmail() << std::endl;
		std::cout << "Banido: " << users.at(i)->getBanido() << std::endl;
		std::cout << "Administrador: " << users.at(i)->getAdm() << std::endl;
		std::cout << std::endl;
	}
}

void Admin::banirUsuario(int idUser, std::vector<User*>& users) {
	int idBanido = -1;
	verUsuarios(users);
	std::cout << "Digite o ID do usuario que deseja banir: ";
	std::cin >> idBanido;
	if (idBanido < 0 || idBanido >= users.size()) {
		std::cout << "ID invalido!" << std::endl;
	}
	else if (users.at(idBanido)->getBanido()) {
		std::cout << "Usuario ja esta banido!" << std::endl;
	}
	else if (users.at(idBanido)->getAdm()) {
		std::cout << "Voce nao pode banir um administrador!" << std::endl;
	}
	else {
		users.at(idBanido)->setBanido(true);
		std::cout << "Usuario banido com sucesso!" << std::endl;
	}
};

void Admin::desbanirUsuario(int idUser, std::vector<User*>& users) {
	int idDesbanido = -1;
	verUsuarios(users);
	std::cout << "Digite o ID do usuario que deseja desbanir: ";
	std::cin >> idDesbanido;
	if (idDesbanido < 0 || idDesbanido >= users.size()) {
		std::cout << "ID invalido!" << std::endl;
	}
	else if (!users.at(idDesbanido)->getBanido()) {
		std::cout << "Usuario nao esta banido!" << std::endl;
	}
	else if (users.at(idDesbanido)->getAdm()) {
		std::cout << "Voce nao pode desbanir um administrador!" << std::endl;
	}
	else {
		users.at(idDesbanido)->setBanido(false);
		std::cout << "Usuario desbanido com sucesso!" << std::endl;
	}
};

void Admin::apagarAnuncio(int idUser, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos) {
	int idAnuncio = -1, totalDisp = 0;
	Anuncio anuncio;
	totalDisp = anuncio.verAnuncios(anuncios, produtos);
	if (totalDisp == 0) {
		std::cout << "Nao ha anuncios disponiveis!" << std::endl;
		return;
	}
	std::cout << "Digite o ID do anuncio que deseja apagar: ";
	std::cin >> idAnuncio;
	if (idAnuncio < 0 || idAnuncio >= anuncios.size()) {
		std::cout << "ID invalido!" << std::endl;
	}
	else {
		anuncios.erase(anuncios.begin() + idAnuncio);
		produtos.erase(produtos.begin() + idAnuncio);
		std::cout << "Anuncio apagado com sucesso!" << std::endl;
	}
};