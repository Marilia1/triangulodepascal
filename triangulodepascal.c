#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define MAX 100


int min(int a, int b);

int binomialCoeff(int lin, int col)
{
    int vet_pascal[lin+1][col+1];
    int i, j;

    for (i = 0; i <= lin; i++)
    {
        for (j = 0; j <= min(i, col); j++)
        {

            if (j == 0 || j == i)
                vet_pascal[i][j] = 1;

            else
                vet_pascal[i][j] = vet_pascal[i-1][j-1] + vet_pascal[i-1][j];
        }
    }

    return vet_pascal[lin][col];
}


int min(int a, int b)
{
    return (a<b)? a: b;
}

int main()
{
   int grau, lin, col, count = 0;
	int vet_pascal[MAX][MAX];
	printf("Digite: ");
	scanf("%i",&grau);
	printf("Digite linha: ");
   scanf("%d", &lin);
   printf("Digite coluna: ");
   scanf("%d", &col);
   printf ("Value of vet_pascal(%d, %d) is %d ", lin, col, binomialCoeff(lin, col) );
   printf("\n");
	for(lin = 1 ; lin <= grau+1 ; lin++){
	printf("Grau %i: ",count);
	count++;

	for(col = 0 ; col < lin; col++){
		if(!col || !lin) vet_pascal[lin][col] = 1;
		else if (vet_pascal[lin][col] == 0) vet_pascal[lin][col] = vet_pascal[lin-1][col] + vet_pascal[lin-1][col-1];

		printf("%i ", vet_pascal[lin][col]);

		}
		printf("\n");

	}


	system("PAUSE");
return 0;


}
