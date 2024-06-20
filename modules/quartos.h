#include <stdio.h>
#include <time.h>
#include <stdlib.h>
FILE *quartos;
FILE *numeroQuartos;
FILE *estadias;
#ifndef BIB3_H_INCLUDED
#define BIB3_H_INCLUDED

//Função 3:
typedef struct
{
    int numero;
    int capacidade;
    float preco;
    int ocupado;
} quarto;

void cadastraQuarto()
{
    int quantidade_de_quartos, i = 0;

    system("md c:\\temp");

    numeroQuartos = fopen("c:/temp/numeroQuartos.txt", "r");
    if (numeroQuartos == NULL)
    {
        numeroQuartos = fopen("c:/temp/numeroQuartos.txt", "w");
        fclose(numeroQuartos);
        quantidade_de_quartos = 0;
    }
    else
    {
        fscanf(numeroQuartos, "%d", &quantidade_de_quartos);
        fclose(numeroQuartos);
    }
    quantidade_de_quartos += 1;
    numeroQuartos = fopen("c:/temp/numeroQuartos.txt", "w");
    fprintf(numeroQuartos, "%d", quantidade_de_quartos);
    fclose(numeroQuartos);

    quartos = fopen("c:/temp/quartos.txt", "a");
    if (quantidade_de_quartos == 1)
    {
        quartos = fopen("c:/temp/quartos.txt", "w");
        quarto novoQuarto;
        printf("Digite o numero do quarto: ");
        scanf("%d", &novoQuarto.numero);
        fprintf(quartos, "%d\n", novoQuarto.numero);
        printf("Digite a capacidade do quarto: ");
        scanf("%d", &novoQuarto.capacidade);
        fprintf(quartos, "%d\n", novoQuarto.capacidade);
        printf("Digite o preco da diaria do quarto: ");
        scanf("%f", &novoQuarto.preco);
        fprintf(quartos, "%f\n", novoQuarto.preco);
        novoQuarto.ocupado = 0;
        fprintf(quartos, "%d\n", novoQuarto.ocupado);
        fclose(quartos);
    }
    else
    {
        int numero_do_quarto_digitado_usuario, controle = 0;
        quarto *novoQuarto = (quarto *)malloc(quantidade_de_quartos * sizeof(quarto));

        quartos = fopen("c:/temp/quartos.txt", "r");

        for (i = 0; i < (quantidade_de_quartos - 1); i++)
        {
            fscanf(quartos, "%d", &novoQuarto[i].numero);
            fscanf(quartos, "%d", &novoQuarto[i].capacidade);
            fscanf(quartos, "%f", &novoQuarto[i].preco);
            fscanf(quartos, "%d", &novoQuarto[i].ocupado);
        }
        fclose(quartos);

        quartos = fopen("c:/temp/quartos.txt", "a");
        printf("Digite o numero do quarto: ");
        scanf("%d", &numero_do_quarto_digitado_usuario);

        while (controle == 0)
        {
            for (i = 0; i < (quantidade_de_quartos - 1); i++)
            {
                if (numero_do_quarto_digitado_usuario == novoQuarto[i].numero)
                {
                    printf("ERRO! Numero de quarto ja cadastrado! Digite outro numero: ");
                    scanf("%d", &numero_do_quarto_digitado_usuario);
                    break;
                }

                if (i == 0)
                {
                    controle = 1;
                }
            }
        }

        fprintf(quartos, "%d\n", numero_do_quarto_digitado_usuario);
        printf("Digite a capacidade do quarto: ");
        scanf("%d", &novoQuarto[quantidade_de_quartos - 1].capacidade);
        fprintf(quartos, "%d\n", novoQuarto[quantidade_de_quartos - 1].capacidade);
        printf("Digite o preco da diaria do quarto: ");
        scanf("%f", &novoQuarto[quantidade_de_quartos - 1].preco);
        fprintf(quartos, "%f\n", novoQuarto[quantidade_de_quartos - 1].preco);
        novoQuarto[quantidade_de_quartos - 1].ocupado = 0;
        fprintf(quartos, "%d\n", novoQuarto[quantidade_de_quartos - 1].ocupado);

        fclose(quartos);
        free(novoQuarto);
    }
}

int verificaDisponibilidade(int capacidade)
{
    FILE *quartos;
    quartos = fopen("c:/temp/quartos.txt", "r");
    if (quartos == NULL)
    {
        printf("Erro ao abrir o arquivo de quartos.\n");
        return -1;
    }

    quarto q;
    while (fscanf(quartos, "%d%d%f%d", &q.numero, &q.capacidade, &q.preco, &q.ocupado) != EOF)
    {
        if (q.capacidade >= capacidade && q.ocupado == 0)
        {
            fclose(quartos);
            return q.numero;
        }
    }
    fclose(quartos);
    return -1;
}

int calculaDiarias(struct tm check_in, struct tm check_out)
{
    time_t start = mktime(&check_in);
    time_t end = mktime(&check_out);
    return (int)difftime(end, start) / (60 * 60 * 24);
}

