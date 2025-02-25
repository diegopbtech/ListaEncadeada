#include <stdio.h>
#include <iostream>

#include "No.cpp"

using namespace std;

class ListaEncadeada {
    public:

        No* cabeca;
        int tamanho;

        // 1. Criação da lista vazia
        ListaEncadeada() {
            cabeca = nullptr;
            tamanho = 0;
        }

        // 2. Verificar se a lista está vazia
        bool vazia(){
            if(tamanho == 0){
                return true;
            }else{
                return false;
            }
        }

        // 3. Obter o tamanho da lista
        int getTamanho(){
            return tamanho;
        }

        // 4. Obter/modificar o valor do elemento de uma determinada posição na lista
        int obterValorPosicao(int pos) {
            int cont = 1;
            No* aux;

            if (vazia() || pos < 1 || pos > tamanho) return -1;  // Verificar se a posição é válida

            aux = cabeca;

            // Percorrer até a posição desejada
            while (cont < pos) {
                aux = aux->getProximo();
                cont++;
            }

            return aux->getConteudo();  // Retornar o valor (conteúdo) do nó
        }


        // 5. Inserir um elemento em uma determinada posição
        bool insere(int pos, int dado) {
            if (vazia() && pos != 1){
                return false;
            }
            if (pos == 1) {
                return insereInicioLista(dado);
            } else if (pos == tamanho + 1) {
                return insereFimLista(dado);
            } else {
                return insereMeioLista(pos, dado);
            }
        }

        bool insereMeioLista(int pos, int dado) {
            if (pos > tamanho || pos < 1){
                return false;
            }
    
            No* aux = cabeca;
            int cont = 1;
    
            while (cont < pos - 1) {
                aux = aux->getProximo();
                cont++;
            }
    
            No* novo = new No();
            novo->setConteudo(dado);
            novo->setProximo(aux->getProximo());
            aux->setProximo(novo);
    
            tamanho++;
            return true;
        }

        bool insereFimLista(int dado) {
            No* novo = new No();
            novo->setConteudo(dado);
            novo->setProximo(nullptr);
    
            if (vazia()) {
                cabeca = novo;
            } else {
                No* aux = cabeca;
                while (aux->getProximo() != nullptr) {
                    aux = aux->getProximo();
                }
                aux->setProximo(novo);
            }
    
            tamanho++;
            return true;
        }

        bool insereInicioLista(int dado) {
            No* novo = new No();
            novo->setConteudo(dado);
            novo->setProximo(cabeca);
            cabeca = novo;
            tamanho++;
            return true;
        }

        // 6. Retirar um elemento de uma determinada posição
        int remove(int pos) {
            if (vazia()) return -1;
            if (pos == 1) {
                return removeInicioLista();
            } else {
                return removeNaLista(pos);
            }
        }

        int removeInicioLista() {
            if (vazia()) return -1;
    
            No* temp = cabeca;
            cabeca = cabeca->getProximo();
            delete temp; 
            tamanho--;
            return 0; 
        }

        int removeNaLista(int pos) {
            if (pos > tamanho || pos < 1) return -1;
    
            No* aux = cabeca;
    
            if (pos == 1) {
                return removeInicioLista();
            }
    
            int cont = 1;
            while (cont < pos - 1) {
                aux = aux->getProximo();
                cont++;
            }
    
            No* temp = aux->getProximo();
            aux->setProximo(temp->getProximo());
            delete temp;
            tamanho--;
            return 0;
        }

        // 7. Imprimir os elementos de toda a lista.
        void exibirValores() {
            if (vazia()) {
                cout << "A lista está vazia!" << endl;
                return;
            }
        
            No* aux = cabeca;
            
            while (aux != nullptr) {
                cout << aux->getConteudo() << " ";
                aux = aux->getProximo();
                cout << endl;
            }
        
        }
        

};
