#ifndef ANUNCIO_HPP
#define ANUNCIO_HPP
#include <iostream>
#include <vector>

class Anuncio {
public:
	Anuncio();
	~Anuncio();

	void setTitulo(std::string _titulo);
	std::string getTitulo();

	void setDescricao(std::string _descricao);
	std::string getDescricao();

	void setPreco(float _preco);
	float getPreco();

	void setTelefone(std::string _telefone);
	std::string getTelefone();

	void setCategoria(std::string _categoria);
	std::string getCategoria();

	void setCidade(std::string _cidade);
	std::string getCidade();
};
#endif