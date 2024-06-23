#ifndef BIB3_H_INCLUDED
#define BIB3_H_INCLUDED
FILE *quartos;
FILE *numeroQuartos;

typedef struct
{
    int numero;
    int capacidade;
    float preco;
    int ocupado;
} quarto;




void cadastraQuarto() {
    int quantidade_de_quartos, i = 0;

    system("md c:\\temp");

    numeroQuartos = fopen("c:/temp/numeroQuartos.txt", "r");
    if(numeroQuartos == NULL) {
        numeroQuartos = fopen("c:/temp/numeroQuartos.txt", "w");
        fclose(numeroQuartos);
        quantidade_de_quartos = 0;
    } else {
        fscanf(numeroQuartos, "%d", &quantidade_de_quartos);
        fclose(numeroQuartos);
    }
    quantidade_de_quartos += 1;
    numeroQuartos = fopen("c:/temp/numeroQuartos.txt", "w");
    fprintf(numeroQuartos, "%d", quantidade_de_quartos);
    fclose(numeroQuartos);

    quartos = fopen("c:/temp/quartos.txt", "a");
    if(quantidade_de_quartos == 1) {
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
    } else {
        int numero_do_quarto_digitado_usuario, controle = 0;
        quarto *novoQuarto = (quarto*) malloc(quantidade_de_quartos * sizeof(quarto));

        quartos = fopen("c:/temp/quartos.txt", "r");
        
        for(i = 0; i < (quantidade_de_quartos - 1); i++) {
            fscanf(quartos, "%d", &novoQuarto[i].numero);
            fscanf(quartos, "%d", &novoQuarto[i].capacidade);
            fscanf(quartos, "%f", &novoQuarto[i].preco);
            fscanf(quartos, "%d", &novoQuarto[i].ocupado);
        }
        fclose(quartos);

        quartos = fopen("c:/temp/quartos.txt", "a");
        printf("Digite o numero do quarto: ");
        scanf("%d", &numero_do_quarto_digitado_usuario);

        while(controle == 0){
            for(i = 0; i < (quantidade_de_quartos - 1); i++) {
                if(numero_do_quarto_digitado_usuario == novoQuarto[i].numero) {
                    printf("ERRO! Numero de quarto ja cadastrado! Digite outro numero: ");
                    scanf("%d", &numero_do_quarto_digitado_usuario);
                    break;
                }
            
                if(i == 0) {
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
        printf("\nNovo cliente criado! ID: %d", numero_do_quarto_digitado_usuario);

        

        fclose(quartos);
        free(novoQuarto);
    }



    

}

#endif