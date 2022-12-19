/*
 Guia_0311 - v0.0. - 28 / 08 / 2022
 Author: João Pedro Aguiar do Prado - MATRÍCULA 756491
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0311 ./Guia0311.cpp
 No Windows: g++ -o Guia0311.exe Guia0311.cpp
 Para executar em uma janela de comandos (terminal):

 No Linux : ./Guia0311
 No Windows: Guia0311
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

void decorateWorld(const char *fileName)
{
    // colocar paredes no mundo

    world->set(2, 7, HWALL); // horizontal
    world->set(3, 7, HWALL); // horizontal
    world->set(4, 7, HWALL); // horizontal

    world->set(2, 2, HWALL); // horizontal
    world->set(3, 2, HWALL); // horizontal
    world->set(4, 2, HWALL); // horizontal

    world->set(6, 2, HWALL); // horizontal
    world->set(7, 2, HWALL); // horizontal
    world->set(8, 2, HWALL); // horizontal

    world->set(6, 7, HWALL); // horizontal
    world->set(7, 7, HWALL); // horizontal
    world->set(8, 7, HWALL); // horizontal

    world->set(1, 3, VWALL); // vertical
    world->set(1, 4, VWALL); // vertical
    world->set(1, 5, VWALL); // vertical
    world->set(1, 6, VWALL); // vertical
    world->set(1, 7, VWALL); // vertical

    world->set(4, 3, VWALL); // vertical
    world->set(4, 4, VWALL); // vertical
    world->set(4, 5, VWALL); // vertical
    world->set(4, 6, VWALL); // vertical
    world->set(4, 7, VWALL); // vertical

    world->set(5, 3, VWALL); // vertical
    world->set(5, 4, VWALL); // vertical
    world->set(5, 5, VWALL); // vertical
    world->set(5, 6, VWALL); // vertical
    world->set(5, 7, VWALL); // vertical

    world->set(8, 3, VWALL); // vertical
    world->set(8, 4, VWALL); // vertical
    world->set(8, 5, VWALL); // vertical
    world->set(8, 6, VWALL); // vertical
    world->set(8, 7, VWALL); // vertical

  

    // colocar quatro marcadores no mundo

    world->set(1, 5, BEEPER);
    world->set(3, 2, BEEPER);
    world->set(3, 8, BEEPER);

    // salvar a configuracao atual do mundo
    world->save(fileName);
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
 @param fileName - nome do arquivo
    */
    void recordActions ( const char *fileName )
{
 // definir dados
 int action;
 // definir arquivo onde gravar comandos
 std::ofstream archive ( fileName );
 // repetir enquanto o comando
 // for diferente de zero
 do
 {
 // ler opcao
 action = IO_readint ( "Command? " );
 // testar se opcao valida
 if ( 0 <= action && action <= 9 )
 {
 // executar comando
 execute ( action );
 // guardar o comando em arquivo
 archive << action << "\n";
 } // end if
 }
 while ( action != 0 );
 // fechar o arquivo
 // INDISPENSAVEL para a gravacao
 archive.close ( );
} // end recordActions ( )

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

    /**
     * pickBeepers - Metodo para coletar marcadores.
     */
    void pickBeepers()
    {
        // repetir (com teste no inicio)
        // enquanto houver marcador proximo
        while (nextToABeeper())
        {
            // coletar um marcador
            pickBeeper();
        } // end while
    }     // end pickBeepers( )

    void putBeepers()
    {
        // repetir (com teste no inicio)
        // enquanto houver marcador proximo
        while (beepersInBag())
        {
            // coletar um marcador
            putBeeper();
        } // end while
    }     // end pickBeepers( )


    /**
     * turn60 - Metodo para virar robo na direção oposta.
     */

        void moveN( int steps )
        {
        // definir dado local
        int step = 0;
        // repetir contando e testando ate' atingir a quantidade de passos
        for ( step = 1; step <= steps; step = step + 1 ) // outra forma de repetir
        {
        // dar um passo por vez
        move( );
        } // end if
        } // end moveN( 


        void turn60()
    {
        // testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar duas vezes 'a esquerda
            turnLeft();
            turnLeft();
            move();
        } // end if
    }     // end turn60 ( )

    /**
    turnRight - Procedimento para virar 'a direita.
    */
    void turnRight()
    {
        // testar se o robo esta' ativo
        if (checkStatus())

        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            turnLeft();
            turnLeft();
            turnLeft();
        } // end if
    }     // end turnRight ( )


    void MoveLeft()
    {
        if (leftIsClear())
        {
            turnLeft();
            move();
        } // fim se
    }

    void MoveRight()
    {
        if (rightIsClear())
        {
            turnRight();
            move();
        } // fim se
    }

  
 

    

}; // end class MyRobot
// --------------------------- acao principal
/**
 Acao principal: executar a tarefa descrita acima.
*/
int main()
{
    // definir o contexto
    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create(""); // criar o mundo
    decorateWorld("Guia0214.txt");
    world->show();
    set_Speed(1); // definir velocidade padrao
                  // criar robo
    MyRobot *robot = new MyRobot();
    // Variáveis

    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 0, "Karel");
    // executar tarefa
   

    // robot->recordActions("Tarefa0311.txt");

       robot-> playActions("Tarefa0311.txt");
   

   

    robot->turnOff(); // desligar-se

    // encerrar operacoes no ambiente
    world->close();
    // encerrar programa
    getchar();
    return (0);
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