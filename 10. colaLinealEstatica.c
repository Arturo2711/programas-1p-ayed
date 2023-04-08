#include <stdlib.h>
#include <stdio.h>
#define MAX 5

typedef int tipoDato;
typedef struct queue{
    tipoDato A[MAX];
    int front;
    int rear;
} Cola;

void vaciarCola(Cola *q);
int colaLlena(Cola *q);
int colaVacia(Cola *q);
void insertarElemento(Cola *q, tipoDato dato);
tipoDato quitarElemento(Cola *q);
tipoDato front(Cola *q);
tipoDato rear(Cola *q);
void mostrarCola(Cola *q);

int main(){
    int salir=0, opc;
    Cola q;
    tipoDato dato;
    vaciarCola(&q);
    do{
        system("cls");
        printf("\t\tMENU\n");
        printf("1. Insertar elemento (Encolar)\n");
        printf("2. Eliminar elemento (Desencolar)\n");
        printf("3. Cola llena\n");
        printf("4. Cola vacia\n");
        printf("5. Frente\n");
        printf("6. Final\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);
        switch(opc){
            case 1: //Encolar
                system("cls");
                mostrarCola(&q);
                printf("\n\t\tENCOLAR\n");
                printf("\nValor a ingresar a la cola: ");
                scanf("%d", &dato);
                insertarElemento(&q, dato);
            break;
            case 2: //Desencolar
                system("cls");
                mostrarCola(&q);
                printf("\n\t\tDESENCOLAR\n");
                dato = quitarElemento(&q);
                (dato==-1)
                ? (printf("No hay elementos que quitar\n"))
                : (printf("Se ha quitado el elemento %d", dato));
            break;
            case 3: //Cola llena
                system("cls");
                colaLlena(&q);
            break;
            case 4: //Cola vacia
                system("cls");
                colaVacia(&q);
            break;
            case 5: //Frente
                system("cls");
                mostrarCola(&q);
                printf("\n\t\tFRONT\n");
                dato = front(&q);
                (dato==-1) 
                ? (printf("No hay elemento front, pues la cola esta vacia"))
                : (printf("El elemento front en la cola es %d", dato));
            break;
            case 6: //Final
                system("cls");
                mostrarCola(&q);
                printf("\n\t\tREAR\n");
                dato = rear(&q);
                (q.rear<0) 
                ? (printf("No hay elemento rear, pues la cola esta vacia"))
                : (printf("El elemento rear en la cola es %d", dato));
            break;
        }
        printf("\nDesea realizar otra operacion? 1. No 2. Si: ");
        scanf("%d", &salir);
    }while(salir!=1);
    return 0;
}

int colaLlena(Cola *q){
    if(q->rear > MAX-2){
        printf("La cola esta llena\n");
        return 0;
    }else{
        printf("La cola no esta llena\n");
        return 1;
    }
}

void vaciarCola(Cola *q){
    q->front = 0;
    q->rear = -1;
}

void insertarElemento(Cola *q, tipoDato dato){
    int dec;
    dec = colaLlena(q);
    if(dec == 1){
        q->rear++;
        q->A[q->rear] = dato;
    }
}

void mostrarCola(Cola *q){
    int i;
    for (i = q->front; i <= q->rear; i++) {
        printf("[%d]", q->A[i]);
    }
    printf("\n");
}

int colaVacia(Cola *q){
    if((q->front==0 && q->rear==-1) || (q->rear==MAX)){
        printf("La cola esta vacia\n");
        return -1;
    }else{
        printf("La cola no esta vacia\n");
        return 1;
    }
}

tipoDato quitarElemento(Cola *q){
    tipoDato aux;
    if((q->front==0 && q->rear==-1) || (q->rear==MAX) || (q->rear<q->front)){
        return -1;
    }else{
        aux = q->A[q->front];
        q->front++;
        return aux;
    }
}

tipoDato front(Cola *q){
    tipoDato aux;
    if(colaVacia(q)<0){
        return -1;
    }else{
        aux = q->A[q->front];
        return aux;
    }
}

tipoDato rear(Cola *q){
    tipoDato aux;
    if(q->rear >= 0){
        aux = q->A[q->rear];
        //return aux;
    }else{
        aux = -1;
    }
    return aux;
}