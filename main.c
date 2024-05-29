#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "random.h"

#define MAXDIM 100000000


ull nrhomari, capacitate, dim[100000000], val[100000000];

int knapsack(ull capacitate, ull dim[], ull val[], ull nrhomari)
{
    int i, w;
    int **K = (int **)malloc((nrhomari + 1) * sizeof(int *));
    for (i = 0; i <= nrhomari; i++) {
        K[i] = (int *)malloc((capacitate + 1) * sizeof(int));
    }

    // construirea tabelului K in maniera bottom-up
    for (i = 0; i <= nrhomari; i++) {
        for (w = 0; w <= capacitate; w++)
        {

            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
            } else if (dim[i - 1] <= w)
            {
                if (val[i - 1] + K[i - 1][w - dim[i - 1]] > K[i - 1][w])
                {
                K[i][w] = val[i - 1] + K[i - 1][w - dim[i - 1]];
                }
                else
                {
                    K[i][w]=K[i - 1][w];

                }

            } else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    int rezultat = K[nrhomari][capacitate];

    // eliberarea memoriei alocate
    for (i = 0; i <= nrhomari; i++) {
        free(K[i]);
    }
    free(K);

    return rezultat;
}


int main()
{
    /*
    scanf("%d", &nrhomari);
    scanf("%d", &capacitate);
    for(i = 0; i < nrhomari; i++)
        scanf("%d%d", &dim[i], &val[i]);
    */
    random_lobsters(&nrhomari, &capacitate, dim, val);
    printf("valoarea maxima a capturii: %d monede de aur\n", knapsack(capacitate, dim, val, nrhomari));

    return 0;
}
