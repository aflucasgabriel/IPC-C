#include <stdio.h>
#include <stdlib.h>

struct horario
{
    int ano;
    int mes;
    int dia;
    int hora;
    int min;
};
typedef struct horario Horario;

struct registro
{
    char status[1];
    char placa[8];
    char modelo[10];
    char cor[10];
    Horario horaEntrada;
    Horario horaSaida;
};
typedef struct registro Registro;

int entradaAno()
{
    int ano;
    printf("Ano: ");
    scanf("%d", &ano);
    return ano;
}

int entradaMes(int bissexto)
{
    int mes;
    while (1)
    {
        printf("Mes: ");
        scanf("%d", &mes);
        if (mes < 1 || mes > 12)
            printf("Entrada invalida: Informe um mes entre 1 e 12!\n");
        else
            return mes;
    }
}

int entradaDia(int tipoMes)
{
    int dia;
    while (1)
    {
        printf("Dia: ");
        scanf("%d", &dia);
        if (dia < 1 || dia > tipoMes)
        {
            printf("Entrada invalida: Informe um dia entre 1 e %d!\n", tipoMes);
        }
        else
            return dia;
    }
}

int entradaHora()
{
    int hora;
    while (1)
    {
        printf("Hora: ");
        scanf("%d", &hora);
        if (hora < 1 || hora > 24)
        {
            printf("Entrada invalida: Informe uma hora entre 1 e 24!\n");
        }
        else
            return hora;
    }
}

int entradaMin()
{
    int min;
    while (1)
    {
        printf("Minuto: ");
        scanf("%d", &min);
        if (min < 0 || min > 59)
        {
            printf("Entrada invalida: Informe um minuto entre 0 e 59!\n");
        }
        else
            return min;
    }
}

void novoHorario(Horario *horario)
{
    // Ano
    int bissexto = 0;
    horario->ano = entradaAno();
    if (((horario->ano) % 400 == 0) || (((horario->ano) % 4 == 0) && ((horario->ano) % 100 != 0)))
    {
        bissexto = 1;
    }

    // Mes
    horario->mes = entradaMes(bissexto);

    // Dia
    if (bissexto == 1 && (horario->mes) == 2)
    {
        horario->dia = entradaDia(29);
    }
    else if ((horario->mes) == 2)
    {
        horario->dia = entradaDia(28);
    }
    else if ((horario->mes) == 1 || (horario->mes) == 3 || (horario->mes) == 1 || (horario->mes) == 5 || (horario->mes) == 7 || (horario->mes) == 8 || (horario->mes) == 10 || (horario->mes) == 12)
    {
        horario->dia = entradaDia(31);
    }
    else
    {
        horario->dia = entradaDia(30);
    }

    // Hora e Min
    horario->hora = entradaHora();
    horario->min = entradaMin();
}

Horario calcularTempo(Horario horarioEntrada, Horario horarioSaida)
{
    Horario tempoNoEstacionamento;

    tempoNoEstacionamento.ano = horarioSaida.ano - horarioEntrada.ano;
    tempoNoEstacionamento.mes = horarioSaida.mes - horarioEntrada.mes;

    if (horarioSaida.dia < horarioEntrada.dia)
    {
        if (horarioEntrada.mes == 2 && ((horarioEntrada.ano) % 400 == 0) || (((horarioEntrada.ano) % 4 == 0) && ((horarioEntrada.ano) % 100 != 0)))
        {
            tempoNoEstacionamento.dia = 29 - horarioEntrada.dia + horarioSaida.dia;
        }
        else if (horarioEntrada.mes == 2)
        {
            tempoNoEstacionamento.dia = 28 - horarioEntrada.dia + horarioSaida.dia;
        }
        else if (horarioEntrada.mes == 1 || horarioEntrada.mes == 3 || horarioEntrada.mes == 5 || horarioEntrada.mes == 7 || horarioEntrada.mes == 8 || horarioEntrada.mes == 10 || horarioEntrada.mes == 12)
        {
            tempoNoEstacionamento.dia = 31 - horarioEntrada.dia + horarioSaida.dia;
        }
        else
        {
            tempoNoEstacionamento.dia = 30 - horarioEntrada.dia + horarioSaida.dia;
        }
    } else {
        tempoNoEstacionamento.dia = horarioSaida.dia - horarioEntrada.dia;
    }

    tempoNoEstacionamento.hora = horarioSaida.hora - horarioEntrada.hora;
    tempoNoEstacionamento.min = horarioSaida.min - horarioEntrada.min;
    if (tempoNoEstacionamento.min < 0)
    {
        tempoNoEstacionamento.min += 60;
        tempoNoEstacionamento.hora -= 1;
    }
    if (tempoNoEstacionamento.hora < 0)
    {
        tempoNoEstacionamento.hora += 24;
        tempoNoEstacionamento.dia -= 1;
    }
    if (tempoNoEstacionamento.mes < 0)
    {
        tempoNoEstacionamento.mes += 12;
        tempoNoEstacionamento.ano -= 1;
    }

    return tempoNoEstacionamento;
}

