#include <vector>
#include <iostream>
#include "lib/User.hpp"
#include "lib/InicializaSistema.hpp"
#include "lib/Admin.hpp"
#include "lib/Anuncio.hpp"
#include "lib/Produto.hpp"


int main(){
	std::vector<User*> users;
	std::vector<Anuncio*> anuncios;
	std::vector<Produto*> produtos;
	int contUser = 0;
	InicializaSistema::InicializaSistema(users, contUser, anuncios, produtos);
	


	return 0;
}
