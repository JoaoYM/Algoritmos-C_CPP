/* PUC-Minas - Ciência da Computação
AED1 – Guia 01
Tema: Introdução à programação
Atividade: Montagem de programas - Karel

 Guia0211 - v0.0. - 21 / 08 / 2022
 Author: João Pedro Aguiar do Prado
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0214 ./Guia0214.cpp
 No Windows: g++ -o Guia0214.exe Guia0214.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0214
 No Windows: Guia0214
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
    world->set(3, 2, HWALL); // horizontal
    world->set(4, 2, HWALL); // horizontal
    world->set(5, 2, HWALL); // horizontal

    world->set(3, 8, HWALL); // horizontal
    world->set(5, 8, HWALL); // horizontal

    world->set(2, 3, VWALL); // vertical
    world->set(2, 4, VWALL); // vertical
    world->set(2, 5, VWALL); // vertical
    world->set(2, 6, VWALL); // vertical
    world->set(2, 7, VWALL); // vertical
    world->set(2, 8, VWALL); // vertical

    world->set(3, 3, VWALL); // vertical
    world->set(3, 4, VWALL); // vertical
    world->set(3, 5, VWALL); // vertical
    world->set(3, 6, VWALL); // vertical
    world->set(3, 7, VWALL); // vertical

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
    world->set(5, 8, VWALL); // vertical

    // colocar quatro marcadores no mundo

    world->set(3, 3, BEEPER);
    world->set(3, 3, BEEPER);
    world->set(3, 3, BEEPER);

    world->set(4, 3, BEEPER);
    world->set(4, 3, BEEPER);
    world->set(4, 3, BEEPER);
    world->set(4, 4, BEEPER);
    world->set(4, 4, BEEPER);

    world->set(5, 3, BEEPER);
    world->set(5, 3, BEEPER);
    world->set(5, 3, BEEPER);
    world->set(5, 4, BEEPER);
    world->set(5, 4, BEEPER);
    world->set(5, 5, BEEPER);

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

    /**
   recordActions - Metodo para mover o robot interativamente
   e guardar a descricao da tarefa em arquivo.
   @param fileName - nome do arquivo
      */
    void recordActions(const char *fileName)
    {
        int x = xAvenue();
        int y = yStreet();
        // definir arquivo onde gravar comandos
        std::ofstream archive(fileName);
        // guardar o comando em arquivo
        if (nextToABeeper())
        {
            archive << x << std::endl;
            archive << y << std::endl;
        }

        // fechar o arquivo
        // INDISPENSAVEL para a gravacao
        archive.close();
    } // end recordActions ( )

        /**
 appendActions - Metodo para acrescentar comandos ao arquivo e traduzi-los.
 @param filename - nome do arquivo
*/
    void appendActions(const char *fileName)
    {
        int x = xAvenue();
        int y = yStreet();
        // definir arquivo para receber acrescimos ao final
        std::fstream archive(fileName, std::ios::app);
        // repetir enquanto acao diferente de zero
        if (nextToABeeper())
        {
            archive << x << std::endl;
            archive << y << std::endl;
        }
        // fechar o arquivo
        // INDISPENSAVEL para a gravacao
        archive.close();
    } // end appendActions ( )

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
    robot->move(); // primeira acao: andar para frente
    robot->MoveLeft();

    robot->moveN( 7 );

    robot->MoveRight();
    robot->move();

    robot->MoveRight();
    robot->MoveRight();
    robot->MoveLeft();

    robot->moveN( 4 );


    robot->recordActions("Tarefa14b.txt");
    robot->pickBeepers();

    robot->turn60();
    robot->moveN( 4 );
    robot->MoveRight();
    robot->MoveRight();
    robot->moveN( 4 );
    robot->appendActions("Tarefa14b.txt");
    robot->pickBeepers();
    robot->turn60();
    robot->appendActions("Tarefa14b.txt");
    robot->pickBeepers();

   
    robot->moveN( 4 );
    robot->MoveRight();
    robot->MoveRight();
    robot->moveN( 4 );
    robot->appendActions("Tarefa14b.txt");
    robot->pickBeepers();
    robot->turn60();
    robot->appendActions("Tarefa14b.txt");
    robot->pickBeepers();
    robot->move( );
    robot->appendActions("Tarefa14b.txt");
    robot->pickBeepers();


       robot->moveN( 3 );

       robot->MoveLeft( );
       robot->MoveRight( );
       robot->MoveRight( );

       robot->moveN( 4 );

       robot->MoveRight( );
       robot->moveN( 7 );

       robot->putBeepers( );

       robot->MoveRight( );
       robot->moveN( 7 );
       robot->turnLeft( );
       robot->turnLeft( ); 

   

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