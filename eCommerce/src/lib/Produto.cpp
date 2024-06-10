#include "Produto.hpp"
#include <iostream>
#include <vector>

Produto::Produto() {};
Produto::~Produto() {};

std::string nome, descricao, categoria, cidade;
float preco;
int quantidade;

void Produto::setNome(std::string _nome) {
	nome = _nome;
};

std::string Produto::getNome() {
	return nome;
};

void Produto::setDescricao(std::string _descricao) {
	descricao = _descricao;
};

std::string Produto::getDescricao() {
	return descricao;
};

void Produto::setPreco(float _preco) {
	preco = _preco;
};

float Produto::getPreco() {
	return preco;
};

void Produto::setQuantidade() {
	quantidade = 1;
};

int Produto::getQuantidade() {
	return quantidade;
};
