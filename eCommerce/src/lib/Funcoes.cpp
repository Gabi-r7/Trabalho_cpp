#include "Funcoes.hpp"
#include "User.hpp"
#include "Anuncio.hpp"
#include "Produto.hpp"
#include "Admin.hpp"
#include <iostream>
#include <vector>
#define adminSenha 1230

//Inicializa sistema
void Funcoes::InicializaSistema(std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, int& contAnuncio, std::vector<Produto*>& produtos, int& contProduto) {
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
			Funcoes::Logar(users, contUser, anuncios, contAnuncio, produtos, contProduto);
			break;
		case 2:
			Funcoes::Cadastrar(users, contUser, anuncios, contAnuncio, produtos, contProduto);
			break;
		default:
			break;
		}
	} while (aux != 0);
}

//Cadastrar
void Funcoes::Cadastrar(std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, int& contAnuncio, std::vector<Produto*>& produtos, int& contProduto) {
	std::string login, password, email, phone;
	bool adm, existe;
	int admAux = 0;
	while (true) {
		existe = false;
		std::cout << "\nFaca seu cadastro!" << std::endl;
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
		std::cout << "\nDigite a senha de administrador caso voce seja: ";
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
	newUser->setEmail(email);
	newUser->setAdm(adm);
	users.push_back(newUser);
	std::cout << "Cadastro realizado com sucesso!\n" << std::endl;
	newUser->setIdUser(contUser);
	contUser++;
	return;
};


//Logar
void Funcoes::Logar(std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, int& contAnuncio, std::vector<Produto*>& produtos, int& contProduto) {
	std::string login, password;
	bool aux = false;
	std::cout << "\nFaca seu login!" << std::endl;
	while (true) {
		std::cout << "Digite seu login: ";
		std::cin >> login;
		std::cout << "Digite sua senha: ";
		std::cin >> password;
		for (User* user : users) {
			if (login == user->getLogin() && password == user->getPassword()) {
				std::cout << "Login realizado com sucesso!" << std::endl;
				if (user->getAdm()) {
					std::cout << "Voce logou como administrador!" << std::endl;
				}
				else {
					std::cout << "Voce logou como um usuario comum!" << std::endl;
				}
				aux = true;
				Funcoes::Acoes(user->getIdUser(), users, contUser, anuncios, contAnuncio, produtos, contProduto);
			}
		}
		if (aux) {
			break;
		}
		std::cout << "Login ou senha incorretos!" << std::endl;
	}
}


//Acoes
void Funcoes::Acoes(int idUser, std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, int& contAnuncio, std::vector<Produto*>& produtos, int& contProduto) {
	Anuncio anuncio;
	User user;
	Admin admin;
	bool adm = users.at(idUser)->getAdm();
	int aux = 0;
	while (true) {
		if (users.at(idUser)->getBanido()) {
			std::cout << "-------------------------------------------------------------------------------\n";
			std::cout << "Voce foi banido do sistema!" << std::endl;
			std::cout << "-------------------------------------------------------------------------------\n";
			break;
		}
		else {
			std::cout << "\n---------- MENU PRINCIPAL ----------" << std::endl;
			std::cout << "0 - Sair" << std::endl;
			std::cout << "1 - Anuncios disponiveis" << std::endl;
			std::cout << "2 - Seus anuncios" << std::endl;
			std::cout << "3 - Seus produtos" << std::endl;
			std::cout << "4 - Sua conta" << std::endl;
			if (adm) {
				std::cout << "5 - Ver usuarios" << std::endl;
				std::cout << "6 - Banir usuario" << std::endl;
				std::cout << "7 - Desbanir usuario" << std::endl;
				std::cout << "8 - Apagar anuncio" << std::endl;
			}
			std::cout << "Opcao: ";
			std::cin >> aux;
			if (aux == 0) { // sair total
				break;
			}
			else if (aux == 1) { // menu de Anuncios
				int aux1 = 0;
				while (true) {
					std::cout << "\n---------- ANUNCIOS DA COMUNIDADE ----------" << std::endl;
					std::cout << "0 - Voltar" << std::endl;
					std::cout << "1 - Ver todos os anuncios disponiveis" << std::endl;
					std::cout << "2 - Favoritar um anuncio" << std::endl;
					std::cout << "3 - Adicionar ao carrinho" << std::endl;
					std::cout << "4 - Realizar uma compra" << std::endl;
					std::cout << "Opcao: ";
					std::cin >> aux1;
					if (aux1 == 0) { // sair op1
						break;
					}
					else if (aux1 == 1) { // todos anuncios
						anuncio.verAnuncios(anuncios, produtos);
					}
					else if (aux1 == 2) {
						user.adicionar(0, anuncios, contAnuncio, produtos);
					}
					else if (aux1 == 3) {
						user.adicionar(1, anuncios, contAnuncio, produtos);
					}
					else if (aux1 == 4) {
						user.comprarProduto(idUser, users, anuncios, contAnuncio, produtos);
						// adicionar verificações
					}
					else {
						std::cout << "Opcao invalida" << std::endl;
					}
				}
				continue;
			}
			else if (aux == 2) { // Seus anuncios
				int aux2 = 0;
				while (true) {
					std::cout << "\n---------- SEUS ANUNCIOS ----------" << std::endl;
					std::cout << "0 - Voltar" << std::endl;
					std::cout << "1 - Ver seus anuncios" << std::endl;
					std::cout << "2 - Adicionar um anuncio" << std::endl;
					std::cout << "3 - Editar um anuncio" << std::endl;
					std::cout << "4 - Deletar um anuncio" << std::endl;
					std::cout << "Opcao: ";
					std::cin >> aux2;
					if (aux2 == 0) { // sair op2
						break;
					}
					else if (aux2 == 1) { // ver seus anuncios
						user.mostrar(anuncios, contAnuncio, idUser);
					}
					else if (aux2 == 2) {
						user.adicionar(anuncios, contAnuncio, users, idUser, produtos, contProduto);
					}
					else if (aux2 == 3) {
						user.editar(anuncios, contAnuncio, idUser);
						// preciso testar
					}
					else if (aux2 == 4) {
						user.deletar(anuncios, contAnuncio, idUser);
						// preciso testar
					}
				}
				continue;
			}
			else if (aux == 3) { // Seus produtos
				int aux3 = 0;
				while (true) {
					std::cout << "\n---------- SEUS PRODUTOS ----------" << std::endl;
					std::cout << "0 - Voltar" << std::endl;
					std::cout << "1 - Ver seus produtos" << std::endl;
					std::cout << "2 - Adicionar um produto" << std::endl;
					std::cout << "3 - Editar um produto" << std::endl;
					std::cout << "4 - Deletar um produto" << std::endl;
					std::cout << "Opcao: ";
					std::cin >> aux3;
					if (aux3 == 0) { // sair op3
						break;
					}
					else if (aux3 == 1) { // ver seus produtos
						user.mostrar(produtos, contProduto, idUser);
					}
					else if (aux3 == 2) {
						user.adicionar(produtos, contProduto, idUser);
					}
					else if (aux3 == 3) {
						user.editar(produtos, contProduto, idUser);
						// preciso testar
					}
					else if (aux3 == 4) {
						user.deletar(produtos, contProduto, anuncios, idUser);
						// preciso testar
					}
				}
				continue;
			}
			else if (aux == 4) {
				int aux4 = 0;
				do {
					std::cout << "\n---------- SUA CONTA ----------" << std::endl;
					std::cout << "0 - Voltar" << std::endl;
					std::cout << "1 - Ver seus dados" << std::endl;
					std::cout << "2 - Editar seus dados" << std::endl;
					std::cout << "3 - Menu de favoritos" << std::endl;
					std::cout << "4 - Menu de carrinho" << std::endl;
					std::cout << "Opcao: ";
					std::cin >> aux4;
					if (aux4 == 1) {
						user.mostrar(idUser, users);//
					}
					else if (aux4 == 2) {
						user.editar(idUser, users);//
					}
					else if (aux4 == 3) {
						int aux;
						do {
							std::cout << "\n---------- MENU DE FAVORITOS ----------" << std::endl;
							std::cout << "0 - Voltar" << std::endl;
							std::cout << "1 - Ver seus favoritos" << std::endl;
							std::cout << "2 - Adicionar um favorito" << std::endl;
							std::cout << "3 - Deletar um favorito" << std::endl;
							std::cout << "Opcao: ";
							std::cin >> aux;
							if (aux == 0) {
								break;
							}
							else if (aux == 1) {
								user.mostrar(0);//
							}
							else if (aux == 2) {
								user.adicionar(0, anuncios, contAnuncio, produtos);//
							}
							else if (aux == 3) {
								user.deletar(0);//
							}
							else {
								std::cout << "Opcao invalida" << std::endl;
							}
						} while (aux != 0);
					}
					else if (aux4 == 4) {
						int aux;
						do {
							std::cout << "\n---------- MENU DO CARRINHO ----------" << std::endl;
							std::cout << "0 - Voltar" << std::endl;
							std::cout << "1 - Ver seu carrinho" << std::endl;
							std::cout << "2 - Adicionar item ao carrinho" << std::endl;
							std::cout << "3 - Deletar item do carrinho" << std::endl;
							std::cout << "4 - Finalizar compra" << std::endl;
							std::cout << "Opcao: ";
							std::cin >> aux;
							if (aux == 0) {
								break;
							}
							else if (aux == 1) {
								user.mostrar(1);//
							}
							else if (aux == 2) {
								user.adicionar(1, anuncios, contAnuncio, produtos);//
							}
							else if (aux == 3) {
								user.deletar(1);//
							}
							else if (aux == 4) {
								user.finalizarCompra(idUser, users, anuncios, produtos);
							}
							else {
								std::cout << "Opcao invalida" << std::endl;
							}
						} while (aux != 0);
					}
				} while (aux4 != 0);
				continue;
			}
			else if (!adm) {
				std::cout << "Opcao invalida" << std::endl;
			}
			if (adm) { // preciso testar todas as opções
				if (aux == 5) {
					admin.verUsuarios(users);
				}
				else if (aux == 6) {
					admin.banirUsuario(idUser, users);
				}
				else if (aux == 7) {
					admin.desbanirUsuario(idUser, users);
				}
				else if (aux == 8) {
					admin.apagarAnuncio(idUser, anuncios, produtos);
				}
				else {
					std::cout << "Opcao invalida" << std::endl;
				}
			}
		}
	}
}

