#ifndef BIB2_H_INCLUDED
#define BIB2_H_INCLUDED
FILE *funcionarios;
FILE *numeroFuncionarios;

void cadastraFuncionario() {
    int id;
    char nome[30], endereço[50], telefone[20], cargo[20];
    float salario;

    system("md c:\\temp");

    numeroFuncionarios = fopen("c:/temp/numeroFuncionarios.txt", "r");
    if(numeroFuncionarios == NULL) {
        numeroFuncionarios = fopen("c:/temp/numeroFuncionarios.txt", "w");
        fclose(numeroFuncionarios);
        id = 0;
    } else {
        fscanf(numeroFuncionarios, "%d", &id);
        fclose(numeroFuncionarios);
    }
    id += 1;
    numeroFuncionarios = fopen("c:/temp/numeroFuncionarios.txt", "w");
    fprintf(numeroFuncionarios, "%d", id);
    fclose(numeroFuncionarios);

    funcionarios = fopen("c:/temp/funcionarios.txt", "a");
    if(funcionarios == NULL) {
        funcionarios = fopen("c:/temp/funcionarios.txt", "w");
    }
    fprintf(funcionarios, "%d\n", id);
    printf("Digite o nome do funcionario: ");
    fgets(nome, 30, stdin);
    fprintf(funcionarios, "%s", nome);
    printf("Digite o endereco do funcionario: ");
    fgets(endereço, 50, stdin);
    fprintf(funcionarios, "%s", endereço);
    printf("Digite o telefone do funcionario: ");
    fgets(telefone, 20, stdin);
    fprintf(funcionarios, "%s", telefone);
    printf("Digite o cargo do funcionario: ");
    fgets(cargo, 20, stdin);
    fprintf(funcionarios, "%s", cargo);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &salario);
    fprintf(funcionarios, "%f\n", salario);
    printf("\nNovo funcionario criado! ID: %d", id);

    fclose(funcionarios);

}

#endif