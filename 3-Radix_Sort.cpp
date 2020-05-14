#include <iostream>
using namespace std;
int getMax(int arreglo[], int n) // Obtenga el valor máximo de la matriz
{
int maximo = arreglo[0];
for (int i = 1; i < n; i++)
if (arreglo[i] > maximo)
maximo = arreglo[i];
return maximo;
}
void countSort(int arreglo[], int n, int exp)
{
int salida[n], i, count[10] = {0};	
for (i = 0; i < n; i++) 	
count[(arreglo[i] / exp) % 10]++;
for (i = 1; i < 10; i++) 	
count[i] += count[i-1];
for (i = n - 1; i >= 0; i--) 
{
salida[count[(arreglo[i] / exp) % 10] - 1] = arreglo[i];
count[(arreglo[i] / exp) % 10]--;
}
for (i = 0; i < n; i++) 	
arreglo[i] = salida[i];
}
void radixsort(int arreglo[], int n)
{
int exp, m;
m = getMax(arreglo, n);
for (exp = 1; m/exp > 0; exp *= 10) 	
countSort(arreglo, n, exp);
}
int main()
{
int n, i;
cout<<"\nIngrese el numero de elementos de datos que se ordenaran: ";
cin>>n;
int arreglo[n];
for(i = 0; i < n; i++)
{
cout<<"Introducir elemento: "<<i+1<<": ";
cin>>arreglo[i];
}
radixsort(arreglo, n);
cout<<"\nDatos ordenados: "; 	
for (i = 0; i < n; i++)
cout<<"->"<<arreglo[i];
return 0;
}
