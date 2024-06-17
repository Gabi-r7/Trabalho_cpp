#include "User.hpp"
#include <vector>
#include <iostream>
#include <string>
#include "Anuncio.hpp"
#include "Produto.hpp"

User::User() : adm(false) {};
User::~User() {};

void User::setEmail(std::string _email) {
	email = _email;
}

std::string User::getEmail() {
	return email;
}

std::string User::getLogin() {
	return login;
}

std::string User::getPassword() {
	return password;
}

int User::getIdUser() {
	return idUser;
}

void User::setAdm(bool _adm) {
	adm = _adm;
}

bool User::getAdm() {
	return adm;
}

void User::setIdUser(int _idUser) {
	idUser = _idUser;
}

void User::setLoginSenha(std::string _login, std::string _senha) {
	login = _login;
	password = _senha;
}

void User::setBanido(bool _banido) {
	banido = _banido;
}

bool User::getBanido() {
	return banido;
}


bool User::comprarProduto(int idUser, std::vector<User*>& users, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos) {
	int aux = 0;
	Anuncio anuncio;
	anuncio.verAnuncios(anuncios, produtos);
	if (anuncios.size() == 0) {
		std::cout << "Nao ha anuncios disponiveis!" << std::endl;
		return false;
	}
	else {
		std::cout << "Digite o id do anuncio que deseja comprar: ";
		std::cin >> aux;
		if (aux < 0 || aux >= anuncios.size()) {
			std::cout << "Anuncio nao encontrado!" << std::endl;
			return false;
		}
		else {
			if (!anuncios.at(aux)->getDisponibilidade()) {
				std::cout << "Anuncio ja vendido!" << std::endl;
				return false;
			}
			else {
				std::cout << "Compra realizada com sucesso!" << std::endl;
				if (produtos.at(anuncios.at(aux)->getIdProduto())->getQuantidade() <= 1) {
					anuncios.at(aux)->setDisponibilidade(false);
				}
				else {
					produtos.at(anuncios.at(aux)->getIdProduto())->setQuantidade(produtos.at(anuncios.at(aux)->getIdProduto())->getQuantidade() - 1);
				}
				return true;
			}
		}
	}
}

void User::finalizarCompra(int idUser, std::vector<User*>& users, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos) {
	bool existe = false;
	existe = mostrar(1);
	if (existe) {
		for (int i = 0; i < carrinho.size(); i++) {
			if (carrinho.at(i)->getDisponibilidade()) {
				if (produtos.at(carrinho.at(i)->getIdProduto())->getQuantidade() <= 1) {
					carrinho.at(i)->setDisponibilidade(false);
				}
				else {
					produtos.at(carrinho.at(i)->getIdProduto())->setQuantidade(produtos.at(carrinho.at(i)->getIdProduto())->getQuantidade() - 1);
				}
			}
			else {
				std::cout << "Produto " << carrinho.at(i)->getIdProduto() << " nao disponivel!" << std::endl;
			}
		}
		std::cout << "Compra finalizada com sucesso!" << std::endl;
		carrinho.clear();
	}
}

// mostrar

void User::mostrar(std::vector<Anuncio*>& anuncios, int idUser) {
	if (anuncios.size() == 0) {
		std::cout << "Voce nao possui anuncios!" << std::endl;
		return;
	}
	else {
		for (int i = 0; i < anuncios.size(); i++) {
			if (anuncios.at(i)->getIdVendedor() == idUser) {
				std::cout << "------------------------------------------" << std::endl;
				std::cout << "Anuncio " << anuncios.at(i)->getIdAnuncio() << std::endl;
				std::cout << "Nome: " << anuncios.at(i)->getNome() << std::endl;
				std::cout << "Autor: " << anuncios.at(i)->getAutor() << std::endl;
				std::cout << "Preco: " << anuncios.at(i)->getPreco() << std::endl;
				std::cout << "Descricao: " << anuncios.at(i)->getDescricao() << std::endl;
				std::cout << "Disponibilidade: " << anuncios.at(i)->getDisponibilidade() << std::endl;
			}
		}
		std::cout << "------------------------------------------" << std::endl;
	}
}

