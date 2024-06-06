#include <iostream>
#include <vector>
#include "Emprestimo.hpp"
#include "Logar.hpp"
#include "Cadastrar.hpp"
#include "InicializaSistema.hpp"

void InicializaSistema::InicializaSistema(std::vector<Livro*>& livros, std::vector<User*>& users) {
    int aux;
    int senha;
    
    std::cout << "Bem vindo ao sistema de biblioteca!" << std::endl;
    do {
        std::cout << "Digite\n- 0 para sair\n- 1 para Logar\n- 2 para criar uma conta\nDigite sua opcao: ";
        std::cin >> aux;
    } while (aux != 1 && aux != 2 && aux != 0);

    switch (aux)
    {
    case 0:
        std::cout << "Ate mais!";
        break;
    case 1:
        Logar::Logar(livros,users);
        break;
    case 2:
        Cadastrar::Cadastrar(livros,users);
        break;
    default:
        break;
    }
};