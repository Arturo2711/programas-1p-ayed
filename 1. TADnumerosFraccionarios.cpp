#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

void suma(struct Fraccion f1, struct Fraccion f2);
void resta(struct Fraccion f1, struct Fraccion f2);
void multiplicacion(struct Fraccion f1, struct Fraccion f2);
void division(struct Fraccion f1, struct Fraccion f2);
void potencia(struct Fraccion f1, int exp);
void simplificar(struct Fraccion f);
struct Fraccion crearFraccion();

struct Fraccion{
	int numerador;
	int denominador;
};

int main(){
	int opc=1;
	struct Fraccion f1, f2;
	do{
		system("cls");
		printf("\tMENU\n");
		printf("1. Suma\n");
		printf("2. Resta\n");
		printf("3. Multiplicacion\n");
		printf("4. Division\n");
		printf("5. Potencia\n");
		printf("6. Simplificacion\n");
		printf("7. Numerador\n");
		printf("8. Denominador\n");
		printf("9. Salir\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				system("cls");
				f1 = crearFraccion();
				f2 = crearFraccion();
				suma(f1, f2);
			break;
			case 2:
				system("cls");
				f1 = crearFraccion();
				f2 = crearFraccion();
				resta(f1, f2);
			break;
			case 3:
				system("cls");
				f1 = crearFraccion();
				f2 = crearFraccion();
				multiplicacion(f1, f2);
			break;
			case 4:
				system("cls");
				f1 = crearFraccion();
				f2 = crearFraccion();
				division(f1, f2);
			break;
			case 5:
				system("cls");
				int exp;
				f1 = crearFraccion();
				printf("Numero del exponente: ");
				scanf("%d", &exp);
				potencia(f1, exp);
			break;
			case 6:
				system("cls");
				f1 = crearFraccion();
				simplificar(f1);
			break;
			case 7:
				system("cls");
				f1 = crearFraccion();
				printf("El numerador es %d", f1.numerador);
			break;
			case 8:
				system("cls");
				f1 = crearFraccion();
				printf("El denominador es %d", f1.denominador);
			break;
			case 9:
				return 0;
			break;
			default:
				system("cls");
				printf("Opcion no valida");
			break;
			}
		printf("Desea hacer otra operacion? 1. Si 9. No: ");
		scanf("%d", &opc);
	}while(opc!=9);
}

void suma(struct Fraccion f1, struct Fraccion f2){
	int newNumerador = (f1.numerador*f2.denominador)+(f1.denominador*f2.numerador);
	int newDenominador = f1.denominador*f2.denominador;
	struct Fraccion newFraccion = {newNumerador, newDenominador};
	printf("La suma %d/%d + %d/%d es: %d/%d\n", f1.numerador, f1.denominador,
												f2.numerador, f2.denominador,
												newNumerador, newDenominador);
	simplificar(newFraccion);
}

void resta(struct Fraccion f1, struct Fraccion f2){
	int newNumerador = (f1.numerador*f2.denominador)-(f1.denominador*f2.numerador);
	int newDenominador = f1.denominador*f2.denominador;
	struct Fraccion newFraccion = {newNumerador, newDenominador};
	printf("La resta %d/%d - %d/%d es: %d/%d\n", f1.numerador, f1.denominador,
												f2.numerador, f2.denominador,
												newNumerador, newDenominador);
	simplificar(newFraccion);
}

void multiplicacion(struct Fraccion f1, struct Fraccion f2){
	int newNumerador = f1.numerador*f2.numerador;
	int newDenominador = f1.denominador*f2.denominador;
	struct Fraccion newFraccion = {newNumerador, newDenominador};
	printf("La multiplicacion %d/%d * %d/%d es: %d/%d\n", f1.numerador, f1.denominador,
														f2.numerador, f2.denominador,
														newNumerador, newDenominador);
	simplificar(newFraccion);
}

void division(struct Fraccion f1, struct Fraccion f2){
	int newNumerador = f1.numerador*f2.denominador;
	int newDenominador = f1.denominador*f2.numerador;
	struct Fraccion newFraccion = {newNumerador, newDenominador};
	printf("La division %d/%d ÷ %d/%d es: %d/%d\n", f1.numerador, f1.denominador,
												f2.numerador, f2.denominador,
												newNumerador, newDenominador);
	simplificar(newFraccion);
}

void potencia(struct Fraccion f1, int exp){
	int newNumerador = pow((f1.numerador), exp);
	int newDenominador = pow((f1.denominador), exp);
	struct Fraccion newFraccion = {newNumerador, newDenominador};
	printf("La fraccion %d/%d elevada a la potencia %d es: %d/%d\n",f1.numerador, f1.denominador, exp,
																	newNumerador, newDenominador);
	simplificar(newFraccion);
}

void simplificar(struct Fraccion f){
	    int num = f.numerador;
	    int den = f.denominador;
	    int ab, r;
	    ab = num * den;
        while (den != 0){
            r = num % den;
            num = den;
            den = r;
        }
        printf("Fraccion simplificada: %d/%d\n", f.numerador/num, f.denominador/num);
}

struct Fraccion crearFraccion(){
	struct Fraccion f;
	printf("Numerador: ");
	scanf("%d", &f.numerador);
	do{
		printf("Denominador: ");
		scanf("%d", &f.denominador);
	}while(f.denominador == 0);
	return f;
}
