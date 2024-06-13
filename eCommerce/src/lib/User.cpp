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

bool User::comprarProduto(int idUser, std::vector<User*>& users, int& contUser, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos) {
	int aux = 0;
	Anuncio anuncio;
	anuncio.verAnuncios(anuncios);
	std::cout << "Digite o id do anuncio que deseja comprar: ";
	std::cin >> aux;
	if (aux < 0 || aux >= anuncios.size()) {
		std::cout << "Anuncio nao encontrado!" << std::endl;
		return false;
	}
	else {
		if (anuncios.at(aux)->getDisponibilidade()) {
			std::cout << "Anuncio ja vendido!" << std::endl;
			return false;
		}
		else {
			std::cout << "Compra realizada com sucesso!" << std::endl;
			anuncios.at(aux)->setDisponibilidade(false);
			return true;
		}
	}
}

void User::mostrarSeusAnuncios(std::vector<Anuncio*>& anuncios, int idUser) {
	for (int i = 0; i < anuncios.size(); i++) {
		if (anuncios.at(i)->getIdVendedor() == idUser) {
			std::cout << "Anuncio " << anuncios.at(i)->getIdAnuncio() << std::endl;
			std::cout << "Nome: " << anuncios.at(i)->getNome() << std::endl;
			std::cout << "Autor: " << anuncios.at(i)->getAutor() << std::endl;
			std::cout << "Preco: " << anuncios.at(i)->getPreco() << std::endl;
			std::cout << "Descricao: " << anuncios.at(i)->getDescricao() << std::endl;
			std::cout << "Disponibilidade: " << anuncios.at(i)->getDisponibilidade() << std::endl;
		}
	}
}

void User::adicionarAnuncio(std::vector<Anuncio*>& anuncios, std::vector<User*>& users, int idUser, std::vector<Produto*>& produtos) {
	int aux = 0;
	std::string nome, autor, descricao;
	float preco;
	bool existe = false;
	for (int i = 0; i < produtos.size(); i++) {
		if (produtos.at(i)->getIdVendedor() == idUser) { //verifica se o usuario possui produtos
			std::cout << "Voce possui produtos para anunciar!" << std::endl;
			existe = true;
			break;
		}
	}
	if (!existe) {
		std::cout << "Voce nao possui produtos para anunciar!" << std::endl;
		std::cout << "Adicione um produto antes de anunciar!" << std::endl;
		//adicionarProduto();       - funcao que nao existe ainda

	}
	else {
		std::cout << "Digite o nome do anuncio: ";
		std::cin >> nome;
		std::cout << "Digite o autor do anuncio: ";
		std::cin >> autor;
		std::cout << "Digite a descricao do anuncio: ";
		std::cin >> descricao;
		std::cout << "Digite o preco: ";
		std::cin >> preco;
		// falta coisa aqui
	}
}