//Função 4:
void registraEstadia()
{
    int client_id, pessoas, quarto_id, dias;
    struct tm check_in = {0}, check_out = {0};

    printf("Digite o código do cliente: ");
    scanf("%d", &client_id);
    printf("Digite a quantidade de hóspedes: ");
    scanf("%d", &pessoas);

    printf("Digite a data de entrada (dd mm yyyy): ");
    scanf("%d %d %d", &check_in.tm_mday, &check_in.tm_mon, &check_in.tm_year);
    check_in.tm_mon -= 1;
    check_in.tm_year -= 1900;

    printf("Digite a data de saída (dd mm yyyy): ");
    scanf("%d %d %d", &check_out.tm_mday, &check_out.tm_mon, &check_out.tm_year);
    check_out.tm_mon -= 1;
    check_out.tm_year -= 1900;

    quarto_id = verificaDisponibilidade(pessoas);
    if (quarto_id == -1)
    {
        printf("Nenhum quarto disponível para a quantidade de hóspedes.\n");
        return;
    }

    dias = calculaDiarias(check_in, check_out);
    if (dias <= 0)
    {
        printf("Data de saída deve ser após a data de entrada.\n");
        return;
    }

    FILE *quartos;
    quartos = fopen("c:/temp/quartos.txt", "r+");
    if (quartos == NULL)
    {
        printf("Erro ao abrir o arquivo de quartos.\n");
        return;
    }

    quarto q;
    while (fscanf(quartos, "%d%d%f%d", &q.numero, &q.capacidade, &q.preco, &q.ocupado) != EOF)
    {
        if (q.numero == quarto_id)
        {
            q.ocupado = 1;
            fseek(quartos, -sizeof(int), SEEK_CUR);
            fprintf(quartos, "%d", q.ocupado);
            break;
        }
    }
    fclose(quartos);

    salvaEstadia(client_id, quarto_id, pessoas, check_in, check_out, dias);
    printf("Estadia cadastrada com sucesso.\n");
    printf("Cliente: %d\n", client_id);
    printf("Quarto: %d\n", quarto_id);
    printf("Hóspedes: %d\n", pessoas);
    printf("Data de entrada: %d/%d/%d\n", check_in.tm_mday, check_in.tm_mon + 1, check_in.tm_year + 1900);
    printf("Data de saída: %d/%d/%d\n", check_out.tm_mday, check_out.tm_mon + 1, check_out.tm_year + 1900);
    printf("Diárias: %d\n", dias);
}

void salvaEstadia(int client_id, int quarto_id, int pessoas, struct tm check_in, struct tm check_out, int dias)
{
    estadias = fopen("c:/temp/numeroQuartos.txt", "a");
    if (estadias == NULL)
    {
        printf("Erro ao abrir o arquivo de estadias.\n");
        return;
    }

    fprintf(estadias, "%d %d %d %d %d %d %d %d %d %d %d\n",
            client_id, quarto_id, pessoas,
            check_in.tm_mday, check_in.tm_mon + 1, check_in.tm_year + 1900,
            check_out.tm_mday, check_out.tm_mon + 1, check_out.tm_year + 1900,
            dias);

    fclose(estadias);
}


// Função 7:
typedef struct {
    int client_id;
    int quarto_id;
    int pessoas;
    int check_in_day;
    int check_in_month;
    int check_in_year;
    int check_out_day;
    int check_out_month;
    int check_out_year;
    int dias;
    int campo_de_erro;  
} Estadia;

void EstadiasCliente() {
    int cliente_id;

    printf("Digite o código do cliente: ");
    scanf("%d",&cliente_id);

    FILE *estadias = fopen("c:/temp/estadias.txt", "r");
    if (estadias == NULL) {
        printf("Erro ao abrir o arquivo de estadias.\n");
        return;
    }

    Estadia estadia;
    int encontrar = 0;

    while (1) {
        int result = fscanf(estadias, "%d %d %d %d %d %d %d %d %d %d %d",
                            &estadia.client_id, &estadia.quarto_id, &estadia.pessoas,
                            &estadia.check_in_day, &estadia.check_in_month, &estadia.check_in_year,
                            &estadia.check_out_day, &estadia.check_out_month, &estadia.check_out_year,
                            &estadia.dias, &estadia.campo_de_erro);  

        if (result == EOF) {
            break;  
        } else if (result != 11) {
            printf("Erro ao ler os dados da estadia, apenas %d valores lidos.\n", result);
            break;  
        }


        if (estadia.client_id == cliente_id) {
            printf("Cliente: %d\n", estadia.client_id);
            printf("Quarto: %d\n", estadia.quarto_id);
            printf("Hóspedes: %d\n", estadia.pessoas);
            printf("Data de entrada: %d/%d/%d\n", estadia.check_in_day, estadia.check_in_month, estadia.check_in_year);
            printf("Data de saída: %d/%d/%d\n", estadia.check_out_day, estadia.check_out_month, estadia.check_out_year);
            printf("Diárias: %d\n", estadia.dias);
            printf("\n");
            encontrar = 1;
        }
    }

    if (!encontrar) {
        printf("Nenhuma estadia encontrada para o cliente %d.\n", cliente_id);
    }

    fclose(estadias);
}

#endif
