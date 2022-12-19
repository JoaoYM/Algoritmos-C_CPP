/**
 * @file Untitled-2
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-10
 *
 * @copyright Copyright (c) 2022
 *
 */

/**

01.) Incluir um método (Exemplo0311) para:
- ler uma palavra do teclado;
- mostrar as letras maiúsculas.
 DICA: Definir um teste para determinar se um caractere é letra maiúscula.
Exemplo: palavra = "PaLaVrA"
 **/

#include "io.h"

/**
 while ( CONTADOR <= N )
 {
 printf ( "\n%d", CONTADOR );
 printf ( " FORNECER UM VALOR INTEIRO QUALQUER : " );
 scanf ( "%d", &X );
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 CONTADOR = CONTADOR + 1;
 } // ENQUANTO ( CONTADOR <= N
 *
 */

/**
 Method01 - Repeticao sobre cadeia de caracateres.
*/
void method01()
{
  // definir dado
  int x = 0;
  int i = 0;
  int contador = 0;

  chars palavra = IO_new_chars(STR_SIZE);
  int tamanho = 0;
  // identificar
  IO_id("EXEMPLO0306 - Method06 - v0.0");
  // ler do teclado
  palavra = IO_readstring("Entrar com uma palavra: ");
  // repetir para cada letra
  tamanho = strlen(palavra) - 1;
  // OBS: A cadeia de caracteres iniciam suas posições em zero.
  // inicio teste variacao

  for (i = 0; i < strlen(palavra); i++)
  {
    if ('A' <= palavra[i] && palavra[i] <= 'Z')
    {
      // mostrar valor atual
      IO_printf("%c", palavra[i]);
      IO_printf("\n");
    }
  } // fim repetir

  // encerrar
  IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**
 Method02 - Repeticao sobre cadeia de caracateres.
*/

/**

02.) Incluir um método (Exemplo0312) para:
- ler uma palavra do teclado;
- contar e mostrar apenas as letras maiúsculas. 
Exemplo: palavra = "PaLaVrA

**/
void method02()
{
  // definir dado
  int x = 0;
  int i = 0;
  int contador = 0;

  chars palavra = IO_new_chars(STR_SIZE);
  int tamanho = 0;
  // identificar
  IO_id("EXEMPLO0306 - Method06 - v0.0");
  // ler do teclado
  palavra = IO_readstring("Entrar com uma palavra: ");
  // repetir para cada letra
  tamanho = strlen(palavra) - 1;
  // OBS: A cadeia de caracteres iniciam suas posições em zero.
  // inicio teste variacao

  for (i = 0; i < strlen(palavra); i++)
  {
    if ('A' <= palavra[i] && palavra[i] <= 'Z')
    {
      // mostrar valor atual
      IO_printf("%c", palavra[i]);

      IO_printf("%i  ", contador);
      IO_printf("\n");
      contador = contador + 1;
    }
  } // fim repetir

  // encerrar
  IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**
 Method03 - Repeticao sobre cadeia de caracateres.
*/

/**

03.) Incluir um método (Exemplo0313) para:
- ler uma palavra do teclado;
- contar e mostrar as letras maiúsculas percorrendo do fim para o início da palavra. 
Exemplo: palavra = "PaLaVrA"


**/

void method03()
{
  // definir dado
  int x = 0;
  int i = 0;
  int contador = 0;

  chars palavra = IO_new_chars(STR_SIZE);
  int tamanho = 0;
  // identificar
  IO_id("EXEMPLO0306 - Method06 - v0.0");
  // ler do teclado
  palavra = IO_readstring("Entrar com uma palavra: ");
  // repetir para cada letra
  tamanho = strlen(palavra) - 1;
  // OBS: A cadeia de caracteres iniciam suas posições em zero.
  // inicio teste variacao

  for (i = strlen(palavra); i >= 0; i--) // for da 3
  {
    if ('A' <= palavra[i] && palavra[i] <= 'Z')
    {
      // mostrar valor atual
      IO_printf("%c", palavra[i]);

      IO_printf("%i  ", contador);
      IO_printf("\n");
      contador = contador + 1;
    }
  } // fim repetir

  // encerrar
  IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**

04.) Incluir um método (Exemplo0314) para:
- ler uma cadeia de caracteres do teclado;
- contar e mostrar todos símbolos que forem letras, ou maiúsculas ou minúsculas. 
Exemplo: palavra = "P4LaVr@"

 **/

void method04()
{
  // definir dado
  int x = 0;
  int i = 0;
  int contador = 0;

  chars palavra = IO_new_chars(STR_SIZE);
  int tamanho = 0;
  // identificar
  IO_id("EXEMPLO0306 - Method06 - v0.0");
  // ler do teclado
  palavra = IO_readstring("Entrar com uma palavra: ");
  // repetir para cada letra
  tamanho = strlen(palavra) - 1;
  // OBS: A cadeia de caracteres iniciam suas posições em zero.
  // inicio teste variacao

  for (i = 0; i < strlen(palavra); i++)
  {
    if ('a' <= palavra[i] && palavra[i] <= 'z' || 'A' <= palavra[i] && palavra[i] <= 'Z')
    {
      // mostrar valor atual
      IO_printf("%c", palavra[i]);
      contador = contador + 1;
    }

  } // fim repetir
  IO_printf("\n");

  IO_printf("%i  ", contador);

  // encerrar
  IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**
05.) Incluir um método (Exemplo0315) para:
- ler uma cadeia de caracteres do teclado;
- contar e mostrar todos os dígitos, percorrendo do fim para o início da cadeia de caracteres.
Exemplo: palavra = "P4LaVr@1"
 **/

void method05()
{
  // definir dado
  int x = 0;
  int i = 0;
  int contador = 0;

  chars palavra = IO_new_chars(STR_SIZE);
  int tamanho = 0;
  // identificar
  IO_id("EXEMPLO0306 - Method06 - v0.0");
  // ler do teclado
  palavra = IO_readstring("Entrar com uma palavra: ");
  // repetir para cada letra
  tamanho = strlen(palavra) - 1;
  // OBS: A cadeia de caracteres iniciam suas posições em zero.
  // inicio teste variacao

  for (i = strlen(palavra); i >= 0; i--)
  {
    if ('0' <= palavra[i] && palavra[i] <= '9')
    {
      // mostrar valor atual
      IO_printf("%c", palavra[i]);

      IO_printf("%i  ", contador);
      IO_printf("\n");
      contador = contador + 1;
    }
  } // fim repetir

  // encerrar
  IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**

  06.) Incluir um método (Exemplo0316) para:
  - ler uma cadeia de caracteres do teclado;
  - contar e mostrar tudo o que não for dígito e também não for letra.
  Exemplo: palavra = "P4LaVr@O!"

 **/

void method06()
{
  // definir dado
  int x = 0;
  int i = 0;
  int contador = 0;

  chars palavra = IO_new_chars(STR_SIZE);
  int tamanho = 0;
  // identificar
  IO_id("EXEMPLO0306 - Method06 - v0.0");
  // ler do teclado
  palavra = IO_readstring("Entrar com uma palavra: ");
  // repetir para cada letra
  tamanho = strlen(palavra) - 1;
  // OBS: A cadeia de caracteres iniciam suas posições em zero.
  // inicio teste variacao

  for (i = 1; i <= strlen(palavra); i++)
  {
    if (!('0' <= palavra[i] && palavra[i] <= '9') && !('a' <= palavra[i] && palavra[i] <= 'z') && !('A' <= palavra[i] && palavra[i] <= 'Z'))
    {
      // mostrar valor atual
      IO_printf("%c ", palavra[i]);
      contador = contador + 1;
    }
  } // fim repetir
  contador = contador - 1;

  IO_printf("\n");
  IO_printf("%i  ", contador);

  // encerrar
  IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**

07.) Incluir um método (Exemplo0317) para:
- ler dois valores inteiros (a,b), limites para definirem um intervalo [a:b];
- ler uma quantidade (n) de valores inteiros a serem testados;
- repetir a leitura de outros tantos valores, quantos os indicados pela quantidade, um (x) por vez;
- contar e mostrar quantos dentre esses valores lidos (x) 
 os que forem múltiplos de 5, e pertençam ao intervalo [a:b]. 
Exemplo: [ 30: 70 ], e n = 7, com { 10, 20, 30, 41, 55, 60, 84 }

**/

void method07()
{
  int IntervaloN1 = 0;
  int IntervaloN2 = 0;
  int Quantidade = 0;
  int Contador = 0;

  IntervaloN1 = IO_readint("Informe o valor inicial do limite a ser estipulado: ");
  IntervaloN2 = IO_readint("Informe o valor final do limite a ser estipulado: ");
  Quantidade = IO_readint("Informe a quantidade de valores inteiros para teste: ");

  for (int i = 1; i <= Quantidade; i++)
  {
    int Valor = 0;

    Valor = IO_readint("Insira o valor desejado: ");

    if ((Valor % 5 == 0) && (Valor >= IntervaloN1 && Valor <= IntervaloN2))
    {

      IO_printf("O valor, %d e multiplo de 5 e esta incluso no intervalo de %d e %d ", Valor, IntervaloN1, IntervaloN2);
    }
    else
    {

      IO_printf("\nO valor informado nao e multiplo de 5 e nao se encontra entre o intervalo %d e %d\n", IntervaloN1, IntervaloN2);
    }

    Contador = Contador + 1;
    if ((Valor % 5 == 0) && (Valor >= IntervaloN1 && Valor <= IntervaloN2))
    {
      Contador = Contador++;

      IO_printf("\n");
      IO_printf("%i  ", Contador);
    }

  } //  End IF

  IO_pause("Apertar ENTER para continuar");
} // Fim método 07

/**
08.) Incluir um método (Exemplo0318) para:
- ler dois valores inteiros (a,b), limites para definirem um intervalo [a:b];
- ler uma quantidade (n) de valores inteiros a serem testados;
- ler outros tantos valores quantos os indicados pela quantidade, um (x) por vez;
- contar e mostrar quantos dentre esses valores lidos (x)
 os que forem múltiplos de 2, que não forem também múltiplos de 3,
 e pertençam ao intervalo [a:b].
Exemplo: [ 30: 70 ], e n = 7, com { 10, 20, 30, 41, 55, 60, 84 }
**/

void method08()
{
  int IntervaloN1 = 0;
  int IntervaloN2 = 0;
  int Quantidade = 0;
  int Contador = 0;

  IntervaloN1 = IO_readint("Informe o valor inicial do limite a ser estipulado: ");
  IntervaloN2 = IO_readint("Informe o valor final do limite a ser estipulado: ");
  Quantidade = IO_readint("Informe a quantidade de valores inteiros para teste: ");

  for (int i = 1; i <= Quantidade; i++)
  {
    int Valor = 0;

    Valor = IO_readint("\nInsira o valor desejado:\n ");

    if ((Valor % 2 == 0) && (!(Valor % 3 == 0)) && (Valor >= IntervaloN1 && Valor <= IntervaloN2))
    {

      IO_printf("\nO valor, %d e multiplo de 2, nao e multiplo de 3 e esta incluso no intervalo de %d e %d ", Valor, IntervaloN1, IntervaloN2);
    }
    else
    {

      IO_printf("\nO valor informado nao atende aos criterios estipulados\n");
    }

    Contador = Contador + 1;

  } //  End IF

  Contador = Contador++;

  IO_printf("\n");
  IO_printf("%i  ", Contador);

  IO_pause("Apertar ENTER para continuar");
} // Fim método 07

/**
09.) Incluir um método (Exemplo0319) para:
- ler dois valores reais (a e b), o primeiro (a) menor que o segundo (b), confirmadamente,
 para definirem um intervalo aberto (a:b);
- ler a quantidade (n) de valores reais a serem testados, e
 ler outros tantos valores (x) quantos os indicados por essa quantidade;
- contar e mostrar todos os valores lidos, pertencentes ao do intervalo,
cujas partes inteiras forem pares.
 DICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int),
antes de testar se é ímpar (ver Exemplo0110).
Exemplo: ( 2.7: 6.4 ), e n = 7, com { 1.0, 2.4, 3.6, 4.1, 5.5, 6.3, 8.4 }
**/

void method09()
{
  float IntervaloN1 = 0.0;
  float IntervaloN2 = 0.0;
  float Quantidade = 0.0;
  float Contador = 0.0;
int valor = 0;

  IntervaloN1 = IO_readfloat("Informe o valor inicial do limite a ser estipulado: ");
  IntervaloN2 = IO_readfloat("Informe o valor final do limite a ser estipulado: ");
if (IntervaloN2>IntervaloN1)
      {
                 Quantidade = IO_readfloat("Informe a quantidade de valores inteiros para teste: ");

                  for (int i = 1; i <= Quantidade; i++)
                    {
                       float Valor2 = 0;

                       Valor2 = IO_readfloat("\nInsira o valor desejado:\n ");
                      valor = (float)Valor2;
                      if (valor %2 == 0)
                   {

                   IO_printf("\nA parte inteira do valor %2.f e par ", Valor2 );
                      Contador = Contador + 1;
                   } else {

                     IO_printf("\nA parte inteira do valor %2.f e impar ", Valor2 );
                   }
                 
                   

               } //  End IF

                   
                   IO_printf("\n");
                   IO_printf("%i  ", Contador);
               } else {

                  IO_print ("O valor final do limite informado e invalido, reinserir valores ao termino da execucao do programa");
                            }

                  IO_pause("Apertar ENTER para continuar");
                } // Fim método 07




/**

10.) Incluir um método (Exemplo0320) para:
- ler dois valores reais (a e b), maiores que 0 e menores que 1, confirmadamente, 
 para definirem um intervalo aberto (a:b);
- ler uma quantidade (n) de valores reais a serem testados, e
 ler outros tantos valores quantos os indicados por essa quantidade;
- contar e mostrar todos os valores lidos 
 que tenham suas partes fracionárias fora do intervalo ]a:b[. 
 DICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int),
e obter a parte fracionária mediante a subtração da parte inteira, antes de testar.
Exemplo: ( 0.3: 0.7 ), e n = 7, com { 1.0, 2.8, 3.6, 4.1, 5.5, 6.9, 8.4 }


         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TO DO!!!!!!!!!!!!!!!!!!!!!!
 **/

void method10()
{

float n1 = 0.0;
float n2 = 0.0;
float in = 0.0;
int ArmazenaIN = 0;
int i = 0;
int N_numeros = 0;
int ContadorDecimal_Out = 0;
  printf ("\nInforme a quantidade de valores a serem lidos: \t");
  scanf ("%d", &N_numeros);

  printf ("\nInforme o valor inicial de ]x: \t");
  scanf ("%f", &n1);
  printf ("\nInforme o valor final de x2[, para definicao do intervalo aberto: \t", n2);
  scanf ("%f", &n2);

  for (i=0; i < N_numeros; i = i + 1)
{
    printf ("\nInforme o valor fracioanario a ser testado: \t");
    scanf ("%f", &in);
    ArmazenaIN = (int)in;
    in = in - ArmazenaIN;
    
    if (in <= n1 || in >= n2)
    {
        printf ("\nO valor %.2f se encontra fora do intervalo ]%.2f:%.2f[ \n", in, n1, n2);
        ContadorDecimal_Out = ContadorDecimal_Out + 1;
    } else 
      {
        if (in > n1 && in < n2)
        {
                  printf ("\nO valor %.2f se encontra dentro do intervalo ]%.2f:%.2f[ \n", in, n1, n2);
        }
      }
    
}

    printf ("\nAo todo temos %d valores lidos fora do intervalo ]%.2f:%.2f[\n", ContadorDecimal_Out, n1, n2);

}





/*
 Funcao principal.
*/
int main()
{
  // definir dado
  int x = 0;
  // repetir até desejar parar
  do
  {
    // identificar
    IO_id("EXEMPLO0306 - Programa - v0.0");

    // ler do teclado
    IO_println("Opcoes");
    IO_println("0 - parar");
    IO_println("1 - Exemplo0311");
    IO_println("2 - Exemplo0312");
    IO_println("3 - Exemplo0313");
    IO_println("4 - Exemplo0314");
    IO_println("5 - Exemplo0315");
    IO_println("6 - Exemplo0316");
    IO_println("7 - Exemplo0317");
    IO_println("8 - Exemplo0318");
    IO_println("9 - Exemplo0319");
    IO_println("10 -Exemplo0320");


    IO_println("");
    x = IO_readint("Entrar com uma opcao: ");

    // testar valor
    switch (x)
    {
    /**
     * case 0:
    method00 ( );
    break;



    case 6:
    method06 ( );
    break;
    **/
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
      IO_pause("ERRO: Valor invalido.");
    } // fim escolher
  } while (x != 0);
  // encerrar
  IO_pause("Apertar ENTER para terminar");
  return (0);
} // fim main( )