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

    #pragma omp parallel for private(q)
        for (int i=2; i<n; i++){
            //#pragma omp critical
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
    clock_t ppstart,ppstop;
	double pswtime, pewtime;

	if (argc > 1)  n = atoi(argv[1]);

    tablica = (int *) malloc(n*sizeof(int));
    for(int i=0; i<n; i++) {
        tablica[i] = 0;
    }

    pswtime = omp_get_wtime();
	ppstart = clock();

    prime_generator(n, tablica);

    ppstop = clock();
	pewtime = omp_get_wtime();

    prime_number_table_print(n, tablica);

    printf("Czas procesorów przetwarzania równoleglego  %f sekund \n", ((double)(ppstop - ppstart)/CLOCKS_PER_SEC));
	printf("Czas trwania obliczen rownoleglych - wallclock %f sekund \n", pewtime-pswtime);

    free(tablica);
	return 0;
}