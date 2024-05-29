#ifndef LIVRO_HPP
#define LIVRO_HPP
#include <vector>
#include <iostream>

class Livro {
public:
	Livro();
	~Livro();

	void setEmprestado(bool _emprestado);

	bool getEmprestado();

	void setIdUser(int _idUser);

	int getIdUser();

	void setIdLivro(int _idLivro);

	int getIdLivro();

	void setTitulo(std::string _titulo);

	std::string getTitulo();

	void setAutor(std::string _autor);

	std::string getAutor();

	void setEditora(std::string _editora);

	std::string getEditora();

	void MostrarDisponiveis(std::vector<Livro*>& livros);

private:
	std::string titulo, autor, editora;
	int idLivro = 0, idUser = 0;
	bool emprestado = false;
};
#endif