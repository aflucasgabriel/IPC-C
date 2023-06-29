#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Lucas Gabriel Alves Ferreira
    // 12121BSI200

  int linhaA, colunaA, linhaB, colunaB;
  printf("Digite as linhas e colunas da primeira matriz: ");
  scanf("%d %d", &linhaA, &colunaA);
  printf("Digite as linhas e colunas da segunda matriz: ");
  scanf("%d %d", &linhaB, &colunaB);

  if (linhaA != colunaB || colunaA != linhaB)
    printf("Nao e possivel multiplicar!\n");
  else
  {
    float matrizA[linhaA][colunaA], matrizB[linhaB][colunaB];

    for (int i = 0; i < linhaA; i++)
      for (int j = 0; j < colunaA; j++)
      {
        printf("Digite o valor da posicao [%d][%d]: ", i, j);
        scanf("%f", &matrizA[i][j]);
      }
    for (int i = 0; i < linhaB; i++)
      for (int j = 0; j < colunaB; j++) {
        printf("Digite o valor da posicao [%d][%d]: ", i, j);
        scanf("%f", &matrizB[i][j]);
      }
    float s;
    for (int i = 0; i < linhaA; i++) {
      for (int j = 0; j < colunaB; j++) {
        s = 0;
        for (int k = 0; k < linhaB; k++) {
          s += matrizA[i][k] * matrizB[k][j];
        }
        printf("%.2f ", s);
      }
    }
  }
    return 0;
}
