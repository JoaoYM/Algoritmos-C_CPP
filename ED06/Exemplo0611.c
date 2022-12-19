#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

/**
01.) Incluir um método recursivo (Exemplo0611) para
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em valores ímpares em ordem crescente começando no valor 9.
Exemplo: valor = 5
**/

void block1(int x)
{

    printf("\n%d", x); // Imprime o valor recebido
}

void for2(int Contador, int Inicial, int Final, int VariacaoContador, int VariacaoValorInicial)

{
    int ValorInicialCadeia = 0; // Recebe valor inicial da cadeia

    if (Contador <= Final) // Controle da repetição
    {

        ValorInicialCadeia += Inicial; // Imprime o valor inicial da cadeia

        block1(ValorInicialCadeia); // Imprime o valor desejado

        for2(Contador + VariacaoContador, Inicial + VariacaoValorInicial, Final, VariacaoContador, VariacaoValorInicial); // Chamada de função
    }
}

int method01(void)

{
    printf("\nMethod_02\n");
    int x = 0;                                                        // Quantidade de valores a serem lidos
    x = IO_readint("Digite a quantidade de numeros a serem lidos: "); // Entrada valor quantidade

    if (x > 0)
    {
        for2(1, 9, x, 1, 2); // Definição do for
        printf("\n Aperte ENTER para finalizar a execucao do programa.\n");
        getchar();
    }
    else
        printf("O valor inserido e' invalido, favor inserir outro valor\n");
}

/**
02.) Incluir um método recursivo (Exemplo0612) para
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em múltiplos de 9 em ordem decrescente encerrando no valor 9.
Exemplo: valor = 5
**/

void block2(int x)
{

    printf("\n%d", x); // Imprime o valor recebido
}

void for3(int Contador, int Final, int VariacaoContador)

{
    int ValorInicialCadeia = 0; // Variável para armazenar o valor inicial da cadeia

    if (Final >= Contador) // Controle da repetição
    {

        ValorInicialCadeia += Final * 9; // Operação dos multiplos de 7

        block2(ValorInicialCadeia); // Imprime o valor desejado

        for3(Contador, Final - VariacaoContador, VariacaoContador); // Chamada de função
    }
}

int method02(void)

{
    printf("\nMethod_02\n");
    int x = 0;                                                        // Quantidade de valores a serem lidos
    x = IO_readint("Digite a quantidade de numeros a serem lidos: "); // Entrada valor quantidade

    if (x > 0)
    {
        for3(1, x, 1); // Definição do for
        printf("\n Aperte ENTER para finalizar a execucao do programa.\n");
        getchar();
    }
    else
        printf("O valor inserido e' invalido, favor inserir outro valor\n");
}

/**
03.) Incluir um método recursivo (Exemplo0613) para
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em valores da sequência: 1 9 18 27 36 ...
Exemplo: valor = 5
**/

void block3(int x)
{

    printf("\n%d", x); // Imprime o valor recebido
}

void for4(int Contador, int Inicial, int Final, int VariacaoContador)

{
    int ValorInicialCadeia = 0; // Variável para armazenar o valor inicial da cadeia

    if (Contador <= Final) // Controle da repetição
    {

        ValorInicialCadeia += Inicial * 9; // Operação dos multiplos de 7

        block3(ValorInicialCadeia); // Imprime o valor desejado

        for4(Contador + VariacaoContador, Inicial + VariacaoContador, Final, VariacaoContador); // Chamada de função
    }
}

int method03(void)

{
    printf("\nMethod_02\n");
    int x = 0;                                                        // Quantidade de valores a serem lidos
    x = IO_readint("Digite a quantidade de numeros a serem lidos: "); // Entrada valor quantidade

    if (x > 0)
    {
        for4(1, 1, x, 1); // Definição do for
        printf("\n Aperte ENTER para finalizar a execucao do programa.\n");
        getchar();
    }
    else
        printf("O valor inserido e' invalido, favor inserir outro valor\n");
}

/**
04.) Incluir um método recursivo (Exemplo0614) para
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em valores decrescentes da sequência: ... 1/6561 1/729 1/81 1/9 1.
Exemplo: valor = 5
**/

/*
void ValoresDecrescentesSequencia(int x)
{

    if (x > 0)
    {
        printf("\n1/%d ", (int)pow(9, x));
        funcao14(x - 1);
    }
}
void method04()
{
    int x;
    printf("\nDigite a quantidade que voce deseja testar: ");
    scanf("%d", &x);
    ValoresDecrescentesSequencia(x - 1);
    printf("\n1 ");
    getchar();
    IO_pause("\nAperte Enter para terminar");
}
*/

/**
05.) Incluir uma função recursiva (Exemplo0615) para
calcular a soma dos primeiros valores ímpares positivos começando no valor 9.
Testar essa função para quantidades diferentes.
Exemplo: valor = 5 => 9 + 11 + 13 + 15 + 17
**/

int NaturaisValorInicial9(int x)
{
    float soma = 0;
    int y = 0;
    int z = 9;

    while (y < x)
    {
        soma = soma + z;
        y = y + 1;
        z = z + 2;
    }
    printf("\nValor total da soma dos valores lidos:\t%.2f", soma);
}
void method05()
{
    int x;
    printf("\nDigite a quantidade que voce deseja: ");
    scanf("%d", &x);
    NaturaisValorInicial9(x);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}

