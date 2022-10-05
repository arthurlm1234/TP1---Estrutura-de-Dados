#include "listausuarios.hpp"

listaUsuarios::~listaUsuarios(){
    Usuario *p;
    p = primeiroUsuario->proximoUsuario;
    while(p!= NULL){
        primeiroUsuario->proximoUsuario = p->proximoUsuario;
        delete(p);
        p = primeiroUsuario->proximoUsuario;
    }

    ultimoUsuario = primeiroUsuario;
    delete(primeiroUsuario);
}


std::string listaUsuarios::cadastraUsuario(int _id){
    std::ostringstream texto;

    Usuario* novo = new Usuario(_id);

    if(primeiroUsuario == nullptr){
        primeiroUsuario = novo;
        ultimoUsuario = novo;
        texto << "OK: CONTA " << _id << " CADASTRADA" << std::endl;
        return texto.str();
    }
    
    Usuario* aux = primeiroUsuario;
    
    while(aux != nullptr){
        if(aux->id == _id){
            texto << "ERRO: CONTA " << _id << " JÁ EXISTENTE" << std::endl;
            return texto.str();
        }
        aux = aux->proximoUsuario;
    }


    ultimoUsuario->proximoUsuario = novo;
    ultimoUsuario = novo;
    texto << "OK: CONTA " << _id << " CADASTRADA" << std::endl;
    return texto.str();
}

std::string listaUsuarios::removeUsuario(int _id){
    std::ostringstream texto;
    
    if(primeiroUsuario == nullptr){
        texto << "FILA VAZIA!" <<std::endl;
        return texto.str();
    }

    if(primeiroUsuario->id == _id){
        
        Usuario *p;
        p = primeiroUsuario;
        primeiroUsuario = p->proximoUsuario;

        delete p;

        texto << "OK: CONTA " << _id << " REMOVIDA" << std::endl;
        return texto.str();
    }

    if(ultimoUsuario->id == _id){
        Usuario* p = primeiroUsuario;

        while(true){
            if(p->proximoUsuario==ultimoUsuario){
                break;
            }
            p = p->proximoUsuario;
        }

        p->proximoUsuario = nullptr;
        delete ultimoUsuario;
        ultimoUsuario = p;

        texto << "OK: CONTA " << _id << " REMOVIDA" << std::endl;
        return texto.str();
    }

    else{
        Usuario* p = primeiroUsuario;

        while(true){
            if(p == ultimoUsuario){
                std::cout << "ERRO: CONTA " << _id << " NAO EXISTE" << std::endl;
                return texto.str();
            }
            else if(p->proximoUsuario->id == _id){
                break;
            }
            p = p->proximoUsuario;
        }

        Usuario* aux = p->proximoUsuario;
        p->proximoUsuario = aux->proximoUsuario;
        delete aux;

        if(p->proximoUsuario == nullptr){
            ultimoUsuario = p;
        }

        texto << "OK: CONTA " << _id << " REMOVIDA" << std::endl;
        return texto.str();
    }

}

std::string listaUsuarios::selecionaRecebedor(int _id, int prioridade, std::string msg){
    std::ostringstream texto;
    Usuario *aux = primeiroUsuario;

    while(true){
        if(aux==ultimoUsuario && ultimoUsuario->id != _id){
            texto << "ERRO: CONTA " << _id << " NAO EXISTE" << std::endl;
            return texto.str();
        }

        if(aux->id == _id){
            aux->caixaUsuario->entregarEmail(prioridade, msg);
            texto << "OK: MENSAGEM PARA " << _id << " ENTREGUE" << std::endl;
            return texto.str();
        }
        aux = aux->proximoUsuario;
    }
}

std::string listaUsuarios::mostraMsg(int _id){
    std::ostringstream texto;
    
    if(primeiroUsuario==nullptr){
        texto << "ERRO: CONTA " << _id << " NAO EXISTE" << std::endl;
        return texto.str(); 
    }
    
    Usuario *aux = primeiroUsuario;
    while(true){
        if(aux==ultimoUsuario && ultimoUsuario->id != _id){
            texto << "ERRO: CONTA " << _id << " NAO EXISTE" << std::endl;
            return texto.str(); 
        }

        if(aux->id == _id){
            return aux->caixaUsuario->consultarEmail(_id);
        }

        aux = aux->proximoUsuario;
    }
}