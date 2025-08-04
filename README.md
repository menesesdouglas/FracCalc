FracCalc - Calculadora Simples de Frações

Descrição:
FracCalc é uma calculadora de frações simples que permite realizar operações básicas como soma, subtração, multiplicação e divisão entre duas frações. O programa exibe o resultado tanto na forma original quanto na forma simplificada.

Funcionalidades:

    Soma de frações

    Subtração de frações

    Multiplicação de frações

    Divisão de frações

    Simplificação automática do resultado

    Validação para evitar denominadores zero e divisão por zero

    Interface via terminal com mensagens claras

Como usar:

    Compile o código com um compilador C, por exemplo: gcc -o fracCalc main.c

    Execute o programa gerado: ./fracCalc

    Siga as instruções apresentadas para escolher a operação e informar as frações.

    Para sair do programa, escolha a opção 0 quando solicitado.

Detalhes técnicos:

    Utiliza o algoritmo de Euclides para calcular o máximo divisor comum (MDC).

    Utiliza o mínimo múltiplo comum (MMC) para somar e subtrair frações com denominadores diferentes.

    O resultado final é simplificado automaticamente antes de ser exibido.

    Corrige sinais para garantir que o denominador esteja sempre positivo.

Estrutura do código:

    Função mdc(int a, int b): calcula o máximo divisor comum entre dois números.

    Função mmc(int a, int b): calcula o mínimo múltiplo comum entre dois números.

    Função finalSomaNumerador(int a, int b, int c): ajusta o numerador para denominadores iguais.

    Função main(): controla o fluxo principal, exibe o menu e processa as operações conforme a escolha do usuário.

Requisitos:

    Compilador C (como GCC ou Clang)

    Ambiente de linha de comando/terminal para execução do programa

Possíveis melhorias futuras:

    Suporte a frações impróprias e conversão para número misto.

    Implementação de outras operações, como potenciação.

    Interface gráfica para facilitar o uso.

    Validação de entrada mais robusta.

Autor:
Douglas Meneses — Estudante de Análise e Desenvolvimento de Sistemas e Desenvolvedor Back-end.

Licença:
Este projeto está disponível sob licença MIT.
