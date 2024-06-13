#include "lib/InicializaSistema.hpp"
#include "lib/User.hpp"
#include "lib/Logar.hpp"
#include "lib/Cadastrar.hpp"
#include "lib/Acoes.hpp"
#include "lib/Anuncio.hpp"
#include "lib/Produto.hpp"
#include <vector>
#include <iostream>
#include <string>

void CriarAnuncios(std::vector<Anuncio*> anuncios) {
	for (int i = 0; i < 10; i++) {
		Anuncio* anuncio = new Anuncio();
		anuncio->setIdAnuncio(i);
		anuncio->setNome("Anuncio " + std::to_string(i));
		anuncio->setAutor("Autor " + std::to_string(i));
		anuncio->setPreco(i * 10);
		anuncio->setDescricao("Descricao " + std::to_string(i));
		anuncio->setDisponibilidade(true);
		anuncios.push_back(anuncio);
	}
};


int main() {
	std::vector<User*> users;
	std::vector<Anuncio*> anuncios;
	std::vector<Produto*> produtos;
	int contUser = 0;
	int contAnuncio = 0;
	int contProduto = 0;
	CriarAnuncios(anuncios);
	InicializaSistema::InicializaSistema(users, contUser, anuncios, contAnuncio, produtos, contProduto);


	return 0;
};