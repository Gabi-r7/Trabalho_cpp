#ifndef LOGAR_HPP
#define LOGAR_HPP
#include <vector>
#include "User.hpp"
#include "Anuncio.hpp"
#include "Produto.hpp"


namespace Logar {
	void Logar(std::vector<User*>& users, int &contUser, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos);
}
#endif