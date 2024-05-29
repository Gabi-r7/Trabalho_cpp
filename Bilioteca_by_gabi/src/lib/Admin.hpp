#ifndef ADMIN_HPP
#define ADMIN_HPP
#include <vector>

class Admin : public User {
public:
    Admin();
    ~Admin();

    void CadastrarLivro(std::vector<Livro*>& livros);

    void ApagarLivro(std::vector<Livro*>& livros);

    bool ModificarStatusUser(int idUser,std::vector<User*>& users);
    
    void CadastrarUser(std::vector<User*>& users);

    void ApagarUser(std::vector<User*>& users);

    void AplicarMulta(std::vector<User*>& users);
};
#endif