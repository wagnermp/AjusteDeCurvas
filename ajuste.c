#include <stdio.h>
#include <math.h>
FILE *arquivo;
#define n 10

void coeficiente(double x1[n], double y1[n])
{
    int i;
    double Sx, Sy, Sxy, Sxx, a0, a1;
  	Sx=0;
  	Sy=0;
  	Sxy=0;
  	Sxx=0;
  	
  	//Calculando os somatórios
	for(i=0; i<n; i++)
	{
		Sx = Sx + x1[i];
		Sxx = Sxx + x1[i]*x1[i];
		Sxy = Sxy + x1[i]*y1[i];
		Sy = Sy + y1[i];
	}
	
	//Imprimindo os somatórios
	{
		printf("\nSx = %.1lf\nSy = %.1lf\nSxx = %.1lf\nSxy = %.1lf\n\n", Sx, Sy, Sxx, Sxy);
	}
	

	//determinando os coeficientes a0 e a1
	
	a0 = (Sxx*Sy - Sxy*Sx)/(n*Sxx - Sx*Sx);
	a1 = (n*Sxy - Sx*Sy)/(n*Sxx - Sx*Sx);
	
	//Imprimindo a1 e a0
	printf("\na1 = %lf\na0 = %lf\n\n", a1, a0);
}

int main()
{	int i;
	double x1[n], y1[n];//coluna 1 e coluna 2 do aquivo "dados.dat"
	
	//Abrindo o arquivo para leitura
	arquivo = fopen("dados.dat", "r");
	
	//Lendo os dados do arquivo
	for(i=0; i<n; i++)
	{
		fscanf(arquivo, "%lf\t\t%lf\n", &x1[i], &y1[i]);
	}


	//Imprimindo os dados na tela
	for(i=0; i<n; i++)
	{
		printf("%.1lf\t\t%.1lf\n", x1[i], y1[i]);
	}
	
	
	coeficiente(x1, y1);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	

