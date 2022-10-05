#include "listausuarios.hpp"
#include "msgassert.hpp"
#include "memlog.hpp"

int main(int argc, char **argv){

    
    
    iniciaMemLog("log.out");
    
    listaUsuarios* lista = new listaUsuarios();

    erroAssert(argv[1], "É necessário o nome de arquivo de entrada.");
    erroAssert(argv[2], "É necessário o nome de arquivo de saída.");
    
    std::ifstream entrada(argv[1]);
    std::ofstream saida(argv[2]);

    erroAssert(entrada.is_open(), "Entrada inválida.");

    std::string comando, msg, palavra;
    int id, prioridade;
    while(!entrada.eof()){
        entrada >> comando;
        if(comando == "CONSULTA"){
            entrada >> id;
            erroAssert(id >= 0 && id <= MAX,"ID fora do intervalo válido.");
            saida << lista->mostraMsg(id);
            comando = "";
        }

        else if(comando == "REMOVE"){
            entrada >> id;
            erroAssert(id >= 0 && id <= MAX,"ID fora do intervalo válido.");
            saida << lista->removeUsuario(id);
            comando = "";
        }

        else if(comando == "ENTREGA"){
            entrada >> id;
            erroAssert(id >= 0 && id <= MAX,"ID fora do intervalo válido.");
            entrada >> prioridade;
            erroAssert(prioridade >= 0 && prioridade <= 9,"Prioridade fora do intervalo válido.");
            while(true){
                entrada >> palavra;
                if(palavra == "FIM"){
                    break;
                }
                msg += palavra + " ";
            }
            saida << lista->selecionaRecebedor(id,prioridade,msg);
            msg = "";
            comando = "";
        }
        else if(comando == "CADASTRA"){
            entrada >> id;
            erroAssert(id >= 0 && id <= MAX,"ID fora do intervalo válido.");
            saida << lista->cadastraUsuario(id);
            comando = "";
        }
    }

    finalizaMemLog();

    return 0;
}