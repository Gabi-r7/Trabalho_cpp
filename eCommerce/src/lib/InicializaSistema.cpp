#include <iostream>
#include <vector>
#include "InicializaSistema.hpp"
#include "Logar.hpp"
#include "Cadastrar.hpp"
#include "Admin.hpp"
#include "Anuncio.hpp"
#include "Produto.hpp"

void InicializaSistema::InicializaSistema(std::vector<User*>& users, int &contUser, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos) {
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
        Logar::Logar(users, contUser, anuncios, produtos);
        break;
    case 2:
        Cadastrar::Cadastrar(users, contUser, anuncios, produtos);
        break;
    default:
        break;
    }
};