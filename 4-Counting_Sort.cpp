#include<iostream>
using namespace std;
int k=0;
void Counting_Sort(int A[],int B[],int n)     /* Método para ordenar el arreglo */
{
	int C[k];
	for(int i=0;i<k+1;i++)
	{
		C[i]=0; /* Inicializará la C con cero */
	}
	for(int j=1;j<=n;j++)
	{
		C[A[j]]++; /* Contará la ocurrencia de cada elemento x en A y la incrementará en la posición x en C */
	}
	for(int i=1;i<=k;i++)
	{
		C[i]+=C[i-1];  /* Almacenará la última ocurrencia del elemento i */
	}
	for(int j=n;j>=1;j--)
	{
		/*It will place the elements at their
		respective index*/
		B[C[A[j]]]=A[j];    /* Colocará los elementos en sus respectivos índices */
		C[A[j]]=C[A[j]]-1;	/* Ayudará si un elemento ocurre más de una vez */
	}
}
int main()
{
	int n;
	cout<<"Introducir el tamaño del arreglo: ";
	cin>>n;
	/* A almacena los elementos ingresados ??por el usuario */
	/* B almacena la secuencia ordenada de elementos */
	int A[n],B[n];
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		if(A[i]>k)
		{
			k=A[i];   /* Modificará k si ocurre un elemento cuyo valor es mayor que k */
		}
	}
	Counting_Sort(A,B,n);
	for(int i=1;i<=n;i++)   /* Se imprimirá la secuencia ordenada en la consola */
	{
		cout<<B[i]<<" ";
	}

	cout<<endl;
	return 0;
}
