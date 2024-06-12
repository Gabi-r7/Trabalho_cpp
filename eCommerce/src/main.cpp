#include "lib/InicializaSistema.hpp"
#include "lib/User.hpp"
#include "lib/Logar.hpp"
#include "lib/Cadastrar.hpp"
#include "lib/Acoes.hpp"
#include "lib/Anuncio.hpp"
#include "lib/Produto.hpp"
#include <vector>


int main() {
	std::vector<User*> users;
	std::vector<Anuncio*> anuncios;
	int contUser = 0;
	InicializaSistema::InicializaSistema(users, contUser, anuncios);


	return 0;
};