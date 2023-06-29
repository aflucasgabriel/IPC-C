#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sexo;
    printf("digite seu sexo (m ou f): ");
    sexo = getchar();

    float altura, ideal;
    printf("Digite sua altura: ");
    scanf("%f", &altura);

    if ((sexo == 'F') || (sexo == 'f'))
        ideal = 62.1 * altura - 44.7;

    else if ((sexo == 'M')|| (sexo == 'm'))
        ideal = 72.7 * altura - 58;
        else {
            printf("Opcao invalida.");
            return 0;
        }

        printf("Sexo %c altura %.2f peso ideal %.2f", sexo, altura, ideal);

    return 0;
}
