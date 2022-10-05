#include "caixaentrada.hpp"

caixaEntrada::~caixaEntrada(){
    Email *p;
    p = primeiroEmail->proximoEmail;
    while(p!= NULL){
        primeiroEmail->proximoEmail = p->proximoEmail;
        delete(p);
        p = primeiroEmail->proximoEmail;
    }

    ultimoEmail = primeiroEmail;
    delete(primeiroEmail);
}


std::string caixaEntrada::consultarEmail(int _id){
    std::ostringstream texto;

    if(primeiroEmail== nullptr){
        texto << "CONSULTA " << _id << ": CAIXA DE ENTRADA VAZIA" << std::endl;
        return texto.str();
    }
    
    texto << "CONSULTA " << _id << ": " << primeiroEmail->msg << std::endl;
    
    Email *p;
    p = primeiroEmail;
    primeiroEmail = p->proximoEmail;

    delete p;
    return texto.str();
}

void caixaEntrada::entregarEmail(int _prioridade, std::string _msg){
    if(primeiroEmail == nullptr){
        primeiroEmail = new Email(_prioridade, _msg);
        ultimoEmail = primeiroEmail;
    }
    else{
        Email* novo = new Email(_prioridade, _msg);
        Email* aux = primeiroEmail;
        if(primeiroEmail->prioridade < _prioridade){
            novo->proximoEmail = primeiroEmail;
            primeiroEmail = novo;
            return;
        }
        else if(ultimoEmail->prioridade >= _prioridade){
            ultimoEmail->proximoEmail = novo;
            ultimoEmail = novo;
            return;
        }
        
        while(true){
            if(aux->proximoEmail->prioridade >= _prioridade){
                aux = aux->proximoEmail;
            }
            else{
                novo->proximoEmail = aux->proximoEmail;
                aux->proximoEmail = novo;
                break;
            }
        }
    }
}