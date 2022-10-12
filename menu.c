#include "raylib.h"
#include <stdio.h>

#define NUM_FRAMES  3


int main(void)
{
 
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "menu");
    
    typedef enum TelasIniciais {TELADECARREGAMENTO=0, JOGAR, SOBRE, INSTRUCOES} TelasIniciais;
    
    
    TelasIniciais currentScreen = TELADECARREGAMENTO;
    
    
    SetTargetFPS(60);           
    
    //carregamento das texturas
    
    Texture2D Grama = LoadTexture("C:/Users/Giovanna Silva/Downloads/menu003.png");
    Texture2D Casa = LoadTexture("C:/Users/Giovanna Silva/Downloads/menu004.png");
    Texture2D Lupa = LoadTexture("C:/Users/Giovanna Silva/Downloads/lupa.png");
    Texture2D Ceu = LoadTexture("C:/Users/Giovanna Silva/Downloads/menu001.png");
    Texture2D Nuvens = LoadTexture("C:/Users/Giovanna Silva/Downloads/menu005.png");
    Texture2D TelaBege = LoadTexture("C:/Users/Giovanna Silva/Downloads/telabege.png");
    Texture2D BotaoStart = LoadTexture("C:/Users/Giovanna Silva/Downloads/botaojogar.png");
    Texture2D BotaoSobre= LoadTexture("C:/Users/Giovanna Silva/Downloads/botaosobre.png");
    Texture2D BotaoInst = LoadTexture ("C:/Users/Giovanna Silva/Downloads/botaoinst.png");
    Texture2D BotaoFechar = LoadTexture("C:/Users/Giovanna Silva/Downloads/botaoclose.png");
    
    //usado para animacao das nuvens
    float movnuvens = 0.0f;
    
    //Botao Jogar:
    
    float frameHeightstart = (float)BotaoStart.height/NUM_FRAMES;
    
    Rectangle sourceRecstart = {0, 0,(float)BotaoStart.width, frameHeightstart+55};
    
    Rectangle btnStartrec = { 150, 350,(float)BotaoStart.width, frameHeightstart+55};
    
    int btnstart = 0;
    
    int btnActionstart = false;
    
 
    //Botao Sobre:
    
    float frameHeightsobre = (float)BotaoStart.height/NUM_FRAMES;
    
    Rectangle sourceRecsobre = {0, 0,(float)BotaoSobre.width, frameHeightsobre+55};
    
    Rectangle btnSobrerec = { 150, 450,(float)BotaoSobre.width, frameHeightsobre+55};
    
    int btnsobre = 0;
    
    int btnActionsobre = false;
    
    //Botao Instrucoes:
    
    float frameHeightinst = (float)BotaoInst.height/NUM_FRAMES;
    
    Rectangle sourceRecinst = {0, 0,(float)BotaoInst.width, frameHeightinst+55};
    
    Rectangle btnInstrec = { 150, 545,(float)BotaoInst.width, frameHeightinst+55};
    
    int btninst = 0;
    
    int btnActioninst = false;
    
    //Botao Fechar:
    
    float frameHeightfechar = (float)BotaoFechar.height/NUM_FRAMES;
    
    Rectangle sourceRecfechar = {0, 0,(float)BotaoFechar.width, frameHeightfechar+20};
    
    Rectangle btnFecharrec = { 1180, 40,(float)BotaoFechar.width, frameHeightfechar+20};
    
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
    
    const char messagejogar1[128] = "Fulano sempre desconfiou que seu vizinho, Sicrano, escondia algo.";
    const char messagejogar2[128] = "Certo dia, Fulano percebeu que Sicrano havia saido e como desde pequeno";
    const char messagejogar3[128] = "sempre foi muito curioso, resolveu invadir a casa dele a fim de encontrar";
    const char messagejogar4[128] = "alguma coisa que confirmasse sua desconfiança."; 
    const char messagejogar5[128] = "Para isso, ele precisa desvendar uma serie de desafios antes que Sicrano chegue e o pegue no flagra!";
    const char messagejogar6[128] = "AJUDE FULANO A MATAR SUA CURIOSIDADE!!";
    
    
    const char messagesobre1[128] = "Este jogo é um projeto para disciplina de Introdução a";
    const char messagesobre2[128] = "Programação, com o objetivo principal aplicar os conhecimentos";
    const char messagesobre3[128] = "da linguagem C e da biblioteca Raylib.";
   
    
    const char messageinst1[128] = "PARA QUE *nome do personagem principal* ANDE PARA DIREITA APERTE : D";
    const char messageinst2[128] = "PARA QUE *nome do personagem principal* ANDE PARA ESQUERDA APERTE : A";
    const char messageinst3[128] = "PARA QUE *nome do personagem principal* ANDE PARA CIMA APERTE : W";
    const char messageinst4[128] = "PARA QUE *nome do personagem principal* ANDE PARA BAIXO APERTE : S";
    const char messageinst5[128] = "PARA QUE *nome do personagem principal* INTERAJA COM ALGO APERTE : E";
                                 
    Vector2 PosMouse = { 0.0f, 0.0f };
    
    while (!WindowShouldClose())   
    {
        
        switch(currentScreen)
        {
       
            case TELADECARREGAMENTO:
            {
                //animacao das nuvens:
                movnuvens -= 0.3f;
       
                if (movnuvens <= -Nuvens.width*2) movnuvens = 0;
       
                //checando colisao do mouse com os botoes:
                
                PosMouse = GetMousePosition();
                //colisao com o botao jogar    
                if (CheckCollisionPointRec(PosMouse, btnStartrec)){
   
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnstart = 2; currentScreen = JOGAR;}
                    else {btnstart = 1;}
            
                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnActionstart = true;   
                }
       
                else btnstart = 0;
                
                sourceRecstart.y = btnstart*(frameHeightstart-30);
       
                //colisao com o botao sobre
       
                if (CheckCollisionPointRec(PosMouse, btnSobrerec)){
   
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnsobre = 2;currentScreen = SOBRE;}
                    else {btnsobre = 1;}
            
                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActionsobre = true;}   
                }
       
                else btnsobre = 0;
                sourceRecsobre.y = btnsobre*(frameHeightsobre-30);
       
                //colisao com o botao instrucoes
       
                if (CheckCollisionPointRec(PosMouse, btnInstrec)){
   
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btninst = 2; currentScreen=INSTRUCOES;}
                    else btninst = 1;
            
                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActioninst = true;}   
                }
       
                else btninst = 0;
                
                sourceRecinst.y = btninst*(frameHeightinst-30);
        
            }break;
       
            case JOGAR:
            {
                //letrinha por letrinha
                framesCounter1++;
                
                if(framesCounter1 > 245){framesCounter2++;}
                if(framesCounter2 > 245){framesCounter3++;}
                if(framesCounter3 > 245){framesCounter4++;}
                if(framesCounter4 > 255){framesCounter5++;}
                if(framesCounter5 > 293){framesCounter6++;}
                
                iniciajogo = true;
            }break;
       
            case SOBRE:
            {
                PosMouse = GetMousePosition();
                
                if (CheckCollisionPointRec(PosMouse, btnFecharrec)){
   
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnfechar = 2; currentScreen=TELADECARREGAMENTO;}
                    else btnfechar = 1;
            
                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActionfechar = true;}   
                }
       
                else btnfechar = 0;
                
                sourceRecfechar.y = btnfechar*(frameHeightfechar-10);
                
            }break;
       
            case INSTRUCOES:
            {
             PosMouse = GetMousePosition();
                
                if (CheckCollisionPointRec(PosMouse, btnFecharrec)){
   
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnfechar = 2; currentScreen=TELADECARREGAMENTO;}
                    else btnfechar = 1;
            
                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActionfechar = true;}   
                }
       
                else btnfechar = 0;
                
                sourceRecfechar.y = btnfechar*(frameHeightfechar-10);
            
            }break;
       
            default: break;
        }
       
       
        BeginDrawing();

            ClearBackground(BLUE);
            
            switch(currentScreen)
            {
                case TELADECARREGAMENTO:
                {
                    
                    DrawTexture(Grama, 0, 0, RAYWHITE); //textura da grama -> teladecarregamento 
                    DrawTextureEx(Nuvens, (Vector2) {movnuvens, -100}, 0.0f, 2.0f, WHITE);//textura das nuvens->telacarreg
                    DrawTextureEx(Nuvens, (Vector2){ Nuvens.width*2 + movnuvens, -100}, 0.0f, 2.0f, WHITE);
                    DrawTexture(Casa, 0, 0, RAYWHITE);//textura da casa
                    DrawTextureRec(BotaoStart, sourceRecstart, (Vector2){ btnStartrec.x, btnStartrec.y}, WHITE);//texturabotao
                    DrawTextureRec(BotaoSobre, sourceRecsobre, (Vector2){ btnSobrerec.x, btnSobrerec.y}, WHITE);//texturabotao
                    DrawTextureRec(BotaoInst, sourceRecinst, (Vector2){ btnInstrec.x, btnInstrec.y}, WHITE);//texturabotao
                  
                    //mudando cor do botao qnd passa o mouse por cima
                    if(btnstart){DrawTextureRec(BotaoStart, sourceRecstart, (Vector2){ btnStartrec.x, btnStartrec.y}, LIGHTGRAY);}
                   
                    if(btnsobre){DrawTextureRec(BotaoSobre, sourceRecsobre, (Vector2){ btnSobrerec.x, btnSobrerec.y},LIGHTGRAY);}
                    
                    if(btninst) {DrawTextureRec(BotaoInst, sourceRecinst, (Vector2){ btnInstrec.x, btnInstrec.y},LIGHTGRAY);}
                    
                    
                }break;
                
                case JOGAR:{
                
                //carregando texturas da tela que aparece antes do jogo comecar
                
                DrawTexture(Ceu, 0, 0, BLACK);
                DrawTexture(TelaBege, 0, 0, WHITE);
                DrawText(TextSubtext(messagejogar1, 0, framesCounter1/3), 70, 150, 25, BLACK);
                DrawText(TextSubtext(messagejogar2, 0, framesCounter2/3), 70, 190, 25, BLACK);
                DrawText(TextSubtext(messagejogar3, 0, framesCounter3/3), 70, 230, 25, BLACK);
                DrawText(TextSubtext(messagejogar4, 0, framesCounter4/3), 70, 270, 25, BLACK);
                DrawText(TextSubtext(messagejogar5, 0, framesCounter5/3), 73, 400, 21, DARKBROWN);
                DrawText(TextSubtext(messagejogar6, 0, framesCounter6/3), 120, 500, 45, RED);
                
                
                
                }break;    
                case SOBRE:{
                    
                    //texturas da tela "sobre"
                    
                    DrawTexture(Ceu, 0, 0, BROWN);
                    DrawTexture(TelaBege, 0, 0, WHITE);
                    DrawTexture(Lupa, 760, 50, WHITE);
                    DrawText("SOBRE", 510, 50, 70, BLACK);
                    DrawText(messagesobre1, 200, 160, 30, DARKBROWN);
                    DrawText(messagesobre2, 200, 210, 30, DARKBROWN);
                    DrawText(messagesobre3, 200, 260, 30, DARKBROWN);
                    DrawTextureRec(BotaoFechar, sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y}, WHITE);
                    
                    //mudando cor do botao "fechar"
                    if(btnfechar){DrawTextureRec(BotaoFechar, sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y},RED);}
                   
                    
                }break;
                
                case INSTRUCOES:
                {
                    //carregando texturas da tela de instrucoes
                    
                    DrawTexture(Ceu, 0, 0, DARKBROWN);
                    DrawTexture(TelaBege, 0, 0, WHITE);
                    DrawText("INSTRUçÕES", 370, 50, 70,BLACK);
                    DrawTexture(Lupa, 840, 50, WHITE);
                    DrawText(messageinst1, 150, 200, 25, BLACK);
                    DrawText(messageinst2, 150, 260, 25, BLACK);
                    DrawText(messageinst3, 150, 320, 25, BLACK);
                    DrawText(messageinst4, 150, 380, 25, BLACK);
                    DrawText(messageinst5, 150, 440, 25, BLACK);
                    DrawTextureRec(BotaoFechar, sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y}, WHITE);
                    
                    //mudando cor do botao "fechar"
                    if(btnfechar){DrawTextureRec(BotaoFechar, sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y},RED);}
                    
                }break;
                
                  
            }  
            
        EndDrawing();
    }  
    
   
    UnloadTexture(Grama);
    UnloadTexture(Casa);
    UnloadTexture(Nuvens);
    UnloadTexture(BotaoStart);
    UnloadTexture(BotaoSobre);
    UnloadTexture(BotaoInst);
    UnloadTexture(BotaoFechar);
    UnloadTexture(Lupa);
    UnloadTexture(TelaBege);
    UnloadTexture(Ceu);
    
    CloseWindow();        
   

    return 0;
}