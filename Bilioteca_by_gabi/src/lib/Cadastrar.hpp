#ifndef CADASTRAR_HPP
#define CADASTRAR_HPP
#include <vector>
#include "Livro.hpp"
#include "User.hpp"

namespace Cadastrar {
	void Cadastrar(std::vector<Livro*>& livros, std::vector<User*>& users);
};
#endif