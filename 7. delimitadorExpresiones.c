#include "PilDinChar.h"

int main(int argc, char const *argv[])
{
    struct pila a;
    struct pila b;
    iniciarPila(&a);
    iniciarPila(&b);
    char caracter;
    do
    {
        fflush(stdin);
        caracter=getche();
        if(caracter!=enter){
        push(&a,caracter);
        }
        else break;
    } while (1);

    for (int i = 0; i <= a.tope; i++)
    {
        if ((a.p[i]=='(')||(a.p[i]=='[')||(a.p[i]=='{'))
        {
            push(&b,a.p[i]);
        }
        else{
        switch (a.p[i])
        {
        case ')':
            if (top(b)=='(')
            {
                pop(&b);
            }
                
        break;
        case ']':
            if (top(b)=='[')
            {
                pop(&b);
            }
            
         break;
        case '}':
            if (top(b)=='{')
            {
                pop(&b);
            }            
            break;        
        default:
            break;
        }
        }        
    }
    if(vacio(&b)){
                printf("\nExpresion valida");
            }
            else{
                printf("\nExpresion no valida");
            }

    return 0;
}
