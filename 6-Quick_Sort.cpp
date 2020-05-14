#include <iostream>
using namespace std;
void intercambio(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int particion (int arreglo[], int inicio, int fin) 
{
    int pivote = arreglo[fin];    // pivote
    int i = (inicio - 1);

    for (int j = inicio; j <= fin- 1; j++)
    {
        if (arreglo[j] <= pivote)
        { 							
            i++;  
            intercambio(&arreglo[i], &arreglo[j]);
        }
    }
    intercambio(&arreglo[i + 1], &arreglo[fin]);
    return (i + 1);
}
void quickSort(int arreglo[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int pivote = particion(arreglo, inicio, fin); 
    
        quickSort(arreglo, inicio, pivote - 1);
        quickSort(arreglo, pivote + 1, fin);
    }
}
void mostrar_matriz(int arreglo[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arreglo[i]<<"\t";

}
int main()
{
    int arreglo[] = {10,42,15,12,37,7,9};
    int n = sizeof(arreglo)/sizeof(arreglo[0]);
    cout<<"Arreglo de entrada: "<<endl;
    mostrar_matriz(arreglo,n);
    cout<<endl;
    quickSort(arreglo, 0, n-1);
    cout<<"Arreglo ordenado con quick sort: "<<endl;
    mostrar_matriz(arreglo,n);
    return 0;
}