/**
06.) Incluir uma função recursiva (Exemplo0616) para
calcular a soma dos inversos (1/x) dos primeiros valores ímpares positivos começando no valor 9.
Testar essa função para quantidades diferentes.
Exemplo: valor = 5 => 1/9 + 1/11 + 1/13 + 1/15 + 1/17
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
        z = z + 2;
    }
    printf("\nValor total da soma dos inversos:%.2f", soma);
}
void method06()
{
    int x;
    printf("\nDigite a quantidade que voce deseja: ");
    scanf("%d", &x);
    InversoNaturaisValorInicial9(x);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}

/**
07.) Incluir um método recursivo (Exemplo0617) para
ler uma cadeia de caracteres e chamar procedimento recursivo para
mostrar cada símbolo separadamente, um por linha.
Exemplo: sequência = "abcde"
**/

int CadeiaCs(int CadeiasCaracteresLidas)
{
    /* Variáveis de controle - Begin */
    int contador = 0; // Controle
    int c = 0;        // Controle de Indice
                      /* Variáveis de controle End*/
    char Cadeia[100]; // Definição tamanho cadeia
    int tamanho = 0;  // tamanho da cadeia de caracteres a ser lida

    printf("\nInforme sua Cadeia para inicio da verificacao: \n");
    getchar();
    gets(Cadeia);             // Lê cadeia de carateres informada pelo usuário
    tamanho = strlen(Cadeia); // Passagem parâmetro para aferir tamanho cadeia
    printf("\nPalavra: %s", Cadeia);
    printf("\n\n");
    /* Inicio do FOR */
    for (c = 0; c < tamanho; c = c + 1)
    {
        printf("\n\n%c\n", Cadeia[c]);
        contador = contador + 1;
    }
}

void method07()
{

    int N_CadeiasCaraacteres = 1;

    CadeiaCs(N_CadeiasCaraacteres);
}

/**
08.) Incluir uma função recursiva (Exemplo0618) para
contar os dígitos com valores pares em uma cadeia de caracteres.
Testar essa função para cadeias de diferentes tamanhos.
Exemplo: sequência = "P4LaVr@1"
**/

int DigitosValoresPares(char x[], int y)
{
    int z = 0;
    if (x[y] != '\0')
    {
        if ('0' <= x[y] && x[y] <= '9' && x[y] % 2 == 0)
        {
            z = 1;
        }
        return z + DigitosValoresPares(x, y + 1);
    }
    return 0;
}
void method08()
{
    char x[80];
    printf("\nDigite uma palavra: ");
    scanf("%s", x);
    int a = DigitosValoresPares(x, 0);
    printf("\nQuantidade de digitos pares: %d", a);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}

/**
09.) Incluir uma função recursiva (Exemplo0619) para
calcular a quantidade de minúsculas em uma cadeia de caracteres.
Testar essa função para cadeias de diferentes tamanhos.
Exemplo: sequência = "P4LaVr@1"
**/

int ContadorMinusculasCadeiaCaracteres(char x[], int y)
{
    int z = 0;
    if (x[y] != '\0')
    {
        if ('a' <= x[y] && x[y] <= 'z')
        {
            z = 1;
        }
        return z + ContadorMinusculasCadeiaCaracteres(x, y + 1);
    }
    return 0;
}
void method09()
{
    char x[80];
    printf("\nDigite uma palavra: ");
    scanf("%s", x);
    int a = ContadorMinusculasCadeiaCaracteres(x, 0);
    printf("\nQuantidade de letras Minusculas: %d", a);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}

/**
10.) Incluir uma função recursiva (Exemplo0620) para
calcular certo termo par da série de Fibonacci começando em 1.
Testar essa função para quantidades diferentes.
DICA: Separar o cálculo do termo e o teste para verificar se é par.
Exemplo: valor = 3 => 2+8+34
**/

int funcaoAuxiliar(int x)
{
    if (x == 1 || x == 2)
    {
        return 1;
    }
    else
    {
        return funcaoAuxiliar(x - 2) + funcaoAuxiliar(x - 1);
    }
}
int TermoParFibonacci(int par)
{
    int y = 1;
    int x = 0;
    int a = 0;
    int b = 0;
    while (x < par)
    {
        b = funcaoAuxiliar(y);
        if (b % 2 == 0)
        {
            a = a + b;
            x = x + 1;
        }
        y = y + 1;
    }
    return (a);
}

void method10()
{
    int x = IO_readint("\nDigite a quantidade que voce deseja testar: ");
    int y = TermoParFibonacci(x);
    printf("\nResultado: %i", y);
    getchar();
    IO_pause("\nAperte Enter para terminar");
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
        IO_println(" 1 - method01");
        IO_println(" 2 - method02");
        IO_println(" 3 - method03");
        IO_println(" 4 - Erro");
        IO_println(" 5 - method05");
        IO_println(" 6 - method06");
        IO_println(" 7 - method07");
        IO_println(" 8 - method08");
        IO_println(" 9 - method09");
        IO_println("10 - method10");

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
        default:
            IO_println("ERRO: Valor invalido.");
        } // fim escolher
    } while (x != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )
