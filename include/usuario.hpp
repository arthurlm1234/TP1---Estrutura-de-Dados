#ifndef USUARIO_H
#define USUARIO_H

#include "caixaentrada.hpp"

class Usuario{
private:
    int id;
    Usuario* proximoUsuario;

public:
    Usuario(int _id);
    ~Usuario();
    caixaEntrada* caixaUsuario;
    
    friend class listaUsuarios;
};

#endif