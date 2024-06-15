#include "Anuncio.hpp"
#include <iostream>
#include <vector>

Anuncio::Anuncio() {};
Anuncio::~Anuncio() {};

void Anuncio::setIdAnuncio(int _id) {
	idAnuncio = _id;
};

int Anuncio::getIdAnuncio() {
	return idAnuncio;
};

void Anuncio::setNome(std::string _nome) {
	nome = _nome;
};

std::string Anuncio::getNome() {
	return nome;
};

void Anuncio::setAutor(std::string _autor) {
	autor = _autor;
};

std::string Anuncio::getAutor() {
	return autor;
};

void Anuncio::setPreco(float _preco) {
	preco = _preco;
};

float Anuncio::getPreco() {
	return preco;
};

void Anuncio::setDescricao(std::string _descricao) {
	descricao = _descricao;
};

std::string Anuncio::getDescricao() {
	return descricao;
};

void Anuncio::setDisponibilidade(bool _disponibilidade) {
	disponibilidade = _disponibilidade;
};

bool Anuncio::getDisponibilidade() {
	return disponibilidade;
};

void Anuncio::setIdVendedor(int _idVendedor) {
	idVendedor = _idVendedor;
};

int Anuncio::getIdVendedor() {
	return idVendedor;
};

void Anuncio::setIdProduto(int _idProduto) {
	idProduto = _idProduto;
};

int Anuncio::getIdProduto() {
	return idProduto;
};

int Anuncio::verAnuncios(std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos) {
	int totalDisp = 0;
	for (int i = 0; i < anuncios.size(); i++) {
		if (anuncios.at(i)->getDisponibilidade()) {
			std::cout << "Anuncio " << anuncios.at(i)->getIdAnuncio() << std::endl;
			std::cout << "Nome: " << anuncios.at(i)->getNome() << std::endl;
			std::cout << "Categoria: " << produtos.at(anuncios.at(i)->getIdProduto())->getCategoria() << std::endl;
			std::cout << "Descricao: " << anuncios.at(i)->getDescricao() << std::endl;
			std::cout << "Autor: " << anuncios.at(i)->getAutor() << std::endl;
			std::cout << "Quantidade disponivel: " << produtos.at(anuncios.at(i)->getIdProduto())->getQuantidade() << std::endl;
			std::cout << "Preco: " << anuncios.at(i)->getPreco() << std::endl;
			totalDisp++;
		}
	}
	std::cout << "Anuncios Disponiveis: " << totalDisp << std::endl;
	return totalDisp;
};