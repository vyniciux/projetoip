#include "raylib.h"
#include "colisoes.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_FRAMES  5

int main(void)
{
 
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Demo");

    Vector2 position = { (float)screenWidth/2, (float)screenHeight/2 };
    

    Texture mn1 = LoadTexture("assets/Menu/menu001.png");
    Texture mn2 = LoadTexture("assets/Menu/menub001.png");
    Texture mn3 = LoadTexture("assets/Menu/menu003.png");
    Texture mn4 = LoadTexture("assets/Menu/menu004.png");
    Texture mn5 = LoadTexture("assets/Menu/menu005.png");
    Texture mn6 = LoadTexture("assets/Menu/menu006.png");

    Texture2D BotaoStart = LoadTexture("assets/Menu/botaojogar.png");
    Texture2D BotaoSobre= LoadTexture("assets/Menu/botaosobre.png");
    Texture2D BotaoInst = LoadTexture ("assets/Menu/botaoinst.png");
    Texture2D BotaoFechar = LoadTexture("assets/Menu/botaoclose.png");
    Texture2D Titulo = LoadTexture("assets/Menu/title.png");

    Texture fundo = LoadTexture("assets/img005.png");
    Texture fundo1 = LoadTexture("assets/img0051.png");
    Texture sala = LoadTexture("assets/img006.png");
    Texture sala1 = LoadTexture("assets/img0061.png");
    Texture fora = LoadTexture("assets/img008.png");
    Texture fora1 = LoadTexture("assets/img0081.png");
    Texture fora2 = LoadTexture("assets/img009.png");
    Texture fora3 = LoadTexture("assets/img0011.png");
    Texture fora4 = LoadTexture("assets/img00111.png");
    Texture casavizin = LoadTexture("assets/img0010.png");
    Texture casavizin1 = LoadTexture("assets/img00101.png");
    Texture casavizin2 = LoadTexture("assets/img00102.png");
    Texture salav = LoadTexture("assets/img0013.png");
    Texture cozinhav = LoadTexture("assets/img0014.png");
    Texture cozinhav1 = LoadTexture("assets/img00141.png");
    Texture quarto = LoadTexture("assets/img0012.png");
    Texture quarto1 = LoadTexture("assets/img00121.png");
    Texture quarto2 = LoadTexture("assets/img00122.png");
    Texture quarto3 = LoadTexture("assets/img00123.png");
    Texture quarto4 = LoadTexture("assets/img00124.png");
    Texture quarto5 = LoadTexture("assets/img00125.png");
    Texture quarto6 = LoadTexture("assets/img00126.png");
    Texture quarto7 = LoadTexture("assets/img00127.png");

    /////Quinha's codd///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
   
    Vector2 nextPosition = { (float)screenWidth/2 + 100, (float)screenHeight/2};
    Cenas *cenas;
    cenas = (Cenas *) malloc (10 * sizeof(Cenas));
    criarCenas(&cenas); 
    Rectangle player = {position.x, position.y, 30, 40};
    

    //FINAL DO CÓDIGO DO QUNHAS/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    //Giovanna's code///////////////////////////////////////////////////////////////////////////////////////////////////////
    
        
    //usado para animacao das nuvens
    float movnuvens = 0.0f;
    
    //Botao Jogar:
    
    float frameHeightstart = (float)BotaoStart.height/NUM_FRAMES;
    
    Rectangle sourceRecstart = {0, 0,(float)BotaoStart.width, frameHeightstart+110};
    
    Rectangle btnStartrec = { 200,500,(float)BotaoStart.width, frameHeightstart+110};
    
    int btnstart = 0;
    
    int btnActionstart = false;
    
 
    //Botao Sobre:
    
    float frameHeightsobre = (float)BotaoStart.height/NUM_FRAMES;
    
    Rectangle sourceRecsobre = {0, 0,(float)BotaoSobre.width, frameHeightsobre+110};
    
    Rectangle btnSobrerec = { 200, 620,(float)BotaoSobre.width, frameHeightsobre+110};
    
    int btnsobre = 0;
    
    int btnActionsobre = false;
    
    //Botao Instrucoes:
    
    float frameHeightinst = (float)BotaoInst.height/NUM_FRAMES;
    
    Rectangle sourceRecinst = {0, 0,(float)BotaoInst.width, frameHeightinst+110};
    
    Rectangle btnInstrec = { 200, 740,(float)BotaoInst.width, frameHeightinst+110};
    
    int btninst = 0;
    
    int btnActioninst = false;
    
    //Botao Fechar:
    
    float frameHeightfechar = (float)BotaoFechar.height/NUM_FRAMES;
    
    Rectangle sourceRecfechar = {0, 0,(float)BotaoFechar.width, frameHeightfechar+100};

    Rectangle btnFecharrec = { 1650, 80,(float)BotaoFechar.width, frameHeightfechar+100};
    
    int btnfechar = 0;
    
    int btnActionfechar = false;

    //usado para animacao do texto
    
    int framesCounter1 = 0;
    int framesCounter2 = 0;
    int framesCounter3 = 0;
    int framesCounter4 = 0;
    int framesCounter5 = 0;
    int framesCounter6 = 0;
    
    //variavel para iniciar o jogo
    
    int iniciajogo = false;
    
    //mensagens:
    
    const char messagejogar1[128] = "Sabrina sempre desconfiou que seu vizinho, Isac, escondia algo.";
    const char messagejogar3[128] = "sempre foi muito curiosa, resolveu invadir a casa dele a fim de encontrar";
    const char messagejogar2[128] = "Certo dia, Sabrina percebeu que Isac havia saido e como desde pequena";
    const char messagejogar4[128] = "alguma coisa que confirmasse sua desconfiança."; 
    const char messagejogar5[128] = "Para isso, ela precisa desvendar uma serie de desafios antes que Isac a pegue no flagra!";
    const char messagejogar6[128] = "AJUDE SABRINA A MATAR SUA CURIOSIDADE!!";
    
    
    const char messagesobre1[128] = "Este jogo é um projeto para disciplina de Introdução a";
    const char messagesobre2[128] = "Programação, com o objetivo principal aplicar os conhecimentos";
    const char messagesobre3[128] = "da linguagem C e da biblioteca Raylib.";
   
    
    const char messageinst1[128] = "PARA QUE SABRINA ANDE PARA DIREITA APERTE : D";
    const char messageinst2[128] = "PARA QUE SABRINA ANDE PARA ESQUERDA APERTE : A";
    const char messageinst3[128] = "PARA QUE SABRINA ANDE PARA CIMA APERTE : W";
    const char messageinst4[128] = "PARA QUE SABRINA ANDE PARA BAIXO APERTE : S";
    const char messageinst5[128] = "PARA QUE SABRINA INTERAJA COM ALGO APERTE : E";
    const char messageinst6[128] = "PARA PAUSAR O JOGO APERTE : P";
                                 
    Vector2 PosMouse = { 0.0f, 0.0f };

    int currentScreen=1;
    

    // FINAL DO CODE DA GIO //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




    int cena = 0;
    int cenapp = 1;

    // Up=0,Donw=1,Left=2,Right=3
    float Vel[4]={0,1,2,3};
    float VelPadrao = 15;


    SetTargetFPS(60);           

    while (!WindowShouldClose())   
    {
        // Update
        //---------------------------------------0------------------------------------------
        // TODO: Update your variables here

        if (IsKeyDown(KEY_RIGHT)&& position.x<1850) nextPosition.x += Vel[3];
        if (IsKeyDown(KEY_LEFT)&& position.x>20) nextPosition.x -= Vel[2];
        if (IsKeyDown(KEY_UP)&& position.y>220) nextPosition.y -= Vel[0];
        if (IsKeyDown(KEY_DOWN)&& position.y<1050) nextPosition.y += Vel[1];

        if (IsKeyDown(KEY_M)) {VelPadrao+=0.5;}
        if (IsKeyDown(KEY_N)){VelPadrao-=0.5;}
        if (IsKeyDown(KEY_P)){if(cena!=0){cenapp=cena;} cena=0;}

        Vel[0]=VelPadrao;
        Vel[1]=VelPadrao;
        Vel[2]=VelPadrao;
        Vel[3]=VelPadrao;



        //LUCAS//------------------------

        player.x = nextPosition.x;
        player.y = nextPosition.y;

        if(colisao(player, cenas[cena])==1){
          player.x = position.x;
          player.y = position.y;
          nextPosition.x = position.x;
          nextPosition.y = position.y;
        }
        else{
          position.x = nextPosition.x;
          position.y = nextPosition.y;
        }

        //-------------------------------


        //GIOVANNA//--------------------
        if(cena==0){

          switch(currentScreen)
          {
        
              case 1:
              {
                  //animacao das nuvens:
                  movnuvens -= 0.3f;
        
                  if (movnuvens <= -mn5.width*2) movnuvens = 0;
        
                  //checando colisao do mouse com os botoes:
                  
                  PosMouse = GetMousePosition();
                  //colisao com o botao jogar    
                  if (CheckCollisionPointRec(PosMouse, btnStartrec)){
    
                      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnstart = 2; currentScreen =2;}
                      else {btnstart = 1;}
              
                      if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnActionstart = true;   
                  }
        
                  else btnstart = 0;
                  
                  sourceRecstart.y = btnstart*(frameHeightstart-30);
        
                  //colisao com o botao sobre
        
                  if (CheckCollisionPointRec(PosMouse, btnSobrerec)){
    
                      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnsobre = 2;currentScreen = 3;}
                      else {btnsobre = 1;}
              
                      if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActionsobre = true;}   
                  }
        
                  else btnsobre = 0;
                  sourceRecsobre.y = btnsobre*(frameHeightsobre-30);
        
                  //colisao com o botao instrucoes
        
                  if (CheckCollisionPointRec(PosMouse, btnInstrec)){
    
                      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btninst = 2; currentScreen=4;}
                      else btninst = 1;
              
                      if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActioninst = true;}   
                  }
        
                  else btninst = 0;
                  
                  sourceRecinst.y = btninst*(frameHeightinst-30);
          
              }break;
        
              case 2:
              {
                  //letrinha por letrinha

                  framesCounter1++;
                  
                  if(framesCounter1 > 245){framesCounter2++;}
                  if(framesCounter2 > 245){framesCounter3++;}
                  if(framesCounter3 > 245){framesCounter4++;}
                  if(framesCounter4 > 255){framesCounter5++;}
                  if(framesCounter5 > 293){framesCounter6++;}
                  
                  iniciajogo = true;
                  if(framesCounter6 > 150){cena=cenapp;currentScreen=1;}
              
                  
              }break;
        
              case 3:
              {

                  PosMouse = GetMousePosition();
                  
                  if (CheckCollisionPointRec(PosMouse, btnFecharrec)){
    
                      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnfechar = 2; currentScreen=1;}
                      else btnfechar = 1;
              
                      if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActionfechar = true;}   
                  }
        
                  else btnfechar = 0;
                  
                  sourceRecfechar.y = btnfechar*(frameHeightfechar-20);
                  
              }break;
        
              case 4:
              {
              PosMouse = GetMousePosition();
                  
                  if (CheckCollisionPointRec(PosMouse, btnFecharrec)){
    
                      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnfechar = 2; currentScreen=1;}
                      else btnfechar = 1;
              
                      if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActionfechar = true;}   
                  }
        
                  else btnfechar = 0;
                  
                  sourceRecfechar.y = btnfechar*(frameHeightfechar-20);
              
              }break;
        
              default: break;
          }
       
        }
        //------------------------------


        printf("X=%.1f ",position.x);
        printf("Y=%.1f ",position.y);
        printf("Cena=%d\n",cena);
        //----------------------------------------------------------------------------------

        // Draw

        //----------------------------------------------------------------------------------
        BeginDrawing();

             ClearBackground(BLUE);
                   
            if(cena==0 ){

              switch(currentScreen)
              {
                case 1:
                {
                    
                    DrawTextureEx(mn5, (Vector2) {movnuvens, -100}, 0.0f, 2.0f, WHITE);//textura das nuvens->telacarreg
                    DrawTexture(mn3, 0, 0, RAYWHITE); //textura da grama -> teladecarregamento 
                    DrawTextureEx(mn5, (Vector2){ mn5.width*2 + movnuvens, -100}, 0.0f, 2.0f, WHITE);
                    DrawTexture(mn4, 0, 0, RAYWHITE);//textura da casa
                    DrawTexture(Titulo, 0, 0, RAYWHITE);//textura da casa
                    DrawTextureRec(BotaoStart, sourceRecstart, (Vector2){ btnStartrec.x, btnStartrec.y}, WHITE);//texturabotao
                    DrawTextureRec(BotaoSobre, sourceRecsobre, (Vector2){ btnSobrerec.x, btnSobrerec.y}, WHITE);//texturabotao
                    DrawTextureRec(BotaoInst, sourceRecinst, (Vector2){ btnInstrec.x, btnInstrec.y}, WHITE);//texturabotao
                  
                    //mudando cor do botao qnd passa o mouse por cima
                    if(btnstart){DrawTextureRec(BotaoStart, sourceRecstart, (Vector2){ btnStartrec.x, btnStartrec.y}, LIGHTGRAY);}
                   
                    if(btnsobre){DrawTextureRec(BotaoSobre, sourceRecsobre, (Vector2){ btnSobrerec.x, btnSobrerec.y},LIGHTGRAY);}
                    
                    if(btninst) {DrawTextureRec(BotaoInst, sourceRecinst, (Vector2){ btnInstrec.x, btnInstrec.y},LIGHTGRAY);}
                    
                    
                }break;
                
                case 2:{
                
                //carregando texturas da tela que aparece antes do jogo comecar
                
               // DrawTexture(mn1, 0, 0, WHITE);
                DrawTexture(mn6, 0, 0, WHITE);
                DrawText(TextSubtext(messagejogar1, 0, framesCounter1/3), 130, 160, 40, BLACK);
                DrawText(TextSubtext(messagejogar2, 0, framesCounter2/3), 130, 220, 40, BLACK);
                DrawText(TextSubtext(messagejogar3, 0, framesCounter3/3), 130, 280, 40, BLACK);
                DrawText(TextSubtext(messagejogar4, 0, framesCounter4/3), 130, 340, 40, BLACK);
                DrawText(TextSubtext(messagejogar5, 0, framesCounter5/3), 133, 480, 31, DARKBROWN);
                DrawText(TextSubtext(messagejogar6, 0, framesCounter6/3), 200, 600, 65, RED);
                
                }break;    
                case 3:{
                    
                    //texturas da tela "sobre"
                    
                  //  DrawTexture(mn1, 0, 0, WHITE);
                    DrawTexture(mn6, 0, 0, WHITE);
                  //  DrawTexture(Lupa, 760, 50, WHITE);
                    DrawText("SOBRE", 780, 100, 100, BLACK);
                    DrawText(messagesobre1, 200, 240, 40, DARKBROWN);
                    DrawText(messagesobre2, 200, 300, 40, DARKBROWN);
                    DrawText(messagesobre3, 200, 360, 40, DARKBROWN);
                    DrawTextureRec(BotaoFechar, sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y}, WHITE);
                    
                    //mudando cor do botao "fechar"
                   if(btnfechar){DrawTextureRec(BotaoFechar, sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y},RED);}
                   
                    
                }break;
                
                case 4:
                {
                    //carregando texturas da tela de instrucoes
                    
                    DrawTexture(mn1, 0, 0, DARKBROWN);
                    DrawTexture(mn6, 0, 0, WHITE);
                    DrawText("INSTRUçÕES", 300, 120, 100,BLACK);
                  // DrawTexture(Lupa, 840, 50, WHITE);
                    DrawText(messageinst1, 300, 320, 30, BLACK);
                    DrawText(messageinst2, 300, 380, 30, BLACK);
                    DrawText(messageinst3, 300, 440, 30, BLACK);
                    DrawText(messageinst4, 300, 500, 30, BLACK);
                    DrawText(messageinst5, 300, 560, 30, BLACK);
                    DrawText(messageinst6, 300, 620, 30, BLACK);
                    DrawTextureRec(BotaoFechar, sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y}, WHITE);
                    
                    //mudando cor do botao "fechar"
                    if(btnfechar){DrawTextureRec(BotaoFechar, sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y},RED);}
                    
                }break;
                
                  
          }  
  
        }
            
            else if(cena == 1){

                DrawTexture(fundo,0,0,WHITE);
                 DrawTexture(fundo1,0,0,WHITE);
                 DrawRectangleRec(player, BLUE);
                
                
            }
        
            else  if(cena ==2){


                DrawTexture(sala,0,0,WHITE);
                DrawTexture(sala1,0,0,WHITE);
                DrawCircle(position.x,position.y,50,BLUE);
              
            
            }

            else if(cena==3){

                DrawTexture(fora,0,0,WHITE );
                 DrawTexture(fora1,0,0,WHITE );
                 DrawCircle(position.x,position.y,50,GREEN);

            }

            else if(cena==4){

                DrawTexture(fora2,0,0,WHITE );
                 DrawCircle(position.x,position.y,50,GREEN);

            }

            else if(cena==5){

                DrawTexture(casavizin,0,0,WHITE );
                DrawTexture(casavizin1,0,0,WHITE );
                 DrawCircle(position.x,position.y,50,GREEN);

            }
             
            else if(cena==6){

                DrawTexture(fora3,0,0,WHITE );
                DrawTexture(fora4,0,0,WHITE );
                DrawCircle(position.x,position.y,50,GREEN);

            }

            else if(cena==7){

                DrawTexture(salav,0,0,WHITE );
                 DrawCircle(position.x,position.y,50,GREEN);

            }

            else if(cena==8){

                DrawTexture(cozinhav,0,0,WHITE );
                 DrawTexture(cozinhav1,0,0,WHITE );
                 DrawCircle(position.x,position.y,50,GREEN);

            }

            else if(cena==9){

                DrawTexture(quarto,0,0,WHITE );
                DrawTexture(quarto1,0,0,WHITE );
                DrawTexture(quarto3,0,0,WHITE );

                 DrawCircle(position.x,position.y,50,GREEN);

            }

            else if(cena==10){

                DrawTexture(fora,0,0,BLUE );
                 DrawCircle(position.x,position.y,50,GREEN);

            }


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
