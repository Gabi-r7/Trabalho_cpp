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
	void setIdProduto(int idProduto);
	void setDisponibilidade(bool disponibilidade);
	void setCategoria(std::string categoria);

	std::string getCategoria();
	std::string getNome();
	int getIdVendedor();
	float getPreco();
	int getQuantidade();
	int getIdProduto();
	bool getDisponibilidade();


	private:
		float preco;
		std::string nome, categoria;
		int quantidade, idProduto, idVendedor;
		bool disponibilidade;
};
#endif