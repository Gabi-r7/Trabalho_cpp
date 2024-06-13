#ifndef INICIALIZASISTEM_HPP
#define INICIALIZASISTEM_HPP
#include <vector>
class User;
class Anuncio;
class Produto;

namespace InicializaSistema {
	void InicializaSistema(std::vector<User*>& users, int &contUser, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos);
}
#endif