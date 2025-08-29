#include <stdio.h>
#include <stdlib.h>

/*
    Ejercicio: Implementación de Merge Sort

    Descripción:
    Se reciben n arreglos lineales, cada uno de tamaño n.
    El programa debe combinarlos en un solo arreglo de tamaño n*n
    y ordenarlo en orden creciente usando Merge Sort.

    Entrada:
    - Un número entero n
    - n arreglos de tamaño n (n*n enteros en total)

    Salida:
    - Un solo arreglo de tamaño n*n con los elementos ordenados en orden creciente

    Ejemplo:

    Input:
    3
    3 1 5
    2 9 4
    8 7 6

    Output:
    1 2 3 4 5 6 7 8 9
*/

// ---- Prototipos ----
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int n;
    scanf("%d", &n);  // Leer el número de arreglos

    int total = n * n;
    int *arr = (int *)malloc(total * sizeof(int));

    // Leer n arreglos de tamaño n
    for (int i = 0; i < total; i++) {
        scanf("%d", &arr[i]);
    }

    // Ordenar usando merge sort
    mergeSort(arr, 0, total - 1);

    // Imprimir el arreglo ordenado
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

// ---- Implementa aquí tu función mergeSort ----

void merge(int arr[], int left, int mid, int right) {
    //i, j y k son índices para las mitades y el arreglo principal
    int i, j, k;
    //n1 es el tamaño de la mitad izquierda, n2 es el tamaño de la mitad derecha
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //Creamos arreglos temporales para cada mitad y copiamos los elementos
    int mitadIzq[n1], mitadDer[n2];
    for (i = 0; i < n1; i++)
        mitadIzq[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        mitadDer[j] = arr[mid + 1 + j];

    //Pone el contenido de ambas mitades en el arreglo en el rango de índices left y right
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2){
        if (mitadIzq[i] <= mitadDer[j]){
            arr[k] = mitadIzq[i];
            i++;
        }
        else {
            arr[k] = mitadDer[j];
            j++;
        }
        k++;
    }
    
    //Copia los elementos faltantes de la mitad izquierda, cuando la mitad derecha acaba antes
    while (i < n1){
        arr[k] = mitadIzq[i];
        i++;
        k++;
    }

    //Copia los elementos faltantes de la mitad derecha cuando la mitad izquierda acaba antes
    while (j < n2){
        arr[k] = mitadDer[j];
        j++;
        k++;
    }
}

//El subarreglo que se va a ordenar está en el rango de índices left y right
void mergeSort(int arr[], int left, int right){
    if (left < right) {
        //Obtenemos la mitad del subarreglo
        int mid = left + ((right - left) / 2);
        //Ordenamos ambas mitades recursivamente. Para la primera mitad, es de left a mid, y la segunda es de mid+1 a right
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        //Juntamos las dos mitades ordenadas
        merge(arr, left, mid, right);
    }
    return; //Si 
}