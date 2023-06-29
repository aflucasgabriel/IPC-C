#include <stdio.h>
#include <stdlib.h>

int main()
{
    float ca, co, h;
    float soma_catetos;

    printf("Digite dois números correspondentes a catetos:"); (ca, co);
    scanf("%f %f", &ca, &co);

    soma_catetos = pow(ca, 2) + pow(ca,2);
    h = soma_catetos;

    printf("A hipotenusa e %.3f", h);


    int ca, co, h;
    int soma_catetos;

    printf("Digite dois números correspondentes a catetos:"); (ca, co);
    scanf("%d %d", &ca, &co);

    soma_catetos = pow(ca, 2) + pow(ca,2);
    h = soma_catetos;

    printf("A hipotenusa e %.3d", h);


    return 0;
}
