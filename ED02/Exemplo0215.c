/*
 Exemplo0211 - v0.0. - 03 / 04 / 2022
 Author: Joao Pedro Aguiar do Prado
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0215 exemplo0215.c
 Windows: gcc -o exemplo0215 exemplo0215.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0215
 Windows: exemplo0215
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

05.) Incluir um procedimento (Exemplo0215) para:
- ler um valor inteiro do teclado e 
- dizer se pertence aos intervalos fechados [15:30] ou [25:40], ou a apenas a um deles.
Exemplos: { 5, 15, 30, 45, 60, 75 }

**/

int main ( )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "Exemplo0211 - Joao Pedro Aguiar - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro >= 15 e <= 30 ou >=25 e <=40: " );
// testar valor
 if ( (x >= 15 && x <= 30) && (x >= 25 && x <=40) )
 {
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( "  pertence a ambos os intervalos fechados entre (15:30) e entre [25:40] " );

 }  else
 {
      if ( x >= 15 && x <= 30  )
    {
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( "  pertence ao intervalo fechado entre (15:30)  " );
   

    }  else
     {
      if ( x >= 25 && x <= 40  )
       {
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( "  pertence ao intervalo fechado entre (25:40)  " );
       }
      else
        {
      
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( "  nao pertence a nenhum dos intervalos fechados previamente estabelecidos  " );
         
        }
     }

 }

// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );

}// fim main( )

