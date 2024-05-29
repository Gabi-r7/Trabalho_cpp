#include <iostream>
#include <vector>
#include "User.hpp"
#include "Livro.hpp"
#include "Emprestimo.hpp"

Emprestimo::Emprestimo() {};
Emprestimo::~Emprestimo() {};

bool Emprestimo::EmprestarLivro(int idLivro, int idUser, std::vector<Livro*>& livros, std::vector<User*>& users) {
    if (idUser < 0 || idUser >= users.size() || idLivro < 0 || idLivro >= livros.size()) {
        std::cout << "ID do usuario ou do livro invalido." << std::endl;
        return false;
    }
    else if (livros.at(idLivro)->getEmprestado()) {
        std::cout << "Livro ja emprestado." << std::endl;
        return false;
    }
    else if (users.at(idUser)->getMulta() > 15) {
        std::cout << "Usuario com multa acima de R$15,00. Voce nao podera emprestar outro livro enquanto nao quitar a divida" << std::endl;
        return false;
    }
    else {
        livros[idLivro]->setEmprestado(true);
        livros[idLivro]->setIdUser(idUser);
        return true;
    }
};

void Emprestimo::DevolverLivro(int idLivro, std::vector<Livro*>& livros) {
    if (idLivro < 0 || idLivro >= livros.size()) {
        std::cout << "ID do livro invalido." << std::endl;
    }
    else if (!livros.at(idLivro)->getEmprestado()) {
        std::cout << "Livro nao emprestado." << std::endl;
    }
    else {
        livros[idLivro]->setEmprestado(false);
        livros[idLivro]->setIdUser(-1);
    }
};