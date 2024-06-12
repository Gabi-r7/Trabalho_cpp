#ifndef PRODUTO_HPP
#define PRODUTO_HPP
#include <vector>
#include <iostream>


class Produto {
public:
	Produto();
	~Produto();

	void setNome(std::string nome);
	void setIdVendedor(int idVendedor);
	void setPreco(float preco);
	void setQuantidade(int quantidade);
	void setIdAnuncio(int idAnuncio);
	void setDisponibilidade(bool disponibilidade);

	std::string getNome();
	int getIdVendedor();
	float getPreco();
	int getQuantidade();
	int getIdAnuncio();
	bool getDisponibilidade();


	private:
		float preco;
		std::string nome;
		int quantidade, idAnuncio, idVendedor;
		bool disponibilidade;
};
#endif