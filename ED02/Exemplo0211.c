/*
 Exemplo0211 - v0.0. - 03 / 04 / 2022
 Author: Joao Pedro Aguiar do Prado
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0211 exemplo0211.c
 Windows: gcc -o exemplo0211 exemplo0211.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0211
 Windows: exemplo0211
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
 01.) Incluir um procedimento (Exemplo0211) para:
- ler um valor inteiro do teclado e 
- dizer se é par ou ímpar.
 DICA: Considerar o zero como par.
 Exemplos: { -6, -3, 0, 3, 6, 9 }

**/

int main ( )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "Exemplo0211 - Joao Pedro Aguiar - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
 if ( x%2 == 0 )
 {
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( "   e par" );

 } else
 {
    if (  !(x%2 == 0 )){
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( "   e impar" );

                       };
 } // fim IF Else
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
