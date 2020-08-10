#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10000

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
      printf("%03d)\t%06d\n", cc, numbers_array[cc-1]);
      if (cc>=MAX_NUMBERS)
        break;
    }


   fclose(fptr);
  return 0;
}
