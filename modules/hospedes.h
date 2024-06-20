#ifndef BIB1_H_INCLUDED
#define BIB1_H_INCLUDED
FILE *clientes;
FILE *numeroClientes;

//Função 1:
void cadastraCliente() {
    int id;
    char nome[30], endereco[50], telefone[20];

    system("md c:\\temp");

    numeroClientes = fopen("c:/temp/numeroClientes.txt", "r");
    if(numeroClientes == NULL) {
        numeroClientes = fopen("c:/temp/numeroClientes.txt", "w");
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
    fgets(endereco, 50, stdin);
    fprintf(clientes, "%s", endereco);
    printf("Digite o telefone do cliente: ");
    fgets(telefone, 20, stdin);
    fprintf(clientes, "%s", telefone);
    printf("\nNovo cliente criado! ID: %d", id);

    fclose(clientes);

}


//Função 6:

void pesquisaCliente() {
    char nome[30], nomeCliente[30], endereco[50], telefone[20];
    int id, encontrado = 0;

    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    clientes = fopen("c:/temp/clientes.txt", "r");
    if(clientes == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    while(fscanf(clientes, "%d\n", &id) != EOF) {
        fgets(nomeCliente, 30, clientes);
        nomeCliente[strcspn(nomeCliente, "\n")] = 0;
        fgets(endereco, 50, clientes);
        endereco[strcspn(endereco, "\n")] = 0;
        fgets(telefone, 20, clientes);
        telefone[strcspn(telefone, "\n")] = 0;

        if(strcmp(nomeCliente, nome) == 0) {
            printf("Cliente encontrado!\n");
            printf("ID: %d\n", id);
            printf("Nome: %s\n", nomeCliente);
            printf("Endereço: %s\n", endereco);
            printf("Telefone: %s\n", telefone);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Nome não encontrado!\n");
    }

    fclose(clientes);
}


#endif