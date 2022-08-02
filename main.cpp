 
#include <iostream>
#include "ListaEstatica.h"
#include <stdlib.h>
#include <fstream>

/*Link video YouTube:
https://youtu.be/1nHSInavkp0*/

using namespace std;
#define MAX_VETOR 100 // define o tamanho maximo do vetor
#define TAM_TESTE 20
int main()
{   //int valor[TAM_TESTE]={70,1,12,8,99,72,5};
    //int valor[TAM_TESTE]={70,2,4,1,10}; 
    int valor[TAM_TESTE] = {70, 1, 12, 8, 99, 72, 5, 15, 20, 91, 14, 61, 66, 41, 81, 88, 16, 21, 34, 90};   //declaraçao do vetor p/ etapa 1                                                                                   
    Lista Lista1;                                                         // declaracao das listas                                        
    Lista Lista2;
    int acessosEtapa1 = 0, acessosEtapa2 = 0, acessosUnitariosEtapa2 = 0,tam = 0, etapa; // variaveis para contar os acessos
    ofstream arquivo; // criaçao de um arquivo para armazenar a quantidade de acessos a memoria de cada lista gerada(etapa 2)

    do
    { // loop para repetição das etapas
        cout << "\nDigite:\n1 - Etapa 1\n2 - etapa 2 \n3 - parar\n"
             << endl;
        cin >> etapa; // recebe o valor para execução das etapas 1 e 2 ou cancelar
        cout << "\n"
             << endl;

        if (etapa == 1)
        {
            for (unsigned i = 0; i < TAM_TESTE; i++)
            {
                Lista1.insere(i, valor[i]); // invoca o metodo insere da lista para inserir os valores do vetor
               
            }
            
            Lista1.imprime();                        // invoca o metodo imprime para imprimir os elementos da lista
            Lista1.mergeSort(true,acessosEtapa1); // recebe o retorno do metodo bubble sort que ira forncer o numero
                                                     // de acessos a memoria e fara a ordenaçao da lista
            cout << "\n"
                 << "Total de Acessos=" << acessosEtapa1 << endl; // imprime o numero de acessos
            
          //teste // Lista1.imprime();
            Lista1.deletaLista(); // deleção da lista e zera os acessos obtidos
            acessosEtapa1 = 0;    //(caso rode novamente o loop a lista e a variavel de contagem de acessos necessitam
                                  // estar vazias)
        
        }
        else if (etapa == 2)
        {
            arquivo.open("TabelaDeAcessos.csv"); // cria o arquivo csv para receber o dados de acessos
            arquivo << "Acessos"
                    << ", "
                    << "Qtd.Elementos" << endl; // adiciona o nome das colunas
            while (tam != MAX_VETOR)
            { // 10   //enquanto o tamanho da lista nao for = 100 o while continuara a rodar

                Lista2.geraLista(tam);          // invocar o metodo gera lista para criar a lista de tamanho (tam)
                
                Lista2.mergeSort(false,acessosUnitariosEtapa2); // aux recebe o retorno do metodo bubble sort que ira forncer o numero
                                                // de acessos a memoria e fara a ordenaçao da lista

                acessosEtapa2 = acessosEtapa2 + acessosUnitariosEtapa2; // contagem do total de acessos a memoria
                cout << "\n"        // imprime os acessos a memoria de cada lista gerada
                     << "Acessos[tamanho=" << tam + 1 << "]" << acessosUnitariosEtapa2 << endl;
                
                Lista2.deletaLista(); // deleta a lista
                tam++;                // incrementa o tamanho para gerar uma nova lista
                
                arquivo << acessosUnitariosEtapa2 << ", " << tam << endl; // imprime a quantidade de acessos a memoria
                                                                          // de cada lista gerada dentro do arquivo csv
                acessosUnitariosEtapa2=0;
            } 
            cout << "\n"
                 << "Total de Acessos=" << acessosEtapa2 << endl; // imprime a quantidade total de acessos no
                                                                  // final da geração das 100 listas
            arquivo.close(); // fecha o arquivo

            acessosEtapa2 = 0, tam = 0; //(caso rode novamente o loop a lista e a variavel de
                                                                             // contagem de acessos necessitam estar vazias)
        }
        else if (etapa == 3)
        {
        }
        else
        {
            cout << "numero invalido" << endl; // se algum outro numero for digitado imprimira a mensagem
        }
    } while (etapa != 3);

    return 0;
};