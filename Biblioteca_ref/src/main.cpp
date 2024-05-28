// Desenvolva o diagrama de classes UML de um sistema de biblioteca e 
// implemente esse sistema. Você deve ser capaz de Cadastrar usuarios, apagar 
// usuarios, modificar o status do usuario (e.g., verificar se o mesmo possui multas 
// por atraso, se a multa for maior que um valor X, ele nao podera mais pegar livros 
// emprestados), Cadastrar livros, emprestar livros, devolver livros, aplicar multas 
// por atraso, e checar se um determinado livro esta disponivel para ser 
// emprestado. Utilize listas como se fossem seu banco de dados (std::vector)
#include <iostream>
#include <vector>
#include "InicializaSistema.hpp"
#include "Usuario.hpp"
#include "Livro.hpp"
#include "Admin.hpp"
#include "Logar.hpp"
#include "Cadastrar.hpp"


void CriarLivros() {
	for (int i = 0; i <= 10; i++) {
		Livro* livro = new Livro();
		livro->setIdLivro(i);
		livro->setTitulo("Livro " + std::to_string(i));
		livro->setAutor("Autor " + std::to_string(i));
		livro->setEditora("Editora " + std::to_string(i));
		livro->setEmprestado(false);
		livros.push_back(livro);
	}
};

int main() {
	int id = 0;

	std::vector<Livro*> livros;
	std::vector<Usuario*> usuarios;
	std::vector<Admin*> admins;
	CriarLivros();
	InicializaSistema(usuarios, admins, id);
	
	
	for (Usuario* usuario : usuarios) {
		delete usuario;
	}
	usuarios.clear();

	for (Livro* livro : livros) {
		delete livro;
	}
	livros.clear();

	return 0;
}