/*
 Exemplo0211 - v0.0. - 03 / 04 / 2022
 Author: Joao Pedro Aguiar do Prado
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0218 exemplo0218.c
 Windows: gcc -o exemplo0218 exemplo0218.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0218
 Windows: exemplo0218
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

08.) Incluir um procedimento (Exemplo0218) para:
- ler dois valores reais do teclado e 
 dizer se o segundo é menor, igual ou maior que o primeiro.
Exemplos: { (5, 15), (30, 30), (98, 89) }

**/

int main ( )
{
// definir dado
 float  x = 0.0; // definir variavel com valor inicial
 float  y = 0.0;
// identificar
 IO_id ( "Exemplo0218 - Joao Pedro Aguiar - v0.0" );
// ler do teclado
 x = IO_readint ( "Digite o valor de x: " );
 y = IO_readint ( "Digite o valor de y: " );
// testar valor
 if ( y == x )
 {
 IO_printf ( "%s (%.2f, %.2f)", "O valor de y e igual ao valor de x, sendo eles respectivamente: ", y, x );

 } else {
     if ( y < x) 

     {
          IO_printf ( "%s (%.2f, %.2f)", "O valor de y e inferior ao valor de x, sendo eles respectivamente: ", y, x );
     }else {
         if (y > x)

          IO_printf ( "%s (%.2f, %.2f)", "O valor de y e superior ao valor de x, sendo eles respectivamente: ", y, x );
       
     }
 }              // fim IF Else

// encerrar
IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
 } 

 

