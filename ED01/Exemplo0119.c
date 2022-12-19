/*
 AED1_ED01 - v0.0. - 04 / 09 / 2022
 Author: João Pedro Aguiar do Prado
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o Exemplo0119 Exemplo0119.c
 Windows: gcc -o Exemplo0119 Exemplo0119.c
 Para executar em terminal (janela de comandos):
 Linux : ./Exemplo0119
 Windows: Exemplo0119
*/

// dependencias
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h> // para funcoes matemáticas: pow( ), sqrt( ), sin( ), cos( ) ...



/*
09.) Fazer um programa (Exemplo0119) para:
- definir e ler um valor real do teclado;
- supor que esse valor represente o raio de um círculo,
 calcular e mostrar a área de um círculo com um quarto do raio.
 DICA: Na biblioteca <math.h> há definição da constante equivalente a PI (M_PI).
Exemplo: valor = 5.0
*/

void method09 (int argc, char* argv[]){
  double raio = 0.0;
  double quarto_raio = 0.0;
  double quarto_area = 0.0;
  double PI = M_PI;

  printf("%s\n", "Exemplo0119 - Programa v0.0"); // %s é alocamento de espaço para String
  printf("\n");

  printf("\n%s","raio = ");
  scanf("%lf", &raio);

  quarto_raio = (raio/4);
  quarto_area = (PI*pow(quarto_raio, 2));

  printf("\nA area do circulo com o quarto do raio inicial [%lf] e: %lf\n", raio, quarto_area);

  // encerramento do código abaixo  
	printf("%s\n\n", "Aperte ENTER para finalizar.");
	fflush(stdin); // flush = descarga // LIMPAR OS DADOS ARMAZENADOS
	getchar(); // continuar apenas quando apertar ENTER
	return 0;
}