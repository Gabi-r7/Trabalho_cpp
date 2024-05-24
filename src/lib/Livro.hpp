#include <iostream>
#include <vector>
#ifndef LIVRO_HPP
#define LIVRO_HPP

class Livro {
    public:
        Livro(bool _emprestado = false) { emprestado = _emprestado; };
        ~Livro(){};

        void setEmprestado(bool _emprestado){
            emprestado = _emprestado;
        };

        bool getEmprestado(){
            return emprestado;
        };

        void setIdUser(int _idUser){
            idUser = _idUser;
        };

        int getIdUser(){
            return idUser;
        };

        void setIdLivro(int _idLivro){
            idLivro = _idLivro;
        };

        int getIdLivro(){
            return idLivro;
        };

        void setTitulo(std::string _titulo){
            titulo = _titulo;
        };

        std::string getTitulo(){
            return titulo;
        };

        void setAutor(std::string _autor){
            autor = _autor;
        };

        std::string getAutor(){
            return autor;
        };

        void setEditora(std::string _editora){
            editora = _editora;
        };

        std::string getEditora(){
            return editora;
        };

        

        void MostrarDisponiveis(std::vector<Livro*> livros){
            std::cout << "Total de livros disponiveis:" << livros.size() << std::endl;
            for (int i = 0; i < livros.size(); i++){
                if (!livros[i]->getEmprestado()){
                    std::cout << "ID: " << livros[i]->getIdLivro() << std::endl;
                    std::cout << "Titulo: " << livros[i]->getTitulo() << std::endl;
                    std::cout << "Autor: " << livros[i]->getAutor() << std::endl;
                    std::cout << "Editora: " << livros[i]->getEditora() << std::endl;
                    std::cout << "--------------------------------" << std::endl;
                }
            }
        };

    private:
        std::string titulo, autor, editora;
        int idLivro, idUser;
        bool emprestado;
};
#endif