void User::mostrar(std::vector<Produto*>& produtos, int idUser) {
	if (produtos.size() == 0) {
		std::cout << "Voce nao possui produtos!" << std::endl;
		return;
	}
	else {
		for (int i = 0; i < produtos.size(); i++) {
			if (produtos.at(i)->getIdVendedor() == idUser) {
				std::cout << "------------------------------------------" << std::endl;
				std::cout << "Produto " << produtos.at(i)->getIdProduto() << std::endl;
				std::cout << "Nome: " << produtos.at(i)->getNome() << std::endl;
				std::cout << "Categoria: " << produtos.at(i)->getCategoria() << std::endl;
				std::cout << "Preco: " << produtos.at(i)->getPreco() << std::endl;
				std::cout << "Quantidade: " << produtos.at(i)->getQuantidade() << std::endl;
				std::cout << "Disponibilidade: " << produtos.at(i)->getDisponibilidade() << std::endl;
			}
		}
		std::cout << "------------------------------------------" << std::endl;
	}
}

void User::mostrar(int idUser, std::vector<User*>& users) {
	for (int i = 0; i < users.size(); i++) {
		if (users.at(i)->getIdUser() == idUser) {
			std::cout << "------------------------------------------" << std::endl;
			std::cout << "Usuario " << users.at(i)->getIdUser() << std::endl;
			std::cout << "Login: " << users.at(i)->getLogin() << std::endl;
			std::cout << "Senha: " << users.at(i)->getPassword() << std::endl;
			std::cout << "Email: " << users.at(i)->getEmail() << std::endl;
			std::cout << "Adm: " << users.at(i)->getAdm() << std::endl;
			std::cout << "Banido: " << users.at(i)->getBanido() << std::endl;
			std::cout << "------------------------------------------" << std::endl;
		}
	}
}

bool User::mostrar(int a) {
	if (a == 0) {
		if (favoritos.size() == 0) {
			std::cout << "Voce nao possui favoritos!" << std::endl;
			return false;
		}
		for (int i = 0; i < favoritos.size(); i++) {
			std::cout << "------------------------------------------" << std::endl;
			std::cout << "Anuncio " << favoritos.at(i)->getIdAnuncio() << std::endl;
			std::cout << "Nome: " << favoritos.at(i)->getNome() << std::endl;
			std::cout << "Autor: " << favoritos.at(i)->getAutor() << std::endl;
			std::cout << "Preco: " << favoritos.at(i)->getPreco() << std::endl;
			std::cout << "Descricao: " << favoritos.at(i)->getDescricao() << std::endl;
			std::cout << "Disponibilidade: " << favoritos.at(i)->getDisponibilidade() << std::endl;
			std::cout << "------------------------------------------" << std::endl;
		}
		return true;
	}
	else {
		if (carrinho.size() == 0) {
			std::cout << "Voce nao possui produtos no carrinho!" << std::endl;
			return false;
		}
		for (int i = 0; i < carrinho.size(); i++) {
			std::cout << "------------------------------------------" << std::endl;
			std::cout << "Produto " << carrinho.at(i)->getIdProduto() << std::endl;
			std::cout << "Nome: " << carrinho.at(i)->getNome() << std::endl;
			//std::cout << "Categoria: " << carrinho.at(i)->getCategoria() << std::endl; //parei aqui
			std::cout << "Preco: " << carrinho.at(i)->getPreco() << std::endl;
			//std::cout << "Quantidade: " << carrinho.at(i)->getQuantidade() << std::endl; //parei aqui
			std::cout << "Disponibilidade: " << carrinho.at(i)->getDisponibilidade() << std::endl;
			std::cout << "------------------------------------------" << std::endl;
		}
		return true;
	}
}

