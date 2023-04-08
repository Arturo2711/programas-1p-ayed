#include<stdio.h>
#include<stdlib.h>
#define enter 13
#define true 1
#define false 0
struct pila
{
    char *p;
    int tope;    
};
//inicializadores 
void iniciarPila(struct pila *a);
void push(struct pila *a,char in);
int pop(struct pila *a);
void imprimirPila(struct pila a);
char top(struct pila a);
int vacio(struct pila*a);

void iniciarPila(struct pila *a){
    a->p=(char*)malloc(1*sizeof(char));
    a->tope=-1;
}
void push(struct pila *a,char in){
    a->tope++;
    a->p=realloc(a->p,sizeof(char)*(a->tope+1));
    a->p[a->tope]=in;
}
int pop(struct pila *a){
    char aux=a->p[a->tope];
    a->tope--;
    a->p=realloc(a->p,sizeof(char)*(a->tope+1));    
    return aux;
}
void imprimirPila(struct pila a){
for (int i = a.tope; i>=0; i--)
    {
        printf("\n[%c]",a.p[i]);
    } 
}
int vacio(struct pila*a){
    if ((a->tope)==-1)
    {
        return true;
    }
    else{
        return false;
    }
}
char top(struct pila a){
    //esta funcion es parecida a pop pero solo hace una consulta y devuelve el valor al tope, no modifica la pila
    char aux;
    if (vacio(&a))
    {
        printf("La pila esta vacia, no tiene ningun dato en el tope\n");
    }
    else{
        aux=a.p[a.tope];
        return aux;
    }

}