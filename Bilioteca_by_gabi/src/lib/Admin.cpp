#include <iostream>
#include <vector>
#include "User.hpp"
#include "Livro.hpp"
#include "Admin.hpp"
#define adminSenha 1230

Admin::Admin() {};
Admin::~Admin() {};

void Admin::CadastrarLivro(std::vector<Livro*>& livros, int &contLivro) {
    std::string titulo, autor, editora;
    int idLivro;
    std::cout << "\nDigite o titulo do livro: ";
    std::cin >> titulo;
    std::cout << "Digite o autor do livro: ";
    std::cin >> autor;
    std::cout << "Digite a editora do livro: ";
    std::cin >> editora;
    Livro* livro = new Livro();
    livro->setTitulo(titulo);
    livro->setAutor(autor);
    livro->setEditora(editora);
    idLivro = livros.size();
    livro->setIdLivro(contLivro);
    contLivro++;
    livro->setEmprestado(false);
    livros.push_back(livro);
};

void Admin::ApagarLivro(std::vector<Livro*>& livros, int &contLivro) {
    int idLivro;
    Livro livro;
    livro.MostrarDisponiveis(livros);
    std::cout << "\nDigite o ID do livro que deseja apagar: ";
    std::cin >> idLivro;
    if (livros.at(idLivro) == nullptr) {
        std::cout << "Livro nao encontrado!" << std::endl;
    }
    else if (idLivro < 0 || idLivro >= contLivro) {
        std::cout << "Livro nao encontrado!" << std::endl;
    }
    else if (livros.at(idLivro)->getEmprestado()) {
        std::cout << "Livro emprestado! Nao pode ser apagado!" << std::endl;
    }
	else {
		for (int i = 0; i < livros.size(); i++) {
			if (livros.at(i)->getIdLivro() == idLivro) {
                delete livros.at(i);
                livros.at(i) = nullptr;
				std::cout << "Livro deletado com sucesso!" << std::endl;
				break;
			}
		}
	}
};

bool Admin::ModificarStatusUser(int idUser, std::vector<User*>& users) {
    
    User user;
    int valorMulta;
    MostrarUsuarios(users);
    while (true) {
        std::cout << "\nDigite o ID do usuario que deseja modificar o status: ";
        std::cin >> idUser;
        if (idUser >= users.size() || idUser < 0) {
			std::cout << "ID invalido!" << std::endl;
		}
		else {
			break;
		}
    }
    for (int i = 0; i < users.size(); i++) {
		if (users[i]->getIdUser() == idUser) {
			if (users[i]->getStatus()) {
				users[i]->setStatus(false);
                std::cout << "Status modificado para nao devedor!" << std::endl;
                users[i]->setMulta(0);
			}
			else {
				users[i]->setStatus(true);
                std::cout << "\nStatus modificado para devedor!" << std::endl;
                std::cout << "Digite o valor da multa: ";
                std::cin >> valorMulta;
                users[i]->setMulta(getMulta() + valorMulta);
			}
		}
	}

    return user.getStatus();
};


void Admin::MostrarUsuarios(std::vector<User*>& users) {
    std::cout << "\nUsuarios cadastrados:" << std::endl;
    for (int i = 0; i < users.size(); i++) {
        std::cout << "ID: " << users[i]->getIdUser() << " - Login: " << users[i]->getLogin() << " - Email: " << users[i]->getEmail() << " - Status: ";
        if (users[i]->getStatus()) {
            std::cout << "Devedor" << std::endl;
        }
        else {
            std::cout << "Nao devedor" << std::endl;
        }
    }
};

void Admin::CadastrarUser(std::vector<User*>& users, int &contUser) {
    std::string login, password, email, phone;
    bool adm = false, existe;
    int admAux = 0;
    while (true) {
        existe = false;
        std::cout << "Faca o cadastro!" << std::endl;
        std::cout << "Digite seu login: ";
        std::cin >> login;
        for (User* user : users) {
            if (login == user->getLogin()) {
                std::cout << "Login ja existente!" << std::endl;
                existe = true;
                break;
            }
        }
        if (existe) {
            continue;
        }
        std::cout << "Digite sua senha: ";
        std::cin >> password;
        std::cout << "Digite seu email: ";
        std::cin >> email;
        //std::cout << "Digite seu telefone: ";
        //std::cin >> phone;
        std::cout << "Digite a senha de administrador caso o usuario seja: ";
        std::cin >> admAux;
        if (admAux == adminSenha) {
            std::cout << "Voce e um administrador!" << std::endl;
            adm = true;
        }
        else {
            adm = false;
        }
        break;
    }
    User* newUser = new User();
    newUser->setLoginSenha(login, password);
    newUser->setAdm(adm);
    users.push_back(newUser);
    std::cout << "Cadastro realizado com sucesso!" << std::endl;
    newUser->setIdUser(contUser);
    contUser++;
};

void Admin::ApagarUser(int id, std::vector<User*>& users) {
    int idUser;
    bool valido = false;
    MostrarUsuarios(users);
    do {
        std::cout << "\nDigite o ID do usuario que deseja apagar (ou -1 para sair): ";
        std::cin >> idUser;
        if (idUser == -1) {
			break;
		}
        else if (idUser >= users.size() || idUser < 0) {
			std::cout << "ID invalido!" << std::endl;
			valido = false;
		}
        else if (idUser == id) {
			std::cout << "Voce nao pode apagar sua propria conta!" << std::endl;
			valido = false;
		}
        else if (users.at(idUser)->getStatus()) {
			std::cout << "Usuario e devedor! Nao pode ser apagado!" << std::endl;
			valido = false;
		}
		else {
			valido = true;
		}
    } while (!valido);
    if (idUser != -1) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i]->getIdUser() == idUser) {
                users.erase(users.begin() + i);
            }
        }
    }
};


void Admin::AplicarMulta(std::vector<User*>& users) {
    int idUser, valor = 0;
    bool valido = false;
    MostrarUsuarios(users);
    do {
        std::cout << "\nDigite o ID do usuario que deseja aplicar a multa (-1 para cancelar): ";
        std::cin >> idUser;
        if (idUser == -1) {
            std::cout << "Operacao cancelada!" << std::endl;
            valido = false;
            break;
        }
        else if (idUser >= users.size() || idUser < 0 && idUser != -1) {
			std::cout << "ID invalido!" << std::endl;
			valido = false;
		}
        else if (users.at(idUser)->getStatus()) {
            std::cout << "Usuario ja e devedor!" << std::endl;
            return;
        }
		else {
			valido = true;
		}
    } while (!valido);
    if (valido){
        std::cout << "Digite o valor da multa: ";
        std::cin >> valor;
        if (valor <= 0) {
            std::cout << "Valor invalido!" << std::endl;
            return;
        }
    }
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getIdUser() == idUser) {
            users[i]->setMulta(getMulta() + valor);
            users[i]->setStatus(true);
            std::cout << "Multa aplicada com sucesso!" << std::endl;
        }
    }
};