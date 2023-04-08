#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef int tipoDato;

typedef struct stack{
    tipoDato valor;
    struct stack * sig;
}Pila;

Pila *top = NULL;

void mostrarPila(Pila * top);
void push(tipoDato dato);
tipoDato pop();
void inicializarPila();
void pilaVacia();
tipoDato topePila();

int main(){
    int opc, salir =0;
    Pila p;
    tipoDato dato;
    do{
        system("cls");
        printf("\tMENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Inicializar pila\n");
        printf("4. Pila vacia\n");
        printf("5. Tope de pila\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                system("cls");
                mostrarPila(top);
                printf("\t\tPUSH\n");
                printf("\nValor a ingresar a la pila: ");
                scanf("%d", &dato);
                push(dato);
            break;
            case 2:
                system("cls");
                mostrarPila(top);
                printf("\t\tPOP\n");
                dato = pop();
                printf("Se ha quitado el elemento %d", dato);
            break;
            case 3:
                system("cls");
                printf("\t\tINICIALIZAR PILA\n");
                inicializarPila();
            break;
            case 4:
                system("cls");
                printf("\t\tPILA VACIA\n");
                pilaVacia();
            break;
            case 5:
                dato = topePila();
                system("cls");
                printf("\t\tTOPE PILA\n");
                printf("El tope de pila es: %d", dato);
            break;
            default:
                printf("Opcion no valida, por favor digite una opcion valida");
            break;
        }
        printf("\nDesea realizar otra operacion? 1. No 2. Si: ");
        scanf("%d", &salir);
    }while(salir!=1);
    return 0;
}

void mostrarPila(Pila *top){
    Pila *ptr;
    ptr = top;
    if(top==NULL){
        printf("La pila esta vacia\n");
    }else{
        while(ptr!=NULL){
            printf("[%d]\n", ptr->valor);
            ptr = ptr->sig;
        }
    }
}

void push(tipoDato dato){
    Pila *newDato;
    newDato = malloc(sizeof(Pila));
    newDato->valor = dato;
    if(top == NULL){
        top = newDato;
        newDato->sig = NULL;
    }else{
        newDato->sig=top;
        top = newDato;
    }
}

tipoDato pop(){
    tipoDato aux;
    if(top!=NULL){
        aux = top->valor;
        Pila *borrar = top;
        top = top->sig;
        free(borrar);
        return aux;
    }else{
        return -1;
    }
}

void inicializarPila(){
    top = NULL;
    printf("La pila ya esta vacia");
}

void pilaVacia(){
    if(top==NULL){
        printf("\nLa pila esta vacia");
    }else{
        printf("\nLa pila no esta vacia");
    }
}

tipoDato topePila(){
    if(top==NULL)
        return -1;
    return top->valor;
}