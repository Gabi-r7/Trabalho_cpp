#ifndef ANUNCIO_HPP
#define ANUNCIO_HPP
#include <vector>
#include <iostream>
#include "Produto.hpp"

class Anuncio {
public:
	Anuncio();
	~Anuncio();
	int verAnuncios(std::vector<Anuncio*>& usuarios, std::vector<Produto*>& produtos);

	void setNome(std::string nome);
	void setAutor(std::string autor);
	void setPreco(float preco);
	void setDescricao(std::string descricao);
	void setIdAnuncio(int idAnuncio);
	void setDisponibilidade(bool disponibilidade);
	void setIdVendedor(int idVendedor);
	void setIdProduto(int idProduto);

	int getIdProduto();
	int getIdVendedor();
	int getIdAnuncio();
	bool getDisponibilidade();
	std::string getNome();
	std::string getAutor();
	float getPreco();
	std::string getDescricao();
	private:
		std::string descricao, autor, nome;
		float preco;
		int idAnuncio, idProduto, idVendedor;
		bool disponibilidade;
};
#endif