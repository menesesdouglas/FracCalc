#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mmc(int a, int b) {
    return (a * b) / mdc(a, b);
}

int finalSomaNumerador(int a, int b, int c){
    int result = (c/b)*a;
    return result;
}

int main(){
    int numerador1,numerador2,denominador1,denominador2,opcao=1;
    
    printf("Bem-vindo à calculadora de frações simples!\n");
    printf("Você pode realizar operações de soma, subtração, multiplicação e divisão entre duas frações.\n");
    printf("Para sair do programa, digite 0 quando solicitado a escolher uma opção.\n");

    while(opcao!=0){
        printf("Escolha uma opção:\n");
        printf("1. Soma\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Informe o numerador da primeira fração: ");
                scanf("%d",&numerador1);
                printf("Informe o denominador da primeira fração: ");
                scanf("%d",&denominador1);
                while(denominador1 == 0){
                    printf("Denominador não pode ser zero. Tente novamente.\n");
                    scanf("%d",&denominador1);
                }
                printf("Informe o numerador da segunda fração: ");
                scanf("%d",&numerador2);
                printf("Informe o denominador da segunda fração: ");
                scanf("%d",&denominador2);
                while(denominador2 == 0){
                    printf("Denominador não pode ser zero. Tente novamente.\n");
                    scanf("%d",&denominador2);
                }

                if(denominador1==denominador2){
                    int somaNumerador = numerador1 + numerador2;
                    int divisor = mdc(somaNumerador, denominador1);
                    int simplesNumerador = somaNumerador / divisor;
                    int simplesDenominador = denominador1 / divisor;
                    printf("Resultado: %d/%d\n", somaNumerador, denominador1);
                    printf("Forma simplificada: %d/%d\n", simplesNumerador, simplesDenominador);
                }else{
                    int novoDenomidador=mmc(denominador1, denominador2);
                    int novoNumerador1=finalSomaNumerador(numerador1,denominador1,novoDenomidador);
                    int novoNumerador2=finalSomaNumerador(numerador2,denominador2,novoDenomidador);
                    printf("Resultado: %d/%d\n", novoNumerador1 + novoNumerador2, novoDenomidador);
                    int divisor = mdc(novoNumerador1 + novoNumerador2, novoDenomidador);
                    int simplesNumerador = (novoNumerador1 + novoNumerador2) / divisor;
                    int simplesDenominador = novoDenomidador / divisor;
                    printf("Forma simplificada: %d/%d\n", simplesNumerador, simplesDenominador);
                }
                break;
            case 2:
                printf("Informe o numerador da primeira fração: ");
                scanf("%d",&numerador1);
                printf("Informe o denominador da primeira fração: ");
                scanf("%d",&denominador1);
                while(denominador1 == 0){
                    printf("Denominador não pode ser zero. Tente novamente.\n");
                    scanf("%d",&denominador1);
                }
                printf("Informe o numerador da segunda fração: ");
                scanf("%d",&numerador2);
                printf("Informe o denominador da segunda fração: ");
                scanf("%d",&denominador2);
                while(denominador2 == 0){
                    printf("Denominador não pode ser zero. Tente novamente.\n");
                    scanf("%d",&denominador2);
                }
                
                if(denominador1==denominador2){
                    int subNumerador = numerador1 - numerador2;
                    int divisor = mdc(subNumerador, denominador1);
                    int simplesNumerador = subNumerador / divisor;
                    int simplesDenominador = denominador1 / divisor;
                    printf("Resultado: %d/%d\n", subNumerador, denominador1);
                    printf("Forma simplificada: %d/%d\n", simplesNumerador, simplesDenominador);
                }else{
                    int novoDenomidador=mmc(denominador1, denominador2);
                    int novoNumerador1=finalSomaNumerador(numerador1,denominador1,novoDenomidador);
                    int novoNumerador2=finalSomaNumerador(numerador2,denominador2,novoDenomidador);
                    int finalNumerador = novoNumerador1 - novoNumerador2;
                    printf("Resultado: %d/%d\n", finalNumerador, novoDenomidador);
                    int divisor = mdc(finalNumerador, novoDenomidador);
                    int simplesNumerador = finalNumerador / divisor;
                    int simplesDenominador = novoDenomidador / divisor;
                    if (simplesDenominador < 0) {
                        simplesDenominador *= -1;
                        simplesNumerador *= -1;
                    }
                    printf("Forma simplificada: %d/%d\n", simplesNumerador, simplesDenominador);
                }
                break;
            case 3:
                printf("Informe o numerador da primeira fração: ");
                scanf("%d",&numerador1);
                printf("Informe o denominador da primeira fração: ");
                scanf("%d",&denominador1);
                while(denominador1 == 0){
                    printf("Denominador não pode ser zero. Tente novamente.\n");
                    scanf("%d",&denominador1);
                }
                printf("Informe o numerador da segunda fração: ");
                scanf("%d",&numerador2);
                printf("Informe o denominador da segunda fração: ");
                scanf("%d",&denominador2);
                while(denominador2 == 0){
                    printf("Denominador não pode ser zero. Tente novamente.\n");
                    scanf("%d",&denominador2);
                }

                printf("Resultado: %d/%d\n", numerador1 * numerador2, denominador1 * denominador2);
                int divisor = mdc(numerador1 * numerador2, denominador1 * denominador2);
                int simplesNumerador = (numerador1 * numerador2) / divisor;
                int simplesDenominador = (denominador1 * denominador2) / divisor;
                printf("Forma simplificada: %d/%d\n", simplesNumerador, simplesDenominador);
                break;
            case 4:
                printf("Informe o numerador da primeira fração: ");
                scanf("%d",&numerador1);
                printf("Informe o denominador da primeira fração: ");
                scanf("%d",&denominador1);
                while(denominador1 == 0){
                    printf("Denominador não pode ser zero. Tente novamente.\n");
                    scanf("%d",&denominador1);
                }
                printf("Informe o numerador da segunda fração: ");
                scanf("%d",&numerador2);
                printf("Informe o denominador da segunda fração: ");
                scanf("%d",&denominador2);
                while(denominador2 == 0){
                    printf("Denominador não pode ser zero. Tente novamente.\n");
                    scanf("%d",&denominador2);
                }

                if (numerador2 == 0) {
                    printf("Erro: divisão por zero (numerador da segunda fração é zero).\n");
                break;
                }

                int resultadoNumerador = numerador1 * denominador2;
                int resultadoDenominador = denominador1 * numerador2;
                printf("Resultado: %d/%d\n", resultadoNumerador, resultadoDenominador);
                int divisorr = mdc(resultadoNumerador, resultadoDenominador);
                int simplesNumeradorr = resultadoNumerador / divisorr;
                int simplesDenominadorr = resultadoDenominador / divisorr;

                // Corrige o sinal, se o denominador estiver negativo
                if (simplesDenominadorr < 0) {
                    simplesNumeradorr *= -1;
                    simplesDenominadorr *= -1;
                }
                printf("Forma simplificada: %d/%d\n", simplesNumeradorr, simplesDenominadorr);
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
