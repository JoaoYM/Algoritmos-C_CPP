/* PUC-Minas - Ciência da Computação
AED1 – Guia 01
Tema: Introdução à programação
Atividade: Montagem de programas - Karel

 Guia0211 - v0.0. - 21 / 08 / 2022
 Author: João Pedro Aguiar do Prado
 Para compilar em uma janela de comandos (terminal):
 
 No Linux : g++ -o Guia0212 ./Guia0212.cpp
 No Windows: g++ -o Guia0212.exe Guia0212.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0212
 No Windows: Guia0212
*/
// lista de dependencias
#include "karel.hpp" 
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar paredes no mundo
 world->set ( 3, 1, HWALL ); // horizontal
 world->set ( 4, 1, HWALL ); // horizontal
 world->set ( 3, 4, HWALL ); // horizontal
 world->set ( 4, 4, HWALL ); // horizontal
 world->set ( 3, 5, HWALL ); // horizontal
 world->set ( 4, 5, HWALL ); // horizontal
 world->set ( 3, 8, HWALL ); // horizontal
 world->set ( 4, 8, HWALL ); // horizontal


 world->set ( 5, 6, HWALL ); // horizontal
 world->set ( 5, 3, HWALL ); // horizontal


 world->set ( 6, 1, HWALL ); // horizontal
 world->set ( 7, 1, HWALL ); // horizontal
 world->set ( 6, 4, HWALL ); // horizontal
 world->set ( 7, 4, HWALL ); // horizontal
 world->set ( 6, 5, HWALL ); // horizontal
 world->set ( 7, 5, HWALL ); // horizontal
 world->set ( 6, 8, HWALL ); // horizontal
 world->set ( 7, 8, HWALL ); // horizontal

    
 world->set ( 4, 7, VWALL ); // vertical
 world->set ( 4, 5, VWALL ); // vertical
 world->set ( 5, 5, VWALL ); // vertical
 world->set ( 4, 8, VWALL ); // vertical
 world->set ( 5, 7, VWALL ); // vertical
 world->set ( 5, 8, VWALL ); // vertical

 world->set ( 4, 2, VWALL ); // vertical
 world->set ( 4, 3, VWALL ); // vertical
 world->set ( 5, 2, VWALL ); // vertical
 world->set ( 5, 3, VWALL ); // vertical

 world->set ( 2, 2, VWALL ); // vertical
 world->set ( 2, 3, VWALL ); // vertical
 world->set ( 2, 4, VWALL ); // vertical
 world->set ( 2, 6, VWALL ); // vertical
 world->set ( 2, 7, VWALL ); // vertical
 world->set ( 2, 8, VWALL ); // vertical

 world->set ( 7, 2, VWALL ); // vertical
 world->set ( 7, 3, VWALL ); // vertical
 world->set ( 7, 4, VWALL ); // vertical
 world->set ( 7, 6, VWALL ); // vertical
 world->set ( 7, 7, VWALL ); // vertical
 world->set ( 7, 8, VWALL ); // vertical



// colocar quatro marcadores no mundo
 world->set ( 5, 3, BEEPER );
 world->set ( 4, 5, BEEPER );  
 world->set ( 5, 7, BEEPER );
 world->set ( 6, 5, BEEPER );

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


void pick ( ) {
    
    if ( nextToABeeper( ) )
 {   
 pickBeeper( );
 } // fim se

}

void turnback ( ) {
    turnLeft ( );
    turnLeft ( );

}

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
 decorateWorld ( "Guia0212.txt" );
 world->show ( );
 set_Speed ( 1 ); // definir velocidade padrao
// criar robo
 MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
 robot->create ( 1, 1, EAST, 0, "Karel" );
// executar tarefa
 robot->move( ); // primeira acao: andar para frente
 robot->move( ); 
 robot->move( ); 
 robot->move( ); 



 //Fim do movimento "stepUpRight" 

//Preparação para descida, posiciona o robô para início movimento "robot->stepDownRight"


 robot->MoveLeft( );
 robot->move( );
 robot->pick( );

 robot->turnback( );
 robot->move( );
 robot->move( );

 robot->turnRight( );
 robot->move( );
 robot->move( );
 robot->move( ); 

 robot->MoveRight( );
 robot->move( );
 robot->move( );
 robot->move( ); 

 robot->MoveRight( );
 robot->move( );
 robot->pick( );


 robot->turnback( );
 robot->move( );
 robot->move( );

 robot->MoveRight( );
 robot->move( );
 robot->move( );
 robot->move( );

 robot->MoveRight( );
 robot->move( );
 robot->move( );


 robot->MoveRight( );
 robot->move( );
 robot->pick( );

 robot->turnback( );
 robot->move( );
 robot->move( );

 robot->MoveRight( );
 robot->move( );
 robot->move( );

 robot->MoveRight( );
 robot->move( );
 robot->move( );
 robot->move( );

 robot->MoveRight( );
 robot->move( );
 robot->pick( );

 robot->turnback( );

 robot->move( );
 robot->move( );

 robot->MoveRight( );
 robot->move( );
 robot->move( );
 robot->move( );

 robot->MoveRight( );
 robot->move( );
 robot->move( );
 robot->move( );
 robot->move( );
 robot->move( );
 robot->move( );

 robot->turnLeft( );
 robot->turnLeft( );

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