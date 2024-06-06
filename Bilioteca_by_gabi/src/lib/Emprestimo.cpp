#include <iostream>
#include <vector>
#include "User.hpp"
#include "Livro.hpp"
#include "Emprestimo.hpp"

Emprestimo::Emprestimo() {};
Emprestimo::~Emprestimo() {};

bool Emprestimo::EmprestarLivro(int idUser, std::vector<Livro*>& livros, std::vector<User*>& users) {
    int idLivro;
    std::cout << "user: " << idUser << "\n";
    std::cout << "Digite o id do livro que deseja emprestar (-1 para cancelar): ";
    std::cin >> idLivro;
    if (idLivro == -1) {
        std::cout << "Emprestimo cancelado." << std::endl;
        return false;
    }
    else if (idUser < 0 || idUser >= users.size() || idLivro < 0 || idLivro >= livros.size()) {
        std::cout << "ID do usuario ou do livro invalido." << std::endl;
        return false;
    }
    else if (livros.at(idLivro)->getEmprestado()) {
        std::cout << "Livro ja emprestado." << std::endl;
        return false;
    }
    else if (users.at(idUser)->getMulta() > 0) {
        std::cout << "\nUsuario com multa de" << users[idUser]->getMulta() <<  " Voce nao podera emprestar outro livro enquanto nao quitar a divida" << std::endl;
        return false;
    }
    else {
        livros[idLivro]->setEmprestado(true);
        livros[idLivro]->setIdUser(idUser);
        return true;
    }
};

bool Emprestimo::DevolverLivro(std::vector<Livro*>& livros) {
    int idLivro;
    std::cout << "Digite o id do livro que deseja devolver (-1 para cancelar): ";
    std::cin >> idLivro;
    if (idLivro == -1) {
		std::cout << "Devolucao cancelada." << std::endl;
		return false;
	}
    else if (idLivro < 0 || idLivro >= livros.size()) {
        std::cout << "ID do livro invalido." << std::endl;
        return false;
    }
    else if (!livros.at(idLivro)->getEmprestado()) {
        std::cout << "Livro nao emprestado." << std::endl;
        return false;
    }
    else {
        livros[idLivro]->setEmprestado(false);
        livros[idLivro]->setIdUser(-1);
        return true;
    }
};

bool Emprestimo::MostrarEmprestados(std::vector<Livro*>& livros, int idUser) {
    bool existe = false;
    for (int i = 0; i < livros.size(); i++) {
        if (livros.at(i)->getIdUser() == idUser) {
            std::cout << "\nID: " << i << " Titulo: " << livros.at(i)->getTitulo() << std::endl;
            existe = true;
        }
    }
    return existe;
};