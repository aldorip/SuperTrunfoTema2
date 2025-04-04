#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para calcular densidade
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para exibir atributos disponíveis
void exibirMenu(int skipOption) {
    printf("Escolha um atributo:\n");
    if (skipOption != 1) printf("1 - População\n");
    if (skipOption != 2) printf("2 - Área\n");
    if (skipOption != 3) printf("3 - PIB\n");
    if (skipOption != 4) printf("4 - Pontos Turísticos\n");
    if (skipOption != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
}

// Função para obter o valor do atributo
float obterValorAtributo(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0;
    }
}

// Função para imprimir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    struct Carta carta1 = {"Brasil", 211000000, 8515767.0, 2200.0, 30, 0};
    struct Carta carta2 = {"Canadá", 38000000, 9984670.0, 1900.0, 20, 0};

    carta1.densidadeDemografica = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidadeDemografica = calcularDensidade(carta2.populacao, carta2.area);

    int atributo1 = 0, atributo2 = 0;

    printf("===== SUPER TRUNFO - DESAFIO MESTRE =====\n\n");

    // Escolha do primeiro atributo
    while (atributo1 < 1 || atributo1 > 5) {
        exibirMenu(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5) printf("Opção inválida!\n");
    }

    // Escolha do segundo atributo (dinâmico)
    while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        exibirMenu(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 == atributo1)
            printf("Você já escolheu esse atributo. Escolha outro!\n");
        else if (atributo2 < 1 || atributo2 > 5)
            printf("Opção inválida!\n");
    }

    // Obtenção dos valores dos atributos
    float valor1_attr1 = obterValorAtributo(carta1, atributo1);
    float valor2_attr1 = obterValorAtributo(carta2, atributo1);
    float valor1_attr2 = obterValorAtributo(carta1, atributo2);
    float valor2_attr2 = obterValorAtributo(carta2, atributo2);

    // Comparações individuais
    int pontos1 = 0, pontos2 = 0;

    // Regras de vitória para cada atributo
    pontos1 += (atributo1 == 5) ? (valor1_attr1 < valor2_attr1) : (valor1_attr1 > valor2_attr1);
    pontos2 += (atributo1 == 5) ? (valor2_attr1 < valor1_attr1) : (valor2_attr1 > valor1_attr1);

    pontos1 += (atributo2 == 5) ? (valor1_attr2 < valor2_attr2) : (valor1_attr2 > valor2_attr2);
    pontos2 += (atributo2 == 5) ? (valor2_attr2 < valor1_attr2) : (valor2_attr2 > valor1_attr2);

    // Soma dos dois atributos para cada carta (respeitando a regra: menor densidade é melhor)
    float soma1 = (atributo1 == 5 ? -valor1_attr1 : valor1_attr1) + (atributo2 == 5 ? -valor1_attr2 : valor1_attr2);
    float soma2 = (atributo1 == 5 ? -valor2_attr1 : valor2_attr1) + (atributo2 == 5 ? -valor2_attr2 : valor2_attr2);

    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("  %s: %.2f\n", nomeAtributo(atributo1), valor1_attr1);
    printf("  %s: %.2f\n", nomeAtributo(atributo2), valor1_attr2);
    printf("  Soma Final: %.2f\n", soma1);

    printf("\nCarta 2: %s\n", carta2.nomePais);
    printf("  %s: %.2f\n", nomeAtributo(atributo1), valor2_attr1);
    printf("  %s: %.2f\n", nomeAtributo(atributo2), valor2_attr2);
    printf("  Soma Final: %.2f\n", soma2);

    // Resultado Final
    printf("\nVENCEDOR: ");
    if (soma1 > soma2)
        printf("%s\n", carta1.nomePais);
    else if (soma2 > soma1)
        printf("%s\n", carta2.nomePais);
    else
        printf("Empate!\n");

    return 0;
}
