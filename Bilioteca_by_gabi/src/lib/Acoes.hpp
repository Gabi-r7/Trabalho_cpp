#ifndef ACOES_HPP
#define ACOES_HPP
#include <vector>
#include "Livro.hpp"
#include "User.hpp"

namespace Acoes {
	void Acoes(int id, std::vector<Livro*>& livros, std::vector<User*>& users);
};
#endif