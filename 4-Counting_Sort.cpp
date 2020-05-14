#include<iostream>
using namespace std;
int k=0;
void Counting_Sort(int A[],int B[],int n)     /* M�todo para ordenar el arreglo */
{
	int C[k];
	for(int i=0;i<k+1;i++)
	{
		C[i]=0; /* Inicializar� la C con cero */
	}
	for(int j=1;j<=n;j++)
	{
		C[A[j]]++; /* Contar� la ocurrencia de cada elemento x en A y la incrementar� en la posici�n x en C */
	}
	for(int i=1;i<=k;i++)
	{
		C[i]+=C[i-1];  /* Almacenar� la �ltima ocurrencia del elemento i */
	}
	for(int j=n;j>=1;j--)
	{
		/*It will place the elements at their
		respective index*/
		B[C[A[j]]]=A[j];    /* Colocar� los elementos en sus respectivos �ndices */
		C[A[j]]=C[A[j]]-1;	/* Ayudar� si un elemento ocurre m�s de una vez */
	}
}
int main()
{
	int n;
	cout<<"Introducir el tama�o del arreglo: ";
	cin>>n;
	/* A almacena los elementos ingresados ??por el usuario */
	/* B almacena la secuencia ordenada de elementos */
	int A[n],B[n];
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		if(A[i]>k)
		{
			k=A[i];   /* Modificar� k si ocurre un elemento cuyo valor es mayor que k */
		}
	}
	Counting_Sort(A,B,n);
	for(int i=1;i<=n;i++)   /* Se imprimir� la secuencia ordenada en la consola */
	{
		cout<<B[i]<<" ";
	}

	cout<<endl;
	return 0;
}
