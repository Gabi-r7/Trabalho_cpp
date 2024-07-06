#include <iostream>
#include <vector>
#include "Emprestimo.hpp"
#include "Logar.hpp"
#include "Cadastrar.hpp"
#include "InicializaSistema.hpp"

void InicializaSistema::InicializaSistema(std::vector<Livro*>& livros, int &contLivro, std::vector<User*>& users, int &contUser) {
    int aux;
    int senha;
    
    std::cout << "Bem vindo ao sistema de biblioteca!" << std::endl;
    do {
        std::cout << "Digite\n- 0 para sair\n- 1 para Logar\n- 2 para criar uma conta\nDigite sua opcao: ";
        std::cin >> aux;

        switch (aux)
        {
        case 0:
            std::cout << "Ate mais!";
            break;
        case 1:
            Logar::Logar(livros, contLivro, users, contUser);
            break;
        case 2:
            Cadastrar::Cadastrar(livros, contLivro ,users, contUser);
            break;
        default:
            std::cout << "\nOpcao invalida!\n" << std::endl;
            break;
        }
    } while (aux != 0);
};