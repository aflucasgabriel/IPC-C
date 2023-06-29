#include <stdio.h>
#include <stdlib.h>
#define n 10
int main()
{
  //vetor estático
  float vet[n];

  //vetor dinamico 
  float *p;
  p = (float *) malloc(n*sizeof(float));

  // imprimindo o vetor estático
  for (int i = 0; i < n; i++){
    printf("Digite o valor da posicao [%d] : ", i);
      scanf("%f", &vet[i]);
  }
  for (int i = 0; i < n; i++) {
    printf("\nEndereco do vetor estatico [%d]: %.2f", i, &vet[i]);
    printf("\nvalor do vetor estatico [%d]: %.2f\n", i, vet[i]);
  }
    printf("\n\n\n\n");
    // imprimindo o vetor dinamico

  for (int i = 0; i < n; i++) {
    printf("Digite o valor da posicao do vetor dinamico na posicao [%d]: ", i);
    scanf("%f", &p[i]);
  }
  for (int i = 0; i < n; i++) {
    printf("\nEndereco do vetor dinamico [%d]: %d", i, &p[i]);
    printf("\nvalor do vetor dinamico [%d]: %.2f\n", i, p[i]);
  }
    
  
  
  
  
    return 0;
}
