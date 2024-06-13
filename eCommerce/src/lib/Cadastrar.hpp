#ifndef CADASTRAR_HPP
#define CADASTRAR_HPP
#include <vector>
#include "User.hpp"
#include "Anuncio.hpp"
#include "Produto.hpp"

namespace Cadastrar {
	void Cadastrar(std::vector<User*>& users, int &contUser, std::vector<Anuncio*>& anuncios, int &contAnuncio, std::vector<Produto*>& produtos, int &contProduto);
};
#endif
