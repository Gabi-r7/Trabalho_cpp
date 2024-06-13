#ifndef ANUNCIO_HPP
#define ANUNCIO_HPP
#include <vector>
#include <iostream>

class Anuncio {
public:
	Anuncio();
	~Anuncio();
	void verAnuncios(std::vector<Anuncio*> usuarios);

	void setNome(std::string nome);
	void setAutor(std::string autor);
	void setPreco(float preco);
	void setDescricao(std::string descricao);
	void setIdAnuncio(int idAnuncio);
	void setDisponibilidade(bool disponibilidade);
	void setIdUser(int idUser);

	int getIdUser();
	int getIdAnuncio();
	bool getDisponibilidade();
	std::string getNome();
	std::string getAutor();
	float getPreco();
	std::string getDescricao();
	private:
		std::string descricao, autor, nome;
		float preco;
		int idAnuncio, idUser;
		bool disponibilidade;
};
#endif