#include <stdio.h>
#include <stdlib.h>

/**
 * Calcula o Máximo Divisor Comum (MDC) entre dois números
 * usando o algoritmo de Euclides.
 * 
 * @param numero_a Primeiro número
 * @param numero_b Segundo número
 * @return MDC entre numero_a e numero_b
 */
int calcular_mdc(int numero_a, int numero_b) {
    numero_a = abs(numero_a);
    numero_b = abs(numero_b);
    
    while (numero_b != 0) {
        int temporario = numero_b;
        numero_b = numero_a % numero_b;
        numero_a = temporario;
    }
    return numero_a;
}

/**
 * Calcula o Mínimo Múltiplo Comum (MMC) entre dois números.
 * 
 * @param numero_a Primeiro número
 * @param numero_b Segundo número
 * @return MMC entre numero_a e numero_b
 */
int calcular_mmc(int numero_a, int numero_b) {
    // Evita divisão por zero e overflow
    if (numero_a == 0 || numero_b == 0) return 0;
    
    int valor_mdc = calcular_mdc(numero_a, numero_b);
    // Calcula MMC de forma segura para evitar overflow
    return (numero_a / valor_mdc) * numero_b;
}

/**
 * Calcula o numerador equivalente quando o denominador é alterado.
 * 
 * @param numerador Numerador original
 * @param denominador Denominador original
 * @param novo_denominador Novo denominador
 * @return Numerador equivalente para o novo denominador
 */
int calcular_numerador_equivalente(int numerador, int denominador, int novo_denominador) {
    return numerador * (novo_denominador / denominador);
}

/**
 * Lê uma fração do usuário com validação.
 * 
 * @param ponteiro_numerador Ponteiro para armazenar o numerador
 * @param ponteiro_denominador Ponteiro para armazenar o denominador
 * @param numero_fracao Número da fração (1ª ou 2ª)
 */
void ler_fracao(int *ponteiro_numerador, int *ponteiro_denominador, int numero_fracao) {
    printf("Informe o numerador da %da fração: ", numero_fracao);
    scanf("%d", ponteiro_numerador);
    
    printf("Informe o denominador da %da fração: ", numero_fracao);
    scanf("%d", ponteiro_denominador);
    
    while (*ponteiro_denominador == 0) {
        printf("Erro: Denominador não pode ser zero. Tente novamente: ");
        scanf("%d", ponteiro_denominador);
    }
}

/**
 * Simplifica uma fração e ajusta o sinal.
 * 
 * @param ponteiro_numerador Ponteiro para o numerador (será modificado)
 * @param ponteiro_denominador Ponteiro para o denominador (será modificado)
 */
void simplificar_fracao(int *ponteiro_numerador, int *ponteiro_denominador) {
    int divisor = calcular_mdc(*ponteiro_numerador, *ponteiro_denominador);
    *ponteiro_numerador /= divisor;
    *ponteiro_denominador /= divisor;
    
    // Garante que o denominador seja sempre positivo
    if (*ponteiro_denominador < 0) {
        *ponteiro_numerador *= -1;
        *ponteiro_denominador *= -1;
    }
}

/**
 * Exibe o resultado de uma operação com frações.
 * 
 * @param numerador Numerador do resultado
 * @param denominador Denominador do resultado
 * @param nome_operacao String representando a operação (ex: "Soma")
 */
void exibir_resultado(int numerador, int denominador, const char *nome_operacao) {
    int numerador_simplificado = numerador;
    int denominador_simplificado = denominador;
    
    printf("\n--- Resultado da %s ---\n", nome_operacao);
    printf("Resultado bruto: %d/%d\n", numerador, denominador);
    
    simplificar_fracao(&numerador_simplificado, &denominador_simplificado);
    printf("Forma simplificada: %d/%d\n", numerador_simplificado, denominador_simplificado);
    
    if (denominador_simplificado == 1) {
        printf("Resultado como inteiro: %d\n", numerador_simplificado);
    }
    printf("-----------------------------\n\n");
}

/**
 * Realiza a operação de soma entre duas frações.
 */
void executar_soma() {
    int numerador_1, denominador_1, numerador_2, denominador_2;
    
    ler_fracao(&numerador_1, &denominador_1, 1);
    ler_fracao(&numerador_2, &denominador_2, 2);
    
    if (denominador_1 == denominador_2) {
        exibir_resultado(numerador_1 + numerador_2, denominador_1, "Soma");
    } else {
        int novo_denominador = calcular_mmc(denominador_1, denominador_2);
        int novo_numerador_1 = calcular_numerador_equivalente(numerador_1, denominador_1, novo_denominador);
        int novo_numerador_2 = calcular_numerador_equivalente(numerador_2, denominador_2, novo_denominador);
        exibir_resultado(novo_numerador_1 + novo_numerador_2, novo_denominador, "Soma");
    }
}

/**
 * Realiza a operação de subtração entre duas frações.
 */
void executar_subtracao() {
    int numerador_1, denominador_1, numerador_2, denominador_2;
    
    ler_fracao(&numerador_1, &denominador_1, 1);
    ler_fracao(&numerador_2, &denominador_2, 2);
    
    if (denominador_1 == denominador_2) {
        exibir_resultado(numerador_1 - numerador_2, denominador_1, "Subtração");
    } else {
        int novo_denominador = calcular_mmc(denominador_1, denominador_2);
        int novo_numerador_1 = calcular_numerador_equivalente(numerador_1, denominador_1, novo_denominador);
        int novo_numerador_2 = calcular_numerador_equivalente(numerador_2, denominador_2, novo_denominador);
        exibir_resultado(novo_numerador_1 - novo_numerador_2, novo_denominador, "Subtração");
    }
}

/**
 * Realiza a operação de multiplicação entre duas frações.
 */
void executar_multiplicacao() {
    int numerador_1, denominador_1, numerador_2, denominador_2;
    
    ler_fracao(&numerador_1, &denominador_1, 1);
    ler_fracao(&numerador_2, &denominador_2, 2);
    
    exibir_resultado(numerador_1 * numerador_2, denominador_1 * denominador_2, "Multiplicação");
}

/**
 * Realiza a operação de divisão entre duas frações.
 */
void executar_divisao() {
    int numerador_1, denominador_1, numerador_2, denominador_2;
    
    ler_fracao(&numerador_1, &denominador_1, 1);
    ler_fracao(&numerador_2, &denominador_2, 2);
    
    if (numerador_2 == 0) {
        printf("Erro: Não é possível dividir por zero!\n");
        return;
    }
    
    exibir_resultado(numerador_1 * denominador_2, denominador_1 * numerador_2, "Divisão");
}

/**
 * Exibe o menu de opções.
 */
void exibir_menu_principal() {
    printf("\n=== Calculadora de Frações ===\n");
    printf("1. Soma\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao_selecionada = -1;
    
    printf("Bem-vindo à calculadora de frações!\n");
    printf("Você pode realizar operações entre duas frações.\n");
    
    while (opcao_selecionada != 0) {
        exibir_menu_principal();
        scanf("%d", &opcao_selecionada);
        
        switch (opcao_selecionada) {
            case 1:
                executar_soma();
                break;
            case 2:
                executar_subtracao();
                break;
            case 3:
                executar_multiplicacao();
                break;
            case 4:
                executar_divisao();
                break;
            case 0:
                printf("Saindo do programa! Obrigado!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }
    
    return 0;
}
