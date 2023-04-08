#include <stdlib.h>
#include <stdio.h>
#define MAX 5

typedef int tipoDato;
typedef struct pila{
    tipoDato A[MAX];
    int top;
} Pila;

void vaciarPila(Pila *P);
void push(Pila *P, tipoDato dato);
tipoDato pop(Pila *P);
int pilaLlena(Pila *P);
int pilaVacia(Pila *P);
tipoDato top(Pila *P);

void mostrarPila(Pila *P);

int main(){
    int salir=0, opc;
    Pila p;
    tipoDato dato;
    vaciarPila(&p);
    do{
        system("cls");
        printf("MENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Pila llena\n");
        printf("5. Pila vacia\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);
        switch(opc){
            case 1: //Push
                system("cls");
                mostrarPila(&p);
                printf("\t\tPUSH\n");
                printf("\nValor a ingresar a la pila: ");
                scanf("%d", &dato);
                push(&p, dato);
            break;
            case 2: //Pop
                system("cls");
                mostrarPila(&p);
                printf("\t\tPOP\n");
                dato = pop(&p);
                printf("Se ha quitado el elemento %d", dato);
            break;
            case 3: //Top
                system("cls");
                mostrarPila(&p);
                printf("\t\tTOP\n");
                dato = top(&p);
                (p.top>0) 
                ? (printf("El elemento superior en la pila es %d", dato)) 
                : (printf("No hay elemento superior, pues la pila esta vacia"));
            break;
            case 4: //Pila llena
                system("cls");
                pilaLlena(&p);
            break;
            case 5: //Pila vacia
                system("cls");
                pilaVacia(&p);
            break;
        }
        printf("\nDesea realizar otra operacion? 1. No 2. Si: ");
        scanf("%d", &salir);
    }while(salir!=1);
    return 0;
}

void mostrarPila(Pila *P){
    printf("Top: %d\n", P->top);
    for(int i=4; i>=0; i--){
        printf("[%d]\n", P->A[i]);
    }
}

int pilaLlena(Pila *P){
    if(P->top > MAX-1){
        printf("La pila esta llena\n");
        return 0;
    }else{
        printf("La pila no esta llena\n");
        return 1;
    }
}

int pilaVacia(Pila *P){
    if(P->top == 0){
        printf("La pila esta vacia\n");
        return 0;
    }else{
        printf("La pila no esta vacia\n");
        return 1;
    }
}

void push(Pila *P, tipoDato dato){
    int dec;
    dec = pilaLlena(P);
    if(dec == 1){
        P->A[P->top] = dato;
        P->top++;
    }
}

tipoDato pop(Pila *P){
    tipoDato aux;
    if(P->top==0)
        printf("No hay elementos que quitar\n");
    else{
        aux = P->A[P->top-1];
        P->top--;
    }
    return aux;
}

void vaciarPila(Pila *P){
    P->top = 0;
}

tipoDato top(Pila *P){
    tipoDato aux;
    if(P->top>=0)
        aux = P->A[P->top-1];
    return aux;
}
