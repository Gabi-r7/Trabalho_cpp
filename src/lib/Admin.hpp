#include <iostream>
#include <vector>
#include "User.hpp"
#include "Livro.hpp"
#define adminSenha 1230
#ifndef ADMIN_HPP
#define ADMIN_HPP
std::vector<User> _users;
std::vector<Livro> _livros;

class Admin : public User {
public:
    Admin() {};
    ~Admin() {};
    User user;

    void CadastrarLivro() {
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
        _livros.push_back(livro);
    };

    void ApagarLivro() {
		int idLivro;
		std::cout << "Digite o ID do livro que deseja apagar: ";
		std::cin >> idLivro;
        for (int i = 0; i < livros.size(); i++) {
            if (_livros[i].getIdLivro() == idLivro) {
				livros.erase(livros.begin() + i);
			}
		}
	};

    bool ModificarStatusUser(int idUser){
        for (int i = 0; i < _users.size(); i++) {
            if (_users[i].getIdUser() == idUser) {
                if (_users[i].getStatus() == true) {
					_users[i].setStatus(false);
                }
                else {
					_users[i].setStatus(true);
				}
			}
		}
        return user.getStatus();
    };
    
    void CadastrarUser() {
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

    void ApagarUser(){
        int idUser;
        std::cout << "Digite o ID do usuario que deseja apagar: ";
        std::cin >> idUser;
        for (int i = 0; i < users.size(); i++) {
            if (users[i]->getIdUser() == idUser) {
				users.erase(users.begin() + i);
			}
		}
    };



    void AplicarMulta(){
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
};
#endif