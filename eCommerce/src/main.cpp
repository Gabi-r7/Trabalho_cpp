#include "lib/InicializaSistema.hpp"
#include "lib/User.hpp"
#include "lib/Logar.hpp"
#include "lib/Cadastrar.hpp"
#include "lib/Acoes.hpp"
#include <vector>


int main() {
	std::vector<User*> users;
	int contUser = 0;
	InicializaSistema::InicializaSistema(users, contUser);


	return 0;
};