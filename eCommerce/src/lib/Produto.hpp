#ifndef PRODUTO_HPP
#define PRODUTO_HPP

class Produto {
public:
	Produto();
	~Produto();

	void setNome(std::string _nome);
	std::string getNome();

	void setDescricao(std::string _descricao);
	std::string getDescricao();

	void setPreco(float _preco);
	float getPreco();

	void setQuantidade();
	int getQuantidade();


};
#endif