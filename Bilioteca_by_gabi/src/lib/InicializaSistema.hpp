#ifndef INICIALIZASISTEMA_HPP
#define INICIALIZASISTEMA_HPP
#include <vector>
#include "Livro.hpp"
#include "User.hpp"

namespace InicializaSistema {
	void InicializaSistema(std::vector<Livro*>& livros, int &contLivro, std::vector<User*>& users, int &contUser);
};
#endif