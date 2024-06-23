#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./modules/hospedes.h"
#include "./modules/funcionarios.h"
#include "./modules/quartos.h"

void menuHospede();
void menuCadastro();

/* TELA APENAS PARA CHAMAR FUNÇÕES DE CADASTROS ( F1, F2, F3 )*/
void menuCadastro()
{
    setlocale(LC_ALL, "Portuguese");

    int escolha;

    printf("---Escolha a Função Desejada---\n");
    printf("1 - Cadastrar Cliente.\n");
    printf("2 - Cadastrar Funcionário.\n");
    printf("3 - Cadastrar Quarto.\n");
    printf("0 - Sair.\n");

    do
    {
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch(escolha)
        {
        case 1:
            cadastraCliente();
            break;
        case 2:
            cadastraFuncionario();
            break;
        case 3:
            cadastraQuarto();
            break;
        case 0:
            printf("Finalizando atendimento...\n");
            break;
        default:
            printf("Valor inválido.\nInsira uma opção disponível.\n");
        }
    } while (escolha != 0);
}

/* TELA DESTINADA A OPERAÇÕES QUE O HOSPEDE FARIA NO SISTEMA */
void menuHospede()
{
    setlocale(LC_ALL, "Portuguese");

    int escolha;

    printf("---Escolha a Função Desejada---\n");
    printf("1 - Alugar quarto\n");
    printf("2 - Total a pagar\n");
    printf("3 - Pontos de fidelidade\n");
    printf("0 - Sair\n");

    do
    {
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            registraEstadia();
            break;
        case 2:
            pagamento();
            break;
        case 3:
            // fidelidade(); - INCOMPLETA
            break;
        case 0:
            printf("Finalizando atendimento...\n");
            break;
        default:
            printf("Valor inválido.\nInsira uma opção disponível.\n");
        }
    } while (escolha != 0);
}

/* TELA PRINCIPAL, APENAS PARA CHAMAR FUNÇÕES */
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int escolha;
    printf("ESCOLHA A OPÇÃO DESEJADA:\n");
    printf("1 - Hóspedes\n");
    printf("2 - Cadastros\n");

    do
    {
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            menuHospede();
            break;
        case 2:
            menuCadastro();
            break;
        default:
            printf("Opção inválida. Insira um número válido.\n");
            break;
        }
    } while (escolha != 0);

    return 0;
}
