/*
 Exemplo0211 - v0.0. - 03 / 04 / 2022
 Author: Joao Pedro Aguiar do Prado
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0219 exemplo0219.c
 Windows: gcc -o exemplo0219 exemplo0219.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0219
 Windows: exemplo0219
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

09.) Incluir um procedimento (Exemplo0219) para:
- ler três valores reais do teclado e 
 dizer se o primeiro está entre os outros dois quando esses forem diferentes entre si.
 OBS.: Notar a ordem dos testes.
Exemplos: { (5, 15, 18), (30, 45, 21), (60, 72, 60), (98, 89, 89) }

**/

int main ( )
{
// definir dado
 float  x = 0.0; // definir variavel com valor inicial
 float  y = 0.0;
 float  z = 0.0;

// identificar
 IO_id ( "Exemplo0218 - Joao Pedro Aguiar - v0.0" );
// ler do teclado
 x = IO_readint ( "Digite o valor de x: " );
 y = IO_readint ( "Digite o valor de y: " );
 z = IO_readint ( "Digite o valor de z: " );

// testar valor
 if ( x == y && y == z )
 {
 IO_printf ( "%s (%.2f, %.2f, %.2f)", "O valor de x e igual ao valor de y que e igual ao valor de z, sendo eles respectivamente: ", y, x, z );

 } else {
     if ( x > y  &&  x < z ) 
// x entre y e z
     {
          IO_printf ( "%s (%.2f, %.2f, %.2f)", "O valor de x esta entre os valores de y e z, sendo essa relacao expressada por: ", y, x, z );
     }else {
     if ( x < y  &&  x > z ) 
// x entre y e z
     {
          IO_printf ( "%s (%.2f, %.2f, %.2f)", "O valor de x esta entre os valores de z e y, sendo essa relacao expressada por: ", z, x, y );
     }else {

          IO_printf ( "%s (%.2f, %.2f, %.2f)", "O valor de x nao esta entre o intervalo aberto (y:z), sendo os valores de x, y, z respectivamente : ", x, y, z );
       
     }
 }              // fim IF Else

 }
// encerrar
IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
 } 

 

