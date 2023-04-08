#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#define PI 3.14159265358979323846

void suma(struct numerosComplejos n1, struct numerosComplejos n2);
void resta(struct numerosComplejos n1, struct numerosComplejos n2);
void multiplicacion(struct numerosComplejos n1, struct numerosComplejos n2);
void cociente(struct numerosComplejos n1, struct numerosComplejos n2);
void magnitud(struct numerosComplejos n);
void conjugado(struct numerosComplejos n);
void angulo(struct numerosComplejos n);
void parteReal(struct numerosComplejos n);
void parteImaginaria(struct numerosComplejos n);
struct numerosComplejos crearNumeroComplejo();
void mostrarNumeroComplejo(struct numerosComplejos n);

struct numerosComplejos{
	float parteReal;
	float parteImaginaria;
};

int main(){
    int opc=1;
	struct numerosComplejos num1, num2;
	do{
		system("cls");
		printf("\nMENU\n");
		printf("1. Sumar\n");
		printf("2. Restar\n");
		printf("3. Multiplicacion\n");
		printf("4. Cociente\n");
		printf("5. Magnitud\n");
		printf("6. Conjugado\n");
		printf("7. Angulo\n");
		printf("8. Parte Real\n");
		printf("9. Parte Imaginaria\n");
		printf("10. Salir\n");
		printf("Selecciona una opcion: ");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                system("cls");
                num1 = crearNumeroComplejo();
                num2 = crearNumeroComplejo();
                suma(num1, num2);
            break;
            case 2:
                system("cls");
                num1 = crearNumeroComplejo();
                num2 = crearNumeroComplejo();
                resta(num1, num2);
            break;
            case 3:
                system("cls");
                num1 = crearNumeroComplejo();
                num2 = crearNumeroComplejo();
                multiplicacion(num1, num2);
            break;
            case 4:
                system("cls");
                num1 = crearNumeroComplejo();
                num2 = crearNumeroComplejo();
                cociente(num1, num2);
            break;
            case 5:
                system("cls");
                num1 = crearNumeroComplejo();
                magnitud(num1);
            break;
            case 6:
                system("cls");
                num1 = crearNumeroComplejo();
                conjugado(num1);
            break;
            case 7:
                system("cls");
                num1 = crearNumeroComplejo();
                angulo(num1);
            break;
            case 8:
                system("cls");
                num1 = crearNumeroComplejo();
                parteReal(num1);
            break;
            case 9:
                system("cls");
                num1 = crearNumeroComplejo();
                parteImaginaria(num1);
            break;
            case 10:
                return 0;
            break;
            default:
                system("cls");
				printf("Opcion no valida");
			break;
        }
        printf("\nDesea hacer otra operacion? 1. Si 10. No: ");
		scanf("%d", &opc);
    }while(opc!=10);
    return 0;
}

struct numerosComplejos crearNumeroComplejo(){
    struct numerosComplejos n;
	printf("\nParte real: ");
	scanf("%f", &n.parteReal);
	printf("Parte imaginaria: ");
	scanf("%f", &n.parteImaginaria);
	return n;
}

void suma(struct numerosComplejos n1, struct numerosComplejos n2){
    float newParteReal, newParteImaginaria;
    newParteReal = n1.parteReal + n2.parteReal;
    newParteImaginaria = n1.parteImaginaria + n2.parteImaginaria;
    struct numerosComplejos newNumComplejo = {newParteReal, newParteImaginaria};
    mostrarNumeroComplejo(newNumComplejo);
}

void mostrarNumeroComplejo(struct numerosComplejos n){
    printf("El numero complejo resultante es: %.2f%c%.2fi",n.parteReal, (n.parteImaginaria<0 ? '-' : '+'), fabs(n.parteImaginaria));
}

void resta(struct numerosComplejos n1, struct numerosComplejos n2){
    float newParteReal, newParteImaginaria;
    newParteReal = n1.parteReal - n2.parteReal;
    newParteImaginaria = n1.parteImaginaria - n2.parteImaginaria;
    struct numerosComplejos newNumComplejo = {newParteReal, newParteImaginaria};
    mostrarNumeroComplejo(newNumComplejo);
}

void multiplicacion(struct numerosComplejos n1, struct numerosComplejos n2){
    float newParteReal, newParteImaginaria;
    newParteReal = (n1.parteReal*n2.parteReal)+(-1)*(n1.parteImaginaria*n2.parteImaginaria);
    newParteImaginaria = n1.parteReal*n2.parteImaginaria+n1.parteImaginaria*n2.parteReal;
    struct numerosComplejos newNumComplejo = {newParteReal, newParteImaginaria};
    mostrarNumeroComplejo(newNumComplejo);
}

void cociente(struct numerosComplejos n1, struct numerosComplejos n2){
    float newParteReal, newParteImaginaria, denominador;
    denominador = (pow((n2.parteReal), 2) + pow((n2.parteImaginaria), 2));
    newParteReal = (n1.parteReal*n2.parteReal+n1.parteImaginaria*n2.parteImaginaria)/(denominador);
    newParteImaginaria = (n1.parteImaginaria*n2.parteReal-n1.parteReal*n2.parteImaginaria)/(denominador);
    struct numerosComplejos newNumComplejo = {newParteReal, newParteImaginaria};
    mostrarNumeroComplejo(newNumComplejo);
}

void magnitud(struct numerosComplejos n){
    float magnitud;
    magnitud = sqrt(pow((n.parteReal),2)+pow((n.parteImaginaria),2));
    printf("La magnitud o modulo del numero complejo %.2f%c%.2fi es : %.2f", n.parteReal, (n.parteImaginaria<0 ? '-' : '+'), 
    fabs(n.parteImaginaria), magnitud);
}

void conjugado(struct numerosComplejos n){
    printf("El conjugado del numero complejo %.2f%c%.2fi es : %.2f%c%.2fi", n.parteReal, (n.parteImaginaria<0 ? '-' : '+'), fabs(n.parteImaginaria), 
    n.parteReal, (n.parteImaginaria<0 ? '+' : '-'), fabs(n.parteImaginaria));
}

void angulo(struct numerosComplejos n){
    float angulo;
    angulo = atan(n.parteImaginaria/n.parteReal);
    printf("El angulo del numero complejo %.2f%c%.2fi es : En %.2f radianes y %.2f en grados", n.parteReal, (n.parteImaginaria<0 ? '-' : '+'), 
    fabs(n.parteImaginaria), angulo, (angulo*180/PI));
}

void parteReal(struct numerosComplejos n){
    printf("La parte real del numero %.2f%c%.2fi es: %.2f", n.parteReal, (n.parteImaginaria<0 ? '-' : '+'), fabs(n.parteImaginaria), n.parteReal);
}

void parteImaginaria(struct numerosComplejos n){
    printf("La parte real del numero %.2f%c%.2fi es: %.2f", n.parteReal, (n.parteImaginaria<0 ? '-' : '+'), fabs(n.parteImaginaria), n.parteImaginaria);
}