void printarRegistro(Registro reg)
{
    printf("\n========== INICIO ===========\n\n");
    printf("Placa: %s \nModelo: %s \nCor: %s\n", reg.placa, reg.modelo, reg.cor);

    printf("Horario entrada: \n %d/%d/%d - %d:%d\n", reg.horaEntrada.dia, reg.horaEntrada.mes, reg.horaEntrada.ano, reg.horaEntrada.hora, reg.horaEntrada.min);

    printf("Horario saida: \n %d/%d/%d - %d:%d\n\n", reg.horaSaida.dia, reg.horaSaida.mes, reg.horaSaida.ano, reg.horaSaida.hora, reg.horaSaida.min);

    Horario horarioEstacionado = calcularTempo(reg.horaEntrada, reg.horaSaida);
    printf("Tempo estacionado: \n Anos: %d\n Meses: %d\n Dias: %d\n Horas: %d\n Minutos: %d\n", horarioEstacionado.ano, horarioEstacionado.mes, horarioEstacionado.dia, horarioEstacionado.hora, horarioEstacionado.min);

    printf("Status: %c\n", reg.status[0]);
    printf("\n========== FIM ===========\n");
}

void decidirLocaoInsercao(FILE *f)
{
    Registro reg;

    printf("\nDeseja inserir um novo registro ou sobescrever um antigo?\n");
    printf("1 - Novo, 2 - Subescrever: ");
    int decisao, choice, contador = 1;
    scanf("%d", &decisao);

    if (decisao == 2)
    {
        rewind(f);
        while (fread(&reg, sizeof(reg), 1, f) > 0)
        {
            if (reg.status[0] == 'R')
            {
                printf("Registro %d: \n", contador);

                printarRegistro(reg);

                printf("Deseja subescrever esse registro? (1 - Sim, 2 - Nao):");

                scanf("%d", &choice);

                if (choice == 1)
                {
                    fseek(f, -sizeof(Registro), SEEK_CUR);
                    break;
                }

                contador++;
            }
        }
        if (choice != 1)
        {
            printf("Nenhum registro escolhido/encontrado. Inserindo entrada no final do arquivo!\n");
            fseek(f, sizeof(Registro), SEEK_END);
        }
    }
    else
    {
        fseek(f, sizeof(Registro), SEEK_END);
    }
}

void inserir(FILE *f)
{
    Registro novoRegistro;

    novoRegistro.status[0] = 'P';
    novoRegistro.status[1] = '\0';

    printf("Placa: ");
    scanf("%s", novoRegistro.placa);

    printf("Modelo: ");
    scanf("%s", novoRegistro.modelo);

    printf("Cor: ");
    scanf("%s", novoRegistro.cor);

    printf("Horario entrada: \n");
    novoHorario(&novoRegistro.horaEntrada);

    printf("Horario saida: \n");
    novoHorario(&novoRegistro.horaSaida);

    decidirLocaoInsercao(f);
    fwrite(&novoRegistro, sizeof(Registro), 1, f);
}

