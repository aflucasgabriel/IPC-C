#include <stdio.h>
#include <stdlib.h>

int main (){

    int x [10], i;

    for (i = 0; i < 10; i++){
        printf("Digite 10 numeros inteiros: ");
        scanf(" %d", &x[i]);
    }
    for (i = 0; i < 10; i++){
        if ( x[i] %2 == 0)
        {
            printf("O numero %d eh par", x[i]);
        }
        else
        {
            printf("o numero %d eh impar", x[i]);
        }
    }


    return 0;

}
