/* PUC-Minas - Ciência da Computação
AED1 – Guia 01
Tema: Introdução à programação
Atividade: Montagem de programas - Karel

 Guia0211 - v0.0. - 21 / 08 / 2022
 Author: João Pedro Aguiar do Prado
 Para compilar em uma janela de comandos (terminal):
 
 No Linux : g++ -o Guia0215 ./Guia0215.cpp
 No Windows: g++ -o Guia0215.exe Guia0215.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0215
 No Windows: Guia0215
*/
// lista de dependencias
#include "karel.hpp" 
#include "stdio.h"
#include "io.hpp"


// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/



void decorateWorld ( const char* fileName )
{
// colocar paredes no mundo
 world->set ( 3, 2, HWALL ); // horizontal
 world->set ( 4, 2, HWALL ); // horizontal
 world->set ( 5, 2, HWALL ); // horizontal

 world->set ( 3, 8, HWALL ); // horizontal
 world->set ( 5, 8, HWALL ); // horizontal


    
 world->set ( 2, 3, VWALL ); // vertical
 world->set ( 2, 4, VWALL ); // vertical
 world->set ( 2, 5, VWALL ); // vertical
 world->set ( 2, 6, VWALL ); // vertical
 world->set ( 2, 7, VWALL ); // vertical
 world->set ( 2, 8, VWALL ); // vertical

 
 world->set ( 3, 3, VWALL ); // vertical
 world->set ( 3, 4, VWALL ); // vertical
 world->set ( 3, 5, VWALL ); // vertical
 world->set ( 3, 6, VWALL ); // vertical
 world->set ( 3, 7, VWALL ); // vertical
 
  
 world->set ( 4, 3, VWALL ); // vertical
 world->set ( 4, 4, VWALL ); // vertical
 world->set ( 4, 5, VWALL ); // vertical
 world->set ( 4, 6, VWALL ); // vertical
 world->set ( 4, 7, VWALL ); // vertical

 world->set ( 5, 3, VWALL ); // vertical
 world->set ( 5, 4, VWALL ); // vertical
 world->set ( 5, 5, VWALL ); // vertical
 world->set ( 5, 6, VWALL ); // vertical
 world->set ( 5, 7, VWALL ); // vertical
 world->set ( 5, 8, VWALL ); // vertical

 



// colocar quatro marcadores no mundo

 world->set ( 3, 3, BEEPER );

 world->set ( 4, 4, BEEPER );
 world->set ( 4, 4, BEEPER );
 world->set ( 4, 3, BEEPER );

 world->set ( 5, 3, BEEPER );
 world->set ( 5, 4, BEEPER );
 world->set ( 5, 4, BEEPER );
 world->set ( 5, 5, BEEPER );
 world->set ( 5, 5, BEEPER );
 world->set ( 5, 5, BEEPER );



// salvar a configuracao atual do mundo
 world->save( fileName );
} // decorateWorld ( )
/**
 Classe para definir robo particular (MyRobot),
 a partir do modelo generico (Robot)
 Nota: Todas as definicoes irao valer para qualquer outro robo
 criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
 public:


 void execute( int option )
 {
 // executar a opcao de comando
 switch ( option )
 {
 case 0: // terminar
 // nao fazer nada
 break;
 case 1: // virar para a esquerda
 if ( leftIsClear ( ) )
 {
 turnLeft( );
 } // end if
 break;
 case 2: // virar para o sul
 while ( ! facingSouth( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 3: // virar para a direita
 if ( rightIsClear ( ) )
 {
 turnRight( );
 } // end if
 break;
 case 4: // virar para o oeste
 while ( ! facingWest( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 5: // mover
 if ( frontIsClear ( ) )
 {
 move( );
 } // end if
 break;
 case 6: // virar para o leste
 while ( ! facingEast( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 7: // pegar marcador
 if ( nextToABeeper( ) )
 {
 pickBeeper( );
 } // end if
 break;
 case 8: // virar para o norte
 while ( ! facingNorth( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 9: // colocar marcador
 if ( beepersInBag( ) )
 {
 putBeeper( );
 } // end if
 break;
 default:// nenhuma das alternativas anteriores
 // comando invalido
 show_Error ( "ERROR: Invalid command." );
 } // end switch
 } // end execute( )




 /**
 recordActions - Metodo para mover o robot interativamente
 e guardar a descricao da tarefa em arquivo.
 @param filename
*/
void recordActions ( const char *filename )
{
 int x, y;
 x = xAvenue( ); // obter posicao atual (avenue)
 y = yStreet( ); // obter posicao atual ( street )
 
 // definir dados
 int action;
 // definir arquivo onde gravar comandos
 std::ofstream archive ( filename );

 // repetir enquanto o comando
 // for diferente de zero
 do
 {
 // ler opcao
 action = IO_readint ( "Command? " );
 // testar se opcao valida
 if ( action >= 0  && action <= 9 )
 {
 // executar comando
 execute ( action );
 // guardar o comando em arquivo
  archive << x << action << std::endl; "\n";
  archive << y << action << std::endl; "\n";
  

 } // end if
 }
 while ( action != 0 );
 // fechar o arquivo
 // INDISPENSAVEL para a gravacao
 archive.close ( );
} // end recordActions ( )


 
 /**
 turnRight - Procedimento para virar 'a direita.
 */
 void turnRight ( )
 {
 // testar se o robo esta' ativo
 if ( checkStatus ( ) )
 
 {
 // o agente que executar esse metodo
 // devera' virar tres vezes 'a esquerda
 turnLeft ( );
 turnLeft ( );
 turnLeft ( );
 } // end if
 } // end turnRight ( )

  void stepUpRight ( )
 {
      turnLeft( );
      move( );
      turnRight( );
      move( ); 

 } // end stepUpRight ( )

