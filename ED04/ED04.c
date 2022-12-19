#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

            
/**
01.) Incluir em um programa (Exemplo0411) um método para:
- ler dois valores reais para definir um intervalo fechado;
- ler certa quantidade de valores reais e 
- contar quantos desses valores estão dentro do intervalo, e quantos estão fora dele.
Exemplo: n = 5 e [ 10.5 : 20.4 ] com { 5.1, 10.5, 15.3, 20.4, 24.2 }
**/


void method_01 ( ){

float x = 0.0; // Valor Inicial 
float y = 0.0; // Valor Final
int quantidade = 0; // Estabele a quantidade de valores a serem informados e lidos
int controle = 1;  // Variável de controle _ Repetição do método
float Valores = 0.0; // Entrada valores reais 
int contador1 = 0;  // Conta o número de valores reais dentro do intervalo fechado previamente informado 
int contador2 = 0; // Conta o número de valores reais dentro do intervalo fechado previamente informado 

x = IO_readfloat ("Digite o valor inicial do intervalo: ");

y = IO_readfloat ("Digite o valor final do intervalo: ");

quantidade = IO_readint ("Digite a quantidade de valores reais a serem lidos: ");

if ( quantidade > 0)
{

    while (controle<=quantidade)
    {
      Valores = IO_readfloat ("Informe o valor do real: ");

      if  (Valores>=x && Valores<=y){
              contador1 = contador1+1;
              controle = controle+1;
              
      }else  { 
              contador2 = contador2+1;
              controle = controle+1;
             }
    }
        IO_printf ("Numero de valores dentro do intervalo %.2lf e %.2lf= %d\n", x, y, contador1);
        IO_printf ("Numero de valores fora do intervalo %.2lf e %.2lf= %d\n", x, y, contador2);

} else 
{
    IO_printf ("\nA quantidade inserida e' invalida\n\n ");
} // end else 

} // end method01

/**
02.) Incluir um método (Exemplo0412) para:
- ler uma sequência de caracteres do teclado;
- contar e mostrar a quantidade de letras maiúsculas maiores que 'J'. 
 DICA: Definir uma função para determinar se um caractere é letra maiúscula.
Exemplo: sequência = AaKkLmM0*Nx
**/

void method_02 (void) 
{
int x = 0;
int y = 0;
char palavra [STR_SIZE];
int tamanho = 0;
int contador = 0;


// identificar 
IO_id ("Exemplo_Operações com Caracteres");
// ler do teclado 
IO_printf ("Entrar com uma palavra: ");
scanf ("%s", palavra);
// repetir para cada letra 
tamanho = strlen (palavra);
// OBS: A cadeia de caracteres iniciam suas posições em 0
// Inicio teste variação 
for (y=0; y<tamanho; y = y+1 )
{
// mostrar valor atual
IO_printf ("%d: [%c]", y, palavra [y]);
// Informar se a letra lida é maiuscula e menor do que K
if ('A'<=palavra [y] && palavra[y] <= 'Z' && palavra[y] > 'J')
    {
        IO_printf ("\tE' maior do que 'J' ");
            
                                contador = contador + 1;                                               
    }
    printf ("\n");
} // fim for 
        printf ("Ao todo temos %d letras Maiusculas maiores do que J.\n", contador);

} // end method_02


/**

03.) Incluir um método (Exemplo0413) para:
- ler uma sequência de caracteres do teclado;
- mostrar a quantidade de letras maiúsculas maiores que 'J' contadas por uma função 
 definida para receber uma cadeia de caracteres como parâmetro.
Exemplo: sequência = AaKkLmM0*Nx

**/

int MaiusculasMenoresK (char* palavra) {

int x = 0;
int y = 0;
int tamanho = 0;
int contador = 0;

// repetir para cada letra 
tamanho = strlen (palavra);
// OBS: A cadeia de caracteres iniciam suas posições em 0

// Inicio teste variação 
for (y=0; y<tamanho; y = y+1 )
{
// mostrar valor atual
IO_printf ("%d: [%c]", y, palavra [y]);
// Informar se a letra lida é maiuscula e menor do que K
if ('A'<=palavra [y] && palavra[y] <= 'Z' && palavra[y] > 'J')
    {
        IO_printf ("\tE' maior do que 'J' ");
            
                                contador = contador + 1;                                               
    }
    printf ("\n");
} // fim for
            return (contador);
}


