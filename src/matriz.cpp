#include "matriz.h"
#include <iostream>
#include <stdlib.h>

/**Alunos: Leonardo Perales (C.C.), Pablo Alcantara (C.C.) e Vivian Santos (C.C.)**/

using namespace std;

Matriz::Matriz(int n)
{
    this->tamanho = n;
    m1 = new int*[n];
    m2 = new int*[n];
    m3 = new int*[n];
    for(int i = 0; i < n; i++)
    {
        m1[i] = new int[n];
        m2[i] = new int[n];
        m3[i] = new int[n];
    }
}

void Matriz::preencherMatriz()
{
    int i, j;
    for(i = 0; i < this->tamanho; i++)
    {
        for(j = 0; j < this->tamanho; j++)
        {
            this->m1[i][j] = rand() % 1001;
            this->m2[i][j] = rand() % 1001;
            this->m3[i][j] = 0;
        }
    }
}

void Matriz::imprimirMatriz()
{
    int i, j;

    cout << "\nMatriz 1:";
    for(i = 0; i < this->tamanho; i++)
    {
        cout << "" << endl;
        for(j = 0; j < this->tamanho; j++)
        {
            cout << this->m1[i][j] <<  "\t";
        }
    }

    cout << "\n\nMatriz 2:";
    for(i = 0; i < this->tamanho; i++)
    {
        cout << "" << endl;
        for(j = 0; j < this->tamanho; j++)
        {
            cout << this->m2[i][j] <<  "\t";
        }
    }

    cout << "\n\nMatriz resultante:";
    for(i = 0; i < this->tamanho; i++)
    {
        cout << "" << endl;
        for(j = 0; j < this->tamanho; j++)
        {
            cout << this->m3[i][j] <<  "\t";
        }
    }

    cout << "" << endl;
}

void Matriz::multiplica(int linha)
{
    int i, j;
    for(i = 0; i < this->tamanho; i++)
    {
        for(j = 0; j < this->tamanho; j++)
        {
            this->m3[linha][i] += (this->m1[linha][j] * this->m2[j][i]);
        }
    }
}

Matriz::~Matriz()
{
    this->m1 = nullptr;
    this->m2 = nullptr;
    this->m3 = nullptr;
}
