#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta
struct Carta {
    char estado[50];
    char codigo[10];
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular a densidade populacional
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}

// Função para imprimir os dados da carta
void exibirCarta(struct Carta c) {
    printf("Cidade: %s (%s)\n", c.nomeCidade, c.estado);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n\n", c.pibPerCapita);
}

int main() {
    // Definindo duas cartas manualmente
    struct Carta carta1 = {
        "SP", "C001", "São Paulo",
        12300000, 1521.0, 750.0, 15
    };

    struct Carta carta2 = {
        "RJ", "C002", "Rio de Janeiro",
        6700000, 1200.0, 410.0, 12
    };

    // Calculando densidade e PIB per capita das duas cartas
    carta1.densidadePopulacional = calcularDensidade(carta1.populacao, carta1.area);
    carta1.pibPerCapita = calcularPIBPerCapita(carta1.pib, carta1.populacao);

    carta2.densidadePopulacional = calcularDensidade(carta2.populacao, carta2.area);
    carta2.pibPerCapita = calcularPIBPerCapita(carta2.pib, carta2.populacao);

    // Exibindo as cartas
    printf("===== CARTA 1 =====\n");
    exibirCarta(carta1);

    printf("===== CARTA 2 =====\n");
    exibirCarta(carta2);

    // Atributo de comparação: População
    printf("Comparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    // Comparando as cartas
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
