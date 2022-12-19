/*
 Exemplo0211 - v0.0. - 03 / 04 / 2022
 Author: Joao Pedro Aguiar do Prado
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0212 exemplo0212.c
 Windows: gcc -o exemplo0212 exemplo0212.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0212
 Windows: exemplo0212
*/
// dependencias
#include "io.h"
#include <stdio.h>
#include <stdlib.h> // para definicoes proprias
/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/

/**

02.) Incluir um procedimento (Exemplo0212) para:
- ler um valor inteiro do teclado e 
- dizer se é par e menor que -30, ou ímpar e maior que 30.
Exemplos: { -60, -33, 0, 13, 26, 39 }

**/

int main ( )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "Exemplo0211 - Joao Pedro Aguiar - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro maior que -31 e menor que 30: " );
// testar valor
 if ( x < -30 && x%2 == 0  )
 {
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( "   e par e menor do que -30" );

 } else
 {
     if ( x > 30 && x%2 != 0 )
          {
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( "   e impar e maior do que 30" );
        }
        else 
       {
     if ( x > -30 && x%2 != 0 )
          {
 IO_printf ( "O valor inserido nao e valido");

                       };
       } 
 } 

 // fim IF Else

// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );

} // fim main( )
