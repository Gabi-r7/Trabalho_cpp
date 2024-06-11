#include "User.hpp"

User::User() {};
User::~User() {};

void User::setEmail(std::string _email) {
	email = _email;
}

std::string User::getEmail() {
	return email;
}

std::string User::getLogin() {
	return login;
}

std::string User::getPassword() {
	return password;
}

int User::getIdUser() {
	return idUser;
}

void User::setAdm(bool _adm) {
	adm = _adm;
}

bool User::getAdm() {
	return adm;
}

void User::setIdUser(int _idUser) {
	idUser = _idUser;
}

void User::setLoginSenha(std::string _login, std::string _senha) {
	login = _login;
	password = _senha;
}
