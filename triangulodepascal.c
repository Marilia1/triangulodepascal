#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100


int min(int a,int b);

int Coeficiente(int lin, int col)
{
    int C[lin+1][col+1];
    int i, j;

    for (i = 0; i <= lin; i++)
    {
        for (j = 0; j <= min(i, col); j++)
        {
            // caso base
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calcular o valor usando os valores armazenados anteriormente
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[lin][col];
}

// retorna min de dois inteiros
int min(int a,int b)
{
    return (a<b)? a: b;
}
int main()
{
   int grau, lin, col, count = 0;
   int n,i;
   printf("");
   scanf("%d", &n);
    int combinacao[MAX][MAX];
	grau = 20;

   for(i = 0; i<n; i++){
   printf("");
   scanf("%d %d", &lin,  &col);
   printf ("Valor da combinacao(%d, %d) eh %d ", lin, col, Coeficiente(lin, col) );
   printf("\n");
   }

	for(lin = 1 ; lin <= grau+1 ; lin++){
	printf("Grau %i: ",count);
	count++;

	for(col = 0 ; col < lin; col++){
		if(!col || !lin) combinacao[lin][col] = 1;
		else if (combinacao[lin][col] == 0) combinacao[lin][col] = combinacao[lin-1][col] + combinacao[lin-1][col-1];

		printf("%i ", combinacao[lin][col]);

		}
		printf("\n");

	}


return 0;


}
