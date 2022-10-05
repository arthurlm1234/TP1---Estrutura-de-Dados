#ifndef CAIXA_H
#define CAIXA_H

#include "email.hpp"

class caixaEntrada{
private:
    
    Email* primeiroEmail = nullptr;
    Email* ultimoEmail = nullptr;

public:

    ~caixaEntrada();
    std::string consultarEmail(int _id);
    void entregarEmail(int _prioridade, std::string _msg);
};

#endif