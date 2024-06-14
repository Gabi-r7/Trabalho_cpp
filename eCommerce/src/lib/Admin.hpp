#ifndef ADMIN_HPP
#define ADMIN_HPP
#include <vector>
#include "User.hpp"

class Admin : public User {
public:
	Admin();
	~Admin();
	void setAdm(bool _adm);
	bool getAdm();

	void verUsuarios(std::vector<User*>& users);

	void banirUsuario(int idUser, std::vector<User*>& users);
	void desbanirUsuario(int idUser, std::vector<User*>& users);
	void apagarAnuncio(int idUser, std::vector<Anuncio*>& anuncios, std::vector<Produto*>& produtos);
};
#endif