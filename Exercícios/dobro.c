#include <stdio.h>
#include <stdlib.h>
int main()
{
  //dobro do valor
  
  int n = 5;
  int *p;
  p = (int *) malloc(5*sizeof(int));

  for (int i = 0; i < n; i++){
    printf("Digite o valor do vetor na posicao [%d]: ", i);
    scanf("%d", &p[i]);
  }
  printf("O dobro de cada elemento do vetor eh: \n");
  for (int i = 0; i < n; i++) {
  printf("%d\n", p[i]*2);
    }
    return 0;
}
