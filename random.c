#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "random.h"
#define MAXDIM 100000000


void initrandom()
{
    srand(time(NULL)*getpid());
}



void random_lobsters(ull *nrhomari,ull *capacitate,ull dim[],ull val[])
{
    initrandom();
    *nrhomari = rand()*15%90000;
    *capacitate= rand()*1111%100000;

    for(int i=0; i<*nrhomari; i++)
    {
        ull idim, ival;
        idim= rand()%5000;
        ival= rand()%5000;
        dim[i]=idim;
        val[i]=ival;
        //printf("iar idim si ival sunt %I64u %I64u\n", idim, ival);
    }

    printf("%I64u\n iar capacitatea sacului %I64u\n",*nrhomari,*capacitate);
}

