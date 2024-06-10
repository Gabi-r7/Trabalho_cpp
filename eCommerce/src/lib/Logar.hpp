#ifndef LOGAR_HPP
#define LOGAR_HPP
#include <vector>
#include "Livro.hpp"
#include "User.hpp"

namespace Logar {
	void Logar(std::vector<Livro*>& livros, int &contLivro, std::vector<User*>& users, int &contUser);
};
#endif