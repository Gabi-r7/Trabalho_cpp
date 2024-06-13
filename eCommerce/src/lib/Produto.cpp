#include "Produto.hpp"
#include <iostream>
#include <vector>

Produto::Produto() {};
Produto::~Produto() {};

void Produto::setNome(std::string _nome) {
	nome = _nome;
};

void Produto::setIdVendedor(int _idVendedor) {
	idVendedor = _idVendedor;
};

void Produto::setPreco(float _preco) {
	preco = _preco;
};

void Produto::setQuantidade(int _quantidade) {
	quantidade = _quantidade;
	if (quantidade == 0) {
		disponibilidade = false;
	}
	else {
		disponibilidade = true;
	}
};

void Produto::setIdProduto(int _idProduto) {
	idProduto = _idProduto;
};

void Produto::setDisponibilidade(bool _disponibilidade) {
	disponibilidade = _disponibilidade;
};

std::string Produto::getNome() {
	return nome;
};

int Produto::getIdVendedor() {
	return idVendedor;
};

float Produto::getPreco() {
	return preco;
};

int Produto::getQuantidade() {
	return quantidade;
};

int Produto::getIdProduto() {
	return idProduto;
};

bool Produto::getDisponibilidade() {
	return disponibilidade;
};

void Produto::setCategoria(std::string _categoria) {
	categoria = _categoria;
};

std::string Produto::getCategoria() {
	return categoria;
};