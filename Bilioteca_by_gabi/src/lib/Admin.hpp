#ifndef ADMIN_HPP
#define ADMIN_HPP
#include <vector>

class Admin : public User {
public:
    Admin();
    ~Admin();


    void MostrarUsuarios(std::vector<User*>& users);

    void CadastrarLivro(std::vector<Livro*>& livros, int &contLivro);

    void ApagarLivro(std::vector<Livro*>& livros, int &contLivro);

    bool ModificarStatusUser(int idUser, std::vector<User*>& users);
    
    void CadastrarUser(std::vector<User*>& users, int &contUser);

    void ApagarUser(int id, std::vector<User*>& users);

    void AplicarMulta(std::vector<User*>& users);
};
#endif