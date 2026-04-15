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

void  BuscarNombrePorId( char* v[], int num){
    if (num >=0 && num<5){
        printf("\nEl nombre de la posicion %d es: %s",num, v[num]);
    }else{
        printf("\nNo se encontró el valor buscado");
    }
}

char* BuscarNombrePorPalabra( char * v[], char *buff, int cant){

    /*esta parte esta bien pero estoy usando mas memoria de la que debia, puedo usar buff y trabajar traquilamente.
    ademas debo liberar la memoria despues del vector y no se podria ya que al usar el return se sale de la funcion
    Tambien por el return no me dara todas las palabras que empiezan con esa silaba a la primera coincidencia me devuelve el nombre*/

    /*char * argumento;
    argumento = (char*)malloc((strlen(buff)+1)*sizeof(char));
    strcpy(argumento,buff);*/ 

    for (int i = 0; i < cant; i++)
    {
        if (strstr(v[i],buff) != NULL)
        {
            return v[i];
        } 
    }
    return NULL;

}

int main()
{
    char *V[Cantidad]; //vector de 5 punteros
    char *buff; //puntero auxiliar que me servira para guardar los nombres
    buff = (char *)malloc(100 * sizeof(char)); //reservo 100 bytes de memoria temporal por las dudas pero con 50 hubiera bastado 

    printf("----Ingrese de nombres---");
    for (int i = 0; i < Cantidad ; i++)
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

    int id;
    char continuar = 's';
        while (continuar == 's' || continuar == 'S') {
        printf("\n\nIngrese el ID (0-4) para buscar un nombre: ");
        scanf("%d", &id);
        
        // Llamamos a la función de esta rama
        BuscarNombrePorId(V, id);

        printf("\n\nQuiere buscar otro ID aprete 's' o 'S' para continuar y cualquier otra letra si no quiere: ");
        getchar(); // Limpia el buffer del Enter anterior
        scanf("%c", &continuar);
    }
    
    // Limpiamos el buffer del teclado antes de usar gets
    fflush(stdin);

    printf("\nIngrese el nombre o al menos una silaba del nombre que quiere ver si se encuentra en el vector: ");
    gets(buff);

    char* mostrar =BuscarNombrePorPalabra(V,buff,Cantidad);
    if (mostrar != NULL)
    {
        printf("\nSe encontro una coincidencia y este es el nombre: %s", mostrar);
    }
    else{
        printf("\n no se encontro coincidencia alguna");
    }
    
    free(buff); //libero o limpiamos el buff auxiliar que ya no usare

    //libero los 5 espacio reservado para los nombres
    for (int i = 0; i < Cantidad; i++)
    {
        free(V[i]);  
    }

    return 0;
}