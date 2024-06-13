#ifndef ACOES_HPP
#define ACOES_HPP
#include <vector>
class User;
class Anuncio;
class Produto;

namespace Acoes {
	void Acoes(int idUser, std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, int &contAnuncio, std::vector<Produto*>& produtos, int &contProduto);
}
#endif