#ifndef LOGAR_HPP
#define LOGAR_HPP
#include <vector>
class User;
class Admin;
class Produto;
class Anuncio;

namespace Logar {
	void Logar(std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos);
};
#endif