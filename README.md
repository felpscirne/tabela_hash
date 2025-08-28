# Análise de Algoritmos de Ordenação e Estruturas de Dados em C

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)
![Padrão](https://img.shields.io/badge/Padrão-C99-brightgreen.svg)
![Build](https://img.shields.io/badge/Build-Makefile-lightgrey.svg)

## Descrição do Projeto

Projeto acadêmico desenvolvido para a disciplina de **Estruturas de Dados**, com o objetivo de realizar uma análise prática do desempenho de diferentes algoritmos de ordenação e métodos de busca. O programa gera uma massa de 10.000 registros de placas de veículos e utiliza essa base de dados para cronometrar e comparar a eficiência das seguintes estruturas e algoritmos:

* **Estruturas de Dados para Busca:** Lista Desordenada, Lista Ordenada e Tabela Hash com tratamento de colisão por encadeamento.
* **Algoritmos de Ordenação:**
    * **Simples (Complexidade $O(n^2)$):** Selection Sort, Insertion Sort, Bubble Sort.
    * **Eficientes (Complexidade $O(n \log n)$):** Shell Sort, Quick Sort.

O objetivo é demonstrar empiricamente as diferenças de performance previstas pela teoria da complexidade de algoritmos.

## Funcionalidades

-   **Geração de Dados:** Criação de 10.000 placas de veículos no formato `LLLNLNN` (ex: `ABC1D23`).
-   **Tabela Hash:** Mapeamento das placas para uma tabela hash de 500 posições, com colisões tratadas por listas simplesmente encadeadas.
-   **Benchmark de Ordenação:** Medição do tempo de execução (usando `clock()`) para ordenar a lista de placas com cada um dos cinco algoritmos implementados.
-   **Benchmark de Busca:** Medição do tempo total para localizar um número `N` de placas (informadas pelo usuário) em três cenários distintos:
    1.  Busca Linear em lista desordenada.
    2.  Busca Binária em lista ordenada.
    3.  Busca direta na Tabela Hash.
-   **Interatividade:** O usuário define quantas e quais placas deseja buscar para o benchmark.

## Tecnologias e Ferramentas

-   **Linguagem C:** Todo o código foi desenvolvido seguindo o padrão **C99**.
-   **Compilador GCC:** O projeto é otimizado para compilação com o GNU Compiler Collection, padrão em ambientes Linux.
-   **Makefile:** A compilação do projeto é automatizada através de um `Makefile`, simplificando o processo de build em múltiplos arquivos.

## Como Compilar e Executar

Este projeto foi projetado para ser compilado em um ambiente Linux com `gcc` e `make` instalados.

1.  **Pré-requisitos:** Certifique-se de ter os pacotes `gcc` e `make` instalados.
    ```bash
    # Em sistemas baseados em Debian/Ubuntu
    # sudo apt-get update && sudo apt-get install build-essential
    ```

2.  **Compile o projeto:**
    O `Makefile` incluído automatiza todo o processo. Na raiz do projeto, execute:
    ```bash
    make
    ```
    Este comando irá compilar todos os arquivos `.c` e gerar o executável `programa_placas`.

3.  **Execute o programa:**
    ```bash
    ./programa_placas
    ```

4.  **Limpar os arquivos compilados (opcional):**
    Para remover o executável e os arquivos objeto (`.o`), use o comando:
    ```bash
    make clean
    ```

## Estrutura do Projeto

O código é modularizado em diferentes arquivos para melhor organização e manutenibilidade.

| Arquivo                  | Descrição                                                                      |
| ------------------------ | ------------------------------------------------------------------------------ |
| `Makefile`               | **Contém as regras para compilar e linkar o projeto de forma automatizada.** |
| `placas.h` / `.c`        | Definições globais (`NUM_PLACAS`, etc.) e a função de geração de placas.         |
| `tabela_hash.h` / `.c`   | Implementação completa da Tabela Hash e das listas encadeadas para colisões.     |
| `ordenacao.h` / `.c`     | Implementação dos cinco algoritmos de ordenação.                               |
| `busca.h` / `.c`         | Implementação dos algoritmos de busca linear e binária.                          |
| `main.c`                 | Ponto de entrada do programa, orquestra os benchmarks e a interação com o usuário. |
| `README.md`              | Este arquivo de documentação.                                                  |

## Análise dos Resultados e Conclusão

### Melhor Algoritmo de Ordenação

Os testes mostraram uma performance drasticamente superior dos algoritmos eficientes em comparação com os simples.

**Ranking de Desempenho (do mais rápido para o mais lento):**
1.  🥇 **Quick Sort ($O(n \log n)$):** O mais rápido, ideal para grandes conjuntos de dados desordenados.
2.  🥈 **Shell Sort:** Performance muito próxima ao Quick Sort, sendo uma excelente alternativa.
3.  🥉 **Insertion Sort, Selection Sort, Bubble Sort ($O(n^2)$):** Extremamente lentos e inviáveis para 10.000 registros.

**Conclusão:** Para ordenação em larga escala, **Quick Sort** é a escolha técnica superior.

### Melhores Métodos de Busca

A estrutura de dados utilizada tem um impacto ainda mais significativo no tempo de busca.

**Ranking de Desempenho (do mais rápido para o mais lento):**
1.  🥇 **Tabela Hash ($O(1)$):** Performance quase instantânea, sendo o método mais rápido.
2.  🥈 **Busca Binária ($O(\log n)$):** Extremamente rápida, representando uma alternativa fantástica se os dados precisarem ser mantidos em ordem.
3.  🥉 **Busca Linear ($O(n)$):** Muito lenta e inadequada para a escala do problema.

| Método            | Complexidade Média | Pré-processamento         | Vantagem Principal                                 |
| ----------------- | ------------------ | ------------------------- | -------------------------------------------------- |
| **Tabela Hash** | **$O(1)$** | Construir a tabela ($O(n)$) | Velocidade máxima para buscas individuais.         |
| **Busca Binária** | **$O(\log n)$** | Ordenar a lista ($O(n \log n)$) | Rapidez e manutenção da ordem dos dados.           |
| **Busca Linear** | **$O(n)$** | Nenhum                    | Simplicidade (apenas para listas muito pequenas). |

### Resumo Final

Este projeto acadêmico demonstra que o custo inicial de organizar os dados (seja ordenando uma lista para busca binária ou construindo uma tabela hash) é um investimento que se paga rapidamente, resultando em buscas ordens de magnitude mais rápidas. A **Tabela Hash** é a campeã em velocidade de busca, enquanto o **Quick Sort** é a ferramenta mais eficiente para ordenação.

## Autor

* **[Seu Nome Aqui]** - *[Seu Email ou Link para Perfil Online]*
