#include "User.hpp"
#include <vector>
#include <iostream>
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

void User::mostrarSeusItens(std::vector<Anuncio*>& anuncios, int idUser) {
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

void User::adicionarItens(std::vector<Anuncio*>& anuncios, int &contAnuncio, std::vector<User*>& users, int idUser, std::vector<Produto*>& produtos) {
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
			adicionarItens(produtos, contAnuncio, idUser);
			adicionarItens(anuncios, contAnuncio, users, idUser, produtos);
		}
		else {
			return;
		}
	}
	else {
		mostrarSeusItens(produtos, idUser);
		while (true) {
			std::cout << "Digite o id do produto que deseja anunciar: ";
			std::cin >> aux1;
			if (aux1 < 0 || aux1 >= produtos.size()) {
				std::cout << "Produto nao encontrado!" << std::endl;
				continue;
			}
			else {
				break;
			}
		}
		std::cout << "Digite o nome do anuncio: ";
		std::cin >> nome;
		std::cout << "Digite a descricao do anuncio: ";
		std::cin >> descricao;
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

void User::deletarItens(std::vector<Anuncio*>& anuncios, int idUser) {
	int aux;
	mostrarSeusItens(anuncios, idUser);
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

void User::deletarItens(std::vector<Produto*>& produtos, int idUser) {
	int aux;
	mostrarSeusItens(produtos, idUser);
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

void User::adicionarItens(std::vector<Produto*>& produtos, int &contProduto, int idUser) {
	std::string nome, categoria;
	float preco;
	int quantidade;
	while (true) {
		std::cout << "Digite o nome do produto: ";
		std::cin >> nome;
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

void User::mostrarSeusItens(std::vector<Produto*>& produtos, int idUser) {
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

void User::editarItens(std::vector<Produto*>& produtos, int idUser) {
	int aux;
	mostrarSeusItens(produtos, idUser);
	std::cout << "Digite o id do produto que deseja editar: ";
	std::cin >> aux;
	do {
		std::cout << "0 - Sair" << std::endl;
		std::cout << "1 - Editar nome" << std::endl;
		std::cout << "2 - Editar categoria" << std::endl;
		std::cout << "3 - Editar preco" << std::endl;
		std::cout << "4 - Editar quantidade" << std::endl;
		std::cin >> aux;
		if (aux == 1) {
			std::string nome;
			std::cout << "Digite o novo nome: ";
			std::cin >> nome;
			produtos.at(aux)->setNome(nome);
		}
		else if (aux == 2) {
			std::string categoria;
			std::cout << "Digite a nova categoria: ";
			std::cin >> categoria;
			produtos.at(aux)->setCategoria(categoria);
		}
		else if (aux == 3) {
			float preco;
			std::cout << "Digite o novo preco: ";
			std::cin >> preco;
			produtos.at(aux)->setPreco(preco);
		}
		else if (aux == 4) {
			int quantidade;
			std::cout << "Digite a nova quantidade: ";
			std::cin >> quantidade;
			produtos.at(aux)->setQuantidade(quantidade);
		}
		else {
			break;
		}
	} while (aux != 0);
}

void User::editarItens(std::vector<Anuncio*>& anuncios, int idUser) {
	int aux;
	mostrarSeusItens(anuncios, idUser);
	std::cout << "Digite o id do anuncio que deseja editar: ";
	std::cin >> aux;
	do {
		std::cout << "0 - Sair" << std::endl;
		std::cout << "1 - Editar autor" << std::endl;
		std::cout << "2 - Editar preco" << std::endl;
		std::cout << "3 - Editar descricao" << std::endl;
		std::cin >> aux;
		if (aux == 1) {
			std::string autor;
			std::cout << "Digite o novo autor: ";
			std::cin >> autor;
			anuncios.at(aux)->setAutor(autor);
		}
		else if (aux == 2) {
			float preco;
			std::cout << "Digite o novo preco: ";
			std::cin >> preco;
			anuncios.at(aux)->setPreco(preco);
		}
		else if (aux == 3) {
			std::string descricao;
			std::cout << "Digite a nova descricao: ";
			std::cin >> descricao;
			anuncios.at(aux)->setDescricao(descricao);
		}
		else {
			break;
		}
	} while (aux != 0);
}