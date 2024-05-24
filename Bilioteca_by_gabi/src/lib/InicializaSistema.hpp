#include <iostream>
#include <vector>
#ifndef INICIALIZASISTEMA_HPP
#define INICIALIZASISTEMA_HPP
#include "Emprestimo.hpp"
#include "Logar.hpp"
#include "Cadastrar.hpp"

void InicializaSistema() {
    User user;
    Livro livro;
    int aux;
    int senha;
    std::cout << "Bem vindo ao sistema de biblioteca!" << std::endl;
    do {
        std::cout << "Digite\n-0 para sair\n-1 para Logar\n-2 para criar uma conta\nDigite sua opcao: ";
        std::cin >> aux;
    } while (aux != 1 && aux != 2 && aux != 0);

    switch (aux)
    {
    case 0:
        std::cout << "Ate mais!";
        break;
    case 1:
        Logar();
        break;
    case 2:
        Cadastrar();
        break;
    default:
        break;
    }
};
#endif