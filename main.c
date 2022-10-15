#include "raylib.h"
#include "colisoes.h"
#include "animacao.h"
#include "itens.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_FRAMES  5

int main(void)
{
 
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "O vizin");

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
    Texture2D Lupa = LoadTexture("assets/Menu/lupa.png");

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
    Texture salav1 = LoadTexture("assets/img00131.png");
    Texture estantef = LoadTexture("assets/img00132.png");
    Texture salaopened = LoadTexture("assets/img00134.png");
    Texture banheiro = LoadTexture("assets/img00151.png");
    Texture selva = LoadTexture("assets/img0016.png");


    Texture senha1 = LoadTexture("assets/Menu/lonb01.png");
    Texture senha2 = LoadTexture("assets/Menu/lonb02.png");
    Texture senha3 = LoadTexture("assets/Menu/lonb03.png");
    Texture senha4 = LoadTexture("assets/Menu/lonb00.png");
    Texture senha5 = LoadTexture("assets/Menu/lonb04.png");

    Texture feixeHorizontal = LoadTexture("assets/img00126.png");
    Texture feixeVertical1 = LoadTexture("assets/img00125.png");
    Texture feixeVertical2 = LoadTexture("assets/img00127.png");

    Texture salalab1 = LoadTexture("assets/puzzle estante/qt001.png");
    Texture salalab2 = LoadTexture("assets/puzzle estante/qt002.png");
    Texture salalab3 = LoadTexture("assets/puzzle estante/qt003.png");
    Texture salalab4 = LoadTexture("assets/puzzle estante/qt004.png");
    Texture salalab5 = LoadTexture("assets/puzzle estante/qt005.png");
    Texture salalab6 = LoadTexture("assets/puzzle estante/qt006.png");
    Texture salalab7 = LoadTexture("assets/puzzle estante/qt007.png");
    Texture salalab8 = LoadTexture("assets/puzzle estante/qt008.png");
    Texture salalab9 = LoadTexture("assets/puzzle estante/qt009.png");

    Texture num1 = LoadTexture("assets/puzzle estante/num23.png");
    Texture num2 = LoadTexture("assets/puzzle estante/num11.png");
    Texture num3 = LoadTexture("assets/puzzle estante/num02.png");
    Texture num4 = LoadTexture("assets/puzzle estante/num31.png");
    Texture num5 = LoadTexture("assets/puzzle estante/num79.png");
    Texture num6 = LoadTexture("assets/puzzle estante/num09.png");
    Texture num7 = LoadTexture("assets/puzzle estante/num01.png");
    Texture num8 = LoadTexture("assets/puzzle estante/num03.png");
    Texture num9 = LoadTexture("assets/puzzle estante/num15.png");

    Texture final1 = LoadTexture("assets/final001.png");

    Texture2D Player =  LoadTexture("assets/personagemov.png");
    Texture2D Pato =  LoadTexture("assets/pato.png");
    Texture2D fogo =  LoadTexture("assets/img00133.png");
    Texture2D espelho = LoadTexture("assets/img00128.png");


 
    Texture2D *texturasDeItens;
    int qtdItens = 5;
    texturasDeItens = (Texture2D *) calloc(qtdItens, sizeof(Texture2D));
    gerarItens(&texturasDeItens);
    ////Joao's code ///////////////////////////////////////////////////////////////////////////////////////////////////

    float FrameWidth = (float) (Player.width/6);
    float x = 10;
    float y = 10;                                                 //PLAYER;
    int frame = 1;
    float Mov = 2;
 
    Rectangle Fire;        
    Vector2 f = {942, 50};                         //FOGO;
 
    float FrameWidth2 = (float) (Pato.width/3);
    float px = 1200;
    float py = 401;                                         //PATO; --- COMIDA++ QUANDO O PATO RECEBE COMIDA;
    int frame2 = 1; 
    float Mov2 = 2;
    int PatoFlag = 0;
    Rectangle patoHitbox = {px, py, FrameWidth2, Pato.height/4};

    InitAudioDevice();                                      //TESTANDO MUSICA
    Music music = LoadMusicStream("assets/sons/MusicaTeste.mp3");          //TESTANDO MUSICA
    PlayMusicStream(music);                                 //TESTANDO MUSICA
    Sound sound = LoadSound("assets/sons/PokemonA.wav");
    


    /////Quinha's code///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
   
    Vector2 nextPosition = { (float)screenWidth/2 + 100, (float)screenHeight/2};
    Cenas *cenas;
    cenas = (Cenas *) malloc (23 * sizeof(Cenas));
    criarCenas(&cenas); 
    Rectangle player = {position.x, position.y, 100, 80};
    

    //FINAL DO CÓDIGO DO QUNHAS/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    //Giovanna's code///////////////////////////////////////////////////////////////////////////////////////////////////////
        
    Vector2 PosMouse = { 0.0f, 0.0f };   

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
    
    int framesCounter7 = 0;
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
                                 
    int currentScreen=1;


    //senha 1
    float frameHeights1 = (float)senha1.height/NUM_FRAMES;
    Rectangle sourceRecs1 = {0, 0,(float)senha1.width, frameHeights1+200};
    Rectangle btnS1rec = { 600, 400,(float)senha1.width, frameHeights1+200};
    int btns1 = 0;
    int btnActions1 = false;
   
    
    // senha 2
    float frameHeights2 = (float)senha2.height/NUM_FRAMES;
    Rectangle sourceRecs2 = {0, 0,(float)senha2.width, frameHeights2+200};
    Rectangle btnS2rec = { 200, 600,(float)senha2.width, frameHeights2+200};
    int btns2 = 0;
    int btnActions2 = false;
    
    //senha 3
    
    float frameHeights3 = (float)senha3.height/NUM_FRAMES;
    Rectangle sourceRecs3 = {0, 0,(float)senha3.width, frameHeights3+180};
    Rectangle btnS3rec = { 1000, 600,(float)senha3.width, frameHeights3+180};
    int btns3 = 0;
    int btnActions3 = false;
    
    //senha 4
   
    
    float frameHeights4 = (float)senha4.height/NUM_FRAMES;
    Rectangle sourceRecs4 = {0, 0,(float)senha4.width, frameHeights4+180};
    Rectangle btnS4rec = { 200, 800,(float)senha4.width, frameHeights4+180};
    int btns4 = 0;
    int btnActions4 = false;
    
    //senha 5
    
    float frameHeights5 = (float)senha5.height/NUM_FRAMES;
    Rectangle sourceRecs5 = {0, 0,(float)senha5.width, frameHeights5+180};
    Rectangle btnS5rec = { 1000, 800,(float)senha5.width, frameHeights5+180};
    int btns5 = 0;
    int btnActions5 = false;

    

    // FINAL DO CODE DA GIO //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Arthur's code   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Jogador jogador;
    for(int h = 0; h < 5; h++){
        jogador.key[h] = false;
        jogador.itens[h] = false;
    }
    int frameEsp1 = 3, frameEsp2 = 0;

    /////////////////////////////////

    int cena = 7;    /////troca aqui pra começar em outra cena  // controle de produção
    int cenapp = 1;
    float VelPadrao = 5;



    SetTargetFPS(60);           

    while (!WindowShouldClose())   
    {

        UpdateMusicStream(music);                          //TOCAR MUSICA;

        // Update
        //---------------------------------------0------------------------------------------
        // TODO: Update your variables here

        position.x = nextPosition.x;
        position.y = nextPosition.y;

        if (IsKeyDown(KEY_D)&& position.x<1890) nextPosition.x += VelPadrao;
        if (IsKeyDown(KEY_A)&& position.x>0) nextPosition.x -= VelPadrao;
        if (IsKeyDown(KEY_W)&& position.y>220) nextPosition.y -= VelPadrao;
        if (IsKeyDown(KEY_S)&& position.y<1040) nextPosition.y += VelPadrao;

        if (IsKeyDown(KEY_M)) {VelPadrao+=0.5;}
        if (IsKeyDown(KEY_N)){VelPadrao-=0.5;}
        if (IsKeyDown(KEY_P)){if(cena!=0){cenapp=cena;} cena=0;}
        //LUCAS//------------------------





        if(trocarCena(player, &(nextPosition.x), &(nextPosition.y), cenas[cena], &cena)==1){
            position.x = nextPosition.x;
            position.y = nextPosition.y;
        }

        player.x = nextPosition.x;
        player.y = nextPosition.y;

        if(colisaoMapa(player, cenas[cena])==1){ //Houve colisão com algum objeto
          player.x = position.x;
          player.y = position.y;
          nextPosition.x = position.x;
          nextPosition.y = position.y;
        }
        if((cena==9)&&(CheckCollisionRecs(patoHitbox, player)==1)){ //Houve colisão com algum objeto
          player.x = position.x;
          player.y = position.y;
          nextPosition.x = position.x;
          nextPosition.y = position.y;
        }
     
     
        //ARTHUR//-----------------------

        jogador.posX = position.x;
        jogador.posY = position.y;

        phaseOne(&jogador, &cena, &cenas[6], sound);
        if(jogador.key[0] == true) cenas[5].portas[2].check = 1;

        phaseTwo(&jogador, &cena, &cenas[8], sound, &PatoFlag);

        phaseThree(&jogador, &cena, &cenas[9], sound, &frameEsp1, &frameEsp2);
        if(jogador.key[2] ==  true) cenas[7].portas[4].check = 1;

        //---------------------------------


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
      
        else if(cena==21){

            PosMouse= GetMousePosition();
            
            if (CheckCollisionPointRec(PosMouse, btnS1rec))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btns1 = 2;
                    else btns1 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActions1 = true;cena=12;}
                }
            else btnActions1 = 0;
                
            sourceRecs1.y = btns1*(frameHeights1-55);
            
            //checando colisao com o botao 2
            
            if (CheckCollisionPointRec(PosMouse, btnS2rec))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btns2 = 2;
                    else btns2 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActions2 = true;cena=12;}
                }
            else btnActions2 = 0;
                
            sourceRecs2.y = btns2*(frameHeights2-55);
            
            //checando colisao com o botao 3
            if (CheckCollisionPointRec(PosMouse, btnS3rec))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btns3 = 2;
                    else btns3 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){btnActions3= true;cena=12;}
                }
            else btnActions3 = 0;
                
            sourceRecs3.y = btns3*(frameHeights3-55);
            
            //checando colisao com o botao 4
            
            if (CheckCollisionPointRec(PosMouse, btnS4rec))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btns4 = 2;
                    else btns4 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){ btnActions4 = true;cena=22;}
                }
            else btnActions4 = 0;
                
            sourceRecs4.y = btns4*(frameHeights4-55);
            
            //checando colisao com o botao 5
            
            if (CheckCollisionPointRec(PosMouse, btnS5rec))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btns5 = 2;
                    else btns5 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActions5 = true;cena=12;}
                }
            else btnActions5 = 0;
            
            sourceRecs5.y = btns5*(frameHeights5-55);
            
            }

        //------------------------------


        printf("X=%.1f ",position.x);
        printf("Y=%.1f ",position.y);
        printf("check=%d ", cenas[7].portas[4].check);
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
                    DrawTexture(Lupa, 1070, 110, WHITE);
                    DrawText("SOBRE", 680, 100, 100, BLACK);
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
                    DrawText("INSTRUçÕES", 320, 120, 100,BLACK);
                    DrawTexture(Lupa, 1000, 130, WHITE);
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
             
                 
            }
        
            else  if(cena ==2){

                DrawTexture(sala,0,0,WHITE);
                DrawTexture(sala1,0,0,WHITE);
             
            }

            else if(cena==3){

                DrawTexture(fora,0,0,WHITE );
                DrawTexture(fora1,0,0,WHITE );
             

            }

            else if(cena==4){

                DrawTexture(fora2,0,0,WHITE );
              

            }

            else if(cena==5){

                DrawTexture(casavizin,0,0,WHITE );
                DrawTexture(casavizin1,0,0,WHITE );
              
            }
             
            else if(cena==6){

                DrawTexture(fora3,0,0,WHITE );
                DrawTexture(fora4,0,0,WHITE );

            }

            else if(cena==7){

                DrawTexture(salav,0,0,WHITE);
                DrawTexture(salav1,0,0,WHITE);
                jogador.itens[0] = false;
                Fire = AnimFogo(fogo);
                DrawTextureRec(fogo, Fire, f, RAYWHITE);

            }

            else if(cena==8){

                DrawTexture(cozinhav,0,0,WHITE );
                DrawTexture(cozinhav1,0,0,WHITE );
             
            }

            else if(cena==9){

                DrawTexture(quarto,0,0,WHITE);
                DrawTexture(quarto1,0,0,WHITE);
                DrawTexture(quarto3,0,0,WHITE);
                AnimEspelho(espelho, frameEsp1, 1000, 700);
                AnimEspelho(espelho, frameEsp2, 130, 700);
                Vector2 vec2 = {px, py};
                AnimPato(Pato, FrameWidth2, &frame2, &Mov2, &px, &py, &nextPosition.x, &nextPosition.y, &Mov, PatoFlag);
                Rectangle Duck = {FrameWidth2*frame2, Pato.height/Mov2, FrameWidth2, (float) Pato.height/4};      //PATO - APENAS NA FASE DO PATO;
                DrawTextureRec(Pato, Duck, vec2, RAYWHITE);
                patoHitbox.x = px;
                patoHitbox.y = py;
                DrawTexture(feixeVertical1,0,0,WHITE);
                if(frameEsp1==0) DrawTexture(feixeHorizontal,0,80,WHITE);
                if(frameEsp1==0 && frameEsp2==2) DrawTexture(feixeVertical2,0,20,WHITE);
            }

            else if(cena==10){

                DrawTexture(banheiro,0,0,WHITE);
              

            }

            else if(cena==11){

                DrawTexture(selva,0,0,WHITE);
              

            }

            //labirinto----------------------------------------------

            else if(cena==12){

                DrawTexture(salalab1,0,0,WHITE);
                DrawTexture(num1,0,10,WHITE);
                jogador.itens[2] = false;

            }

            else if(cena==13){

                DrawTexture(salalab2,0,0,WHITE);
                DrawTexture(num2,0,10,WHITE);

            }

            else if(cena==14){

                DrawTexture(salalab3,0,0,WHITE);
                DrawTexture(num3,0,10,WHITE);

            }

            else if(cena==15){

                DrawTexture(salalab4,0,0,WHITE);
                DrawTexture(num4,0,10,WHITE);
            }

            else if(cena==16){

                DrawTexture(salalab5,0,0,WHITE);
                DrawTexture(num5,0,10,WHITE);
             
            }

            else if(cena==17){

                DrawTexture(salalab6,0,0,WHITE);
                DrawTexture(num6,0,10,WHITE);
               

            }

            else if(cena==18){

                DrawTexture(salalab7,0,0,WHITE);
                DrawTexture(num7,0,10,WHITE);
                

            }

            else if(cena==19){

                DrawTexture(salalab8,0,0,WHITE);
                DrawTexture(num8,0,10,WHITE);
               
            }

            else if(cena==20){

                DrawTexture(salalab9,0,0,WHITE);
                DrawTexture(num9,0,10,WHITE);
             

            }

            
            if(cena==21){

                ClearBackground(BLUE);
                DrawTexture(mn6, 0, 0, WHITE);
                DrawText("Qual a senha?",450,200,150,BLACK);
                DrawTextureRec(senha1, sourceRecs1, (Vector2){ btnS1rec.x, btnS1rec.y}, WHITE);
                DrawTextureRec(senha2, sourceRecs2, (Vector2){ btnS2rec.x, btnS2rec.y}, WHITE);
                DrawTextureRec(senha3, sourceRecs3, (Vector2){ btnS3rec.x, btnS3rec.y}, WHITE);
                DrawTextureRec(senha4, sourceRecs4, (Vector2){ btnS4rec.x, btnS4rec.y}, WHITE);
                DrawTextureRec(senha5, sourceRecs5, (Vector2){ btnS5rec.x, btnS5rec.y}, WHITE);

            }

            else if(cena==22){
                
                framesCounter7++;

                DrawTexture(final1,0,0,RAYWHITE);

                if(framesCounter7<300)DrawText(TextSubtext("???????????????????????????????????", 0, framesCounter7/3), 200, 850, 60, BLACK);
                if(framesCounter7>300&&framesCounter7<600)DrawText("Sabrina: ?????????  Então era você o saci Perêrê", 200, 850, 60,WHITE);
                if(framesCounter7>600&&framesCounter7<1100)DrawText("Saci: Como você chegou aqui?", 200, 850, 60, RED);
                if(framesCounter7>600&&framesCounter7<1100)DrawText("Já vi que o labirinto não é de nada.", 200,920, 60, RED);
                if(framesCounter7>1100&&framesCounter7<1500)DrawText("Sabrina: Nada que uma garota ", 200, 850, 60, WHITE);
                if(framesCounter7>1100&&framesCounter7<1500)DrawText("de talentos não dê conta ;).", 200,920, 60, WHITE);
                if(framesCounter7>1500&&framesCounter7<1900)DrawText("Saci: Só não me prenda numa garrafa,", 200, 850, 60, RED);
                if(framesCounter7>1500&&framesCounter7<1900)DrawText("tenho más memórias", 200,920, 60, RED);
                if(framesCounter7>1900&&framesCounter7<2200)DrawText("Sabrina: Não é o tipo  de magia que eu faço.", 200, 850, 60, WHITE);
                if(framesCounter7>2200&&framesCounter7<2600)DrawText("Saci: Mas...... por favor não conte, ", 200, 850, 60, RED);
                if(framesCounter7>2200&&framesCounter7<2600)DrawText("meu segredo a ninguém!", 200,920, 60, RED);
                if(framesCounter7>2600&&framesCounter7<3000)DrawText("Saci: o preconceio é demais nessa ", 200, 850, 60, RED);
                if(framesCounter7>2600&&framesCounter7<3000)DrawText("jsociedade opressora", 200,920, 60, RED);
                if(framesCounter7>3000&&framesCounter7<3300)DrawText("Sabrina: Qual motivo eu teria pra guardar segredo?", 200, 850, 60, WHITE);
                if(framesCounter7>3300&&framesCounter7<3700)DrawText("Saci: Você também tem seus segredos,", 200, 850, 60, RED);
                if(framesCounter7>3300&&framesCounter7<3700)DrawText(" gostaria de explanar?", 200,920, 60, RED);
                if(framesCounter7>3700&&framesCounter7<4000)DrawText("Sabrina: Bom ponto, não mexo em quem tá quieto", 200, 850, 60, WHITE);
                if(framesCounter7>4000&&framesCounter7<4300)DrawText("Sabrina: Gostei do senhor, seu segredo está guardado", 190, 850, 60, WHITE);
                if(framesCounter7>4300&&framesCounter7<4700)DrawText("Sabrina: Só me garanta que vai cuida da ", 200, 850, 60, WHITE);
                if(framesCounter7>4300&&framesCounter7<4700)DrawText("natureza, e lutar contra o desmatamento", 200,920, 60, WHITE);
                if(framesCounter7>4700&&framesCounter7<5100)DrawText("Sabrina e Saci observam juntos a paisagem.", 200,850, 60, BLACK);
                if(framesCounter7> 5100){cena=11; nextPosition.y=800;}




            }

            else if(cena>0){

                Vector2 vec = {nextPosition.x-200, nextPosition.y-250};
                AnimPlayer(Player, FrameWidth, &frame, &Mov, &x, &y);
                Rectangle Character = {FrameWidth*frame, Player.height/Mov, FrameWidth, (float) Player.height/4};     //PLAYER - INICIO DO LOOP;
                DrawTextureRec(Player, Character, vec, RAYWHITE);
                DrawRectangleRec(player, BLUE);
            } 
            

            AnimItem(texturasDeItens, jogador.itens, 5, nextPosition.x - 200, nextPosition.y - 250);
            
            EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseAudioDevice();
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}