#include <stdio.h>
#include <math.h>
FILE *arquivo;
#define n 10

void coeficientes(double x1[n], double y1[n])
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
	
	//calculando a0 e a1
	a0 = (Sxx*Sy - Sxy*Sx)/(n*Sxx - Sx*Sx);
	a1 = (n*Sxy - Sx*Sy)/(n*Sxx - Sx*Sx);
	
	printf("Valores de a0 e a1 \n");
	
	//Imprimindo a1 e a0
	printf("\na1 = %lf\na0 = %lf\n\n", a1, a0);
}

int main()
{	
	int i;
	double x1[n], y1[n];//coluna 1 e coluna 2 do aquivo "dados.dat"
	
	//Abrindo o arquivo para leitura
	arquivo = fopen("dados.dat", "r");
	
	//Lendo os dados
	for(i=0; i<n; i++)
	{
		fscanf(arquivo, "%lf\t\t%lf\n", &x1[i], &y1[i]);
	}


	//Imprimindo os dados na tela
	for(i=0; i<n; i++)
	{
		printf("%.1lf\t%.1lf\n", x1[i], y1[i]);
	}
	
	
	coeficientes(x1, y1);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	

