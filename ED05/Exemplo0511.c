#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"


/**
Exercícios:
DICAS GERAIS: Consultar o Anexo C 02 na apostila para outros exemplos.
Montar todos os métodos em um único programa conforme o último exemplo.
 Incluir ao final desse programa os dados e os resultados de testes.
**/

/**
01.) Incluir função e método (Exemplo0511) para:
para ler uma quantidade inteira (n) do teclado e, mediante um método,
mostrar essa quantidade em valores múltiplos de 9 em ordem crescente.
Exemplo: n = 5 => { 9, 18, 27, 36, 45 }
**/


int multiplo9(int x)
{

    x = 9 * x;
    return (x);
}

void method01()
{

    int x = 0;
    int y = 1; // controle

    x = IO_readint("Digite a quantidade desejada: ");

    while (y <= x)
    {

        IO_printf("%s%d\t%d\n", "Valor = ", y, multiplo9(y));

        y = y + 1;

    } // end while

} // end method01

/**

02.) Incluir função e método (Exemplo0512) para:
para ler uma quantidade inteira do teclado e, mediante um método
mostrar essa quantidade em valores ímpares múltiplos de 9 em ordem crescente.
Exemplo: n = 5 => { 9, 27, 45, 63, 81 }


**/

int multiplo9impar(int x)
{

    int i = 0;
    int j = 0;

    while (i < x)
    {
        j = j + 1;

        if (j % 2 != 0)
        {

            printf("\nValor atual: \t %d \n", 9 * j);
            j = j + 1;
        }
        else
        {
            j = j + 1;
            printf("\nValor atual: \t %d \n", 9 * j);

        }          // End Else
        i = i + 1; // Controle Repetição
    }
}

void method02()
{

    int x = 0;

    x = IO_readint("Digite a quantidade desejada: ");

    multiplo9impar(x);

} // end method01

/**

03.) Incluir função e método (Exemplo0513) para:
para ler uma quantidade inteira do teclado e, mediante um método,
mostrar essa quantidade em valores pares múltiplos de 9 em ordem decrescente.
Exemplo: n = 5 => { 90, 72, 54, 36, 18 }

**/

int multiplo9par(int x)
{

    int i = 0;
    int j = 2 * x;

    while (x > i)
    {

        if (j % 2 == 0)
        {

            printf("\nValor atual: \t %d \n", 9 * j);
        }
        else
        {
            j = j - 1;
            printf("\nValor atual: \t %d \n", 9 * j);

        }          // End Else
        j = j - 1; // Controle dos Múltiplos
        x = x - 1; // Controle Repetição
    }
}

void method03()
{

    int x = 0;

    x = IO_readint("Digite a quantidade desejada: ");

    multiplo9par(x);

} // end method01

/**

04.) Incluir função e método (Exemplo0514) para:
para ler uma quantidade inteira do teclado e, mediante um método,
mostrar essa quantidade em valores crescentes nos denominadores
(sequência dos inversos) múltiplos de 9.
Exemplo: n = 5 => { 1/9, 1/18, 1/27, 1/36, 1/45 }

**/

int InversoMultiplo9(int n)
{
    int ValorBase = 9;
    int i = 0;
    int ValorAtual = 0;

    while (i <= n)
    {
        if (i > 0)
        {
            ValorAtual = ValorBase * i;
            printf("\n1/%d\n", ValorAtual);
        }
        i = i + 1;
    }
    return (0);
}

void method04()
{
    int n = 0;
    printf("\nDigite a quantidade de valores desejados: \t");
    scanf("%d", &n);
    InversoMultiplo9(n);
}

/**
05.) Incluir função e método (Exemplo0515) para:
para ler um valor real real (x) do teclado;
para ler uma quantidade inteira do teclado e, mediante um método,
mostrar essa quantidade em valores crescentes nos denominadores
da sequência: 1 1/x 1/x² 1/x³
...
DICA: Usar da biblioteca <math.h> a função pow ( x, y ) para calcular a potência.
Exemplo: n = 5 => { 1, 1/x², 1/x³,...}
**/

