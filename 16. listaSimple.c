//Lista lineal simplemente enlazada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista_Simple
{
    char *dato;
    struct Lista_Simple *next;
}lista;

lista *front = NULL;
lista *rear = NULL;

int empty(){
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void first_node(char *data){
    lista *apt;
    apt = (lista*)malloc(sizeof(lista));
    apt->dato = (char*)malloc(sizeof(char)*(strlen(data)+1));
    strcpy(apt->dato, data);
    apt->next = NULL;

    front = apt;
    rear = apt;
}

void insert_start(char *data){
    lista *apt;
    apt = (lista*)malloc(sizeof(lista));
    apt->dato = (char*)malloc(sizeof(char)*(strlen(data)+1));
    strcpy(apt->dato, data);

    if (empty())
    {
        printf("First create a node !! \n");
    }
    else
    {
        apt->next = front;
        front = apt;
    }
}

void insert_end(char *data){
    lista *apt;
    apt = (lista*)malloc(sizeof(lista));
    apt->dato = (char*)malloc(sizeof(char)*(strlen(data)+1));
    strcpy(apt->dato,data);
    apt->next = NULL;

    if (empty())
    {
        printf("First create a node !! \n");
    }
    else
    {
        rear->next = apt;
        rear = apt;
    }
}

void insert_position(int p, char *data){
    lista *apt;
    apt = (lista*)malloc(sizeof(lista));
    apt->dato = (char*)malloc(sizeof(char)*(strlen(data)+1));
    strcpy(apt->dato,data);

    if (empty())
    {
        printf("First create a node !! \n");
    }
    else
    {
        lista *aux;
        aux = front;
        for (int i = 1; i < p-1; i++)
        {
            aux = aux->next;
        }

        apt->next = aux->next;
        aux->next = apt; 
        
    }
}

void delete_start(){
    lista *aux;
    if (empty())
    {
        printf("LIST UNDERFLOW \n");
    }
    else
    {
        aux = front;
        front = front->next;
    }
    printf("The information that has been removed is: %s \n ", aux->dato);
    free(aux->dato);    
    free(aux);
}

char delete_end(){
    lista *aux ;
    lista *aux2;
    aux = front;
    aux2 = rear;

    while (aux->next != rear)
    {
        aux = aux->next;
    }
    printf("The information that has been removed is: %s \n", aux2->dato);

    rear = aux;
    rear->next = NULL;

    free(aux2->dato);
    free(aux2);
}

int delete_position(int p){
    lista *aux;
    lista *aux2;
    aux = front;
    aux2 = front;
    
    for (int i = 1; i < p; i++)
    {
        aux2 = aux2->next;
    }

    for (int j = 1; j < p-1; j++)
    {
        aux = aux->next;
    }
    aux->next = aux2->next;
    
    printf("The information that has been removed is: %s \n", aux2->dato);

    free(aux2->dato);
    free(aux2);

}

void display(){
    int i = 1;
    lista *apt;
    apt = front;
    while (apt != NULL)
    {
        printf("(%d) %s \n",i, apt->dato);
        i++;
        apt = apt->next;
    }
}

int search_item(char *find){
    lista *aux;
    aux = front;
    int i = 1;

    while (strcmp(aux->dato, find) != 0)
    {
        aux = aux->next;

        if (aux == NULL)
        {
            return 0;
        }
        
        i++;
    }
    
    return i;
}

char *search_position(int p){
    lista *aux;
    aux = front;

    for (int i = 1; i < p; i++)
    {
        aux = aux->next;
    }

    return aux->dato;
}

int menu(){
    int op;
    printf("\t \t MENU \n");
    printf("\t (1) Create node \n");
    printf("\t (2) Insert at start \n");
    printf("\t (3) Insert at end \n");
    printf("\t (4) Insert at position \n");
    printf("\t (5) Delete at start \n");
    printf("\t (6) Delete at end \n");
    printf("\t (7) Delete at position \n");
    printf("\t (8) Search item \n");
    printf("\t (9) Search in position \n");
    printf("\t (0) Exit \n ");
    printf("What option do you want: ");
    scanf("%d", &op);
    return op;
}

int main(){
    int op, aux;
    op = menu();
    int post;
    char data[50];

    while (op != 0)
    {
        switch (op)
        {
        case 1:
            printf("Enter a string: ");
            fflush(stdin);
            scanf("%[^\n]", &data);
            first_node(data);
            break;
        case 2:
            printf("Enter a string: ");
            fflush(stdin);
            scanf("%[^\n]", &data);
            insert_start(data);
            break;
        case 3:
            printf("Enter a string: ");
            fflush(stdin);
            scanf("%[^\n]", &data);
            insert_end(data);
            break;
        case 4:
            printf("Enter a string: ");
            fflush(stdin);
            scanf("%[^\n]", &data);
            printf("Enter the position: ");
            scanf("%d", &post);
            insert_position(post, data);
            break;
        case 5:
            delete_start();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            printf("Enter the position: ");
            scanf("%d", &post);
            delete_position(post);
            break;
        case 8:
            printf("Enter the item to search: ");
            fflush(stdin);
            scanf("%[^\n]", &data);
            aux = search_item(data);
            if (aux != 0)
            {
                printf("%s is at position %d \n", data, aux);
            }
            else
            {
                printf("There is no similar item in the list !! \n");
            }
            break;
        case 9:
            printf("Enter the position to search: ");
            scanf("%d", &post);
            printf("The item to find in the position %d is: %s \n", post, search_position(post));
            break;
        default:
            printf("Invalid option \n");
            break;
        }
        display();
        op = menu();
    }
    printf("\t \t The program has ended \n");
    return 0;
}

