#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define enter 13

typedef char tipoDato;

typedef struct stack{
    tipoDato *valor;
    int top;
}Pila;

void llenarPila(Pila *P, tipoDato letra);
void mostrarPila(Pila *P);
void vaciarPila(Pila *P);
void convInfAPos(Pila *P, Pila *Q, Pila *R);
int prioridad(char o);
int esOperador(char c);

int main(){
    char caracter;
    Pila exp, operadores, res;
    vaciarPila(&exp);
    vaciarPila(&operadores);
    vaciarPila(&res);
    printf("Ingrese la expresion en notacion infija: ");
    do{
        fflush(stdin);
        caracter=getche();
        if(caracter!=enter){
            llenarPila(&exp,caracter);
            caracter=NULL;
        }
        else break;
    } while (1);
    system("cls");
    printf("La expresion es: ");
    mostrarPila(&exp);
    printf("\nLa expresion en su notacion posfija es: ");
    convInfAPos(&exp, &operadores, &res);
    mostrarPila(&res);
    return 0;
}

void llenarPila(Pila *P, tipoDato letra){
    P->valor=(tipoDato *)realloc(P->valor,sizeof(char)*(P->top+1));
    P->valor[P->top]=letra;
    P->top++;
}

void mostrarPila(Pila *P){
    for(int i=0; i<P->top; i++){
        printf("%c", P->valor[i]);
    }
}

void vaciarPila(Pila *P){
    P->valor=(char*)malloc(1*sizeof(char));
    P->top = 0;
}

int esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int prioridad(char c) {
    switch(c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void convInfAPos(Pila *exp, Pila *operadores, Pila *res) {
    int i;
    char c, d;
    for(i = 0; i < exp->top; i++) {
        c = exp->valor[i];
        if(c == '('){
            llenarPila(operadores, c);
        }
        else if(c == ')'){
            while(operadores->top > 0 && operadores->valor[operadores->top-1] != '(') {
                d = operadores->valor[operadores->top-1];
                llenarPila(res, d);
                operadores->top--;
            }
            operadores->top--;
        }
        else if(!esOperador(c)) {
            llenarPila(res, c);
        }
        else {
            while(operadores->top > 0 && prioridad(operadores->valor[operadores->top-1]) >= prioridad(c)) {
                d = operadores->valor[operadores->top-1];
                llenarPila(res, d);
                operadores->top--;
            }
            llenarPila(operadores, c);
        }
    }
    while(operadores->top > 0) {
        d = operadores->valor[operadores->top-1];
        llenarPila(res, d);
        operadores->top--;
    }
}