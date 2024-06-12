#ifndef INICIALIZASISTEM_HPP
#define INICIALIZASISTEM_HPP
#include <vector>
class User;
class Anuncio;

namespace InicializaSistema {
	void InicializaSistema(std::vector<User*>& users, int &contUser, std::vector<Anuncio*>& anuncios);
}
#endif