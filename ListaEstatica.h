#ifndef LISTA_ESTATICA_H_INCLUDED
#define LISTA_ESTATICA_H_INCLUDED
#include <time.h>

using namespace std;
#define MAX_ELEMENTOS 100 // define o max de elementos na lista/ tamanho do vetor

class Lista
{ // criaçaõ da classe lista

public:
    unsigned tamanho; // declaração de variaveis
    int inteiros[MAX_ELEMENTOS];
    //int contadorAcessos = 0;

    Lista()
    {
        tamanho = 0; // construtor da lista
    }

    ~Lista()
    { // destrutor
    }

    void imprime()
    { // imprime os elementos da lista

        for (unsigned u = 0; u < tamanho; u++)
            cout << inteiros[u] << endl;

        cout << "\n"
             << endl;
    }

    void insere(unsigned posicao, int inteiro)
    {

        // verifica se a posicao solicitada é inválida (maior que a lista)
        if (posicao > tamanho)
        {
            cout << "posicao invalida" << endl;
            return;
        }

        // verifica se a lista está cheia
        if (MAX_ELEMENTOS == tamanho)
        {
            cout << "lista cheia" << endl;
            return;
        }

        // desloca todos os inteiros, a partir da posicao, uma posicao a diante

        for (int i = tamanho; i > posicao; i--)
        {
            inteiros[i] = inteiros[i - 1];
        }

        // inserindo novo valor
        inteiros[posicao] = inteiro;
        tamanho++;
    }

    void merge(int inicio, int meio, int fim,int &contadorAcessos){
        
        int aux, cont = 0;
        while (cont < fim){                                      
            for (int i = inicio; i < meio - cont; i++){         //1 5 8 12    70 72 99
                contadorAcessos = contadorAcessos + 2;         

                if (inteiros[meio - cont] < inteiros[i]){
                    aux = inteiros[meio - cont];
                    inteiros[meio - cont] = inteiros[i];
                    inteiros[i] = aux;
                    contadorAcessos = contadorAcessos + 4;
                }
            }
            for (int j = meio; j <= fim - cont; j++){
                contadorAcessos = contadorAcessos + 2;

                if (inteiros[fim - cont] < inteiros[j]){
                    aux = inteiros[fim - cont];
                    inteiros[fim - cont] = inteiros[j];
                    inteiros[j] = aux;
                    contadorAcessos = contadorAcessos + 4;
                }
            }
            cont++;
        }
        cont = 0;

        for (int k = inicio; k < meio; k++){
            for (int y = meio; y <= fim; y++){                  
                contadorAcessos = contadorAcessos + 2;

                if (inteiros[k] > inteiros[y]){
                    aux = inteiros[k];
                    inteiros[k] = inteiros[y];
                    inteiros[y] = aux;
                    contadorAcessos = contadorAcessos + 4;
                }
            }
        }
        while (cont < fim){
            for (int j = meio; j <= fim - cont; j++){
                contadorAcessos = contadorAcessos + 2;

                if (inteiros[fim - cont] < inteiros[j]){
                    aux = inteiros[fim - cont];
                    inteiros[fim - cont] = inteiros[j];
                    inteiros[j] = aux;
                    contadorAcessos = contadorAcessos + 4;
                }
            }
            cont++;
        }
    }
    void mergeSort(bool etapas,int &contadorAcessos){
        
        mergeSort(etapas,0,tamanho-1,contadorAcessos);
    }
    // novo mergesort //int & contador na mergeSort atual
    void mergeSort(bool etapas, int inicio, int fim, int &contadorAcessos) {

        if (fim - inicio > 1)
        {
            int meio = (inicio + fim) / 2;

            mergeSort(etapas, inicio, meio,contadorAcessos);
            mergeSort(etapas, meio, fim,contadorAcessos);
            merge(inicio, meio, fim,contadorAcessos);
            if (etapas)
            {
                imprime();
            }
        }
    }

    void geraLista(int tam)
    {
        // recebe o tamanho da lista
        int numero;
        srand(time(NULL)); // define a semente como null(cada lista tera valores independentes das listas passadas)
        for (unsigned j = 0; j <= tam; j++)
        { // gera os elemen-tos para a lista de acordo com o tamanho da lista com valores aleatorios entre 1 e 1000
            numero = rand() % 1000 + 1;
            insere(j, numero); // insere os elementos na lista
        }
    }

    void deletaLista()
    { // deleta todos os elementos da lista
        tamanho = 0;
    }
};

#endif