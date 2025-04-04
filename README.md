# 🃏 Super Trunfo - Comparador de Cartas (Nível Mestre)

Este é um projeto em linguagem **C** que simula o jogo **Super Trunfo**, onde você compara **cartas de países** com base em múltiplos atributos como População, Área, PIB, Pontos Turísticos e Densidade Demográfica.

Este desafio é a culminação dos níveis **Novato**, **Aventureiro** e **Mestre**, focando em menus dinâmicos, múltiplas comparações e lógica de decisão avançada.

---

## 🚀 Funcionalidades

- 🔢 **Comparação com dois atributos numéricos diferentes** escolhidos pelo jogador
- 🧠 **Regra especial** para Densidade Demográfica (menor vence)
- 🧮 **Soma dos atributos** e comparação final
- 📋 **Menus interativos e dinâmicos** usando `switch`
- 🧪 **Tratamento de empates**
- ✅ **Validação de entrada**
- 🎯 **Cálculo automático** da densidade demográfica
- 💡 Uso de **operador ternário** e **estrutura `if-else` aninhada**

---

## 📚 Atributos disponíveis para comparação

| Nº | Atributo               | Tipo     | Regra de vitória         |
|----|------------------------|----------|--------------------------|
| 1  | População              | Inteiro  | Maior valor vence        |
| 2  | Área                   | Float    | Maior valor vence        |
| 3  | PIB                    | Float    | Maior valor vence        |
| 4  | Pontos Turísticos      | Inteiro  | Maior valor vence        |
| 5  | Densidade Demográfica  | Float    | **Menor** valor vence 🔄 |

---

## 📦 Estrutura do Projeto

```bash
super-trunfo/
│
├── super_trunfo.c      # Código-fonte principal
├── README.md           # Documentação do projeto
└── Makefile (opcional) # Para compilar com make
```

---

## 🛠️ Como compilar e executar

**Compilação com GCC:**

```bash
gcc -o super_trunfo super_trunfo.c
```

**Execução:**

```bash
./super_trunfo
```

---

## ✅ Exemplo de execução

```txt
===== SUPER TRUNFO - DESAFIO MESTRE =====

Escolha um atributo:
1 - População
2 - Área
3 - PIB
4 - Pontos Turísticos
5 - Densidade Demográfica
Digite sua opção: 1

Escolha um atributo:
2 - Área
3 - PIB
4 - Pontos Turísticos
5 - Densidade Demográfica
Digite sua opção: 3

===== RESULTADO DA COMPARAÇÃO =====
Carta 1: Brasil
  População: 211000000.00
  PIB: 2200.00
  Soma Final: 211002200.00

Carta 2: Canadá
  População: 38000000.00
  PIB: 1900.00
  Soma Final: 38001900.00

VENCEDOR: Brasil
```

---

## ✍️ Autor

Desenvolvido por **Aldo Ribeiro** como parte do desafio de programação em C – *Super Trunfo Comparador de Países*.
