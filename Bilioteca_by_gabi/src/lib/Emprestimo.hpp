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

	bool DevolverLivro(int idLivro, std::vector<Livro*>& livros);

	void MostrarEmprestados(std::vector<Livro*>& livros, int idUser);
};
#endif