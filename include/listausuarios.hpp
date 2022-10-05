#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H

#define MAX 1000000

#include "usuario.hpp"

class listaUsuarios{

private:
    
    Usuario* primeiroUsuario = nullptr;
    Usuario* ultimoUsuario = nullptr;

public:
    
    ~listaUsuarios();
    std::string cadastraUsuario(int _id);
    std::string removeUsuario(int _id);
    std::string selecionaRecebedor(int _id, int prioridade, std::string msg);
    std::string mostraMsg(int _id);
};

#endif