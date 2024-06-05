#include <iostream>
#include <vector>
#include "Livro.hpp"

Livro::Livro() {};
Livro::~Livro() {};

void Livro::setEmprestado(bool _emprestado) {
    emprestado = _emprestado;
};

bool Livro::getEmprestado() {
    return emprestado;
};

void Livro::setIdUser(int _idUser) {
    idUser = _idUser;
};

int Livro::getIdUser() {
    return idUser;
};

void Livro::setIdLivro(int _idLivro) {
    idLivro = _idLivro;
};

int Livro::getIdLivro() {
    return idLivro;
};

void Livro::setTitulo(std::string _titulo) {
    titulo = _titulo;
};

std::string Livro::getTitulo() {
    return titulo;
};

void Livro::setAutor(std::string _autor) {
    autor = _autor;
};

std::string Livro::getAutor() {
    return autor;
};

void Livro::setEditora(std::string _editora) {
    editora = _editora;
};

std::string Livro::getEditora() {
    return editora;
};

void Livro::MostrarDisponiveis(std::vector<Livro*>& livros) {
    std::cout << "\n\nTotal de livros disponiveis:" << livros.size() << std::endl;
    for (int i = 0; i < livros.size(); i++) {
        if (!livros[i]->getEmprestado()) {
            std::cout << "ID: " << livros[i]->getIdLivro() << std::endl;
            std::cout << "Titulo: " << livros[i]->getTitulo() << std::endl;
            std::cout << "Autor: " << livros[i]->getAutor() << std::endl;
            std::cout << "Editora: " << livros[i]->getEditora() << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }   
    }
};