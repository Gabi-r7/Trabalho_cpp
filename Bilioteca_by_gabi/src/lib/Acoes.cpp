#include <iostream>
#include <vector>
#include "User.hpp"
#include "Livro.hpp"
#include "Emprestimo.hpp"
#include "Admin.hpp"
#include "Acoes.hpp"
#include "InicializaSistema.hpp"


void Acoes::Acoes(int id, std::vector<Livro*>& livros, std::vector<User*>& users) {
    User* user = users[id];
    Livro livro;
    Emprestimo emprestimo;
    Admin admin;
    int aux;
    bool adm = user->getAdm(), funcionou = false, status;
    while (true) {
        if (user->getMulta() > 0) {
            std::cout << "-------------------------------------------------------------------------------\n";
            std::cout << "Voce esta com uma multa de R$" << user->getMulta() << ". Pague para poder emprestar outro livro." << std::endl;
            std::cout << "-------------------------------------------------------------------------------";
        }
        std::cout << "\n\nO que deseja fazer?" << std::endl;
        std::cout << "Digite 0 para sair" << std::endl;
        std::cout << "Digite 1 para emprestar um livro" << std::endl;
        std::cout << "Digite 2 para devolver um livro" << std::endl;
        std::cout << "Digite 3 para ver os livros disponiveis" << std::endl;
        if (adm) {
            std::cout << "Digite 4 para cadastrar um livro" << std::endl;
            std::cout << "Digite 5 para apagar um livro" << std::endl;
            std::cout << "Digite 6 para modificar o status de um usuario" << std::endl;
            std::cout << "Digite 7 para cadastrar um usuario" << std::endl;
            std::cout << "Digite 8 para apagar um usuario" << std::endl;
            std::cout << "Digite 9 para aplicar uma multa" << std::endl;
        }
        std::cin >> aux;
        if (aux == 0) {
            std::cout << "Ate mais!" << "\n\n";
            InicializaSistema::InicializaSistema(livros, users);
            break;
        }
        else if (aux == 1) {
            livro.MostrarDisponiveis(livros);
            funcionou = emprestimo.EmprestarLivro(id, livros, users);
            if (funcionou) {
                std::cout << "Livro emprestado com sucesso!" << std::endl;
            }
            else {
                std::cout << "Nao foi possivel emprestar o livro!" << std::endl;
            }
        }
        else if (aux == 2){
                emprestimo.MostrarEmprestados(livros, id);
                funcionou = emprestimo.DevolverLivro(livros);
                if (funcionou) {
                    std::cout << "Livro devolvido com sucesso!" << std::endl;
                }
                else {
                    std::cout << "Nao foi possivel devolver o livro!" << std::endl;
                }
        }
        else if (aux == 3) {
            livro.MostrarDisponiveis(livros);
        }
        else if (!adm) {
            std::cout << "Erro!" << std::endl;
        }
        if (adm) {
            if (aux == 4) {
                admin.CadastrarLivro(livros);
                std::cout << "Livro cadastrado com sucesso!" << std::endl;
            }
            else if (aux == 5) {
                admin.ApagarLivro(livros);
                std::cout << "Livro apagado com sucesso!" << std::endl;
            }
            else if (aux == 6) {
                admin.ModificarStatusUser(id, users); // parei aqui
            }
            else if (aux == 7) {
                admin.CadastrarUser(users);
            }
            else if (aux == 8) {
                admin.ApagarUser(id, users);
            }
            else if (aux == 9) {
                admin.AplicarMulta(users); // nao terminei
                std::cout << "Multa aplicada com sucesso!" << std::endl;
            }
            else if (aux != 0 && aux != 1 && aux != 2 && aux != 3){
                std::cout << "Erro!" << std::endl;
            }
        }
    }
};