void method_03 (void) 
{
   char palavra [STR_SIZE];

    
// identificar 
IO_id ("Exemplo_Operações com Caracteres");
// ler do teclado 
IO_printf ("Entrar com uma palavra: ");
scanf ("%s", palavra);

        printf ("Ao todo temos %d letras Maiusculas menores do que K.\n", MaiusculasMenoresK(palavra));

} // end method_03


/**

04.) Incluir um método (Exemplo0414) para:
- ler uma sequência de caracteres do teclado;
- mostrar as letras maiúsculas maiores que 'J' separadas por uma função 
 definida para receber uma cadeia de caracteres como parâmetro.
Exemplo: sequência = AaKkLmM0*Nx
**/


int MaiuscMenoresK (char* palavra) {

int x = 0;
int y = 0;
int tamanho = 0;
int contador = 0;

// repetir para cada letra 
tamanho = strlen (palavra);
// OBS: A cadeia de caracteres iniciam suas posições em 0

// Inicio teste variação 
for (y=0; y<tamanho; y = y+1 )
{
// Informar se a letra lida é maiuscula e menor do que K
if ('A'<=palavra [y] && palavra[y] <= 'Z' && palavra[y] < 'J')
    {
        IO_printf ("\tValores menores que 'J': ");
            
                                contador = contador + 1;       
                         IO_printf ("%d: [%c]", y, palavra [y]);                                                                
    }
    printf ("\n");
    // mostrar valor atual
} // fim for
            return (contador);
}


void method_04 (void) 
{
   char palavra [STR_SIZE];

    
// identificar 
IO_id ("Exemplo_Operações com Caracteres");
// ler do teclado 
IO_printf ("Entrar com uma palavra: ");
scanf ("%s", palavra);

        printf ("Ao todo temos %d letras Maiusculas menores do que J.\n", MaiuscMenoresK(palavra));

} // end method_04


/**
05.) Incluir um método (Exemplo0415) para:
- ler uma sequência de caracteres do teclado;
- mostrar a quantidade de letras (tanto maiúsculas, quanto minúsculas) maiores que 'J' e 'j'
 contadas por uma função definida para receber uma cadeia de caracteres como parâmetro.
Exemplo: sequência = AaKkLmM0*Nx
**/


int MaiuscMenoresKk (char* palavra) {

int x = 0;
int y = 0;
int tamanho = 0;
int controle = 0;
int contador = 0;
int contador2 = 0;

// repetir para cada letra 
tamanho = strlen (palavra);
// OBS: A cadeia de caracteres iniciam suas posições em 0

// Inicio teste variação 
for (y=0; y<tamanho; y = y+1 )
{
// Informar se a letra lida é maiuscula e menor do que K
if ('A'<=palavra [y] && palavra[y] <= 'Z' && palavra[y] > 'J')
    {
        IO_printf ("\tValor maior que 'J': ");

                                controle = controle +1;
                                contador = contador + 1;       
                         IO_printf ("%d: [%c]", y, palavra [y]);     
                         printf ("\n");                                                           
    } else {
                // Informar se a letra lida é maiuscula e menor do que K
              if ('a'<=palavra [y] && palavra[y] <= 'z' && palavra[y] > 'j')
             {
                  IO_printf ("\tValor maior que 'j': ");
            
                                 controle = controle +1;
                                contador2 = contador2 + 1;       
                         IO_printf ("%d: [%c]", y, palavra [y]);     
                         printf ("\n");                                                           
             } else {
                    
                    }
           }
                         

    // mostrar valor atual
} // fim for

             IO_printf ("\nTemos o total de valores maiores que 'J' sendo respectivamente %d\n", contador );     
             IO_printf ("\nTemos o total de valores maiores que 'j' sendo respectivamente %d\n", contador2);    
            return (controle);
}


void method_05 (void) 
{
   char palavra [STR_SIZE];

    
// identificar 
IO_id ("Exemplo_Operações com Caracteres");
// ler do teclado 
IO_printf ("Entrar com uma palavra: ");
scanf ("%s", palavra);

        printf ("\nTemos o total de valores maiores que 'J' e 'j' de %d.\n", MaiuscMenoresKk(palavra));

} // end method_05