int ProgressaoDenominadores(double x, int y, int contador)
{
    int i = 1;

    printf("\n1 ");

    while (i < contador)
    {
        printf("\n1/%.1lf ", pow(x, y));
        i = i + 1;
        y = y + 1;
    }
}

void method05()
{
    int y = 0;
    double x;
    int contador;
    printf("\nDigite o valor de x: ");
    scanf("%lf", &x);
    printf("\nDigite a quantidade de valores a serem testados ");
    scanf("%d", &contador);
    ProgressaoDenominadores(x, y, contador);
    IO_pause("\nAperte Enter para terminar");
}

/**

06.) Incluir função e método (Exemplo0516) para
calcular a soma dos primeiros valores pares ímpares positivos começando no valor 9
e não múltiplos de 5.
Testar essa função para quantidades diferentes.
Exemplo: n = 5 => 9 + 27 + 63 + 81 + 99


**/

int NaturaisValorInicial9(int x)
{
    int soma = 0;
    int y = 0;
    int z = 9;
    int i = 0;

    while (y < x)
    {

        if (i % 2 != 0 && (z * i) % 5 != 0)
        {
            soma += z * i;
            printf("\nValor atual Soma: %d \n", soma);
        }
        else
        {
            i = i + 1;
            if (i % 2 != 0 && (z * i) % 5 != 0)
            {
                soma += z * i;
                printf("\nValor atual Soma: %d \n", soma);
            }
            else
            {
                i = i + 2;
                soma += z * i;
                printf("\nValor atual Soma: %d \n", soma);
            }
        }
        i = i + 1;

        y = y + 1;
    }
    printf("\nValor total da soma dos valores lidos:%d", soma);
}
void method06()
{
    int x;
    printf("\nDigite a quantidade de valores a serem testados: ");
    scanf("%d", &x);
    NaturaisValorInicial9(x);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}

/**
07.) Incluir função e método (Exemplo0517) para
calcular a soma dos inversos (1/x) dos primeiros valores ímpares positivos,
começando no valor 9 e não múltiplos de 5.
Testar essa função para quantidades diferentes.
Exemplo: n = 5 => 1/9 + 1/27 + 1/63 + 1/81 + 1/99
**/

int InversosStart9(int x)
{
    float soma = 0;
    int y = 0;
    int z = 9;
    int i = 0;

    while (y < x)
    {

        if (i % 2 != 0 && (z * i) % 5 != 0)
        {
            soma += (float)1 / (z * i);
            printf("\nValor atual Soma: %lf \n", soma);
        }
        else
        {
            i = i + 1;
            if (i % 2 != 0 && (z * i) % 5 != 0)
            {
                soma += (float)1 / (z * i);
                printf("\nValor atual Soma: %lf \n", soma);
            }
            else
            {
                i = i + 2;
                soma += (float)1 / (z * i);
                printf("\nValor atual Soma: %lf \n", soma);
            }
        }
        i = i + 1;

        y = y + 1;
    }
    printf("\nValor total da soma dos valores lidos:%lf", soma);
}
void method07()
{
    int x;
    printf("\nDigite a quantidade de valores a serem testados: ");
    scanf("%d", &x);
    InversosStart9(x);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}

/**
08.) Incluir função e método (Exemplo0518) para
calcular a soma dos primeiros números naturais começando no valor 9.
Testar essa função para quantidades diferentes de valores.
Exemplo: n = 5 => 9 + 10 + 11 + 13 + 15
**/

int SomaNumerosNaturais(int x)
{
    int soma = 0;
    int y = 0;
    int z = 9;

    while (y < x)
    {
        soma = soma + z;
        z = z + 1;
        y = y + 1;
    }

    printf("\nValor total soma dos números naturais: %d", soma);
}
void method08()
{
    int x;
    printf("\nDigite a quantidade que voce deseja: ");
    scanf("%d", &x);
    SomaNumerosNaturais(x);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}

