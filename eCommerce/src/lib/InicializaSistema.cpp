#include "InicializaSistema.hpp"
#include <vector>
#include <iostream>
#include "Cadastrar.hpp"
#include "Logar.hpp"
#include "Anuncio.hpp"

void InicializaSistema::InicializaSistema(std::vector<User*>& users, int &contUser, std::vector<Anuncio*>& anuncios, int &contAnuncio, std::vector<Produto*>& produtos, int &contProduto) {
    int aux;
    std::cout << "Bem vindo ao sistema de vendas Duzhomi!" << std::endl;
    do {
        std::cout << "Digite\n- 0 para sair\n- 1 para Logar\n- 2 para criar uma conta\nDigite sua opcao: ";
        std::cin >> aux;
        switch (aux)
        {
        case 0:
            std::cout << "Ate mais!";
            break;
        case 1:
            Logar::Logar(users, contUser, anuncios, contAnuncio, produtos, contProduto);
            break;
        case 2:
            Cadastrar::Cadastrar(users, contUser, anuncios, contAnuncio, produtos, contProduto);
            break;
        default:
            break;
        }
    } while (aux != 0);
}