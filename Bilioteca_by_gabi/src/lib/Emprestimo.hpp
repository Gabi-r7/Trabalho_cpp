#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

class Emprestimo {
public:
	Emprestimo();
	~Emprestimo();

	bool EmprestarLivro(int idLivro, int idUser);

	void DevolverLivro(int idLivro);
};
#endif