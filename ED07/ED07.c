#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

/**
01.) Incluir um método (Exemplo0711) para
ler um valor inteiro do teclado e 
gravar essa quantidade em múltiplos de 5, ímpares, em ordem crescente, começando em 5.
Exemplo: n = 5 => { 5, 15, 25, 35, 45 }
**/

/**
writeInts - Gravar em arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/
void writeInts(chars fileName, int quantidade)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int y = 1;
    int x = 5;
    // repetir para a quantidade de dados
    while (y <= quantidade)
    {
        if (x % 5 == 0 && x % 2 != 0)
        {
            // gravar valor
            fprintf(arquivo, "%d\n", x);
            y++;
        }
        x++;
    } // fim repetir
    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim writeInts ( )

/**
 Method01 - Mostrar certa quantidade de valores.
*/
void method01()
{
    int n = 0;
    n = IO_readint("Informe a quantidade de valores a serem lidos:");

    // identificar
    IO_id("EXEMPLO0701 - Method01 - v0.0");
    // executar o metodo auxiliar
    writeInts("DADOS1.TXT", n);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method01 ( )

/**

02.) Incluir um método (Exemplo0712) para
ler um valor inteiro do teclado e 
gravar essa quantidade em múltiplos de 7, pares , em ordem decrescente encerrando em 14.
Exemplo: n = 5 => { 70, 56, 42, 28, 14 }

**/

/**
writeInts - Gravar em arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/
void MultiplosD3ParesDecrescentes(chars fileName, int quantidade)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int y = 1;
    int x = 14 * quantidade;
    // int ArmazenaX = 0;
    // printf ("Valor de Y: %d", y );
    //  repetir para a quantidade de dados
    while (y <= quantidade)
    {

        if (x % 7 == 0 && x % 2 == 0 && x >= 14)
        {
            // gravar valor
            fprintf(arquivo, "%d\n", x);
            quantidade = quantidade - 1;
        }
        x--;

    } // fim repetir

    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim writeInts ( )

/**
 Method01 - Mostrar certa quantidade de valores.
*/
void method02()
{

    int n = 0;
    n = IO_readint("Informe a quantidade de valores a serem lidos:");

    // identificar
    IO_id("EXEMPLO0701 - Method01 - v0.0");
    // executar o metodo auxiliar
    MultiplosD3ParesDecrescentes("DADOS2.TXT", n);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method01 ( )

/**
03.) Incluir um método (Exemplo0713) para
ler um valor inteiro do teclado e 
gravar essa quantidade em valores da sequência: 1 3 9 27 81 ...
Exemplo: n = 5 => { 1, 3, 9, 27, 81 }
**/

void SequenciaN(chars fileName, int quantidade)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int y = 1;
    int x = 1;
    int ArmazenaXValue = 0;
    // int ArmazenaX = 0;
    // printf ("Valor de Y: %d", y );
    //  repetir para a quantidade de dados  // n = n*5
    while (y <= quantidade)
    {

        ArmazenaXValue = x * 3;

        if (x == 1)
        {
            fprintf(arquivo, "%d\n", x);
            y = y + 1;
            x = x + 2;
            fprintf(arquivo, "%d\n", x);
            y = y + 1;
        }
        else
        {
            if (ArmazenaXValue % 3 == 0 && ArmazenaXValue % 2 != 0)
            {
                // gravar valor
                fprintf(arquivo, "%d\n", ArmazenaXValue);
                x = ArmazenaXValue;
                y = y + 1;
            }
        }
    }
    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
}

void method03()
{

    int n = 0;
    n = IO_readint("Informe a quantidade de valores a serem lidos:");

    // identificar
    IO_id("EXEMPLO0701 - Method01 - v0.0");
    // executar o metodo auxiliar
    SequenciaN("DADOS3.TXT", n);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method01 ( )


/**
04.) Incluir um método (Exemplo0714) para
ler um valor inteiro do teclado e 
gravar essa quantidade em valores decrescentes da sequência: ... 1/256 1/64 1/16 1/4 1.
Exemplo: n = 5 => { 1/256, 1/64, 1/16, 1/4, 1 }
**/

/**
writeInts - Gravar em arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/


void ValoresDecrescentes (int x)
{
    FILE *arquivo = fopen("Exemplo0714.txt", "wt");
    x = x - 1;
    while (x > 0)
    {
        fprintf(arquivo, "%lf ", 1 / pow(4, x));
        x = x - 1;
    }
    fprintf(arquivo, "1");
    fclose(arquivo);
}
void method04()
{
    int x;
    printf("\nDigite a quantidade que voce deseja testar: ");
    scanf("%d", &x);
    ValoresDecrescentes(x);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}




/********************* Solução alternativa ED04 ***********************/

/**
void ValoresInversosDecrescentes(chars fileName, int inicial, int quantidade)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int y = 1;
    int x = 0;

    while (y <= quantidade)
    {
        if (x == 0)
        {
            fprintf(arquivo, "%.2lf\n", 1.0/inicial);
            quantidade = quantidade - 1;
            x += inicial / 3;
            fprintf(arquivo, "%.2lf\n", 1.0/x);
            quantidade = quantidade - 1;
        }
        else
        {
            x = x / 3;
            fprintf(arquivo, "%.2lf\n", 1.0/x);
            quantidade = quantidade - 1;
        }

    } // fim repetir

    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim writeInts ( )
**/

/**
 Method01 - Mostrar certa quantidade de valores.
*/

/**
void method04()
{

    int n = 0;
    float ValorInicial = 0;
    n = IO_readint("Informe a quantidade de valores a serem lidos:");
    ValorInicial = pow(3, n - 1);

    // identificar
    IO_id("EXEMPLO0701 - Method01 - v0.0");
    // executar o metodo auxiliar
    ValoresInversosDecrescentes("DADOS4.TXT", ValorInicial, n);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method01 ( )
**/



/**
05.) Incluir em um programa (Exemplo0715) um método para
ler um valor inteiro do teclado (n) e outro valor real (x),
gravar essa quantidade (n) em valores reais da sequência: 1 1/x1 1/x3 1/x5
...
DICA: Usar pow ( x, y ) da biblioteca <math.h> para calcular a potência.
Exemplo: n = 5 => { 1, 1/x1
, 1/x3
, 1/x5
, 1/x7
}
**/

int SequenciaValoresReais(double x, int y)
{
    FILE *arquivo = fopen("Exemplo0715.txt", "wt");
    fprintf(arquivo, "1 ");
    int impar = 1;
    int z = 0;
    while (z < y)
    {
        fprintf(arquivo, "%lf ", 1 / pow(x, impar));
        z = z + 1;
        impar = impar + 2;
    }
    fclose(arquivo);
}
void method05()
{
    int y;
    double x;
    printf("\nDigite a quantidade que voce deseja testar: ");
    scanf("%d", &y);
    printf("\nDigite o valor do denominador: ");
    scanf("%lf", &x);
    SequenciaValoresReais(x, y);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}



/**
06.) Incluir um método e uma função (Exemplo0716) para
ler um valor inteiro do teclado para representar certa quantidade de valores 
a serem somados dentre os primeiros gravados no exercício anterior.
Testar essa função para quantidades diferentes. 
Gravar em outro arquivo ("RESULTADO06.TXT") cada quantidade e seu resultado.
**/


int SomaSequenciaValoresReais(int x)
{
    FILE *arquivo = fopen("Exemplo0715.txt", "r");
    FILE *pasta = fopen("Exemplo0716.txt", "wt");
    double soma = 0.0;
    double y;
    int z = 0;
    while (z < x && !feof(arquivo))
    {
        fscanf(arquivo, "%lf", &y);
        soma = soma + y;
        z = z + 1;
    }
    fprintf(pasta, "%lf", soma);
    fclose(arquivo);
    fclose(pasta);
}
void method06()
{
    int x;
    printf("\nDigite a quantidade que voce deseja testar: ");
    scanf("%d", &x);
    SomaSequenciaValoresReais(x);
    getchar();
    IO_pause("\nAperte Enter para terminar");
} // fim repetir


/**
07.) Incluir um método e uma função (Exemplo0717) para
ler um valor inteiro do teclado, e até essa quantidade, um valor por vez,
calcular a soma dos inversos das potências do exercício 04.
Gravar em outro arquivo ("RESULTADO07.TXT") cada quantidade e seu resultado.
Exemplo: n = 5 => { 1/256 1/64 1/16 1/4 1 }
**/


int GravarSomaDosInversos(int x)
{
    FILE *arquivo = fopen("Exemplo0714.txt", "r");
    FILE *pasta = fopen("Exemplo0717.txt", "wt");
    double soma = 0.0;
    double y;
    int z = 0;
    while (z < x && !feof(arquivo))
    {
        fscanf(arquivo, "%lf", &y);
        soma = soma + y;
        z = z + 1;
    }
    fprintf(pasta, "%lf", soma);
    fclose(arquivo);
    fclose(pasta);
}
void method07()
{
    int x;
    printf("\nDigite a quantidade que voce deseja testar: ");
    scanf("%d", &x);
    GravarSomaDosInversos(x);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}



/**
08.) Incluir um método e uma função (Exemplo0718) para
ler um valor inteiro do teclado, e até atingir essa quantidade, um valor por vez,
gravar o valor correspondente aos primeiros termos pares da série de Fibonacci.
Gravar em outro arquivo ("RESULTADO08.TXT") cada quantidade e seu resultado.
Exemplo: n = 5 => { 2, 8, 34, 144, 610}
**/


int funcaoB(int x)
{
    if (x == 1 || x == 2)
    {
        return 1;
    }
    else
    {
        return funcaoB(x - 2) + funcaoB(x - 1);
    }
}
void funcaoA(int par)
{
    int y = 1;
    int x = 0;
    int b = 0;
    FILE *arquivo = fopen("Exemplo0718.txt", "wt");
    while (x < par)
    {
        b = funcaoB(y);
        if (b % 2 == 0)
        {
            fprintf(arquivo, "%d ", b);
            x = x + 1;
        }
        y = y + 1;
    }
    fclose(arquivo);
}

void method08()
{
    int x;
    printf("\nDigite a quantidade que voce deseja: ");
    scanf("%d", &x);
    funcaoA(x);
    getchar();
    IO_pause("\nAperte Enter para terminar");
}



/**
09.) Incluir um método e uma função (Exemplo0719) para
para calcular a quantidade de maiúsculas em cadeia de caracteres de um arquivo texto.
Gravar em outro arquivo ("RESULTADO09.TXT") cada cadeia de caracteres e seus resultados.
Testar essa função com cadeias de tamanhos diferentes.
Exemplo: PaReDe de TiJoLoS VerMElHOS
**/


void CaracteresMaiusculas()
{
    FILE *arquivo = fopen("ExemploRegMaiusculas.txt", "wt");
    chars vetor = IO_new_chars ( STR_SIZE );
        
     int x = 0;
     int y = 0;


            printf ("\nDigite a cadeia de caracteres a ser testada: \t");  
            strcpy ( vetor, IO_readln ( "" ) );


            do 
        {
            if ('A' <= vetor[x] && vetor[x] <= 'Z')
            {
                y = y + 1;
            } else {
                        y = y;    
            }
             x = x + 1;

        } while (x<=strlen(vetor));

         fprintf(arquivo, "\nCadeia de caracteres: %s \t Numero total de caracteres maiusculas: %d \n", vetor, y);

         fclose(arquivo);

    }

   
void method09(){

                            CaracteresMaiusculas();
                            getchar();
                            IO_pause("\nAperte Enter para terminar");
}    

/**
10.) Incluir um método e uma função (Exemplo0720) para
para contar dígitos maiores ou iguais a 7 em uma cadeia de caracteres.
Gravar em outro arquivo ("RESULTADO10.TXT") cada cadeia de caracteres e seu resultado.
Testar essa função para cadeias de tamanhos diferentes.
Exemplo: P4R3D3 de T1J0L05 V3rMElH05
**/


void DigitosMaiorOuIgualA7()
{
    FILE *arquivo = fopen("ExemploRegNumeros.txt", "wt");
    chars vetor = IO_new_chars ( STR_SIZE );
        
     int x = 0;
     int y = 0;
       
            printf ("\nDigite a cadeia de caracteres a ser testada: \t");  
            strcpy ( vetor, IO_readln ( "" ) );

            do 
        {
            if ('7' <= vetor[x] && vetor[x] <= '9')
            {
                y = y + 1;
            } else {
                        y = y;    
            }
             x = x + 1;

        } while (x<=strlen(vetor));

         fprintf(arquivo, "\nCadeia de caracteres: %s \t Numero de Digitos >= 7: %d \n", vetor, y);

         fclose(arquivo);

    }

   
void method10()
{    
    DigitosMaiorOuIgualA7();
    getchar();
    IO_pause("\nAperte Enter para terminar");
}

/*
Tarefas extras:
E1.) Incluir um método (Exemplo07E1) para
programa ler um valor inteiro do teclado, e
gravar em arquivo os seus divisores em ordem decrescente.
*/






/*
E2.) Incluir um método e uma função (Exemplo07E2) para
ler palavras de um arquivo, uma por linha, e
contar quantas começam com a letra 'a' (ou 'A').
*/


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
        IO_println(" 1 - .");
        IO_println(" 2 -  ");
        IO_println(" 3 -  ");
        IO_println(" 4 -  ");
        IO_println(" 5 -  ");
        IO_println(" 6 -  ");
        IO_println(" 7 -  ");
        IO_println(" 8 -  ");
        IO_println(" 9 -  ");
        IO_println("10 -  ");
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
        default:
            IO_println("ERRO: Valor invalido.");
        } // fim escolher
    } while (x != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )