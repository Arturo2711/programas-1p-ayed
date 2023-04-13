#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX 6

typedef struct alumnos{
    char nombre[50];
    char apellido[50];
    float promedio;
}Alumno;

typedef struct queue{
    Alumno A[MAX];
    int front;
    int rear;
} Cola;

void vaciarCola(Cola *q);
int colaLlena(Cola *q);
int colaVacia(Cola *q);
void mostrarCola(Cola *q);

void insertarAlumno(Cola *q, Alumno al);
void generarAlumnos(Cola *q);
void mostrarAlumnoLlega(Alumno alumno);
void ordenarDes(Cola *q);
void inscribirAlumnos(Cola *estMat, Cola *estIns, Cola *estEsp);
Alumno quitarAlumno(Cola *q);
void moverAlumno(Cola* colaOrigen, Cola* colaDestino, int caso);

int main(){
    Cola alMatriculados, alInscritos, alEnEspera;
    vaciarCola(&alMatriculados);
    vaciarCola(&alInscritos);
    vaciarCola(&alEnEspera);
    generarAlumnos(&alMatriculados);
    mostrarCola(&alMatriculados);
    printf("\n\n");
    inscribirAlumnos(&alMatriculados, &alInscritos, &alEnEspera);  
}

void generarAlumnos(Cola *q){
    int i=1, min=1;
    Cola espera; 
    Alumno alumno;
    char *nombres[] = {"Juan", "Daniel", "Alejandro", "Maria", "Pedro", "Lucia", "Javier", "Ana", "Luis", "Carla", "Diego", "Laura"};
    char *apellidos[] = {"Garcia", "Gachuz", "Perez", "Fonseca", "Fernandez", "Gonzalez", "Hernandez", "Ruiz", "Gomez", "Sanchez", "Martinez", "Jimenez"};
    float promedios[] = {6.0, 10.0, 9.8, 6.6, 6.2, 8.0, 9.2, 9.1, 8.4, 8.9};

    int num_nombres = sizeof(nombres) / sizeof(nombres[0]);
    int num_apellidos = sizeof(apellidos) / sizeof(apellidos[0]);
    int num_promedios = sizeof(promedios) / sizeof(promedios[0]);

    srand(time(NULL));

    for(i = 0; i < MAX; i++){
        int indice_nombre = rand() % num_nombres;
        int indice_apellido = rand() % num_apellidos;
        int indice_promedios = rand() % num_promedios;
        strcpy(alumno.nombre, nombres[indice_nombre]);
        strcpy(alumno.apellido, apellidos[indice_apellido]);
        alumno.promedio = promedios[indice_promedios];
        insertarAlumno(q, alumno);
    }
}

void insertarAlumno(Cola *q, Alumno alumno){
    if (q->rear == MAX - 1) {
        printf("La cola está llena.\n");
    }else{
        q->rear++;
        q->A[q->rear] = alumno;
    }
}

Alumno quitarAlumno(Cola *q) {
    Alumno aux;
    if(colaVacia(q)){
        printf("\nLa cola esta vacia");
    }else{
        aux = (q->A[q->front]);
        q->front++;
        return aux;
    }
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

int colaVacia(Cola *q){
    if((q->front==0 && q->rear==-1) || (q->rear==MAX)){
        printf("La cola esta vacia\n");
        return -1;
    }else{
        printf("La cola no esta vacia\n");
        return 1;
    }
}

void mostrarCola(Cola *q){
    int i;
    for (i = q->front; i <= q->rear; i++) {
        printf("Nombre: %s\n", q->A[i].nombre);
        printf("Apellido: %s\n", q->A[i].apellido);
        printf("Promedio: %.2f\n", q->A[i].promedio);
    }
}


void ordenarDes(Cola *q){
    int i, j;
    Alumno temp;
    for (i = 0; i < MAX - 1; i++) {
        for (j = 0; j < MAX - i - 1; j++) {
            if (q->A[j].promedio < q->A[j+1].promedio) {
                temp = q->A[j];
                q->A[j] = q->A[j+1];
                q->A[j+1] = temp;
            }
        }
    }
}

void inscribirAlumnos(Cola *estMat, Cola *estIns, Cola *estEsp){
    int numA = 1, numMin=1;
    moverAlumno(estMat, estIns, 1);
    while (numA <= MAX || (numA > MAX && numMin<MAX*3)){
        moverAlumno(estMat, estEsp, 2);
        if(numMin%3==0){
            ordenarDes(estEsp);
            printf("\nCOLA ESPERA\n");
            mostrarCola(estEsp);
            moverAlumno(estEsp, estIns, 3);
            quitarAlumno(estEsp);            
            printf("\nCOLA INSCRITOS\n");
            mostrarCola(estIns);
        }
        numMin++;
        numA++;
    }  
}

void moverAlumno(Cola* colaOrigen, Cola* colaDestino, int caso) {
    //Caso: 1 -> moverAlumno(estMat, estIns) (Muestra el primer alumno inscrito)
    //Caso: 2 -> moverAlumno(estMat, estEsp) (Muestra que ha llegado tal alumno)
    //Caso: 3 -> moverAlumno(estEsp, estIns) (Muestra que se ha inscrito tal alumno y el que sigue)
    if (colaOrigen->front == -1) {
        printf("La cola de origen esta vacia.\n");
    } else {
        // Sacamos el alumno de la cola de origen
        Alumno alumno = colaOrigen->A[colaOrigen->front];
        if (colaOrigen->front == colaOrigen->rear) {
            // Si solo había un elemento en la cola, la dejamos vacía
            colaOrigen->front = -1;
            colaOrigen->rear = -1;
        } else {
            // Si había más de un elemento, avanzamos el frente de la cola
            colaOrigen->front = (colaOrigen->front + 1) % MAX;
        }
        // Agregamos el alumno a la cola de destino
        if (colaDestino->front == -1) {
            // Si la cola de destino estaba vacía, la inicializamos
            colaDestino->front = 0;
            colaDestino->rear = 0;
        } else {
            // Si ya había elementos en la cola, avanzamos el final
            colaDestino->rear = (colaDestino->rear + 1) % MAX;
        }
        colaDestino->A[colaDestino->rear] = alumno;

        // Mostramos información adicional según el tipo de cola de destino
        if (caso == 1) {
            printf("Se ha inscrito el alumno %s %s con promedio %.2f.\n",
                   alumno.nombre, alumno.apellido, alumno.promedio);
        } else if (caso == 2) {
            printf("Ha llegado el alumno %s %s con promedio %.2f\n",
                   alumno.nombre, alumno.apellido, alumno.promedio);
        }else if (caso == 3) {
            printf("Se ha inscrito el alumno %s %s con promedio %.2f.\n",
                   alumno.nombre, alumno.apellido, alumno.promedio);
            printf("Siguiente alumno en inscribirse: %s %s con promedio %.2f\n",
                   colaOrigen->A[colaOrigen->front].nombre,
                   colaOrigen->A[colaOrigen->front].apellido,
                   colaOrigen->A[colaOrigen->front].promedio);
        }
    }
}