// adicionar 


void User::adicionar(std::vector<Anuncio*>& anuncios, int &contAnuncio, std::vector<User*>& users, int idUser, std::vector<Produto*>& produtos) {
	int aux = 0, aux1;
	std::string nome, autor, descricao;
	float preco;
	bool existe = false;
	for (int i = 0; i < produtos.size(); i++) {
		if (produtos.at(i)->getIdVendedor() == idUser) { //verifica se o usuario possui produtos
			existe = true;
			break;
		}
	}
	if (!existe) {
		std::cout << "Voce nao possui produtos para anunciar!" << std::endl;
		std::cout << "Adicione um produto antes de anunciar!" << std::endl;
		std::cout << "Deseja adicionar um produto agora?" << std::endl;
		std::cout << "1 - Sim" << std::endl;
		std::cout << "2 - Nao" << std::endl;
		std::cin >> aux;
		if (aux == 1) {
			adicionar(produtos, contAnuncio, idUser);
			adicionar(anuncios, contAnuncio, users, idUser, produtos);
		}
		else {
			return;
		}
	}
	else {
		mostrar(produtos, idUser);
		while (true) {
			std::cout << "Digite o id do produto que deseja anunciar: ";
			std::cin >> aux1;
			if (aux1 < 0 || aux1 >= produtos.size()) {
				std::cout << "Produto nao encontrado!" << std::endl;
				continue;
			}
			else if (!produtos.at(aux1)->getDisponibilidade()) {
				std::cout << "Produto nao disponivel!" << std::endl;
				continue;
			}
			else {
				break;
			}
		}
		std::cout << "Digite o nome do anuncio: ";
		std::cin >> nome;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Digite a descricao do anuncio: ";
		std::getline(std::cin, descricao);
		Anuncio* newAnuncio = new Anuncio();
		newAnuncio->setNome(nome);
		newAnuncio->setAutor(users.at(idUser)->getLogin());
		newAnuncio->setDescricao(descricao);
		newAnuncio->setPreco(produtos.at(aux1)->getPreco());
		newAnuncio->setIdVendedor(idUser);
		newAnuncio->setIdProduto(aux1);
		newAnuncio->setIdAnuncio(contAnuncio);
		newAnuncio->setDisponibilidade(true);
		std::cout << "Anuncio adicionado com sucesso!" << std::endl;
		contAnuncio++;
		anuncios.push_back(newAnuncio);
	}
}

void User::adicionar(std::vector<Produto*>& produtos, int& contProduto, int idUser) {
	std::string nome, categoria;
	float preco;
	int quantidade;
	while (true) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Digite o nome do produto: ";
		std::getline(std::cin, nome);
		std::cout << "Digite a categoria do produto: ";
		std::cin >> categoria;
		std::cout << "Digite o preco do produto: ";
		std::cin >> preco;
		if (preco <= 0) {
			std::cout << "Preco invalido!" << std::endl;
			continue;
		}
		std::cout << "Digite a quantidade do produto em estoque: ";
		std::cin >> quantidade;
		if (quantidade <= 0) {
			std::cout << "Quantidade invalida!" << std::endl;
			continue;
		}
		Produto* newProduto = new Produto();
		newProduto->setNome(nome);
		newProduto->setCategoria(categoria);
		newProduto->setPreco(preco);
		newProduto->setQuantidade(quantidade);
		newProduto->setIdVendedor(idUser);
		newProduto->setIdProduto(contProduto);
		produtos.push_back(newProduto);
		std::cout << "Produto adicionado com sucesso!" << std::endl;
		contProduto++;
		break;
	}
}