/**
06.) Incluir um método (Exemplo0416) para:
- ler uma sequência de caracteres do teclado;
- mostrar as letras (tanto maiúsculas, quanto minúsculas) maiores que 'J' e 'j'
 separadas por uma função definida para receber uma cadeia de caracteres como parâmetro.
Exemplo: sequência = AaKkLmM0*Nx
**/


int MaiuscMenoresKk2 (char* palavra) {

int x = 0;
int y = 0;
int tamanho = 0;
int controle = 0;
int contador = 0;
int contador2 = 0;

// repetir para cada letra 
tamanho = strlen (palavra);
// OBS: A cadeia de caracteres iniciam suas posições em 0

// Inicio teste variação 
for (y=0; y<tamanho; y = y+1 )
{
// Informar se a letra lida é maiuscula e menor do que K
if ('A'<=palavra [y] && palavra[y] <= 'Z' && palavra[y] > 'J')
    {
        IO_printf ("\tValor maior que 'J': ");

                                controle = controle +1;
                                contador = contador + 1;       
                         IO_printf ("%d: [%c]", y, palavra [y]);     
                         printf ("\n");                                                           
    } else {
                // Informar se a letra lida é maiuscula e menor do que K
              if ('a'<=palavra [y] && palavra[y] <= 'z' && palavra[y] > 'j')
             {
                  IO_printf ("\tValor maior que 'j': ");
            
                                 controle = controle +1;
                                contador2 = contador2 + 1;       
                         IO_printf ("%d: [%c]", y, palavra [y]);     
                         printf ("\n");                                                           
             } else {
                    
                    }
           }
                         

    // mostrar valor atual
} // fim for

             IO_printf ("\nTemos o total de valores maiores que 'J' sendo respectivamente %d\n", contador );     
             IO_printf ("\nTemos o total de valores maiores que 'j' sendo respectivamente %d\n", contador2);    
            return (controle);
}


void method_06 (void) 
{
   char palavra [STR_SIZE];

    
// identificar 
IO_id ("Exemplo_Operações com Caracteres");
// ler do teclado 
IO_printf ("Entrar com uma palavra: ");
scanf ("%s", palavra);

        printf ("\nTemos o total de valores maiores que 'K' e 'k' sendo de %d.\n", MaiuscMenoresKk2(palavra));

} // end method_06


/**
07.) Incluir um método (Exemplo0417) para:
- ler uma sequência de caracteres do teclado;
- mostrar a quantidade de dígitos pares em uma cadeia de caracteres contados por uma função
 definida para receber uma cadeia de caracteres como parâmetro.
 DICA: Considerar o valor inteiro do código equivalente (type casting) para teste. 
Exemplo: sequência = A1b2C3d4E5f6
**/



int CadeiaCharN (char* palavra) {

int x = 0;
int y = 0;
int tamanho = 0;
int contador = 0;

// repetir para cada letra 
tamanho = strlen (palavra);
// OBS: A cadeia de caracteres iniciam suas posições em 0

// Inicio teste variação 
for (y=0; y<tamanho; y = y+1 )
{
// Informar se a letra lida é maiuscula e menor do que K
if ( '2' <=palavra [y] && palavra[y] < '9' )
    {
        IO_printf ("\tValor e' Par: ");
            
                                contador = contador + 1;       
                         IO_printf ("%d: [%c]", y, palavra [y]); 

                         y= y+1;                                                               
    }
    printf ("\n");
    // mostrar valor atual
} // fim for
            return (contador);
}


void method_07 (void) 
{
   char palavra [STR_SIZE];

    
// identificar 
IO_id ("Exemplo_Operações com Caracteres");
// ler do teclado 
IO_printf ("Entrar com uma palavra: ");
scanf ("%s", palavra);

        printf ("Ao todo temos %d numeros pares na cadeia.\n", CadeiaCharN(palavra));

} // end method_04


/**
08.) Incluir um método (Exemplo0418) para:
- ler uma sequência de caracteres do teclado;
- mostrar todos os símbolos não alfanuméricos (letras e dígitos) em uma cadeia de caracteres 
 separados por meio de uma função. 
Exemplo: sequência = (A1b2+C3d4)*E5f6
**/



