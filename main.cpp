#include <stdio.h>
#include <iostream>

#include "Lista.cpp"

using namespace std;

int main() {

    int menu = 0;
    int numero, posNum;
    char opcao;
    ListaEncadeada* lista = new ListaEncadeada();

    // Adicionando elementos à lista para realizar testes
    do {
        cout << "Adicione um número à lista: ";
        cin >> numero;
        cout << "Deseja adicionar mais números? [S/N]: ";
        cin >> opcao;

        if (!lista->insereFimLista(numero)) {
            cout << "Erro ao adicionar o número!" << endl;
        }

        if (opcao == 'N' || opcao == 'n') {
            break;
        }

    } while (true);

    do {
        cout << "\nMENU DE OPERAÇÕES\n";
        cout << "1. Verificar se a lista está vazia\n";
        cout << "2. Obter o tamanho da lista\n";
        cout << "3. Obter/modificar o valor do elemento de uma posição\n";
        cout << "4. Inserir um elemento em uma determinada posição\n";
        cout << "5. Retirar um elemento de uma determinada posição\n";
        cout << "6. Imprimir os elementos de toda a lista\n";
        cout << "0. Finalizar programa\n";
        cout << "\nSelecione uma opção: ";
        cin >> menu;

        if (menu == 1) {
            if (lista->vazia()) {
                cout << "A lista está vazia!" << endl;
            } else {
                cout << "A lista não está vazia!" << endl;
            }
        }
        
        else if (menu == 2) {
            cout << "O tamanho da lista é: " << lista->tamanho << endl;
        }
        
        else if (menu == 3) {
            cout << "Digite a posição do valor que deseja obter: ";
            cin >> posNum;
            if (lista->obterValorPosicao(posNum) == -1) {
                cout << "Posição inválida!" << endl;
            } else {
                cout << "Valor na posição " << posNum << ": " << lista->obterValorPosicao(posNum) << endl;
            }
        }
        
        else if (menu == 4) {
            int novoValor;
            cout << "Digite a posição para inserir o valor: ";
            cin >> posNum;
            cout << "Digite o novo valor: ";
            cin >> novoValor;
            if (lista->insere(posNum, novoValor)) {
                cout << "Valor inserido com sucesso!" << endl;
            } else {
                cout << "Erro ao inserir valor!" << endl;
            }
        }
        
        else if (menu == 5) {
            cout << "Digite a posição do valor a remover: ";
            cin >> posNum;
            if (lista->remove(posNum) != -1) {
                cout << "Valor removido com sucesso!" << endl;
            } else {
                cout << "Erro ao remover valor!" << endl;
            }
        }

        else if (menu == 6) {
            lista->exibirValores();
        }

    } while (menu != 0);

    return 0;

}