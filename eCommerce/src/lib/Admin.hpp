#ifndef ADMIN_HPP
#define ADMIN_HPP
#include <vector>

class Admin : public User {
	public:
		Admin();
		~Admin();

		bool apagarUser(std::vector<User*>& users);
		bool cadastrarUser(std::vector<User*>& users);
		bool apagarAnuncio(std::vector<Anuncio*>& anuncios);

};
#endif