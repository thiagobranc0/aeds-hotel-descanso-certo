#ifndef BIB1_H_INCLUDED
#define BIB1_H_INCLUDED
FILE *clientes;
FILE *numeroClientes;
FILE *funcionarios;
FILE *numeroFuncionarios;
FILE *quartos;
FILE *numeroQuartos;

void cadastraCliente() {
    int id;
    char nome[30], endereço[50], telefone[20];

    system("md c:\\temp");

    numeroClientes = fopen("c:/temp/numeroClientes.txt", "r");
    if(numeroClientes == NULL) {
        numeroClientes = fopen("c:/temp/numeroClientes.txt", "w");
        fprintf(numeroClientes, "%d", 1);
        fclose(numeroClientes);
        id = 0;
    } else {
        fscanf(numeroClientes, "%d", &id);
        fclose(numeroClientes);
    }
    id += 1;
    numeroClientes = fopen("c:/temp/numeroClientes.txt", "w");
    fprintf(numeroClientes, "%d", id);
    fclose(numeroClientes);

    clientes = fopen("c:/temp/clientes.txt", "a");
    if(clientes == NULL) {
        clientes = fopen("c:/temp/clientes.txt", "w");
    }
    fprintf(clientes, "%d\n", id);
    printf("Digite o nome do cliente: ");
    fgets(nome, 30, stdin);
    fprintf(clientes, "%s", nome);
    printf("Digite o endereco do cliente: ");
    fgets(endereço, 50, stdin);
    fprintf(clientes, "%s", endereço);
    printf("Digite o telefone do cliente: ");
    fgets(telefone, 20, stdin);
    fprintf(clientes, "%s", telefone);
    printf("\nNovo cliente criado! ID: %d", id);

    fclose(clientes);

}

#endif