void User::adicionar(int a, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos) {
	Anuncio anuncio;
	int tot = 0;
	if (a == 0) {
		tot = anuncio.verAnuncios(anuncios, produtos);
		if (tot == 0) {
			std::cout << "Nao ha anuncios disponiveis!" << std::endl;
			return;
		}
		int aux;
		std::cout << "Digite o id do anuncio que deseja adicionar aos favoritos: ";
		std::cin >> aux;
		if (aux < 0 || aux >= anuncios.size()) {
			std::cout << "Anuncio nao encontrado!" << std::endl;
		}
		else {
			favoritos.push_back(anuncios.at(aux));
			std::cout << "Anuncio adicionado aos favoritos!" << std::endl;
		}
	}
	else {
		tot = anuncio.verAnuncios(anuncios, produtos);
		if (tot == 0) {
			std::cout << "Nao ha anuncios disponiveis!" << std::endl;
			return;
		}
		int aux;
		std::cout << "Digite o id do anuncio que deseja adicionar ao carrinho: ";
		std::cin >> aux;
		if (aux < 0 || aux >= anuncios.size()) {
			std::cout << "Anuncio nao encontrado!" << std::endl;
		}
		else {
			carrinho.push_back(anuncios.at(aux));
			std::cout << "Anuncio adicionado ao carrinho!" << std::endl;
		}
	}
}

// editar


void User::editar(std::vector<Anuncio*>& anuncios, int idUser) {
	int aux, aux1; //aqui
	mostrar(anuncios, idUser);
	std::cout << "Digite o id do anuncio que deseja editar: ";
	std::cin >> aux;
	if (aux < 0 || aux >= anuncios.size()) {
		std::cout << "Anuncio nao encontrado!" << std::endl;
		return;
	}
	else if (anuncios.at(aux)->getIdVendedor() != idUser) {
		std::cout << "Voce nao possui permissao para editar este anuncio!" << std::endl;
		return;
	}
	else {
		do {
			std::cout << "0 - Sair" << std::endl;
			std::cout << "1 - Editar preco" << std::endl;
			std::cout << "2 - Editar descricao" << std::endl;
			std::cin >> aux1; //aqui
			if (aux1 == 1) {
				float preco;
				std::cout << "Digite o novo preco: ";
				std::cin >> preco;
				anuncios.at(aux)->setPreco(preco);
			}
			else if (aux1 == 2) {
				std::string descricao;
				std::cout << "Digite a nova descricao: ";
				std::cin >> descricao;
				anuncios.at(aux)->setDescricao(descricao);
			}
			else {
				break;
			}
		} while (aux1 != 0); //aqui
	}
}

void User::editar(std::vector<Produto*>& produtos, int idUser) {
	int aux, aux1;
	mostrar(produtos, idUser);
	std::cout << "Digite o id do produto que deseja editar: ";
	std::cin >> aux;
	if (aux < 0 || aux >= produtos.size()) {
		std::cout << "Produto nao encontrado!" << std::endl;
		return;
	}
	else if (produtos.at(aux)->getIdVendedor() != idUser) {
		std::cout << "Voce nao possui permissao para editar este produto!" << std::endl;
		return;
	}
	else {
		do {
			std::cout << "0 - Sair" << std::endl;
			std::cout << "1 - Editar nome" << std::endl;
			std::cout << "2 - Editar categoria" << std::endl;
			std::cout << "3 - Editar preco" << std::endl;
			std::cout << "4 - Editar quantidade" << std::endl;
			std::cin >> aux1;
			if (aux1 == 1) {
				std::string nome;
				std::cout << "Digite o novo nome: ";
				std::cin >> nome;
				produtos.at(aux)->setNome(nome);
			}
			else if (aux1 == 2) {
				std::string categoria;
				std::cout << "Digite a nova categoria: ";
				std::cin >> categoria;
				produtos.at(aux)->setCategoria(categoria);
			}
			else if (aux1 == 3) {
				float preco;
				std::cout << "Digite o novo preco: ";
				std::cin >> preco;
				produtos.at(aux)->setPreco(preco);
			}
			else if (aux1 == 4) {
				int quantidade;
				std::cout << "Digite a nova quantidade: ";
				std::cin >> quantidade;
				produtos.at(aux)->setQuantidade(quantidade);
			}
			else {
				break;
			}
		} while (aux1 != 0);
	}
}

