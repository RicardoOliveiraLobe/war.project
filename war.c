#include <stdio.h>
#include <string.h>

// Define a estrutura de dados para cada território do mapa.
struct Territorio
{
    char nome[30];
    char cor[10];
    int tropas;
};

int main()
{
    // Cria um vetor para armazenar 5 territórios.
    struct Territorio mapa[5];
    int i;

    printf("======================================\n\n");
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n\n");

    // Loop para cadastrar os 5 territórios.
    for (i = 0; i < 5; i++)
    {
        printf("--- Cadastrando Territorio %d ---\n", i + 1);

        // Limpa o buffer de entrada para a leitura correta do nome.
        while (getchar() != '\n')
            ;

        // Lê o nome do território de forma segura.
        printf("Nome do territorio: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);

        // Remove o caractere '\n' que o fgets adiciona no final da string.
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        // Lê a cor e o número de tropas.
        printf("Cor do Exercito (ex: amarelo, vermelho, azul): ");
        scanf("%s", mapa[i].cor);

        printf("Numero de tropas: ");
        scanf("%d", &mapa[i].tropas);

        printf("\n");
    }

    // --- Exibe o mapa final com os dados cadastrados ---
    printf("====================================\n");
    printf("--- MAPA DO MUNDO - ESTADO ATUAL ---\n");
    printf("====================================\n\n");
    for (i = 0; i < 5; i++)
    {
        printf("Territorio %d:\n", i + 1);
        printf(" - Nome: %s\n", mapa[i].nome);
        printf(" - Dominado por: exercito %s\n", mapa[i].cor);
        printf(" - Tropas: %d\n", mapa[i].tropas);
        printf("\n");
    }

    return 0;
}