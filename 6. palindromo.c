#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define enter 13

typedef char tipoDato;

typedef struct stack{
    tipoDato *valor;
    int top;
}Pila;

void pedirLetra(Pila *P, tipoDato letra);
void mostrarPila(Pila *P);
void vaciarPalabra(Pila *P);
void esPalindromo(Pila *P);

int main(){
    // Solo para un fork 
    char letra;
    Pila p;
    vaciarPalabra(&p);
    printf("Ingrese la palabra: ");
    do{
        fflush(stdin);
        letra=getche();
        if(letra!=enter){
            pedirLetra(&p,letra);
            letra=NULL;
        }
        else break;
    } while (1);
    mostrarPila(&p);
    esPalindromo(&p);
    return 0;
}

void pedirLetra(Pila *P, tipoDato letra){
    P->valor=(tipoDato *)realloc(P->valor,sizeof(char)*(P->top+1));
    P->valor[P->top]=letra;
    P->top++;
}

void mostrarPila(Pila *P){
    for(int i=P->top-1; i>=0; i--){
        printf("\n[%c]", P->valor[i]);
    }
}

void vaciarPalabra(Pila *P){
    P->valor=(char*)malloc(1*sizeof(char));
    P->top = 0;
}

void esPalindromo(Pila *P){
    Pila dos;
    int aux=0;
    vaciarPalabra(&dos);
    for (int i = P->top-1; i>=0; i--)
        pedirLetra(&dos,P->valor[i]); 
    for (int i = P->top-1; i>=0; i--){
        if (P->valor[i]!=dos.valor[i]){
            aux=1;
            break;
        }
    }
    (aux==1)
    ? (printf("\nLa palabra no es un palindromo\n"))
    : (printf("\nLa palabra es un palindromo\n"));
}
