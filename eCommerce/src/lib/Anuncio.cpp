#include "Anuncio.hpp"
#include <iostream>
#include <vector>

Anuncio::Anuncio() {};
Anuncio::~Anuncio() {};
std::string titulo, descricao, telefone, categoria, cidade;
float preco;

void Anuncio::setTitulo(std::string _titulo) {
	titulo = _titulo;
};

std::string Anuncio::getTitulo() {
	return titulo;
};

void Anuncio::setDescricao(std::string _descricao) {
	descricao = _descricao;
};

std::string Anuncio::getDescricao() {
	return descricao;
};

void Anuncio::setPreco(float _preco) {
	preco = _preco;
};

float Anuncio::getPreco() {
	return preco;
};

void Anuncio::setTelefone(std::string _telefone) {
	telefone = _telefone;
};

std::string Anuncio::getTelefone() {
	return telefone;
};

void Anuncio::setCategoria(std::string _categoria) {
	categoria = _categoria;
};

std::string Anuncio::getCategoria() {
	return categoria;
};

void Anuncio::setCidade(std::string _cidade) {
	cidade = _cidade;
};

std::string Anuncio::getCidade() {
	return cidade;
};
