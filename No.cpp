#include <stdio.h>
#include <iostream>

using namespace std;

class No {
    private:

        int conteudo;
        No* proximo;

    public:
        No() {
            proximo = nullptr;
        }

        int getConteudo(){
            return conteudo;
        }

        void setConteudo(int cont){
            this->conteudo = cont;
        }

        No* getProximo() {
            return proximo;
        }

        void setProximo(No* proximo) {
            this->proximo = proximo;
        }
};
