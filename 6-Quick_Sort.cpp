#include <iostream>
using namespace std;
void intercambio(int* a, int* b) // Intercambia dos elementos - Función de utilidad
{
    int t = *a;
    *a = *b;
    *b = t;
}
int particion (int arreglo[], int inicio, int fin)  // particiona la matriz usando el último elemento como pivote
{
    int pivote = arreglo[fin];    // pivote
    int i = (inicio - 1);

    for (int j = inicio; j <= fin- 1; j++)
    {
        if (arreglo[j] <= pivote) // si el elemento actual es más pequeño que el pivote, incremente el elemento bajo
        { 							// intercambia elementos en i y j
            i++;    // índice de incremento del elemento más pequeño
            intercambio(&arreglo[i], &arreglo[j]);
        }
    }
    intercambio(&arreglo[i + 1], &arreglo[fin]);
    return (i + 1);
}
void quickSort(int arreglo[], int inicio, int fin) //algoritmo quicksort
{
    if (inicio < fin)
    {
        int pivote = particion(arreglo, inicio, fin);  //particiona el arreglo
        // clasifica las sub matrices de forma independiente
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
