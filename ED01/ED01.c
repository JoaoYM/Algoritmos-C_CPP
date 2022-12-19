/*
 AED1_ED01 - v0.0. - 04 / 09 / 2022
 Author: João Pedro Aguiar do Prado
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o ED01 ED01.c
 Windows: gcc -o ED01 ED01.c
 Para executar em terminal (janela de comandos):
 Linux : ./ED01
 Windows: ED01
*/


/**
 * 01.) Fazer um programa (Exemplo0111) para:
- definir e ler um valor inteiro do teclado;
- supor que esse valor represente o lado de um quadrado,
 calcular e mostrar um sexto da área do mesmo.
 DICA: Usar constantes reais em expressões que envolvam valores reais.
Exemplo: valor = 5
**/

// dependencias
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h> // para funcoes matemáticas: pow( ), sqrt( ), sin( ), cos( ) ...

void method01 ( ) {
  
int base = 0;
int altura = 0;
int area = 0;
float Fracao_Area = 0;


    printf ( "Programa - versao 0.0 - 2022\n" );
    printf ( "756491 - AED1\n" );
    printf ( "\n" );

     
    printf("Informe o valor da base do quadrado: ");
    scanf ("%d", &base);
    printf("Informe o valor da altura do quadrado: ");
    scanf ("%d", &altura);
                   area = (float) base*altura;
                   Fracao_Area = ((area*1)/6);
    printf ("\n O valor da area do quadrado e: %i metros quadrados, e o valor correspondente a 1/6 de sua area e igual a aproximadamente: %.2f metros quadrados", area, Fracao_Area );
      


return (0);
    
} // end int main 


/**
02.) Fazer um programa (Exemplo0112) para:
- definir e ler um valor inteiro do teclado;
- supor que esse valor represente o lado de um quadrado,
 calcular e mostrar a área e o perímetro de um quadrado com o dobro do tamanho do lado.
Exemplo: valor = 5
**/

void method02 ( ) {
  
int lado, base, altura = 0;
int areaQuadradox2 = 0;
int PerimetroQuadradoX2 = 0;


    printf ( "Programa - versao 0.0 - 2022\n" );
    printf ( "756491 - AED1\n" );
    printf ( "\n" );

     
    printf("Informe o valor do lado do quadrado: ");
    scanf ("%d", &lado);

                   base = altura = lado;
                   areaQuadradox2  = ((2*lado)*(2*lado));
                   PerimetroQuadradoX2 = (4*(2*lado));

    printf ("\n Altura do quadrado: %i m: \n ", altura );
    printf ("Base do quadrado: %i m\n", base);
    printf ("Sendo assim, a area e o perimetro de um quadrado com o triplo do tamanho do lado, sao respectivamente, %i metros quadrados e %i m ", areaQuadradox2, PerimetroQuadradoX2);
      
return (0);
    
} // end int main 


/**
03.) Fazer um programa (Exemplo0113) para:
- definir e ler dois valores inteiros do teclado;
- supor que esses dois valores representem lados de um retângulo,
 calcular e mostrar um quarto da área do mesmo.
 DICA: Usar constantes reais em expressões que envolvam valores reais.
Exemplo: valores = 3 e 5
**/


void method03 ( ) {
  
int  base, altura = 0;
int area = 0;
int Fracao_1quarto = 0;


    printf ( "Programa - versao 0.0 - 2022\n" );
    printf ( "756491 - AED1\n" );
    printf ( "\n" );

     
    printf("Informe o valor da altura do retangulo: ");
    scanf ("%d", &altura);
    printf("Informe o valor da base do retangulo: ");
    scanf ("%d", &base);
                   area = base*altura;
                   Fracao_1quarto = ((area*25)/100);
    printf ("\n O valor da area do retangulo e: %i metros quadrados, e o valor correspondente a 1/3 de sua area e igual a: %i metros quadrados", area, Fracao_1quarto );
      

return (0);
    
} // end int main 

