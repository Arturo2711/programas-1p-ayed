//Cola dinamica

#include <stdio.h>
#include <stdlib.h>

typedef struct ColasD
{
    int data;
    struct ColasD *next;
}nodo;

nodo *front = NULL;
nodo *rear = NULL;

int vacia(){
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert(int data){
    nodo *apt;
    apt = (nodo*)malloc(sizeof(nodo));
    apt->data = data;
    apt->next = NULL;
    if (vacia())
    {
        front = apt;
        rear = apt;
    }
    else
    {
        rear->next = apt;
        rear = apt;
    }
    
}

int delete(){
    int aux;
    nodo *apt;
    apt = front;
    if (vacia())
    {
        printf("QUEUE UNDERFLOOW !!! \n");
    }
    else
    {
        printf("The number that has been removed is: %d \n", apt->data);
        front = front->next;
        aux = apt->data;
    }
    free(apt);
    return aux;
}

void peek(){
    if (vacia())
    {
        printf("QUEUE IS EMPTY !! \n");
    }
    else
    {
        printf("The last number in is: %d \n", rear->data);
    }
}

void display(){
    nodo *apt;
    apt = front;
    while (apt != NULL)
    {
        printf("[%d] ", apt->data);
        apt = apt->next;
    }
    printf("\n");
}

int menu(){
    int op;
    printf(" \t \t QUEUE MAIN MENU \n");
    printf("(1) Insert data \n");
    printf("(2) Delete data \n");
    printf("(3) Peek \n");
    printf("(0) Exit \n");

    printf("Which option do you want: ");
    scanf("%d", &op);
    return op;
}

int main(){
    int opc;
    int data;
    opc = menu();

    while (opc != 0)
    {
        switch (opc)
        {
        case 1:
            printf("Insert number: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            delete();
            break;
        case 3:
            peek();
            break;
        default:
        printf("Invalid option \n");
            break;
        }
        display();
        opc = menu();
    }

    printf("The program has ended \n");
    return 0;
}