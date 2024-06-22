#ifndef FUNCOES_HPP
#define FUNCOES_HPP
#include <vector>
class User;
class Anuncio;
class Produto;

namespace Funcoes {
	void Acoes(int idUser, std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, int& contAnuncio, std::vector<Produto*>& produtos, int& contProduto);

	void Cadastrar(std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, int& contAnuncio, std::vector<Produto*>& produtos, int& contProduto);

	void InicializaSistema(std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, int& contAnuncios, std::vector<Produto*>& produtos, int& contProduto);

	void Logar(std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, int& contAnuncio, std::vector<Produto*>& produtos, int& contProduto);
}
#endif