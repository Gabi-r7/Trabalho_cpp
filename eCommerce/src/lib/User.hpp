#ifndef USER_HPP
#define USER_HPP

class User {
    public:
        User();
        ~User();


        void setEmail(std::string _email);

        std::string getEmail();

        void setStatus(bool _devedor);

        bool getStatus();

        std::string getLogin();

        std::string getPassword();

        int getIdUser();

        void setAdm(bool _adm);

        bool getAdm();

        void setMulta(float _valorMulta);

        float getMulta();

        void setIdUser(int _idUser);

        void setLoginSenha(std::string _login, std::string _senha);

        void pagarMulta();

    protected:
        std::string email = "a";
        bool devedor = false;
        std::string login = "a";
        std::string password = "a";
        int idUser = 0;
        bool adm;
        float valorMulta = 0.0;
};
#endif