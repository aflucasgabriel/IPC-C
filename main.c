#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 





typedef struct {
    int cpf[11];
    char nome[30];
    time_t entrada;
    time_t saida;
    char status;

} funcionario_t;

typedef struct {
    int cpf[11];
    time_t horario;
    char evento;

} log_t;

void listar(FILE *funcionarios){

    funcionario_t lista[100];
    int i = 0;

    
    printf("\n==============\n");

        printf("CPF: %p\n", lista[i].cpf);
        printf("Nome: %s\n", lista[i].nome);
        printf("Data entrada: %ld\n", ctime(lista[i].entrada));
        
        if(lista[i].status == 's' || lista[i].status == 'A'){
            printf("Data Saida: %ld\n", ctime(lista[i].saida));
        }
        printf("Status: %c", lista[i].status);
            
    
    printf("\n");

    
   
}

void registro(FILE *funcionarios, FILE *log) {
    
    funcionario_t  funcionario[100];
    log_t cad_log[100];
    time_t horario;
    int i;
    int quant = 0;
    int x;

    printf("\nDeseja registrar o ponto de quantos funcionarios?: ");
    scanf("%d", &quant);

    if(quant < 1){
        printf("Digite um numero maior que 0.");
        return;
    }

    for(i = 0; i < quant; i++){
        printf("\nDigite o cpf do funcionario %d: ", i);
        setbuf (stdin, NULL);
        scanf("%d", funcionario[i].cpf);


        while (fread(&funcionario, sizeof(funcionario_t), 1, funcionarios) == 1){

            for ( i = 0; i < quant; i++){
                if(funcionario[i].cpf == 0){
                    printf("Funcionario nao encontrado. Deseja inclui-lo?\n1 - Sim\n2 - Nao");
                    setbuf (stdin, NULL);
                    scanf("%d", &x);

                    if (x == 1){
                        printf("Digite o cpf do funcionario: ");
                        setbuf (stdin, NULL);
                        scanf("%d", funcionario[i].cpf);

                        

                        fprintf(funcionarios, "%p", funcionario[i].cpf);

                        printf("\nDigite o nome do funcionario %d: ", i);
                        setbuf (stdin, NULL);
                        scanf("%s", funcionario[i].nome);

                        fprintf(funcionarios, "%s", funcionario[i].nome);

                        printf("\nO funcionario %d esta: [e] entrando ou [s] saindo?: ", i);
                        setbuf(stdin, NULL);
                        scanf(" %c", &(funcionario[i].status));

                        fprintf(funcionarios, "%c", funcionario[i].status);

                        horario = time(NULL);
                        if (funcionario[i].status == 'P') {
                            funcionario[i].saida = horario;
                            funcionario[i].status = 'A';

                            fprintf(funcionarios, "%ld", funcionario[i].saida);

                        } else {
                            funcionario[i].entrada = horario;
                            funcionario[i].status = 'P';

                            fprintf(funcionarios, "%ld", funcionario[i].entrada);
                            }

                    } else
                        return;
                    
                }
         }
            
        
        }
    }

    fprintf(funcionarios, "%p", funcionario[i].cpf);

    for(i = 0; i < quant; i++){
    printf("\nDigite o nome do funcionario %d: ", i);
    setbuf (stdin, NULL);
    scanf("%s", funcionario[i].nome);
    }
    fprintf(funcionarios, "%s", funcionario[i].nome);

    for(i = 0; i < quant; i++){
    printf("\nO funcionario %d esta: \n[e] entrando: \n[s] saindo:\n ", i);
    setbuf(stdin, NULL);
    scanf("%c", &(funcionario[i].status));
    }

    fprintf(funcionarios, "%d", funcionario[i].status);

    horario = time(NULL);
        if (funcionario[i].status == 'P') {
            funcionario[i].saida = horario;
            funcionario[i].status = 'A';

            fprintf(funcionarios, "%ld", funcionario[i].saida);

            } else {
                    funcionario[i].entrada = horario;
                    funcionario[i].status = 'P';
                    fprintf(funcionarios, "%ld", funcionario[i].entrada);
            }


    if (funcionario[i].status == 'e'){
        cad_log[i].evento = 'P';
    } 
        else if (funcionario[i].status == 's'){
        cad_log[i].evento = 'A';
    }
    
    fprintf(funcionarios, "%d", funcionario[i].status);

    printf("\n");

    if (funcionario[i].status == 'P'){
        printf("\nPonto registrado com sucesso.\nTenha um bom trabalho!");
    } 
    else if (funcionario[i].status == 'A'){
        printf("\nPonto registrado com sucesso.\nTenha um bom descanso!");
    }

    if (funcionario[i].status == 'P' || funcionario[i].status == 'A'){
        fwrite(&cad_log, sizeof(log_t), 1, log);
        fwrite(&funcionario, sizeof(funcionario_t), 1, funcionarios);
    } 
    
    
}   

void listagem_funcionarios(FILE *funcionarios) {


    
    int i = 0;
    puts("Lista de Funcionários"); 
    for(i=0;i < 25; i++){
       listar(funcionarios);
    }
    
} 

void listagem_log(FILE *log) {
    funcionario_t n[100];
    log_t f[100];
    log_t resultado;
    char cpf[11];
    int x;
    int cpf_arquivo;
    int i = 0;

    printf("\nDigite cpf de busca: ");
    setbuf (stdin, NULL);
    scanf("%d", &x);

    while (fscanf(log, "%d %s %c", &cpf_arquivo, n[i].nome, f[i].evento) != EOF) {
        if (x == cpf_arquivo) {
            
            printf("Funcionario encontrado: \n");
            printf("CPF: %p\n", f[i].cpf);
            printf("Nome: %s\n", n[i].nome);
            printf("Status: %c\n", f[i].evento);
            break;
        }
    }


   if (feof(log)) {
       printf("\n");
       printf("Funcionario nao encontrado\n");
   }

  

    
}

int main() {
   
    FILE *funcionarios;
    FILE *log;

    funcionarios = fopen("funcionarios.bin", "wb+");
    log = fopen("log.bin", "wb+");



    if (funcionarios == NULL || log == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        system("pause");
        exit(1);
    } 

    printf("\n\n\n");
    printf("------------------------------------\n");
    printf("| Bem vindo(a) |\n");
    printf("------------------------------------\n");


    
    int opcao;
    do {
        printf("\n\n 0-sair\n 1-registro entrada/saida\n 2-lista funcionarios\n 3-lista log\n");
        printf("\n Opcao: "); scanf(" %d",&opcao);
        switch(opcao) {
            case 1: registro(funcionarios,log); break;
            case 2: listagem_funcionarios(funcionarios); break;
            case 3: listagem_log(log); break;
            printf("\n\n\n");
        }
    } while (opcao != 0);

    fclose(funcionarios);
    fclose(log);
    return 0;
}