void alterar(FILE *f)
{
    char placaBuscada[8];
    printf("Placa do registro a ser alterado: ");
    scanf("%s", placaBuscada);
    printf("\n");

    Registro reg;

    int cont = 1;
    rewind(f);
    while (fread(&reg, sizeof(reg), 1, f) > 0)
    {
        if (strcmp(reg.placa, placaBuscada) == 0 && reg.status[0] == 'P')
        {
            printf("\nRegistro %d: \n", cont);

            printarRegistro(reg);

            printf("Deseja alterar esse registro? (1 - Sim, 2 - Nao):");
            int decisao;
            scanf("%d", &decisao);

            if (decisao == 1)
            {
                int opcao;
                while (1)
                {
                    printf("O que deseja alterar: \n");
                    printf("1 - Placa\n");
                    printf("2 - Modelo\n");
                    printf("3 - Cor\n");
                    printf("4 - Horario entrada\n");
                    printf("5 - Horario saida\n");
                    scanf("%d", &opcao);

                    if (opcao < 1 || opcao > 5)
                    {
                        printf("Entrada invalida!");
                    }
                    else if (opcao == 1)
                    {
                        printf("Placa: ");
                        scanf("%s", reg.placa);

                        fseek(f, -sizeof(Registro), SEEK_CUR);
                        fwrite(&reg, sizeof(Registro), 1, f);
                    }
                    else if (opcao == 2)
                    {
                        printf("Modelo: ");
                        scanf("%s", reg.modelo);

                        fseek(f, -sizeof(Registro), SEEK_CUR);
                        fwrite(&reg, sizeof(Registro), 1, f);
                    }
                    else if (opcao == 3)
                    {
                        printf("Cor: ");
                        scanf("%s", reg.cor);

                        fseek(f, -sizeof(Registro), SEEK_CUR);
                        fwrite(&reg, sizeof(Registro), 1, f);
                    }
                    else if (opcao == 4)
                    {
                        printf("Horario Entrada: \n");
                        novoHorario(&reg.horaEntrada);

                        fseek(f, -sizeof(Registro), SEEK_CUR);
                        fwrite(&reg, sizeof(Registro), 1, f);
                    }
                    else if (opcao == 5)
                    {
                        printf("Horario Saida: \n");
                        novoHorario(&reg.horaSaida);

                        fseek(f, -sizeof(Registro), SEEK_CUR);
                        fwrite(&reg, sizeof(Registro), 1, f);
                    }

                    printf("Deseja fazer mais alguma alteracao? (1 - Sim, 2 - Nao): ");
                    scanf("%d", &opcao);
                    if (opcao == 2)
                    {
                        break;
                    }
                }
            }

            cont++;
        }
    }
}

void remover(FILE *f)
{
    char placaBuscada[8];
    printf("Placa a ser removida: ");
    scanf("%s", placaBuscada);
    printf("\n");

    Registro reg;

    int cont = 1;
    rewind(f);
    while (fread(&reg, sizeof(reg), 1, f) > 0)
    {
        if (strcmp(reg.placa, placaBuscada) == 0 && reg.status[0] == 'P')
        {
            printf("Registro %d: \n", cont);

            printarRegistro(reg);

            printf("Deseja apagar registro? (1 - Sim, 2 - Nao):");
            int decisao;
            scanf("%d", &decisao);

            if (decisao == 1)
            {
                fseek(f, -sizeof(Registro), SEEK_CUR);
                reg.status[0] = 'R';
                fwrite(&reg, sizeof(Registro), 1, f);
            }

            cont++;
        }
    }
}

void buscar(FILE *f)
{
    char placaBuscada[8];
    printf("Placa a ser buscada: ");
    scanf("%s", placaBuscada);
    printf("\n");

    Registro reg;

    rewind(f);
    while (fread(&reg, sizeof(reg), 1, f) > 0)
    {
        if (strcmp(reg.placa, placaBuscada) == 0 && reg.status[0] == 'P')
        {
            printarRegistro(reg);
        }
    }
}

void listar(FILE *f)
{
    Registro reg;

    rewind(f);
    while (fread(&reg, sizeof(reg), 1, f) > 0)
    {
        if (reg.status[0] == 'P')
        {
            printarRegistro(reg);
        }
    }
}

int main()
{
    FILE *f;
    f = fopen("registros.dat", "wb+");
    if (f == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        system("pause");
        exit(1);
    }

    int opcao = -1;
    while (opcao != 0)
    {
        printf("\n\n 0-sair\n 1-insere\n 2-altera\n 3-remove\n 4-busca\n 5-lista\n");
        printf("\n Opcao: ");
        scanf(" %d", &opcao);
        switch (opcao)
        {
        case 1:
            inserir(f);
            break;
        case 2:
            alterar(f);
            break;
        case 3:
            remover(f);
            break;
        case 4:
            buscar(f);
            break;
        case 5:
            listar(f);
            break;
            printf("\n\n\n");
        }
    }

    fclose(f);
    return 0;
}
