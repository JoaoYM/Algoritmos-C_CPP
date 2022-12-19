/*
 AED1_ED01 - v0.0. - 04 / 09 / 2022
 Author: João Pedro Aguiar do Prado
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o Exemplo0120 Exemplo0120.c
 Windows: gcc -o Exemplo0120 Exemplo0120.c
 Para executar em terminal (janela de comandos):
 Linux : ./Exemplo0120
 Windows: Exemplo0120
*/



// dependencias
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h> // para funcoes matemáticas: pow( ), sqrt( ), sin( ), cos( ) ...



/*
10.) Fazer um programa (Exemplo0120) para:
- definir e ler um valor real do teclado;
- supor que esse valor represente o raio de uma esfera,
 calcular e mostrar o volume de uma esfera com cinco oitavos do raio.
 DICA: Usar constantes reais em expressões que envolvam valores reais.
Exemplo: valor = 5.0
*/


void method10 (int argc, char* argv[]){
  double raio = 0.0;
  double cinco_oitavos_raio = 0.0;
  double cinco_oitavos_volume = 0.0;
  double PI = M_PI;

	printf("%s\n", "Exemplo0120 - Programa v0.0"); // %s é alocamento de espaço para String
	printf("\n");

  printf("\n%s","raio = ");
  scanf("%lf", &raio);

  cinco_oitavos_raio = (raio*5)/8;
  cinco_oitavos_volume = (4*PI*pow(cinco_oitavos_raio, 3))/3;

  printf("\nO volume da esfera com cinco oitavos do raio inicial [%lf] e: %lf\n", raio, cinco_oitavos_volume);

  // encerramento do código abaixo  
	printf("%s\n\n", "Aperte ENTER para finalizar.");
	fflush(stdin); // flush = descarga // LIMPAR OS DADOS ARMAZENADOS
	getchar(); // continuar apenas quando apertar ENTER
	return 0;
}