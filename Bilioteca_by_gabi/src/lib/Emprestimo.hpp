#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP
#include "Livro.hpp"
#include "User.hpp"
#include <vector>

class Emprestimo {
public:
	Emprestimo();
	~Emprestimo();

	bool EmprestarLivro(int idUser, std::vector<Livro*>& livros, int &contLivro, std::vector<User*>& users);

	bool DevolverLivro(std::vector<Livro*>& livros);

	bool MostrarEmprestados(std::vector<Livro*>& livros, int idUser);
};
#endif