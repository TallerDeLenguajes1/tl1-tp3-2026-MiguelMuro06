#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos;    // El tamaño de este arreglo depende de la variable
                        //  “CantidadProductosAPedir”
};

// item iv
float CalcularCostoProducto(struct Producto p){
    return p.Cantidad * p.PrecioUnitario;
}

void Mostrar(struct Cliente *listado, int cant){

    printf("\n----------Comprador, su compra y su total---------\n");
    for (int i = 0; i < cant ; i++)
    {
        float totalPagar = 0;
        printf("\nCliente %d y su ID es: %d",i+1,listado[i].ClienteID);
        printf("\nNombre del cliente: %s",listado[i].NombreCliente);
        printf("\nCantidad de productos seleccionados : %d",listado[i].CantidadProductosAPedir);

        printf("\n\n ------Descricpcion de los productos-----");

        for (int j = 0; j < listado[i].CantidadProductosAPedir; j++)
        {
            printf("\n\nID del producto: %d", listado[i].Productos[j].ProductoID);
            printf("\nTipo del producto: %s", listado[i].Productos[j].TipoProducto);
            printf("\nCantidad del producto: %d  || Y precio: %.2f", listado[i].Productos[j].Cantidad, listado[i].Productos[j].PrecioUnitario);

            float costoProd = CalcularCostoProducto(listado[i].Productos[j]);

            printf("\nSubTotal: %.2f", costoProd);
            
            totalPagar += costoProd;

        }

        printf("\n------------------");
        printf("\nTotal a pagar del cliente %s es : %.2f",listado[i].NombreCliente, totalPagar);
        printf("\n------------------");

    }
    
}

int main(){
    srand(time(NULL));
    int cantidadCliente;
    char buff[50];

    printf("\n Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadCliente);
    fflush(stdin);
    
    //reserva dinamica para el arreglo  de los clientes, 
    //ire guardando la cantidad de clientes en estructuras, es decir,
    // si ingreso 3 clientes ire guardando 3 estructuras una al lado de la otra para colocar los datos  del cliente
    struct Cliente *listado = (struct Cliente*)malloc(sizeof(struct Cliente)*cantidadCliente);

    for (int i = 0; i < cantidadCliente; i++)
    {
        listado[i].ClienteID = i+1;
        printf("\n Nombre del cliente %d : ", i+1);
        gets(buff);
        listado[i].NombreCliente = (char*)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(listado[i].NombreCliente,buff);

        listado[i].CantidadProductosAPedir = rand() % 5 +1;
        
        //Reserva para los productos
        listado[i].Productos = (struct Producto*)malloc(sizeof(struct Producto)*listado[i].CantidadProductosAPedir);

        for (int j = 0; j < listado[i].CantidadProductosAPedir; j++)
        {
            listado[i].Productos[j].ProductoID = j+1;
            listado[i].Productos[j].Cantidad = rand() %10 +1;     
            listado[i].Productos[j].PrecioUnitario = (rand() % 91) + 10; //entre 10 y 100     

            int indiceTipo = rand () % 5;
            listado[i].Productos[j].TipoProducto = TiposProductos[indiceTipo];
        }

    }
    
    Mostrar(listado, cantidadCliente);

    for (int i = 0; i < cantidadCliente; i++)
    {
        free(listado[i].NombreCliente);  //libero los nombres
        free(listado[i].Productos); //libero el vector de los productos

    }
        free(listado); //libero el arreglo del cliente
    return 0;
}