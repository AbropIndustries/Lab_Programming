/*Suma de Matrices con apuntadores y memoria dinamica*/

/*Librerias*/
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h> //Linux

/*Definiciones*/
#define NUMPARAMS 2

/*Declaraciones*/
void IngresarDimension(int *f1, int *c1, int *f2, int *c2);
float **InicializarMatriz(int fil, int col);
void IngresarValores(float **matriz, char *mat, int fil, int col);
float **SumarMatrices(float **matriz1, float **matriz2, int fil, int col);
void ImprimirMatriz(float **matriz, char *mat, int fil, int col);
int CleanInput(void);

int main()
{
	float **matriz1, **matriz2, **matriz_suma;
	int f1=0, c1=0, f2=0, c2=0;
	
	IngresarDimension(&f1, &c1, &f2, &c2);
	matriz1=InicializarMatriz(f1, c1);
	matriz2=InicializarMatriz(f2, c2);
	
	IngresarValores(matriz1, "matriz A", f1, c1);
	IngresarValores(matriz2, "matriz B", f2, c2);
	
	matriz_suma=SumarMatrices(matriz1, matriz2, f1, c2);
	
	ImprimirMatriz(matriz1, "Matriz A", f1, c1);
	ImprimirMatriz(matriz2, "Matriz B", f2, c2);
	ImprimirMatriz(matriz_suma, "Matriz A+B", f1, c2);
	return 0; 
}

void IngresarDimension(int *f1, int *c1, int *f2, int *c2)
{
	char c;
	printf("Numero de renglones en la matriz 1?: ");
	while(!(scanf("%d%c", f1, &c)==NUMPARAMS && c=='\n') || *f1<=0)
	{
		printf("Introducir solo valor numerico entero mayor que cero, intente nuevamente.\n");
		printf("Numero de renglones en la matriz 1?: ");
		CleanInput();
	}
	printf("Numero de columnas en la matriz 1?: ");
	while(!(scanf("%d%c", c1, &c)==NUMPARAMS && c=='\n') || *c1<=0)
	{
		printf("Introducir solo valor numerico entero mayor que cero, intente nuevamente.\n");
		printf("Numero de renglones en la matriz 1?: ");
		CleanInput();
	}
	do
	{
		printf("Numero de renglones en la matriz 2?: ");
		while(!(scanf("%d%c", f2, &c)==NUMPARAMS && c=='\n') || *f2<=0)
		{
			printf("Introducir solo valor numerico entero mayor que cero, intente nuevamente.\n");
			printf("Numero de renglones en la matriz 2?: ");
			CleanInput();
		}
		printf("Numero de columnas en la matriz 2?: ");
		while(!(scanf("%d%c", c2, &c)==NUMPARAMS && c=='\n') || *c2<=0)
		{
			printf("Introducir solo valor numerico entero mayor que cero, intente nuevamente.\n");
			printf("Numero de renglones en la matriz 2?: ");
			CleanInput();
		}
		if(*f1 != *f2 || *c1 != *c2)
		{
			printf("Las matrices deben tener las mismas dimensiones para ser sumadas.\n");
			printf("Intentelo nuevamente.\n");
		}
	}while(*f1 != *f2 || *c1 != *c2);
}

float **InicializarMatriz(int fil, int col)
{
	float **arreglo;
	arreglo=(float **)calloc(fil, sizeof(float *));
	if(arreglo==NULL)
	{
		printf("!NO SE PUEDE ASIGNAR MEMORIA\n");
		exit(1);
	}
	for(register int m=0; m<col; m++)
	{
		arreglo[m] = (float *)calloc(col, sizeof(float));
		if(arreglo[m]==NULL)
		{
			printf("!NO SE PUEDE ASIGNAR MEMORIA\n");
			exit(1);
		}
	}
	return arreglo;
}

void IngresarValores(float **matriz, char *mat, int fil, int col)
{
	char c;
	printf("\nIngresa los valores de la %s:\n", mat);
	for(register int i=0; i<fil; i++)
	{
		for(register int j=0; j<col; j++)
		{
			printf("elemento[%d][%d]= ", i, j);
			while(!(scanf("%f%c", &matriz[i][j], &c)==NUMPARAMS && c=='\n'))
			{
				printf("introducir unicamente valor numerico, intente nuevamente.\n");
				printf("elemento[%d][%d]= ", i, j);
				CleanInput();
			}
		}
	}
}

float **SumarMatrices(float **matriz1, float **matriz2, int fil, int col)
{
	float **suma;
	suma=InicializarMatriz(fil, col);
	for(register int i=0; i<fil; i++)
	{
		for(register int j=0; j<col; j++)
		{
			suma[i][j] = matriz1[i][j] + matriz2[i][j];
		}
	}
	return suma;
}

void ImprimirMatriz(float **matriz, char *mat, int fil, int col)
{
	printf("\n%s:\n", mat);
	for(register int i=0; i<fil; i++)
	{
		for(register int j=0; j<col; j++)
		{
			printf("\t%f", matriz[i][j]);
		}
		printf("\n");
	}
}

int CleanInput(void)
{
	//fflush(stdin); //Windows
	__fpurge(stdin); //Linux
	return 0;
}