int NaoAlfanumerico (char* palavra) {

int x = 0;
int y = 0;
int tamanho = 0;
int contador = 0;

// repetir para cada letra 
tamanho = strlen (palavra);
// OBS: A cadeia de caracteres iniciam suas posições em 0

// Inicio teste variação 
for (y=0; y<tamanho; y = y+1 )
{
// Informar se o caractrere lido e' um nao alfanumerico
if ( !('0' <= palavra [y] && palavra[y] <= '9') && !('a'<= palavra [y] && palavra[y] <= 'z') && !('A'<= palavra [y] && palavra[y] <= 'Z' ) || ( ('!','&','|') == palavra [y])  )
    {
        IO_printf ("\tValor nao alfanumerico: ");
            
                                contador = contador + 1;       
                         IO_printf ("%d: [%c]\n", y, palavra [y]); 

    }
          //  printf("\n");
    // mostrar valor atual
} // fim for
            return (contador);
}


void method_08 (void) 
{
   char palavra [STR_SIZE];

    
// identificar 
IO_id ("Exemplo_Operações com Caracteres");
// ler do teclado 
IO_printf ("Entrar com uma palavra: \n");
scanf ("%s", palavra);

        printf ("\nAo todo temos %d caracteres nao alfanumericos na cadeia.\n", NaoAlfanumerico(palavra));

} // end method_04


/**
09.) Incluir um método (Exemplo0419) para:
- ler uma sequência de caracteres do teclado;
- mostrar todos os símbolos alfanuméricos (letras e dígitos) em uma cadeia de caracteres 
 separados por meio de uma função. 
Exemplo: sequência = (A1b2+C3d4)*E5f6
**/


int Alfanumerico (char* palavra) {

int x = 0;
int y = 0;
int tamanho = 0;
int contador = 0;

// repetir para cada letra 
tamanho = strlen (palavra);
// OBS: A cadeia de caracteres iniciam suas posições em 0

// Inicio teste variação 
for (y=0; y<tamanho; y = y+1 )
{
// Informar se o caractrere lido e' um nao alfanumerico
if ( '0' <= palavra [y] && palavra[y] <= '9' || 'a'<= palavra [y] && palavra[y] <= 'z' || 'A'<= palavra [y] && palavra[y] <= 'Z'  )
    {
        IO_printf ("\tValor Alfanumerico: ");
            
                                contador = contador + 1;       
                         IO_printf ("%d: [%c]\n", y, palavra [y]); 

    }
          //  printf("\n");
    // mostrar valor atual
} // fim for
            return (contador);
}


void method_09 (void) 
{
   char palavra [STR_SIZE];

    
// identificar 
IO_id ("Exemplo_Operações com Caracteres");
// ler do teclado 
IO_printf ("Entrar com uma palavra: \n");
scanf ("%s", palavra);

        printf ("\nAo todo temos %d caracteres alfanumericos na cadeia.\n", Alfanumerico(palavra));

} // end method_04



/**

10.) Incluir um método (Exemplo0420) para:
- ler certa quantidade de cadeias de caracteres do teclado, uma por vez;
- mostrar e contar a quantidade de símbolos alfanuméricos (letras e dígitos) em cada palavra, 
 por meio de uma função, e calcular o total acumulado de todas as palavras.
Exemplo: sequências = { (A1b2+C3d4)*E5f6, [P&&Q]||[R&&!S], (a<b&&b<c) }

**/



int Alfanumerico2 (char* palavra) {

int x = 0;
int y = 0;
int tamanho = 0;
int contador = 0;
int contador2 = 0;
int Total = 0;

// repetir para cada letra 
tamanho = strlen (palavra);
// OBS: A cadeia de caracteres iniciam suas posições em 0

// Inicio teste variação 
for (y=0; y<tamanho; y = y+1 )
{
// Informar se o caractrere lido e' um nao alfanumerico
if ( '0' <= palavra [y] && palavra[y] <= '9' || 'a'<= palavra [y] && palavra[y] <= 'z' || 'A'<= palavra [y] && palavra[y] <= 'Z'  )
    {
        IO_printf ("\tValor Alfanumerico: ");
            
                                contador = contador + 1;       
                         IO_printf ("%d: [%c]\n", y, palavra [y]); 

    } else {
                          contador2 = contador2 + 1; 
           }
            
          //  printf("\n");
    // mostrar valor atual
} // fim for
            Total = contador + contador2;
            printf ("Ao todo temos %d caracteres na cadeira", Total);
            return (contador);
}


