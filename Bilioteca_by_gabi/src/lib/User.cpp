#include <iostream>
#include <vector>
#include "User.hpp"


User::User() {};
User::~User() {};
std::string login;
int idUser;

void User::setEmail(std::string _email) {
    email = _email;
};

std::string User::getEmail() {
    return email;
};

void User::setStatus(bool _devedor) {
    devedor = _devedor;
};


bool User::getStatus() {
    return devedor;
};

std::string User::getLogin() {
    return login;
};

std::string User::getPassword() {
    return password;
};

int User::getIdUser() {
    return idUser;
};

void User::setAdm(bool _adm) {
    adm = _adm;
};

bool User::getAdm() {
    return adm;
};

void User::setMulta(float _valorMulta) {
    valorMulta = _valorMulta;
};

float User::getMulta() {
    return valorMulta;
};

void User::setIdUser(int _idUser) {
    idUser = _idUser;
};

void User::setLoginSenha(std::string _login, std::string _senha) {
    login = _login;
    password = _senha;
};

void User::pagarMulta() {
    if (getMulta() == 0) {
        std::cout << "Voce nao possui multa!" << std::endl;
        return;
    }
    else {
        std::cout << "Voce pagou a multa de R$" << getMulta() << " com sucesso!" << std::endl;
        setMulta(0);
    }
};