/*
04.) Fazer um programa (Exemplo0114) para:
- definir e ler dois valores inteiros do teclado;
- supor que esses dois valores representem lados de um retângulo,
 calcular e mostrar a área e o perímetro de um retângulo com a metade do tamanho dos lados.
Exemplo: valores = 3 e 5
*/

void method04 ( ) {
  
int base, altura = 0;
int Metade_AreaQuadrado = 0;
int Metade_PerimetroQuadrado = 0;


    printf ( "Programa - versao 0.0 - 2022\n" );
    printf ( "756491 - AED1\n" );
    printf ( "\n" );

     
    printf("Informe a altura do retangulo: ");
    scanf ("%d", &altura);
    printf("Informe a base do retangulo: ");
    scanf ("%d", &base);
                   Metade_AreaQuadrado  = ((altura/2)*(base/2));
                   Metade_PerimetroQuadrado = (   (  2*( altura/2) ) + (  2*(base/2) )   );

    printf ("\n Altura do quadrado: %i: \n ", altura );
    printf ("Base do quadrado: %i\n", base);
    printf ("Sendo assim, a area e o perimetro de um retangulo com a metade do tamanho do lado, sao respectivamente, %i metros quadrados e %i m", Metade_AreaQuadrado, Metade_PerimetroQuadrado);
      
return (0);
    
} // end int main 

/*
05.) Fazer um programa (Exemplo0115) para:
- definir e ler dois valores reais do teclado;
- supor que esses dois valores representem base e altura de um triângulo,
 calcular e mostrar a área de um triângulo com um terço da altura do mesmo.
 DICA: Usar constantes reais em expressões que envolvam valores reais.
Exemplo: valores = 3 e 5
*/



void method05 () {
  
int base, altura = 0;
float FracaoAltura = 0;
float areaTriangulo = 0;


    printf ( "Programa - versao 0.0 - 2022\n" );
    printf ( "756491 - AED1\n" );
    printf ( "\n" );

     
    printf("Informe o valor da altura do triangulo: ");
    scanf ("%d", &altura);
    printf("Informe o valor da base do triangulo: ");
    scanf ("%d", &base);
                   
                   FracaoAltura = (float)((altura*1)/3);
                   areaTriangulo = ((base * FracaoAltura)/2);

    printf ("\n Altura do triangulo: %i: \n ", altura );
    printf ("Base do triangulo: %i\n", base);
    printf ("Sendo assim, a area de um triangulo com 1/5 da altura do mesmo, e de: %i metros quadrados", areaTriangulo);
      



return (0);
    
} // end int main 

/*
06.) Fazer um programa (Exemplo0116) para:
- definir e ler um valor real do teclado;
- supor que esse valor represente o lado de um triângulo equilátero,
 calcular e mostrar a altura, área e o perímetro do triângulo com o dobro do lado.
 DICA: Usar constantes reais em expressões que envolvam valores reais.
Exemplo: valor = 5.0
*/


void method06 ( ) {
  
double lado = 0.0;
float areaTriangulo = 0.0;
float PerimetroTriangulo = 0.0;


    printf ( "Programa - versao 0.0 - 2022\n" );
    printf ( "756491 - AED1\n" );
    printf ( "\n" );

     
    printf("Informe o valor do lado do triangulo: ");
    scanf ("%lf", &lado);
    
                   PerimetroTriangulo = ((lado*2)*3);
                   areaTriangulo = ((lado * lado)/2);

    printf ("\n Altura do triangulo: %.2lf \n ", lado );
    printf ("Base do triangulo: %.2lf\n", lado);
    printf ("Sendo assim, a area do triangulo, e de: %.2lf metros quadrados \n", areaTriangulo);
    printf ("E o perimetro do triangulo, e de: %.2lf m", PerimetroTriangulo);
      



return (0);
    
} // end int main 

/*
07.) Fazer um programa (Exemplo0117) para:
- definir e ler um valor real do teclado;
- supor que esse valor represente a medida de lados de um cubo,
 calcular e mostrar o volume do sólido com um quarto da medida do lado.
 DICA: Usar constantes reais em expressões que envolvam valores reais.
Exemplo: valor = 5.0
*/

