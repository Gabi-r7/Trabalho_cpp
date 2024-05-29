#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP
#include "Livro.hpp"
#include "User.hpp"
#include <vector>

class Emprestimo {
public:
	Emprestimo();
	~Emprestimo();

	bool EmprestarLivro(int idLivro, int idUser, std::vector<Livro*>& livros, std::vector<User*>& users);

	void DevolverLivro(int idLivro, std::vector<Livro*>& livros);
};
#endif