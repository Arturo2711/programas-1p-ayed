#include "PilDinChar.h"

int main() {
    struct pila a;
    struct pila b;
    iniciarPila(&a);
    iniciarPila(&b);
    int operando1,operando2,resultado;
    char caracter;
    // Lectura de la expresión posfija
    printf("Ingrese la expresion posfija:\n");
    do
    {
        fflush(stdin);
        caracter=getche();
        if(caracter!=enter){
        push(&a,caracter);
        }
        else break;
    } while (1);


    // Evaluación de la expresión posfija
    for(int i = 0; i<=a.tope; i++) {
        if(isdigit(a.p[i])) {
            // Si el token es un número, conviértelo en un entero y colócalo en la pila
            push(&b,a.p[i] - '0'); // Restamos el valor ascii de '0' para obtener el valor numérico correspondiente
        } else if(a.p[i] == '+' || a.p[i] == '-' || a.p[i] == '*' || a.p[i] == '/'|| a.p[i] == '^') {
            // Si el token es un operador, saca los dos elementos superiores de la pila y realiza la operación indicada por el operador
            operando2 = pop(&b);
            operando1 = pop(&b);

            switch(a.p[i]) {
                case '+':
                    resultado = operando1 + operando2;
                    break;
                case '-':
                    resultado = operando1 - operando2;
                    break;
                case '*':
                    resultado = operando1 * operando2;
                    break;
                case '/':
                    resultado = operando1 / operando2;
                    break;
                case '^':
                    resultado = operando1 / operando2;
                    break;
            }

            // Coloca el resultado en la pila
            push(&b,resultado);
        }
    }

    // El resultado final estará en la cima de la pila
    resultado = pop(&b);
    printf("El resultado de la expresion es: %d\n", resultado);

    return 0;
}

