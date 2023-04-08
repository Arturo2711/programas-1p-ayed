#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

struct puntos crearPunto();
void distanciaEntreDosPuntos(struct puntos p1, struct puntos p2);
void puntoMedioEntreDosPuntos(struct puntos p1, struct puntos p2);
float pendienteEntreDosPuntos(struct puntos p1, struct puntos p2);
void ecuacionDeRecta(struct puntos p1,struct puntos p2, float m);
void mostrarX(struct puntos p1);
void mostrarY(struct puntos p1);

struct puntos{
    float x;
    float y;
};

int main(){
    int opc=1;
	struct puntos p1, p2;
	do{
		system("cls");
		printf("\tMENU\n");
		printf("1. Distancia entre dos puntos\n");
		printf("2. Punto medio\n");
        printf("3. Pendiente\n");
        printf("4. Ecuacion de la recta\n");
        printf("5. Mostrar X\n");
        printf("6. Mostrar Y\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                system("cls");
                p1 = crearPunto();
                p2 = crearPunto();
                distanciaEntreDosPuntos(p1, p2);
            break;
            case 2:
                system("cls");
                p1 = crearPunto();
                p2 = crearPunto();
                puntoMedioEntreDosPuntos(p1, p2);
            break;
            case 3:
                system("cls");
                p1 = crearPunto();
                p2 = crearPunto();
                pendienteEntreDosPuntos(p1, p2);
            break;
            case 4:
                system("cls");
                p1 = crearPunto();
                p2 = crearPunto();
                ecuacionDeRecta(p1, p2, pendienteEntreDosPuntos(p1,p2));
            break;
            case 5:
                system("cls");
                p1 = crearPunto();
                mostrarX(p1);
            break;
            case 6:
                system("cls");
                p1 = crearPunto();
                mostrarY(p1);
            break;
            case 7:
                return 0;
            break;
            default:
                system("cls");
				printf("Opcion no valida");
			break;
        }
        printf("\nDesea hacer otra operacion? 1. Si 7. No: ");
		scanf("%d", &opc);
    }while(opc!=7);
    return 0;
}

struct puntos crearPunto(){
    struct puntos p;
    printf("Coordenada en X: ");
    scanf("%f", &p.x);
    printf("Coordenada en Y: ");
    scanf("%f", &p.y);
    return p;
}

void distanciaEntreDosPuntos(struct puntos p1, struct puntos p2){
    float d = sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
    printf("La distancia entre los puntos (%.2f, %.2f) y (%.2f, %.2f) es: %.2f", p1.x, p1.y, p2.x, p2.y, d);
}

void puntoMedioEntreDosPuntos(struct puntos p1, struct puntos p2){
    float xM, yM;
    xM = (p1.x+p2.x)/2;
    yM = (p1.y+p2.y)/2;
    printf("El punto medio entre los puntos (%.2f, %.2f) y (%.2f, %.2f) es: (%.2f, %.2f)", p1.x, p1.y, p2.x, p2.y, xM, yM);
}

float pendienteEntreDosPuntos(struct puntos p1, struct puntos p2){
    float m = (p2.y-p1.y)/(p2.x-p1.x);
    printf("La pendiente de la recta entre los puntos (%.2f, %.2f) y (%.2f, %.2f) es: %.2f", p1.x, p1.y, p2.x, p2.y, m);
    return m;
}

void ecuacionDeRecta(struct puntos p1,struct puntos p2, float m){
    float b = p1.y-m*p1.x;
    printf("\nLa ecuacion de la recta que pasa por los puntos (%.2f, %.2f) y (%.2f, %.2f) es: y=%.2f*x%c%.2f", p1.x, p1.y, p2.x, p2.y, 
                                                                m, (b<0 ? '-' : '+'), fabs(b));
}

void mostrarX(struct puntos p1){
    printf("La coordenada en X del punto (%.2f, %.2f) es: %.2f", p1.x, p1.y, p1.x);
}

void mostrarY(struct puntos p1){
    printf("La coordenada en Y del punto (%.2f, %.2f) es: %.2f", p1.x, p1.y, p1.y);
}