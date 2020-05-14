#include <iostream>
using namespace std;
void merge(int *,int, int , int );
void merge_sort(int *arr, int inicio, int fin)
{
    int medio;
    if (inicio < fin){
// divide el arreglo a mitad y ordena de forma independiente usando la combinación de ordenación
		medio=(inicio+fin)/2;
        merge_sort(arr,inicio,medio);
        merge_sort(arr,medio+1,fin);
        merge(arr,inicio,fin,medio); // fusionar arreglos ordenadas
    }
}
// Merge sort
void merge(int *arr, int inicio, int fin, int medio)
{
    int i, j, k, c[50];
    i = inicio;
    k = inicio;
    j = medio + 1;
    while (i <= medio && j <= fin) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= medio) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= fin) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = inicio; i < k; i++)  {
        arr[i] = c[i];
    }
}
 // lee la matriz de entrada y ordena a mergesort
int main()
{
    int arreglo[30], num;
    cout<<"Ingrese el número de elementos que se ordenaran:";
    cin>>num;
    cout<<"Enter "<<num<<" elementos a ordenar : ";
    for (int i = 0; i < num; i++) { cin>>arreglo[i];
    }
    merge_sort(arreglo, 0, num-1);
    cout<<"Arreglo ordenado:\n";
    for (int i = 0; i < num; i++)
    {
        cout<<arreglo[i]<<"\t";
    }
}
