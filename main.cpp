#include <iostream>
#include <matriz.h>
#include<omp.h>
#include <time.h>

using namespace std;

int main()
{
    int tid = 0, n = 0;
    cout << "Digite o valor de N: ";
    cin >> n;
    Matriz mat(n);

    #pragma omp parallel shared(mat)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                mat.preencherMatriz();
            }
        }
    }

    cout << "\n";
    clock_t Ticks[2];
    Ticks[0] = clock();

    #pragma omp parallel num_threads(n) shared(mat)
    {
        tid=omp_get_thread_num();
        #pragma omp for
        for (int i=0; i< n; i++)
        {
            mat.multiplica(i);
            cout << "Thread #" << tid << " executando na linha #" << i << endl;
        }
    }

    Ticks[1] = clock();

    #pragma omp parallel shared(mat)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                mat.imprimirMatriz();
            }
        }
    }

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nTempo gasto: %g ms. \n\n", Tempo);

    return 0;
}
