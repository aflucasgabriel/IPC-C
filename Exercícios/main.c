#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   int a, b, c;
    printf("a b c: "); scanf(" %d %d %d", &a,&b,&c);
    printf("\nResolvendo equacao %dx^2 + %dx + %d = 0\n\n",a,b,c);
    if (a == 0) {
        printf("nao eh eq 2o grau."); return 0;
    }
    float delta = b * b - 4 * a * c;
    if (delta == 0) {
        float x = - b / (2 * a);
        printf("Raiz %f\n\n", x);
    }
    else if (delta > 0) {
        float x1 = (-b + sqrt(delta)) / (2 * a);
        float x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Raizes %f %f\n\n", x1, x2);
    }
    else {
        printf("Nao tem raizes reais.\n\n");
    }
}
