#ifndef ACOES_HPP
#define ACOES_HPP
#include <vector>
class User;
class Anuncio;

namespace Acoes {
	void Acoes(int idUser, std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios);
}
#endif