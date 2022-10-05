#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include <sstream>
#include <fstream>

class Email{

private:

    int prioridade;
    std::string msg;
    Email* proximoEmail = nullptr;

public:

    Email(int _prioridade, std::string _msg);
    ~Email();
    
    friend class caixaEntrada;
};

#endif