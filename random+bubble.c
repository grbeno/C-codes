#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

#define UPPER 35
#define LOWER 1
#define INTV (UPPER - LOWER + 1) + LOWER //ebben az intervallumban //+1 = benne van az upper is! (interval)
#define SOR 7
#define N 5

int main() {

	setlocale(LC_ALL, "Hungarian_Hungary.1250");
	
	//Random
	time_t t;
	srand((unsigned)time(&t));
	int i, j, k, r, temp = 0;
	
	printf("Random sorok ismétlésekkel\n");
	for (j = 0; j < N; j++) {
		printf("%d. sor: ", j + 1);
		for (i = 0; i < SOR; i++) {
			r = rand() % INTV;
			printf("%d ", r);
		}
		printf("\n");
	}
	
	//ne legyen ismétlõdés... avoid repetition
	bool arr[INTV] = {0};
	int szamok[N][SOR];
	printf("\nRandom sorok ismétlések nélkül\n");
	for (j = 0; j < N; j++) {
		printf("%d. sor: ", j+1);
		for (i = 0; i < SOR; i++) {
			r = rand() % INTV;
			if (!arr[r]) {
				szamok[j][i] = r;
				printf("%d ", r);
			}
			else
				i--;
			arr[r] = 1;
		}
		memset(arr, 0, sizeof(arr));
		printf("\n");
	}

	//emelkedõ sorrendbe... ascending order
	printf("Emelkedõ sorrendben:\n");
	for (k=0;k<N;k++) {
		for (i=0;i<SOR;i++) {
			for (j = i + 1; j<SOR;j++) {
				if (szamok[k][i] > szamok[k][j]) {
					temp = szamok[k][i];
					szamok[k][i] = szamok[k][j];
					szamok[k][j] = temp;
				}
			}
		}
	}
	
	//kiíratás... print
	for (i = 0; i < N; i++) {
		printf("%d. sor: ", i + 1);
		for (j = 0; j < SOR; j++)
			printf("%d ", szamok[i][j]);
		printf("\n");
	}
	
	return 0;
}