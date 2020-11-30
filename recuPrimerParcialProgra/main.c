#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

//1. Crear una función llamada calcularIVA que reciba como parámetro el precio bruto de un producto
 //y devuelva el valor del impuesto (el IVA es 21%). Realizar la llamada desde main. *

//2. Crear una función que se llame reemplazarCaracter que reciba una cadena de caracteres como primer parámetro, como segundo parámetro el carácter
 //a reemplazar y como tercero el nuevo carácter y devuelva la cantidad de veces que se reemplazo el carácter. int reemplazarCaracter(char [], char, char);

//3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha estructura por marca.
 //Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.


typedef struct{
    int id;
    int procesador;
    char marca[20];
    int precio;
}eNotebook;


float calcularIVA(float pBruto);
int reemplazarCaracter(char string[], char a, char b);
int ordenarNotebooksMarcaPrecio(eNotebook lista[], int tam);
void mostrarNotebook(eNotebook unaNotebook);
int mostrarNotebooks(eNotebook lista[], int tam);



int main()
{


    // todo este main es para probar todas las funciones en tiempo de ejecucion

    float precioBruto = 250;
    char string[20];
    char caracter;
    char reemplazar;
    int cantidad ;
    // hardcoddeo de lista
    eNotebook lista[4] = {{200,345,"asus",30000},{210,350,"bangho",50000},{220, 500, "compaq", 75000},{240,200,"bgh",25000},};

    mostrarNotebooks(lista, TAM);

    ordenarNotebooksMarcaPrecio(lista, TAM);

    mostrarNotebooks(lista, TAM);


    printf("\n\nEl iva es : %f\n\n", calcularIVA(precioBruto));



    printf("Ingrese la cadena: ");
    fflush(stdin);
    scanf("%s", string);
    printf("\nIngrese el caracter a buscar: ");
    fflush(stdin);
    scanf("%c", &caracter);
    printf("\nIngrese el caracter reemplazante: ");
    fflush(stdin);
    scanf("%c", &reemplazar);

    cantidad = reemplazarCaracter(string,caracter,reemplazar);

    printf("El string quedo asi: %s",string);
    printf("se reemplazo %d veces", cantidad);






}
/////////// ejercicio 1
float calcularIVA(float pBruto)
{
    float iva = pBruto*0.21;

    return iva;
}

//////////// ejercicio 2
int reemplazarCaracter(char string[], char a, char b)
{
    int contador = 0;
    int i = 0;

    while ( string[i] != '\0' )
    {
        if(string[i] == a)
        {
        	string[i] = b;
            contador++;
        }
        i++;
    }
    return contador;
}

////////////// ejercicio 3
int ordenarNotebooksMarcaPrecio(eNotebook lista[], int tam)
{
    int error = 1 ;
    eNotebook auxNote;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1 ; i++)
        {
            for(int j = i+1; j < tam ; j++)
            {
                if(strcmp((lista[i].marca), (lista[j]).marca) > 0)
                {
                    auxNote = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxNote;
                }
                else if(strcmp((lista[i].marca), (lista[j]).marca) == 0 && lista[i].precio > lista[j].precio)
                {
                    auxNote = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxNote;
                }
            }
        }

        error = 0;
    }

    return error;
}


///// funciones de prueba para ver que funcione todo bien (las tenia del parcial 2 )

void mostrarNotebook(eNotebook unaNotebook)
{
	printf("%d    %7s    %d    %d\n", unaNotebook.id, unaNotebook.marca,unaNotebook.precio, unaNotebook.procesador);
}

int mostrarNotebooks(eNotebook lista[], int tam)
{
    printf("Lista de notebooks\n\n");
    printf("ID        Marca   Precio  Procesador\n\n");
    for(int i  = 0 ; i < tam ; i++)
    {
        mostrarNotebook(lista[i]);
    }
    return 0;
}
