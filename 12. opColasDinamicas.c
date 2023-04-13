#include <stdio.h>
#include <stdlib.h>

typedef struct cola{
    int data;
    struct cola *next;
}node;

typedef struct colaD{
    node *front;
    node *rear;
}queue;

queue *q1, *q2, *q3;

void create_queue(queue *q);
void insert(queue *q, int d);
void delete(queue *q);
void display(queue *q);
void display_rev(queue *q);
void disrev(node *n);
void concatenar(queue *q1, queue *q2, queue *q3);

int main()
{
    int data, op1 = 0, op2 = 0;

    q1 = (queue*)malloc(sizeof(queue));
    create_queue(q1);
    q2 = (queue*)malloc(sizeof(queue));
    create_queue(q2);
    q3 = (queue*)malloc(sizeof(queue));
    create_queue(q3);

    do {
        system("cls");
        printf("\nOPCIONES:\n");
        printf(" 1) Modificar Cola 1\n 2) Modificar Cola 2 \n 3) Imprimir Colas\n 4) Inversa de las Colas\n 5) Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &op1);
        switch (op1) {
            case 1:
                system("cls");
                printf("\nOperaciones disponibles: \n");
                printf("1. Insertar elemento\n");
                printf("2. Borrar elemento\n");
                printf("3. Concatenar con cola 2\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &op2);
                switch (op2) {
                    case 1:
                        system("cls");
                        printf("Ingrese el elemento a insertar: ");
                        scanf("%d", &data);
                        insert(q1, data);
                        break;
                    case 2:
                        delete(q1);
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        create_queue(q3);
                        concatenar(q1, q2, q3);
                        break;
                    default:
                        system("cls");
                        printf("Opcion no valida\n");
                        break;
                    }
                break;
            case 2:
                system("cls");
                printf("\nOperaciones disponibles: \n");
                printf("1. Insertar elemento\n");
                printf("2. Borrar elemento\n");
                printf("3. Concatenar con cola 1\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &op2);
                switch (op2) {
                    case 1:
                        system("cls");
                        printf("Ingrese el elemento a insertar: ");
                        scanf("%d", &data);
                        insert(q2, data);
                        break;
                    case 2:
                        delete(q2);
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        create_queue(q3);
                        concatenar(q2, q1, q3);
                        break;
                    default:
                        system("cls");
                        printf("Opcion no valida\n");
                        break;
                    }
                break;
            case 3:
                system("cls");
                printf("COLA 1: ");
                display(q1);
                printf("COLA 2: ");
                display(q2);
                printf("COLA CONCATENADA: ");
                display(q3);
                break;
            case 4:
                system("cls");
                printf("COLA 1 inversa: ");
                display_rev(q1);
                printf("COLA 2 inversa: ");
                display_rev(q2);
                printf("COLA CONCATENADA inversa: ");
                display_rev(q3);
                break;
            case 5:
                system("cls");
                printf("\nFIN DEL PROGRAMA\n");
                break;
            default:
                system("cls");
                printf("Opcion no valida\n");
                break;
        }
    } while (op1 != 5);

    return 0;
}

void create_queue(queue *q)
{
    q->front = q->rear = NULL;
}

void concatenar(queue *q1, queue *q2, queue *q3){
    // Copy elements from q1 to q3
    node *ptr = q1->front;
    while (ptr != NULL) {
        insert(q3, ptr->data);
        ptr = ptr->next;
    }

    // Copy elements from q2 to q3
    ptr = q2->front;
    while (ptr != NULL) {
        insert(q3, ptr->data);
        ptr = ptr->next;
    }
}

void insert(queue *q, int d){
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->data = d;
    if(q->front == NULL)
    {
        q->front = q->rear = ptr;
        q->front->next = q->rear->next = NULL;
    }
    else
    {
        q->rear = q->rear->next = ptr;
        q->rear->next = NULL;
    }
}

void delete(queue *q) {
    node *ptr;
    if(q->front == NULL) {
        printf("La cola esta vacia\n");
        return;
    }
    ptr = q->front;
    q->front = q->front->next;
    free(ptr);
}

void display(queue *q) {
    node *ptr;
    if(q->front == NULL) {
        printf("La cola esta vacia\n");
        return;
    }
    ptr = q->front;
    while(ptr != NULL) {
        printf("[%d]", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void display_rev(queue *q) {
    if(q->front == NULL) {
        printf("La cola esta vacia\n");
        return;
    }
    disrev(q->front);
    printf("\n");
}

void disrev(node *n) {
    if(n == NULL) {
        return;
    }
    disrev(n->next);
    printf("[%d]", n->data);
}
