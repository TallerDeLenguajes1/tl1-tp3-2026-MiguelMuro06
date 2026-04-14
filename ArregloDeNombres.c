#include <stdio.h>
#include <stdlib.h> //Libreria necesaria para usar malloc y free
#include <string.h> //Libreria necesaria para usar en este punto strlen, strcpy
#define Cantidad 5  // contante para los nombre, uso esto por si despues dice 6 o mas y el codigo seguiria andando bien

// funcion de mostrar las personas

void MostrarPersonas(char *v[], int cantidad)
{
    printf("\n----Nombre de las personas----");
    for (int i = 0; i < cantidad; i++)
    {
        printf("\n El nombre del [%d] es: %s", i + 1, v[i]); //muestro cada uno de los nombres  por el puntero v[i] ya que va a su direccion de memoria
    }
}

int main()
{
    char *V[Cantidad]; //vector de 5 punteros
    char *buff; //puntero auxiliar que me servira para guardar los nombres
    buff = (char *)malloc(100 * sizeof(char)); //reservo 100 bytes de memoria temporal por las dudas pero con 50 hubiera bastado 

    printf("----Ingrese de nombres---");
    for (int i = 0; i < 5; i++)
    {
        printf("\n Ingrese el nombre [%d]: ", i + 1);
        gets(buff);

        V[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        /* RESERVA DINÁMICA:
           1. Medimos el largo del nombre con strlen(buff)
           2. Sumamos 1 para el carácter nulo '\0' que indica el fin de la cadena.
           3. Pedimos a la memoria (heap) ese tamaño exacto para V[i].
        */
        strcpy(V[i], buff); // copiamos lo que tiene buffer a la memoria recien reservada
    }
    MostrarPersonas(V, Cantidad);

    free(buff); //libero o limpiamos el buff auxiliar que ya no usare

    //libero los 5 espacio reservado para los nombres
    for (int i = 0; i < Cantidad; i++)
    {
        free(V[i]);  
    }

    return 0;
}

/*char buff[50];
    scanf("%s", buff);
    int tamanioDeCadenaIngresadaPorUsuario = strlen(buff); // no considera el caracter nulo por lo tanto devuelve 10

    char * Cadena;
    Cadena = (char *) malloc (sizeof(char) * tamanioDeCadenaIngresadaPorUsuario + 1); // Reserva de memoria para la cadena pero aumento 1 byte para el carcter nulo

    strcpy(Cadena, buff);
    printf("%s",Cadena);

    getchar();
      */
