//Lista lineal doblemente ligada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista_Doble
{
    char *data;
    struct Lista_Doble *next;
    struct Lista_Doble *prior;
}list;

list *front = NULL;
list *rear = NULL;

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
    list *apt;
    apt = (list*)malloc(sizeof(list));
    apt->data = (char*)malloc(sizeof(char)*(strlen(data)+1));
    strcpy(apt->data, data);
    apt->next = NULL;
    apt->prior = NULL;

    front = apt;
    rear = apt;
}

void insert_start(char *data){
    list *apt;
    apt = (list*)malloc(sizeof(list));
    apt->data = (char*)malloc(sizeof(char)*(strlen(data)+1));
    strcpy(apt->data, data);

    if (empty())
    {
        printf("First create a node !! \n");
    }
    else
    {
        apt->next = front;
        apt->prior = NULL;
        front->prior = apt;
        front = apt;
    }
}

void insert_end(char *data){
    list *apt;
    apt = (list*)malloc(sizeof(list));
    apt->data = (char*)malloc(sizeof(char)*(strlen(data)+1));
    strcpy(apt->data, data);
    apt->next = NULL;

    if (empty())
    {
        printf("First create a node !! \n");
    }
    else
    {
        apt->prior = rear;
        rear->next = apt;
        rear = apt;

    }
}

void insert_position(int post, char *data){
    if (empty())
    {
        printf("First create a node !! \n");
    }
    else
    {
        if (post == 1)
        {
            insert_start(data);
        }
        else
        {
            list *apt;
            apt = (list*)malloc(sizeof(list));
            apt->data = (char*)malloc(sizeof(char)*(strlen(data)+1));
            strcpy(apt->data, data);

            list *aux;
            list *aux2;
            aux = front;

            for (int i = 1; i < post-1; i++)
            {
                aux = aux->next;
            }
            aux2 = aux->next;

            apt->next = aux2;
            aux2->prior = apt;
            apt->prior = aux;
            aux->next = apt;
        }
    }   
}

char *delete_item(int postn){
    list *aux;
    char *straux;

    if (postn == 1)
    {
        aux = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        else
        {
            front->prior = NULL;
        }
    }
    else
    {
        if (postn == -1)
        {
            aux = rear;
            if (rear->prior == NULL)
            {
                rear = rear->prior;
                front = front->prior;
            }
            else
            {
                rear = rear->prior;
                rear->next = NULL;
            }
        }
        else
        {
            aux = front;
            for (int i = 1; i < postn; i++)
            {
                aux = aux->next;
            }
            aux->next->prior = aux->prior;
            aux->prior->next = aux->next;
        }
    }
    straux = (char*)malloc(sizeof(char)*(strlen(aux->data)+1));
    strcpy(straux, aux->data);
    free(aux->data);
    free(aux);
    return straux;
}

int search_item(char *find){
    list *aux;
    aux = front;
    int i = 1;

    while (strcmp(aux->data, find) != 0)
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

char *search_position(int postn){
    list *aux;
    aux = front;

    for (int i = 1; i < postn; i++)
    {
        aux = aux->next;
    }
    return aux->data;
}

void display(){
    list *aux;
    int i = 1;
    aux = front;

    while (aux != NULL)
    {
        printf("\t \t (%d) %s \n", i, aux->data);
        aux = aux->next;
        i++;
    }
}

void destroy_list(){
    while (front != NULL)
    {
        list *aux;
        aux = front;
        front = front->next;
        front->prior = NULL;
        free(aux->data);
        free(aux);
    }
}

int menu(){
    int op;
    printf("\t  MENU \n");
    printf(" (1) Create node \n");
    printf(" (2) Insert at start \n");
    printf(" (3) Insert at end \n");
    printf(" (4) Insert at position \n");
    printf(" (5) Delete at start \n");
    printf(" (6) Delete at end \n");
    printf(" (7) Delete at position \n");
    printf(" (8) Search item \n");
    printf(" (9) Search in position \n");
    printf(" (0) Exit \n ");
    printf("Enter a option: ");
    scanf("%d", &op);
    return op;
}

int main(){
    int op, post, aux;
    char data[50];

    op = menu();
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
            printf("Enter position: ");
            scanf("%d", &post);
            insert_position(post, data);
            break;
        case 5:
            post = 1;
            printf("The information that has been removed is: %s \n", delete_item(post));
            break;
        case 6:
            post = -1;
            printf("The information that has been removed is: %s \n", delete_item(post));
            break;
        case 7:
            printf("Enter position: ");
            scanf("%d", &post);
            printf("The information that has been removed is: %s \n", delete_item(post));
            break;
        case 8:
            printf("Enter the item to search: ");
            fflush(stdin);
            scanf("%[^\n]", &data);
            aux = search_item(data);
            if (aux != 0)
            {
                printf("%s is at position (%d) \n", data, aux);
            }
            else
            {
                printf("There is no similar item in the list !! \n");
            }
            break;
        case 9:
            printf("Enter the position to search: ");
            scanf("%d", &post);
            printf("The item found in position (%d) is: %s \n", post, search_position(post));
            break;
        default:
        printf("Invalid option \n");
            break;
        }
        display();
        op = menu();
    }
    
    printf("\t \t The program has ended \n");
    destroy_list();
    return 0;
}