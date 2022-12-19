/*
 Guia_0212 - v0.0. - 28 / 08 / 2022
 Author: João Pedro Aguiar do Prado - MATRÍCULA 756491
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0315 ./Guia0315.cpp
 No Windows: g++ -o Guia0315.exe Guia0315.cpp
 Para executar em uma janela de comandos (terminal):

 No Linux : ./Guia0315
 No Windows: Guia0315
*/
// lista de dependencias
#include "karel.hpp"
#include "io.hpp"
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
    // colocar paredes no mundo
    world->set(1, 6, VWALL);
    world->set(1, 5, VWALL);

    world->set(8, 6, VWALL);
    world->set(8, 5, VWALL);
    // fim das paredes verticais

    world->set(2, 4, HWALL);
    world->set(3, 4, HWALL);
    world->set(4, 4, HWALL);
    world->set(5, 4, HWALL);
    world->set(6, 4, HWALL);
    world->set(7, 4, HWALL);
    world->set(8, 4, HWALL);

    world->set(2, 5, HWALL);
    world->set(3, 5, HWALL);
    world->set(4, 5, HWALL);
    world->set(6, 5, HWALL);
    world->set(7, 5, HWALL);
    world->set(8, 5, HWALL);

    world->set(2, 6, HWALL);
    world->set(3, 6, HWALL);
    world->set(4, 6, HWALL);
    world->set(5, 6, HWALL);
    world->set(6, 6, HWALL);
    world->set(7, 6, HWALL);
    world->set(8, 6, HWALL);    // fim das paredes horizontais

    world->set(2, 6, BEEPER);



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
 turnRight - Procedimento para virar 'a direita.
 */

    void execute(int option){
        switch (option)
        {
        case 0:
            turnOff();
            break;

        case 1:
            turnLeft();
            break;

        case 2:
            while(! facingSouth()){
                turnLeft();
            }
            break;

        case 3:
            turnRight();
            break;

        case 4:
            while(! facingWest()){
                turnLeft();
            }
            break;

        case 5:
            if(frontIsClear()){
                move();
            }
            break;

        case 6:
            while(! facingEast()){
                turnLeft();
            }
            break;

        case 7:
            pickAllBeepers();
            
            break;

        case 8:
            while(! facingNorth()){
                turnLeft();
            }
            break;

        case 9:
            if(beepersInBag()){
                putAllBeepers();
            }
            
            break;
            default: show_Error("ERROR: Invalid command.");
        }
    }
    void halfPath(){
        moveN(3);
    }
    void turnUpRight(){
        while(! facingNorth()){
            turnLeft();
        }
        move();
        turnRight();
    }
    void turnDownRight(){
        while(! facingSouth()){
            turnLeft();
        }
        move();
        turnLeft();
    }
    void turnUpLeft(){
        while(! facingNorth()){
            turnLeft();
        }
        move();
        turnLeft();
    }
    void turnDownLeft(){
        while(! facingSouth()){
            turnLeft();
        }
        move();
        turnRight();
    }

    void doCommands(int lenght, int commands[]){
        int x = 0;
        int action = 0;

        for(x=0; x<lenght;x+=1){
            execute(commands[x]);

        }
    }
    void doFirstTaskJarel(){
        halfPath();
        turnUpLeft();
        halfPath();
        pickBeeper();
        turnAround();
        halfPath();
    }
    void doSecondTaskJarel(){ // quando os dois robôs estão nas mesmas coordenadas
        if(nextToARobot()){
            if(beepersInBag()){
                putBeeper();
            }
        }else{
            char message[40];
            message[0] = '\0';
            sprintf(message, "não há um robô por perto.");
            show_Text(message);

            turnDownRight();
            halfPath();
        }
        halfPath();
        turnLeft();

        turnOff();
    }
    
    void doFirstTaskKarel(){
        halfPath();
        turnUpRight();
        
    }
    void doSecondTaskKarel(){ 
        if(nextToABeeper()){
            pickBeeper();
        }
        turnDownRight();
        halfPath();

        if(beepersInBag()){
            putBeeper();
        }

        turnAround();
        halfPath();
        halfPath();
        turnAround();

        turnOff();
    }
    void doTask(const char*fileName){
        int quantidade = 0;
        int comandos[MAX_COMMANDS];
        char message[80];

        quantidade = readCommands(comandos, "Teste0303.txt");
        message[0] = '\0';
        sprintf(message, "Commands: %d", quantidade);
        show_Text(message);

        doCommands(quantidade, comandos);
    }
    int countCommands(const char*fileName){
        char message [80];
        int x = 0;
        int lenght = 0;

        std::ifstream archive(fileName);
        archive >> x;
        while(! archive.eof()){
            lenght+=1;
            archive >> x;
        }
        archive.close();

        return lenght;
    }
    int readCommands(int commands[], const char*fileName){
        int x = 0;
        int lenght = 0;
        int action = 0;
        std::ifstream archive(fileName);

        lenght = countCommands(fileName);
        if(lenght < MAX_COMMANDS){
            for(x = 0; x < lenght; x += 1){
                archive >> action;
                commands[x] = action;
            }
            archive.close();
        }// end if
        return lenght;
    }
    void mapWorld(int map[][WIDTH]){
        char message[80];

        int street = 0,
            avenue = 0;
        int beepers = 0;

        for(street = 1; street <= world->streets(); street += 1){
            for(avenue = 1; avenue <= world->avenues(); avenue += 1){
                map[street-1][avenue-1] = 0;
                if(nextToABeeper()){
                    message[0] = '\0';
                    sprintf(message, "Beeper at %dx%d", avenue, street);
                    show_Text(message);
                    beepers += 1;

                    map[street-1][avenue-1] = 1;
                }
                if(avenue < world->avenues()){
                    move();
                }
            } // end for(avenue)
            turnLeft();
            turnLeft();

            moveN(world->avenues()-1);

            if(street < world->streets()){
                turnRight();
                move();
                turnRight();
            }
        }
        if(world != nullptr){
            message[0] = '\0';
            sprintf(message, "World is %dx%d", world->avenues(),world->streets());
            show_Text(message);
        }
    }
    void turnAround(){
        turnLeft();
        turnLeft();
    }
    void saveMap(const char*fileName, int map[][WIDTH]){
        int street = 0,
            avenue = 0;

        std::ofstream archive(fileName);

        if(world != nullptr){
            archive << world->avenues() <<"\n";
            archive << world->streets() <<"\n";

            for(street = 1; street <= world->streets(); street += 1){
                for(avenue = 1; avenue <= world->avenues(); avenue += 1){
                    if(map[street-1][avenue-1] == 1){
                        archive << avenue << std::endl;
                        archive << street << std::endl;
                        archive << map[street-1][avenue-1] << std::endl;
                    }
                }
            }
            archive.close();
        }
    }
    void recordAction(const char*fileName){
        int action;
        std::ofstream archive(fileName);

        action = IO_readint("Command? ");
        while (action > 0){
            if(0 <= action && action <= 9){
                execute(action);
                if(action == 7){
                    int x = xAvenue();
                    int y = yStreet();
                    archive << x << ", ";
                    archive << y << "\n";
                }
                // depois de executar, arquive o comando. !! "archive" é o nome do arquivo
            archive << action << "\n";
            }
        action = IO_readint("Command? ");
        } // end while

        archive.close();
        
    } // end recordAction()
    void playAction(const char*fileName){
        int action;

        std::ifstream archive (fileName);

        archive >> action; // tentar ler a primeira linha
        while(! archive.eof()){ // enquanto não encontrar o fim do arquivo, execute
            IO_print(IO_toString(action)); // mostre o comando do arquivo na tela

            delay(stepDelay); // não sei o que é isso

            execute(action); // execute o switch case novamente

            archive >> action; // leia a próxima linha

        } // end while  /*  enquanto não acabar o arquivo, continue lendo a próxima linha   */

        archive.close();
    }
    void turnRight()
    {
        // definir dado local
        int step = 0;
        // testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            if (rightIsClear())
            {
                for (step = 1; step <= 3; step = step + 1)
                {
                    turnLeft();
                } // end for
            }
            
            
        }     // end if
    }         // end turnRight ( )
    /**
 moveN - Metodo para mover certa quantidade de passos.
 @param steps - passos a serem dados.
 */
    void pickAllBeepers(){
        while (nextToABeeper())
        {
            pickBeeper();
            
        }

    }// end pickBeepers()
    void putAllBeepers(){
        while (beepersInBag())
        {
            putBeeper();
        }
        /*int control = 0;

        for (control = n; control > 0; control -= 1){
            putBeeper();
        } */
    }//  end putBeepers()
    void moveN(int steps)
    {
        // definir dado local
        int step = 0;
        // testar se a quantidade de passos e' maior que zero
        for (step = steps; step > 0; step = step - 1)
        {
            // dar um passo
            if(frontIsClear()){
                move();
            } // end if
            
        } // end for
    }     // end moveN( )
    /**
 doPartialTask - Metodo para especificar parte de uma tarefa.
 */

    /**
 doTask - Relacao de acoes para o robo executar.
 */
    int pickBeepers(){

        int n = 0;
        // pegue um beeper se estiver em cima de um
        while(nextToABeeper()){
            pickBeeper();

            n += 1;

            
        }  // end while
        return (n);
    } // end pickBeepers

    /**
            * moveI - Metodo para mover o robot interativamente.
            * Lista de comandos disponiveis:
                * 0 - turnOff
                * 1 - turnLeft      2 - to South
                * 3 - turnRight     4 - to West
                * 5 - move          6 - to East
                * 7 - pickBeeper    8 - to North
                * 9 - putBeeper
    */

};    // end class MyRobot
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
    decorateWorld("Guia0315.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0315.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(3);                // definir velocidade padrao
                                 // criar robo
    MyRobot *robot1 = new MyRobot();
    MyRobot *robot2 = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot1->create(2, 5, EAST, 0, "Karel");
    robot2->create(8, 5, WEST, 0, "Jarel");

    robot2->doFirstTaskJarel();
    robot1->doFirstTaskKarel();
    robot2->doSecondTaskJarel();
    robot1->doSecondTaskKarel();

    // executar tarefa

    // encerrar operacoes no ambiente
    world->close();
    // encerrar programa
    getchar();
    return (0);

}// end main ( )
// -------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
--------------------------------------------- testes
Versao Teste
 0.1 01. (0K) countCommands() funcional.
 0.2 01. (OK) countCommands(parametro) funcional com retorno.
 0.3 01. (OK) readcommands() funcional. Faz os comandos e depois lê a quantidade.
 0.4 01. (OK) não entendi, mas parece estar funcionando.
 0.5 01. (OK) igual o 0.4, porém, dentro do doTask()
 1.5 01. (OK) Jarel faz tudo corretamente caso não tenha nenhum robô por perto
     02. (OK) funcional
*/
