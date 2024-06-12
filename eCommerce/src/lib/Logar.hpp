#ifndef LOGAR_HPP
#define LOGAR_HPP
#include <vector>
class User;
#include "Anuncio.hpp"

namespace Logar {
	void Logar(std::vector<User*>& users, int &contUser, std::vector<Anuncio*>& anuncios);
}
#endif