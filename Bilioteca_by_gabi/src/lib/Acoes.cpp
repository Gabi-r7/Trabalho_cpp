#include <iostream>
#include <vector>
#include "User.hpp"
#include "Livro.hpp"
#include "Emprestimo.hpp"
#include "Admin.hpp"
#include "Acoes.hpp"
#include "InicializaSistema.hpp"


void Acoes::Acoes(int id, std::vector<Livro*>& livros, int &contLivro, std::vector<User*>& users, int &contUser) {
    User* user = users[id];
    Livro livro;
    Emprestimo emprestimo;
    Admin admin;
    int aux;
    bool adm = user->getAdm(), funcionou = false, status, existe = true;
    while (true) {
        if (user->getMulta() > 0) {
            std::cout << "-------------------------------------------------------------------------------\n";
            std::cout << "Voce esta com uma multa de R$" << user->getMulta() << ". Pague para poder emprestar outro livro." << std::endl;
            std::cout << "-------------------------------------------------------------------------------";
        }
        std::cout << "\n\nO que deseja fazer?" << std::endl;
        std::cout << "- 0 para sair" << std::endl;
        std::cout << "- 1 para emprestar um livro" << std::endl;
        std::cout << "- 2 para devolver um livro" << std::endl;
        std::cout << "- 3 para ver os livros disponiveis" << std::endl;
        std::cout << "- 4 para pagar uma multa" << std::endl;
        if (adm) {
            std::cout << "- 5 para cadastrar um livro" << std::endl;
            std::cout << "- 6 para apagar um livro" << std::endl;
            std::cout << "- 7 para modificar o status de um usuario" << std::endl;
            std::cout << "- 8 para cadastrar um usuario" << std::endl;
            std::cout << "- 9 para apagar um usuario" << std::endl;
            std::cout << "- 10 para aplicar uma multa" << std::endl;
        }
        std::cout << "Digite sua opcao: ";
        std::cin >> aux;
        if (aux == 0) {
            std::cout << "Ate mais!" << "\n\n";
            break;
        }
        else if (aux == 1) {
            if (user->getMulta() > 0) {
                continue;
            }
            else {
                livro.MostrarDisponiveis(livros);
                funcionou = emprestimo.EmprestarLivro(id, livros, contLivro, users);
            }
            if (funcionou) {
                std::cout << "Livro emprestado com sucesso!" << std::endl;
            }
            else {
                std::cout << "Nao foi possivel emprestar o livro!" << std::endl;
            }
        }
        else if (aux == 2){
                existe = emprestimo.MostrarEmprestados(livros, id);
                if (!existe) {
					std::cout << "Nao ha livros emprestados!" << std::endl;
					continue;
				}
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
        else if (aux == 4) {
            user->pagarMulta();
        }
        else if (!adm) {
            std::cout << "Erro!" << std::endl;
        }
        if (adm) {
            if (aux == 5) {
                admin.CadastrarLivro(livros, contLivro);
                std::cout << "Livro cadastrado com sucesso!" << std::endl;
            }
            else if (aux == 6) {
                admin.ApagarLivro(livros, contLivro);
            }
            else if (aux == 7) {
                admin.ModificarStatusUser(id, users);
            }
            else if (aux == 8) {
                admin.CadastrarUser(users, contUser);
            }
            else if (aux == 9) {
                admin.ApagarUser(id, users);
            }
            else if (aux == 10) {
                admin.AplicarMulta(users);
            }
            else if (aux != 0 && aux != 1 && aux != 2 && aux != 3 && aux != 4){
                std::cout << "Erro!" << std::endl;
            }
        }
    }
};