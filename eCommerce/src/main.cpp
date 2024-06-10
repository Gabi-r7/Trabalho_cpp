#include <vector>
#include <iostream>
#include "lib/User.hpp"
#include "lib/InicializaSistema.hpp"
#include "lib/Admin.hpp"
#include "lib/Anuncio.hpp"


int main(){
	std::vector<User*> users;
	std::vector<Admin*> admins;
	std::vector<Anuncio*> anuncios;
	std::vector<Produto*> produtos;
	InicilizaSistema::inicializaSistema(users, admins, anuncios, produtos);
	
}
