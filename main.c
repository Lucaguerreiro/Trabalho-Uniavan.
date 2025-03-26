    #include <stdio.h>
    #include <stdlib.h>

    // Estrutura para representar uma fra��o
    typedef struct {
        int numerador;
        int denominador;
    } Fracao;

    // Fun��o para calcular o MDC (M�ximo Divisor Comum) - Usado para simplificar fra��es
    int mdc(int a, int b) {
        if (b == 0)
            return a;
        return mdc(b, a % b);
    }

    // Fun��o para simplificar a fra��o
    Fracao simplificar(Fracao f) {
        int divisor = mdc(f.numerador, f.denominador);
        f.numerador /= divisor;
        f.denominador /= divisor;
        if (f.denominador < 0) { // Garante que o denominador sempre ser� positivo
            f.numerador = -f.numerador;
            f.denominador = -f.denominador;
        }
        return f;
    }

    // Fun��o para somar duas fra��es
    Fracao somar(Fracao f1, Fracao f2) {
        Fracao resultado;
        resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
        resultado.denominador = f1.denominador * f2.denominador;
        return simplificar(resultado);
    }

    // Fun��o para subtrair duas fra��es
    Fracao subtrair(Fracao f1, Fracao f2) {
        Fracao resultado;
        resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
        resultado.denominador = f1.denominador * f2.denominador;
        return simplificar(resultado);
    }

    // Fun��o para multiplicar duas fra��es
    Fracao multiplicar(Fracao f1, Fracao f2) {
        Fracao resultado;
        resultado.numerador = f1.numerador * f2.numerador;
        resultado.denominador = f1.denominador * f2.denominador;
        return simplificar(resultado);
    }

    // Fun��o para dividir duas fra��es
    Fracao dividir(Fracao f1, Fracao f2) {
        Fracao resultado;
        resultado.numerador = f1.numerador * f2.denominador;
        resultado.denominador = f1.denominador * f2.numerador;
        return simplificar(resultado);
    }

    // Fun��o principal (main)
    int main() {
        Fracao f1, f2, resultado;
        char operacao;

        // Entrada do usu�rio
        printf("Digite o primeiro numerador ou denominador: ");
        scanf("%d %d", &f1.numerador, &f1.denominador);
        printf("Digite a opera��o (+, -, *, /): ");
        scanf(" %c", &operacao);
        printf("Digite o segundo numerador ou denominador: ");
        scanf("%d %d", &f2.numerador, &f2.denominador);

        // Verifica e executa a opera��o desejada
        switch (operacao) {
            case '+':
                resultado = somar(f1, f2);
                break;
            case '-':
                resultado = subtrair(f1, f2);
                break;
            case '*':
                resultado = multiplicar(f1, f2);
                break;
            case '/':
                if (f2.numerador == 0) {
                    printf("Erro: Opa! isso � ilegal\n");
                    return 1;
                }
                resultado = dividir(f1, f2);
                break;
            default:
                printf("OBJE��O!\n");
                return 1;
        }

        // Exibe o resultado simplificado
        printf("Resultado: %d/%d\n", resultado.numerador, resultado.denominador);
        return 0;
    }
