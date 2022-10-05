#include "email.hpp"

Email::Email(int _prioridade, std::string _msg){
    prioridade = _prioridade;
    msg = _msg;
}

Email::~Email(){}
