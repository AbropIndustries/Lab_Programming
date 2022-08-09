/*Programa para calcular el determinante de una matriz
con apuntadores y memoria dinamica*/

/*Librerias*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdio_ext.h> //Linux

/*Definiciones*/
#define Max_Dim 100
#define NUMPARAMS 2

/*Declaraciones*/
void PreguntarDimension(int *dim);
float **InicializarMatriz(int dim);
void IngresarValores(float **matriz, int dim);
void ImprimirMatriz(float **matriz, int dim);
float DeterminanteMatriz(float **matriz, int dim);
void ImprimirDeterminante(float *det);
int CleanInput(void);

int main()
{
	float **matriz1, Det;
	int dim_mtrz=0;
	
	PreguntarDimension(&dim_mtrz);
	matriz1=InicializarMatriz(dim_mtrz);
	IngresarValores(matriz1, dim_mtrz);
	ImprimirMatriz(matriz1, dim_mtrz);
	Det=DeterminanteMatriz(matriz1, dim_mtrz);
	ImprimirDeterminante(&Det);
	return 0;
}

void PreguntarDimension(int *dim)
{
	char c;
	printf("\nCual es la dimension de la matriz?: ");
	while(!(scanf("%d%c", dim, &c)==NUMPARAMS && c=='\n') || *dim<=0)
	{
		printf("Ingrese solo valor numerico entero mayor que cero, intente nuevamente.\n");
		printf("Cual es la dimension de la matriz?: ");
		CleanInput();
	}
}

float **InicializarMatriz(int dim)
{
	float **arreglo;
	arreglo=(float **)calloc(dim, sizeof(float *));
	if(arreglo==NULL)
	{
		printf("NO SE PUEDE ASIGNAR MEMORIA.\n");
		exit(1);
	}
	for(register int m=0; m<dim; m++)
	{
		arreglo[m]=(float *)calloc(dim, sizeof(float));
		if(arreglo==NULL)
		{
			printf("NO SE PUEDE ASIGNAR MEMORIA.\n");
			exit(1);
		}
	}
	return arreglo;
}

void IngresarValores(float **matriz, int dim)
{
	char c;
	printf("\n\nIngresa los valores de la MATRIZ\n");
	for(register int i=0; i<dim; i++)
	{
		for(register int j=0; j<dim; j++)
		{
			printf("elemento[%d][%d]: ", i+1, j+1);
			while(!(scanf("%f%c", &matriz[i][j], &c)==NUMPARAMS &&c=='\n'))
			{
				printf("Introducir unicamente valor numerico, intente nuevamente.\n");
				printf("elemento[%d][%d]: ", i+1, j+1);
				CleanInput();
			}
		}
	}
}

void ImprimirMatriz(float **matriz, int dim)
{
	printf("\n\nMatriz:\n");
	for(register int i=0; i<dim; i++)
	{
		for(register int j=0;j<dim; j++)
		{
			printf("\t%f", matriz[i][j]);
		}
		printf("\n");
	}
}

float DeterminanteMatriz(float **matriz, int dim)
{
  	float **submatriz, det=0, aux=0;
  	register int aux_fil=0, aux_col=0;
  	submatriz=InicializarMatriz(dim - 1);
  	if(dim == 1)
  	{
    		det=matriz[0][0];
  	}
  	else
  	{
    		for(register int col=0; col<dim; col++)
    		{
    			aux_fil=0; aux_col=0;
      		for(register int i=0; i<dim; i++)
      		{
        			for(register int j=0; j<dim; j++)
        			{
          			if(i!=0 && j!=col)
          			{
            				submatriz[aux_fil][aux_col]=matriz[i][j];
            				aux_col++;
            				if(aux_col >= dim - 1)
            				{
              					aux_fil++;
              					aux_col=0;
            				}
          			}
        			}
      		}
      		det += pow(-1, 0+col)*matriz[0][col]*DeterminanteMatriz(submatriz, dim - 1);
    		}
  	}
  	return det;
}

void ImprimirDeterminante(float *det)
{
	printf("\n\nEl determinante de la matriz es: %f\n\n", *det);
}

int CleanInput(void)
{
	//fflush(stdin); //Windows
	__fpurge(stdin); //Linux
	return 0;
}