void stepDownRight ( ) 
{
     move( );
     turnRight( );
     move( );
     turnLeft( );
     

}

void stepUpLeft ( )

{
    turnLeft( );
    move( );
    turnRight( );
    move( );

}

void stepDownLeft ( )

{
    move( );
    turnLeft( );
    move ( );
    turnRight( );

}


void MoveLeft ( ) {
 if ( leftIsClear( ) )
 {
 turnLeft( );
 move( );
 } // fim se


}

void MoveRight ( ) {
 if ( rightIsClear( ) )
 {
 turnRight( );
 move( );
 } // fim se

}

void turnback ( ) {
    turnLeft ( );
    turnLeft ( );

}


void dropTheBeeper( ) {
if ( areYouHere(1,7) && beepersInBag( ) )
 {
    putBeeper( );
    putBeeper( );
    putBeeper( );
    putBeeper( );
    putBeeper( );
    putBeeper( );
    putBeeper( );
    putBeeper( );
    putBeeper( );
    putBeeper( );
 }
 


 } // fim se

  void playActions(const char *fileName)
    {
        // definir dados
        int action;
        // definir arquivos de onde ler dados
        std::ifstream archive(fileName);
        // repetir enquanto houver dados
        archive >> action;     // tentar ler a primeira linha
        while (!archive.eof()) // testar se nao encontrado o fim
        {
            // mostrar mais um comando
            IO_print(IO_toString(action));
            delay(stepDelay);
            // executar mais um comando
            execute(action);
            // tentar ler a proxima linha
            archive >> action; // tentar ler a próxima linha
        }                      // end for
        // fechar o arquivo
        // RECOMENDAVEL para a leitura
        archive.close();
    } // end playActions ()

}; // end class MyRobot
// --------------------------- acao principal
/**
 Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
// definir o contexto
// criar o ambiente e decorar com objetos
// OBS.: executar pelo menos uma vez,
// antes de qualquer outra coisa
// (depois de criado, podera' ser comentado)
 world->create ( "" ); // criar o mundo
 decorateWorld ( "Guia0211.txt" );
 world->show ( );
 set_Speed ( 1 ); // definir velocidade padrao
// criar robo
 MyRobot *robot = new MyRobot( );
 //Variáveis 
 
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
 robot->create ( 1, 1, EAST, 0, "Karel" );
// executar tarefa

/**
 
robot->move( ); // primeira acao: andar para frente
robot->MoveLeft( );


robot->move( ); 
robot->move( ); 
robot->move( ); 
robot->move( ); 
robot->move( ); 
robot->move( ); 
robot->move( ); 



robot->MoveRight( );
robot->move( );

robot->MoveRight( );
robot->MoveRight( );
robot->MoveLeft( );

robot->move( ); 
robot->move( ); 
robot->move( ); 
robot->move( ); 

**/


// robot->recordActions ( "Tarefa0215.txt" ); 
 
//
 robot-> playActions("Tarefa0215.txt");

 world->set ( 3, 3, BEEPER );

 world->set ( 4, 4, BEEPER );
 world->set ( 4, 4, BEEPER );
 world->set ( 4, 3, BEEPER );

 world->set ( 5, 3, BEEPER );
 world->set ( 5, 4, BEEPER );
 world->set ( 5, 4, BEEPER );
 world->set ( 5, 5, BEEPER );
 world->set ( 5, 5, BEEPER );
 world->set ( 5, 5, BEEPER ); 


 robot->turnOff ( ); // desligar-se

 
// encerrar operacoes no ambiente
 world->close ( );
// encerrar programa
 getchar ( );
 return ( 0 );
} // end main ( )
// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( ) identificacao de programa
*/
/** 02.) Compilar o programa.
Se houver erros, identificar individualmente a referência para a linha onde ocorrem.
Consultar atentamente o modelo acima na linha onde ocorreu o erro (e também linhas próximas),
verificar os nomes de dados e de métodos, cuidar da pontuação, 
editar as modificações necessárias.
Recomenda-se destacar os conteúdos dos blocos e manter o alinhamento de comandos
a fim de facilitar a identificação e a leituras das partes.
Compilar novamente e proceder assim até que todos os erros tenham sido resolvidos.
Se não houver erros, seguir para o próximo passo.
OBS.: O ajuste de velocidade deverá ser feito para compatibilizar-se com o sistema operacional.
Recomenda-se, entretanto, não usar valores que acelerem demais o processo.
DICA: Se precisar de ajuda sobre como proceder a compilação,
consultar os vídeos com as demonstrações sobre algumas formas para fazê-lo.
SUGESTÃO: Para se acostumar ao tratamento de erros,
registrar a mensagem de erro (como comentário)
e o que foi feito para resolvê-lo.
**/


/** 03.) Executar o programa.
Observar as saídas.
Registrar os resultados.
// ---------------------------------------------- testes
//
// Versao Teste
// 0.1 01. ( OK ) teste inicial
//
04.) Copiar a versão atual do programa para outra (nova) – Guia0102.cpp.
**/