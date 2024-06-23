#include <stdio.h>
#include <stdlib.h>

int diasCliente(int cliente_id);
float valorQuarto(int cliente_id);

// JA EXISTE
typedef struct
{
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

// JA EXISTE
typedef struct
{
    int numero;
    int capacidade;
    float preco;
    int ocupado;
} quarto;

FILE *estadias; // JA EXISTE
FILE *quartos;  // JA EXISTE

void pagamento()
{
    int id_pessoa, quant_dias;
    float valor_total, diarias, valor_quarto;

    printf("Insira o seu número ID: ");
    scanf("%d", &id_pessoa);

    quant_dias = diasCliente(id_pessoa);
    valor_quarto = valorQuarto(id_pessoa);

    valor_total = quant_dias * valor_quarto;

    printf("A quantidade total a se pagar é de R$%.2f\n", valor_total);
}

int diasCliente(int cliente_id)
{
    FILE *estadias = fopen("c:/temp/estadias.txt", "r");

    if (estadias == NULL)
    {
        printf("Erro ao abrir o arquivo de estadias.\n");
        return -1; // Retorna um valor negativo para indicar erro
    }

    Estadia estadia;
    int encontrar = 0;
    int dias = -1;

    while (fscanf(estadias, "%d %d %d %d %d %d %d %d %d %d %d",
                  &estadia.client_id, &estadia.quarto_id, &estadia.pessoas,
                  &estadia.check_in_day, &estadia.check_in_month, &estadia.check_in_year,
                  &estadia.check_out_day, &estadia.check_out_month, &estadia.check_out_year,
                  &estadia.dias, &estadia.campo_de_erro) != EOF)
    {
        if (estadia.client_id == cliente_id)
        {
            dias = estadia.dias;
            encontrar = 1;
            break; // Sai do loop ao encontrar o cliente
        }
    }

    fclose(estadias);

    if (!encontrar)
    {
        printf("Nenhuma estadia encontrada para o cliente %d.\n", cliente_id);
    }

    return dias;
}

float valorQuarto(int cliente_id)
{
    FILE *quartos = fopen("c:/temp/quartos.txt", "r");
    if (quartos == NULL)
    {
        printf("Erro ao abrir o arquivo dos quartos.\n");
        return -1.0; // Retorna um valor negativo para indicar erro
    }

    quarto q;
    float preco = -1.0;
    int encontrar = 0;

    while (fscanf(quartos, "%d%d%f%d", &q.numero, &q.capacidade, &q.preco, &q.ocupado) != EOF)
    {
        if (q.numero == cliente_id)
        {
            preco = q.preco;
            encontrar = 1;
            break; // Sai do loop ao encontrar o quarto
        }
    }

    fclose(quartos);

    if (!encontrar)
    {
        printf("Nenhum quarto encontrado para o cliente %d.\n", cliente_id);
    }

    return preco;
}