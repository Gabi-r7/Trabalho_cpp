// Desenvolva o diagrama de classes UML de um sistema de biblioteca e 
// implemente esse sistema. Você deve ser capaz de Cadastrar usuarios, apagar 
// usuarios, modificar o status do usuario (e.g., verificar se o mesmo possui multas 
// por atraso, se a multa for maior que um valor X, ele nao podera mais pegar livros 
// emprestados), Cadastrar livros, emprestar livros, devolver livros, aplicar multas 
// por atraso, e checar se um determinado livro esta disponivel para ser 
// emprestado. Utilize listas como se fossem seu banco de dados (std::vector)
#include <iostream>
#include <vector>
#include <string>
#include "lib/InicializaSistema.hpp"
#include "lib/User.hpp"
#include "lib/Livro.hpp"
#include "lib/Emprestimo.hpp"
#include "lib/Admin.hpp"
#include "lib/Logar.hpp"
#include "lib/Cadastrar.hpp"


void CriarLivros(std::vector<Livro*>& livros, int &contLivro) {
   while(true) {
        if (contLivro == 11) {
			break;
		}
        Livro* livro = new Livro();
        livro->setIdLivro(contLivro);
        livro->setTitulo("Livro " + std::to_string(contLivro));
        livro->setAutor("Autor " + std::to_string(contLivro));
        livro->setEditora("Editora " + std::to_string(contLivro));
        contLivro++;
        livro->setEmprestado(false);
        livros.push_back(livro);
    }
};


int main() {
    std::vector<Livro*> livros;
    std::vector<User*> users;
    int contUser = 0;
    int contLivro = 0;
    CriarLivros(livros, contLivro);
    InicializaSistema::InicializaSistema(livros, contLivro, users, contUser);

    return 0;
};