void User::editar(int idUser, std::vector<User*>& users) {
	int aux;
	do {
		std::cout << "0 - Sair" << std::endl;
		std::cout << "1 - Editar login" << std::endl;
		std::cout << "2 - Editar senha" << std::endl;
		std::cout << "3 - Editar email" << std::endl;
		std::cin >> aux;
		if (aux == 1) {
			std::string login;
			std::cout << "Digite o novo login: ";
			std::cin >> login;
			if (login == users.at(idUser)->getLogin()) {
				std::cout << "Login ja existente!" << std::endl;
				continue;
			}
			else {
				users.at(idUser)->setLoginSenha(login, users.at(idUser)->getPassword());
			}
		}
		else if (aux == 2) {
			std::string senha;
			std::cout << "Digite a nova senha: ";
			std::cin >> senha;
			users.at(idUser)->setLoginSenha(users.at(idUser)->getLogin(), senha);
		}
		else if (aux == 3) {
			std::string email;
			std::cout << "Digite o novo email: ";
			std::cin >> email;
			users.at(idUser)->setEmail(email);
		}
		else {
			std::cout << "Opcao invalida!" << std::endl;
		}
	} while (aux != 0);
}
// deletar

void User::deletar(std::vector<Anuncio*>& anuncios, int idUser) {
	int aux;
	mostrar(anuncios, idUser);
	if (anuncios.size() == 0) {
		std::cout << "Voce nao possui anuncios!" << std::endl;
		return;
	}
	else {
		while (true) {
			std::cout << "Digite o id do anuncio que deseja deletar: ";
			std::cin >> aux;
			if (aux < 0 || aux >= anuncios.size()) {
				std::cout << "Anuncio nao encontrado!" << std::endl;
				continue;
			}
			else {
				break;
			}
		}
		anuncios.erase(anuncios.begin() + aux);
		std::cout << "Anuncio deletado com sucesso!" << std::endl;
	}
}

void User::deletar(std::vector<Produto*>& produtos, int idUser) {
	int aux;
	mostrar(produtos, idUser);
	if (produtos.size() == 0) {
		std::cout << "Voce nao possui anuncios!" << std::endl;
		return;
	}
	else {
		while (true) {
			std::cout << "Digite o id do Produto que deseja deletar: ";
			std::cin >> aux;
			if (aux < 0 || aux >= produtos.size()) {
				std::cout << "Produto nao encontrado!" << std::endl;
				continue;
			}
			else {
				break;
			}
		}
		produtos.erase(produtos.begin() + aux);
		std::cout << "Produto deletado com sucesso!" << std::endl;
	}
}

void User::deletar(int a) {
	bool existe = false;
	if (a == 0) {
		existe = mostrar(0);
		if (existe) {
			int aux;
			std::cout << "Digite o id do anuncio que deseja deletar dos favoritos: ";
			std::cin >> aux;
			if (aux < 0 || aux >= favoritos.size()) {
				std::cout << "Anuncio nao encontrado!" << std::endl;
			}
			else {
				favoritos.erase(favoritos.begin() + aux);
				std::cout << "Anuncio deletado dos favoritos!" << std::endl;
			}
		}
	}
	else {
		existe = mostrar(1);
		if (existe) {
			int aux;
			std::cout << "Digite o id do anuncio que deseja deletar do carrinho: ";
			std::cin >> aux;
			if (aux < 0 || aux >= carrinho.size()) {
				std::cout << "Anuncio nao encontrado!" << std::endl;
			}
			else {
				carrinho.erase(carrinho.begin() + aux);
				std::cout << "anuncio deletado do carrinho!" << std::endl;
			}
		}
	}
}