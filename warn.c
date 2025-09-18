#include <stdio.h>
#include <string.h>

// --- A Receita do Território ---
// Aqui a gente define o "molde" ou a "receita" para cada território.
// É uma struct, que é tipo uma caixa onde a gente guarda
// informações relacionadas. Assim, em vez de ter dados soltos,
// a gente agrupa tudo bonitinho: nome, cor e tropas.
struct Territorio {
    char nome[30]; // Um espaço pra guardar o nome do território, com até 30 letras.
    char cor[10];  // Pra cor do exército, tipo 'vermelho' ou 'azul'.
    int tropas;    // O número de soldados que a gente tem lá.
};

int main() {
    // --- Preparando o Jogo ---
    // A gente cria um vetor, que é tipo uma lista, pra guardar 5 territórios.
    // É o nosso mapa estático, que já vem com 5 espaços prontos.
    struct Territorio mapa[5];
    int i; // Essa variável 'i' vai ser nosso contador para percorrer os territórios.

    printf("======================================\n\n");
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n\n");

    // --- Hora do Cadastro! ---
    // Este é o 'for', nosso laço de repetição. Ele vai rodar 5 vezes, uma pra cada território.
    // Pense nele como um robô que repete as mesmas instruções pra gente.
    for (i = 0; i < 5; i++) {
        printf("--- Cadastrando Territorio %d ---\n", i + 1);

        // --- Limpando a Casa ---
        // Essa linha é super importante. Ela limpa a 'sujeira' (o Enter que a gente dá)
        // que sobrou no buffer do teclado da vez anterior. Isso evita que o programa
        // pule a pergunta do nome do território, o que seria bem chato!
        while (getchar() != '\n'); 

        // --- Pegando o Nome do Território ---
        // A gente usa o 'fgets' pra ler o nome. Ele é mais seguro que o 'scanf'
        // porque não deixa a gente digitar mais do que o espaço disponível.
        printf("Nome do territorio: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        
        // --- Tirando o 'Enter' da String ---
        // O 'fgets' é tão bonzinho que ele também guarda o 'Enter' que a gente digita.
        // Essa linha encontra esse 'Enter' e troca ele por um caractere que diz:
        // "Opa, a string termina aqui!". Assim, o nome fica limpinho.
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        // --- A Cor do Exército ---
        // Agora sim, a gente usa o 'scanf' pra pegar a cor. Como a cor não tem espaços,
        // ele funciona perfeito aqui.
        printf("Cor do Exercito (ex: amarelo, vermelho, azul): ");
        scanf("%s", mapa[i].cor);

        // --- O Número de Tropas ---
        // E, por fim, a gente pega o número de soldados. O '&' antes do nome da variável
        // é pra dizer ao 'scanf' pra guardar o valor no endereço de memória da variável 'tropas'.
        printf("Numero de tropas: ");
        scanf("%d", &mapa[i].tropas);
        
        printf("\n");
    }

    // --- Exibindo o Mapa Final ---
    // Depois de preencher tudo, a gente usa outro 'for' pra ler os dados
    // do nosso vetor 'mapa' e mostrar na tela de um jeito bem organizado,
    // com todos os detalhes de cada território cadastrado.
    printf("====================================\n");
    printf("--- MAPA DO MUNDO - ESTADO ATUAL ---\n");
    printf("====================================\n\n");
    for (i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf(" - Nome: %s\n", mapa[i].nome);
        printf(" - Dominado por: exercito %s\n", mapa[i].cor);
        printf(" - Tropas: %d\n", mapa[i].tropas);
        printf("\n");
    }

    // A gente retorna 0 pra mostrar que o programa rodou sem nenhum erro.
    return 0;
}