void method_10 (void) 
{
   char palavra [STR_SIZE];

int n = 0;
int z = 0;

        n = IO_readint ("Digite a quantidade de cadeias a serem lidas: ");

while (z<n)
{    
// identificar 
IO_id ("Exemplo_Operações com Caracteres");
// ler do teclado 
IO_printf ("Entrar com uma palavra: \n");
scanf ("%s", palavra);

        printf ("\nAo todo temos %d caracteres alfanumericos na cadeia.\n", Alfanumerico2(palavra));

        z = z + 1;
}
                    printf ("\nAo todo temos %d cadeias\n", n);

} // end method_04

/*
_Tarefas extras_

E1.) Incluir um método (Exemplo04E1) para:
- ler certa quantidade de cadeias de caracteres do teclado;
- contar a quantidade de símbolos alfanuméricos, incluindo espaços em branco, em cada palavra, 
 e calcular o total de todas as palavras, por meio de uma função. 
 OBS.: Para a leitura incluir espaços em branco, usar IO_readln( ), ou gets( ), menos recomendado.
Exemplo: sequência = (A1b2 + C3d4) * E5f6
*/

  void Extra01 ( ) 
 {

  //char palavra[15];
  int y = 0;
  int tamanho = 0;   // Armazena tamanho da cadeia 
  int controle = 0; // Controle para validar número de cadeias total a serem lidas
  int contador = 0; // Conta numero de cadeias lidas
  int TotalAlfanumerico = 0; // Armazena quantidade caracteres alfanúmericos lidos 
  int TotalCadeia = 0;      // Armazena quantidade de caracteres total lidos em todas as cadeias informadas
  char palavra [100];   // Variável que armazena string lida [Tamanho suportado]

    /* Informar quantidade de cadeias de caracteres a serem lidas */
    printf ("\nQuantas cadeias de caracteres voce deseja utilizar durante sua validacao? \t");
    scanf ("%d", &controle);
 /* -------------------------------------- Inicio validação caracteres da cadeia -----------------------------------*/ 
  do{
        if (contador == 0 && y == 0) // Validação primeira cadeia de caracteres
        {
            printf ("\nDigite uma cadeia de no maximo 15 caracteres: \t");
            getchar ( );
            strcpy ( palavra, IO_readln ( "" ) );
            //gets(palavra);
            tamanho =  strlen(palavra);
        } else{
                  if (contador>0 && y==0) // Validação cadeias de caracteres subsequentes 
                {
                    printf ("\nPressione Enter para continuar...\n");
                    IO_flush  ( );
                    printf ("\nInforme a proxima cadeia de caracteres:\t \n");
                    strcpy ( palavra, IO_readln ( "" ) );
                    //gets(palavra);
                    tamanho =  strlen(palavra);
                } else {} // "Fazer nada"
              }
 
/* --------------------------------------- Autenticação dos tipos e quantidades -----------------------------------*/
        if (contador >= 0 && y == 0){
                    for (y=0; y<tamanho; y++) // Ciclo FOR para percorrer toda a cadeia informada
                {
                  /* Alfanuméricos -----------------------------------------------------------------------------------------------------------------*/  
                    if ('a' <= palavra[y] && palavra [y] <= 'z' || 'A' <= palavra[y] && palavra [y] <= 'Z' || '0' <= palavra[y] && palavra[y] <= '9' || ' ' == palavra[y])
                        {
                                printf ("\nValor alfanumerico: \t %c\n", palavra[y]);
                                TotalAlfanumerico = TotalAlfanumerico + 1;
                        } /* Não Alfanúmerico -> */ else {
                                  printf("\nCaractere nao alfanumerico: %c\n", palavra[y]);
                        }
                                    TotalCadeia = TotalCadeia + 1;
                }
                         y = 0; // reset valor indice
                         contador = contador + 1;
        } 

    } while (contador < controle);

            printf ("\nTotal caracteres lidos em todas as cadeias: %d\t", TotalCadeia);
            printf ("\nTotal caracteres alfanumericos lidos em todas as cadeias: %d\t\n", TotalAlfanumerico);

  
  }

