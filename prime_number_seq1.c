#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>


void prime_number_table_print(int n, int * tablica) {
    printf("Primes numbers: ");
    for (int i=2; i<n; i++) {
        if(tablica[i] == 0) printf("%d ",i);
    }
    printf("\n");
}

void prime_generator(int n, int*tablica) {
    int q = 0;
    for (int i=2; i<n; i++){
        q = (int) sqrt(i);
        for(int j=2; j<=q; j++){
            if(i%j == 0) tablica[i] = 1;
        }
    }
}


int main(int argc, char* argv[])
{
    int * tablica = NULL;
    int n;
	if (argc > 1)  n = atoi(argv[1]);

    tablica = (int *) malloc(n*sizeof(int));
    for(int i=0; i<n; i++) {
        tablica[i] = 0;
    }
    prime_generator(n, tablica);
    prime_number_table_print(n, tablica);

    free(tablica);
	return 0;
}