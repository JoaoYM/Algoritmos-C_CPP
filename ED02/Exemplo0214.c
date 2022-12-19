/*
 Exemplo0211 - v0.0. - 03 / 04 / 2022
 Author: Joao Pedro Aguiar do Prado
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0214 exemplo0214.c
 Windows: gcc -o exemplo0214 exemplo0214.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0214
 Windows: exemplo0214
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

04.) Incluir um procedimento (Exemplo0214) para:
- ler um valor inteiro do teclado e 
- dizer se pertence ao intervalo fechado entre [25:40].
Exemplos: { 5, 15, 30, 45, 60 }


**/

int main ( )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "Exemplo0211 - Joao Pedro Aguiar - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro >= 25 e <= 40: " );
// testar valor
 if ( x >= 25 && x <= 40  )
 {
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( "  pertence ao intervalo fechado entre (25:40)  " );

 } else
 {
     if ( !( x >= 25 && x <= 40  ) )
          {
 IO_printf ( "%s (%d)", "O numero", x );
 IO_printf ( " nao pertence ao intervalo fechado entre (25:40) " );
        }  // fim IF Else


} // fim main( )

        
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );

}