/*
E2.) Incluir um método (Exemplo04E2) para:
- ler duas cadeias de caracteres do teclado;
- calcular qual das duas sequências possui a menor quantidade de dígitos,
 por meio de uma função. 
Exemplo: sequência = { A1b2, C3d4E5 }
*/

 void Extra02 ( ) 
 {

  char palavra[15];
  int y = 0;
  int j = 0;
  int tamanho = 0;
  int TamanhoPrimeiraCadeia = 0;
  int TamanhoSegundaCadeia = 0;
  int MaiorCadeia = 0;


    /* --------------Validação caracteres/quantidade cadeia_1---------------*/
        printf ("\nDigite uma cadeia de no maximo 15 caracteres: \t");
        scanf ("%s", &palavra);
        tamanho =  strlen(palavra);

             for (y=0; y<tamanho; y++)
        {
              printf ("\nCaractere atual: \t %c", palavra[y]);
              TamanhoPrimeiraCadeia = TamanhoPrimeiraCadeia + 1;
        } 
    // End Validação Primeira Cadeia

    /* --------------Validação caracteres/quantidade cadeia_2--------------*/

        printf ("\nDigite uma cadeia de no maximo 15 caracteres: \t");
        scanf ("%s", &palavra);
        tamanho =  strlen(palavra);
            
             for (j=0; j<tamanho; j++)
        {
             printf ("\nCaractere atual: \t %c", palavra[j]);
            TamanhoSegundaCadeia = TamanhoSegundaCadeia + 1;
        }
    // End Validação Segunda Cadeia

    /* Inicio verificação das diferença de tamanho entre as cadeias de caracteres */
        if (TamanhoPrimeiraCadeia>TamanhoSegundaCadeia)
        {
            printf ("\n A primeira cadeia e' maior do que a segunda.\n");
        } else {
                if (TamanhoPrimeiraCadeia<TamanhoSegundaCadeia)
                {
                printf ("\n A segunda cadeia e' maior do que a primeira.\n");
                } else {
                            if (TamanhoPrimeiraCadeia==TamanhoSegundaCadeia)
                            {
                                printf ("\nAs cadeias possuem o mesmo tamanho\n");
                            }
                }
               }
 } // END EXTRA02






int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXEMPLO0401 - Programa - v0.0" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - parar" );
 IO_println ( " 1 - Contador valores reais dentro e fora do intervalo" );
 IO_println ( " 2 - Contar e mostrar a quantidade de letras maiusculas maiores que 'J'." );
 IO_println ( " 3 - Mostrar a quantidade de letras maiusculas maiores que 'J' contadas por uma funcao definida para receber uma cadeia de caracteres como parametro " );
 IO_println ( " 4 - Mostrar as letras maiusculas maiores que 'J' separadas por uma funcao definida para receber uma cadeia de caracteres como parametro.  " );
 IO_println ( " 5 - Mostrar a quantidade de letras (tanto maiusculas, quanto minusculas) maiores que 'J' e 'j' contadas por uma funcao definida para receber uma cadeia de caracteres como parametro. " );
 IO_println ( " 6 - Mostrar as letras (tanto maiusculas, quanto minusculas) maiores que 'J' e 'j' separadas por uma funcao definida para receber uma cadeia de caracteres como parametro." );
 IO_println ( " 7 - Mostrar a quantidade de digitos pares em uma cadeia de caracteres contados por uma funcao definida para receber uma cadeia de caracteres como parametro." );
 IO_println ( " 8 - Mostrar todos os simbolos não alfanumericos (letras e digitos) em uma cadeia de caracteres separados por meio de uma funcao.  " );
 IO_println ( " 9 - Mostrar todos os simbolos alfanumericos (letras e digitos) em uma cadeia de caracteres separados por meio de uma funcao.  " );
 IO_println ( " 10- Mostrar e contar a quantidade de simbolos alfanumericos (letras e digitos) em cada palavra, por meio de uma funcao, e calcular o total acumulado de todas as palavras." );
 IO_println ( " 11- Extra01");
 IO_println ( " 12- Extra02");


 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 
 // testar valor
 switch ( x )
 {
 case 0:
 break;
 case 1:
 method_01 ( );
 break;
 case 2:
 method_02 ( );
 break;
 case 3:
 method_03 ( );
 break;
 case 4:
 method_04 ( );
 break;
 case 5:
 method_05 ( );
 break;
 case 6:
 method_06 ( );
 break;
 case 7:
 method_07 ( );
 break;
 case 8:
 method_08 ( ); 
 break;
 case 9:
 method_09 ( );
 break;
 case 10:
 method_10 ( );
 break;
 case 11:
 Extra01 ( );
 break;
 case 12:
 Extra02 ( );
 break;
 default:
 IO_pause ( "ERRO: Valor invalido." );
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )