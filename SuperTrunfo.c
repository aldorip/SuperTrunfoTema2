#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para calcular densidade demográfica
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para exibir uma carta
void exibirCarta(struct Carta c) {
    printf("\nPaís: %s\n", c.nomePais);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", c.densidadeDemografica);
}

int main() {
    struct Carta carta1 = {"Brasil", 211000000, 8515767.0, 2200.0, 30, 0};
    struct Carta carta2 = {"Canadá", 38000000, 9984670.0, 1900.0, 20, 0};

    // Calcular densidade demográfica
    carta1.densidadeDemografica = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidadeDemografica = calcularDensidade(carta2.populacao, carta2.area);

    int opcao;

    printf("======= SUPER TRUNFO - COMPARAÇÃO ENTRE PAÍSES =======\n");
    printf("Escolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção (1-5): ");
    scanf("%d", &opcao);

    printf("\nCarta 1:");
    exibirCarta(carta1);
    printf("\nCarta 2:");
    exibirCarta(carta2);
    printf("\n");

    // Comparação com switch
    switch(opcao) {
        case 1:
            printf("Comparando População...\n");
            printf("%s: %d habitantes\n", carta1.nomePais, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nomePais, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("Comparando Área...\n");
            printf("%s: %.2f km²\n", carta1.nomePais, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomePais, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("Comparando PIB...\n");
            printf("%s: R$ %.2f bilhões\n", carta1.nomePais, carta1.pib);
            printf("%s: R$ %.2f bilhões\n", carta2.nomePais, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("Comparando Pontos Turísticos...\n");
            printf("%s: %d pontos\n", carta1.nomePais, carta1.pontosTuristicos);
            printf("%s: %d pontos\n", carta2.nomePais, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("Comparando Densidade Demográfica (MENOR VENCE)...\n");
            printf("%s: %.2f hab/km²\n", carta1.nomePais, carta1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", carta2.nomePais, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida. Por favor, escolha de 1 a 5.\n");
    }

    return 0;
}
