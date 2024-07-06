#include "lib/User.hpp"
#include "lib/Anuncio.hpp"
#include "lib/Produto.hpp"
#include "lib/Funcoes.hpp"
#include <vector>
#include <iostream>
#include <string>

int main() {
	std::vector<User*> users;
	std::vector<Anuncio*> anuncios;
	std::vector<Produto*> produtos;
	int contUser = 0;
	int contAnuncio = 0;
	int contProduto = 0;
	Funcoes::InicializaSistema(users, contUser, anuncios, contAnuncio, produtos, contProduto);

	for (int i = 0; i < users.size(); i++) {
		delete users.at(i);
		users.at(i) = nullptr;
	}
	for (int i = 0; i < anuncios.size(); i++) {
		delete anuncios.at(i);
		anuncios.at(i) = nullptr;
	}
	for (int i = 0; i < produtos.size(); i++) {
		delete produtos.at(i);
		produtos.at(i) = nullptr;
	}

	return 0;
};