void method07 ( ) {
  
double lado = 0.0;
double FracaoVolumeCubo = 0.0;
double VolumeCubo = 0.0;


    printf ( "Programa - versao 0.0 - 2022\n" );
    printf ( "756491 - AED1\n" );
    printf ( "\n" );

     
    printf("Informe o valor do lado do cubo: ");
    scanf ("%lf", &lado);
                   FracaoVolumeCubo = ((lado * 25)/100);
                      
                   VolumeCubo = FracaoVolumeCubo * FracaoVolumeCubo * FracaoVolumeCubo;

    printf ("\n Medida lados: %.2lf \n ", lado );
    printf ("Sendo assim, o volume do cubo com um sexto da medida do lado, e de: %.2lf centimetros cubicos\n", VolumeCubo);
      



return (0);
    
} // end int main 


/*
08.) Fazer um programa (Exemplo0118) para:
- definir e ler três valores reais do teclado;
- supor que esses valores correspondam ao comprimento, à largura e à altura
 de um paralelepípedo, respectivamente,
- calcular e mostrar o volume do sólido com sete vezes esses valores.
Exemplo: valores = 3.0, 4.0 e 5.0
*/

void method08 ( ) {
  
double altura, comprimento, largura = 0.0;
double alturaX7, comprimentoX7, larguraX7 = 0.0;
double VolumeParalelepipedo = 0.0;


    printf ( "Programa - versao 0.0 - 2022\n" );
    printf ( "756491 - AED1\n" );
    printf ( "\n" );

     
    printf("Informe o valor da altura do paralelepipedo: \n ");
    scanf ("%lf", &altura);
    printf("Informe o valor do comprimento do paralelepipedo: \n");
    scanf ("%lf", &largura);
    printf("Informe o valor da largura do paralelepipedo: \n ");
    scanf ("%lf", &comprimento);

    
    

                   
              // Multiplicação dos lados x6        
                   alturaX7 = altura * 7;
                   larguraX7 = largura * 7;
                   comprimentoX7 = comprimento * 7;
             // end Multiplicação 
                   VolumeParalelepipedo = alturaX7 * larguraX7 * comprimentoX7;

    printf ("\n Medida altura: %.2lf \n ", altura );
    printf ("\n Medida largura: %.2lf \n ", largura );
    printf ("\n Medida comprimento: %.2lf \n ", comprimento );
    printf ("\n Sendo assim, o volume do paralelepipedo com seis vezes as medidas previamente informadas, e de: %.2lf centimetros cubicos\n", VolumeParalelepipedo);
      



return (0);
    
} // end int main 




/**
 * Funcao principal
 * @return codigo de encerramento
 */
int main()
{
    // definir dado
    int x = 0; // definir variavel com valor inicial

    // repetir até desejar parar
    do
    {
        // identificar
        IO_println("ED01 - Programa");

        // ler do teclado
        IO_println("\nOpcoes:");
        IO_println("\nDigite 0 - parar");
        IO_println("Digite 1 - Exemplo0111");
        IO_println("Digite 2 - Exemplo0112");
        IO_println("Digite 3 - Exemplo0113");
        IO_println("Digite 4 - Exemplo0114");
        IO_println("Digite 5 - Exemplo0115");
        IO_println("Digite 6 - Exemplo0116");
        IO_println("Digite 7 - Exemplo0117");
        IO_println("Digite 8 - Exemplo0118");

        x = IO_readint("Escolha com uma opcao: ");

        // testar valor
        switch (x)
        {
        case 0:
            // method00();
            break;
        case 1:
            method01();
            break;
        case 2:
            method02();
            break;
        case 3:
            method03();
            break;
        case 4:
            method04();
            break;
        case 5:
            method05();
            break;
        case 6:
            method06();
            break;
        case 7:
            method07();
            break;
        case 8:
            method08();
            break;
        default:
            IO_println("ERRO: Valor invalido.");
        } // end switch
    } while (x != 0);

    // encerrar
    IO_pause("Aperte ENTER para terminar");
    return (0);
}