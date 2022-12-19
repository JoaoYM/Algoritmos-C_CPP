/*
 Exemplo0211 - v0.0. - 03 / 04 / 2022
 Author: Joao Pedro Aguiar do Prado
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0216 exemplo0216.c
 Windows: gcc -o exemplo0216 exemplo0216.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0216
 Windows: exemplo0216
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

06.) Incluir um procedimento (Exemplo0216) para:
- ler dois valores inteiros do teclado e 
 dizer se o primeiro é par e o segundo é ímpar.
Exemplos: { (5, 15), (30, 45), (60, 72), (98, 89) }

**/

int main ( )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
 int x2 = 0;
// identificar
 IO_id ( "Exemplo0216 - Joao Pedro Aguiar - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro: " );
 x2 = IO_readint ( "Entrar com o segundo valor inteiro: " );

// testar valor
 if ( x%2 == 0 )
 {
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( "   e par" );

 } else
 {
    if (  !(x%2 == 0 )){
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( "   e impar\n" );

                       } 
 }  // fim IF Else

 if ( x2%2 == 0 )
 {
 IO_printf ( "%s (%d)", "O numero", x2 );
 IO_printf ( "   e par\n" );

 } else
 {
    if (  !(x2%2 == 0 )){
 IO_printf ( "%s (%d)", "\nO numero", x2 );
 IO_printf ( "   e impar" );

                       } 
 }  // fim IF Else
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