/**
09.) Incluir função e método (Exemplo0519) para
calcular a soma dos quadrados dos primeiros números naturais começando no valor 9.
Testar essa função para quantidades diferentes de valores.
Exemplo: n = 5 => 81 + 100 + 121 + 144 + 169
**/

int QuadradoNumerosNaturais(int x)
{
    int soma = 0;
    int y = 0;
    int z = 9;

    while (y < x)
    {
        int quad = pow(z, 2);
        soma = soma + quad;
        z = z + 1;
        y = y + 1;
    }
    printf("\nValor total correspondente aos valores lidos:%d", soma);
}
void method09()
{
    int x;
    printf("\nDigite a quantidade que voce deseja: ");
    scanf("%d", &x);
    QuadradoNumerosNaturais(x);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}

/**
10.) Incluir função e método (Exemplo0520) para
calcular a soma dos inversos (1/x) dos primeiros números naturais começando no valor 9.
Testar essa função para quantidades diferentes de valores.
Exemplo: n = 5 => 1/9 + 1/10 + 1/11 + 1/13 + 1/15
**/

int InversoNaturaisValorInicial9(int x)
{
    float soma = 0;
    int y = 0;
    int z = 9;

    while (y < x)
    {
        float fracao = 1.0 / z;
        soma = soma + fracao;
        y = y + 1;
        z = z + 1;
    }
    printf("\nValor total da soma dos inversos:%.2f", soma);
}
void method10()
{
    int x;
    printf("\nDigite a quantidade que voce deseja: ");
    scanf("%d", &x);
    InversoNaturaisValorInicial9(x);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}

/**
E1.) Incluir função e método (Exemplo05E1) para
ler um número inteiro do teclado (n) e,
mediante o uso da função, calcular e mostrar o fatorial desse valor:
n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1 se n>0
**/

int fatorial(int n)

{
    int fat = 1;

    for (fat = 1; n > 1; n = n - 1)
    {
        fat = fat * n;
    }

    printf("\n%d", fat);
}

void Extra01()
{
    int n = 0;
    printf("\nDigite o valor a ser testado: \n");
    scanf("%d", &n);
    fatorial(n);
}

int main()
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
               // repetir até desejar parar
    do
    {
        // identificar
        IO_id("EXEMPLO0501 - Programa - v0.0");

        // ler do teclado
        IO_println("Opcoes");
        IO_println(" 0 - parar");
        IO_println(" 1 - Multiplos de 9 em ordem crescente");
        IO_println(" 2 - Multiplos de 9 em ordem crescente e impares");
        IO_println(" 3 - Multiplos de 9 em ordem decrescente");
        IO_println(" 4 - Valores crescentes nos denominadores (sequência dos inversos) múltiplos de 9");
        IO_println(" 5 - Valores crescentes nos denominadores da sequência: 1 1/x 1/x² 1/x³");
        IO_println(" 6 - Soma dos primeiros valores pares impares positivos começando no valor 9 e nao multiplos de 5");
        IO_println(" 7 - Soma dos inversos (1/x) dos primeiros valores impares positivos,começando no valor 9 e não multiplos de 5");
        IO_println(" 8 - Soma dos primeiros números naturais começando no valor 9");
        IO_println(" 9 - Soma dos quadrados dos primeiros números naturais começando no valor 9");
        IO_println("10 - Soma dos inversos (1/x) dos primeiros números naturais começando no valor 9");
        IO_println("11 - (EXTRA01) Calcular e mostrar o fatorial do valor lido");

        x = IO_readint("Entrar com uma opcao: ");

        // testar valor
        switch (x)
        {
        case 0:
            break;
        case 1:
            method01();
            break;
        case 2:
            method02();
            break;
        case 3:
            method03();
            break;
        case 4:
            method04();
            break;
        case 5:
            method05();
            break;
        case 6:
            method06();
            break;
        case 7:
            method07();
            break;
        case 8:
            method08();
            break;
        case 9:
            method09();
            break;
        case 10:
            method10();
            break;
        case 11:
            Extra01();
        default:
            IO_println("ERRO: Valor invalido.");
        } // fim escolher
    } while (x != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )
