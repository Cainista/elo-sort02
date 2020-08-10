#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10000

// Funciones
int imprimeArreglo();
void insertionSort();
void heapSort();

// Bloque principal
int main(int argc, char* argv[]){
  // Verificamos sintaxis
  if (argc < 2){
    printf("Sintaxis incorrecta\n" );
    printf("Debe indicar el nombre del archivo con datos\n" );
    printf("Ejemplo: %s random_150.txt\n", argv[0] );
    exit(1);
  }


  // Variables
  char *line_buf = NULL;
  size_t line_buf_size = 0;
  ssize_t line_size;
  FILE *fptr;
  char *fileName = argv[1];

  int cc = 0;
  int numbers_array[MAX_NUMBERS];

  if ((fptr = fopen(fileName, "r")) == NULL) {
       printf("Error al abrir el archivo");
       // Salir del programa con error
       // si el archivo no existe
       exit(1);
   }

    //Muestra los datos del .txt
    while (getline(&line_buf, &line_buf_size, fptr) > 0 ) {
      numbers_array[cc++]=atoi(line_buf);
      // printf("%03d)\t%06d\n", cc, numbers_array[cc-1]);
      if (cc>=MAX_NUMBERS)
        break;
    }
    fclose(fptr);

    imprimeArreglo(numbers_array, cc);
    insertionSort(numbers_array, cc);
    imprimeArreglo(numbers_array, cc);
    heapSort(numbers_array, cc);
    imprimeArreglo(numbers_array, cc);

    // Imprime numeros desordenados

  return 0;
} // main


int imprimeArreglo(int *numArray, int size){
  for (int i = 0; i < size; i++)
    printf("%03d: %06d\n",i+1, numArray[i]);
  return 0;
}


void insertionSort(int *numArray, int size){
    // Base case
    if (size <= 1)
        return;

    // Sort first n-1 elements
    insertionSort( numArray, size-1 );

    // Insert last element at its correct position
    // in sorted array.
    int last = numArray[size-1];
    int j = size-2;

    /* Move elements of arr[0..i-1], that are
      greater than key, to one position ahead
      of their current position */
    while (j >= 0 && numArray[j] > last)
    {
        numArray[j+1] = numArray[j];
        j--;
    }
    numArray[j+1] = last;
}



/***********************
* heapSort y funciones asociadas
***********************/
// intercambia los valores
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Funcion principal heap sort
void heapSort(int numArray[], int size)
{
  // Crea pila
  for (int i = size / 2 - 1; i >= 0; i--)
      heapify(numArray, size, i);

  // One by one extract an element from heap
  for (int i=size-1; i>0; i--)
  {
      // Move current root to end
      swap(&numArray[0], &numArray[i]);

      // call max heapify on the reduced heap
      heapify(numArray, i, 0);
  }
}
