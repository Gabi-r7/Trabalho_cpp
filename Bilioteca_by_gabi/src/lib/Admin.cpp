#include <iostream>
#include <vector>
#include "User.hpp"
#include "Livro.hpp"
#include "Admin.hpp"
#define adminSenha 1230
User user;


Admin::Admin() {};
Admin::~Admin() {};

void Admin::CadastrarLivro(std::vector<Livro*>& livros) {
    Livro livro;
    std::string titulo, autor, editora;
    int idLivro;
    std::cout << "Digite o titulo do livro: ";
    std::cin >> titulo;
    livro.setTitulo(titulo);
    std::cout << "Digite o autor do livro: ";
    std::cin >> autor;
    livro.setAutor(autor);
    std::cout << "Digite a editora do livro: ";
    std::cin >> editora;
    livro.setEditora(editora);
    idLivro = livros.size();
    livro.setIdLivro(idLivro);
    livros.push_back(&livro);
};

void Admin::ApagarLivro(std::vector<Livro*>& livros) {
    int idLivro;
    std::cout << "Digite o ID do livro que deseja apagar: ";
    std::cin >> idLivro;
    for (int i = 0; i < livros.size(); i++) {
        if (livros[i]->getIdLivro() == idLivro) {
            livros.erase(livros.begin() + i);
        }
    }
};

bool Admin::ModificarStatusUser(int idUser, std::vector<User*>& users) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getIdUser() == idUser) {
            if (users[i]->getStatus() == true) {
                users[i]->setStatus(false);
            }
            else {
                users[i]->setStatus(true);
            }
        }
    }
    return user.getStatus();
};

void Admin::CadastrarUser(std::vector<User*>& users) {
    std::string login, password, email, phone;
    bool adm, existe;
    int admAux;
    while (true) {
        std::cout << "Faca seu cadastro!" << std::endl;
        std::cout << "Digite seu login: ";
        std::cin >> login;
        std::cout << "Digite sua senha: ";
        std::cin >> password;
        std::cout << "Digite seu email: ";
        std::cin >> email;
        std::cout << "Digite seu telefone: ";
        std::cin >> phone;
        std::cout << "Digite a senha de administrador caso voce seja: ";
        std::cin >> admAux;
        if (admAux == adminSenha) {
            adm = true;
            user.setAdm(adm);
        }
        else {
            adm = false;
            user.setAdm(adm);
        }
        for (User* user : users) {
            if (login == user->getLogin()) {
                std::cout << "Login ja existente!" << std::endl;
                existe = true;
                break;
            }
        }
        if (!existe) {
            break;
        }
    }
    User* newUser = new User();
    newUser->setLoginSenha(login, password);
    users.push_back(newUser);
    std::cout << "Cadastro realizado com sucesso!" << std::endl;
    newUser->setIdUser(users.size() - 1);
};

void Admin::ApagarUser(std::vector<User*>& users) {
    int idUser;
    std::cout << "Digite o ID do usuario que deseja apagar: ";
    std::cin >> idUser;
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getIdUser() == idUser) {
            users.erase(users.begin() + i);
        }
    }
};



void Admin::AplicarMulta(std::vector<User*>& users) {
    int idUser, valor;
    std::cout << "Digite o ID do usuario que deseja aplicar a multa: ";
    std::cin >> idUser;
    std::cout << "Digite o valor da multa: ";
    std::cin >> valor;
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getIdUser() == idUser) {
            users[i]->setMulta(valor);
        }
    }
};