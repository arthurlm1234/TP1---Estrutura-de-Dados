#include "usuario.hpp"

Usuario::Usuario(int _id){
    id = _id;
    caixaUsuario = new caixaEntrada();
}

Usuario::~Usuario(){}