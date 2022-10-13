#include "raylib.h"
#include "colisoes.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Demo");

    Vector2 position = { (float)screenWidth/2 + 100, (float)screenHeight/2};
    Vector2 nextPosition = { (float)screenWidth/2 + 100, (float)screenHeight/2};

    Texture mn1 = LoadTexture("assets/Menu/menu001.png");
    Texture mn2 = LoadTexture("assets/Menu/menub001.png");
    Texture mn3 = LoadTexture("assets/Menu/menu003.png");
    Texture mn4 = LoadTexture("assets/Menu/menu004.png");
    Texture mn5 = LoadTexture("assets/Menu/menu005.png");



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
    Texture quarto = LoadTexture("assets/img0012.png");

    Cenas *cenas;
    cenas = (Cenas *) malloc (10 * sizeof(Cenas));
    criarCenas(&cenas); 
    
    //-------------------------------------------------------------------
    int cenaAtual = 6;
    //-------------------------------------------------------------------

    Rectangle player = {position.x, position.y, 30, 40};
    int cenaja = 1;

    // Up=0,Donw=1,Left=2,Right=3
    float Vel[4]={0,1,2,3};
    float VelPadrao = 5;


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
        if (IsKeyDown(KEY_P)) cenaAtual=0;

        Vel[0]=VelPadrao;
        Vel[1]=VelPadrao;
        Vel[2]=VelPadrao;
        Vel[3]=VelPadrao;

        player.x = nextPosition.x;
        player.y = nextPosition.y;

        if(colisao(player, cenas[cenaAtual])==1){
          player.x = position.x;
          player.y = position.y;
          nextPosition.x = position.x;
          nextPosition.y = position.y;
        }
        else{
          position.x = nextPosition.x;
          position.y = nextPosition.y;
        }



        printf("X=%.1f ",position.x);
        printf("Y=%.1f ",position.y);
        printf("Cena=%d\n",cenaAtual);
        //----------------------------------------------------------------------------------

        // Draw

        //----------------------------------------------------------------------------------
        BeginDrawing();

             ClearBackground(BLUE);
                   
                 if(cenaAtual==0 ){

                    int xcloud = 0;
                    
                     xcloud++;
                     if(xcloud>1850){xcloud=-1920;}

                     DrawTexture(mn1,0,0,WHITE);
                     DrawTexture(mn3,0,0,WHITE);
                     DrawTexture(mn5,xcloud,0,WHITE);
                     DrawTexture(mn5,-1920+xcloud,0,WHITE);
                     DrawTexture(mn4,0,0,WHITE);
                     DrawTexture(mn2,0,0,WHITE);
  
        }
            
            else if(cenaAtual == 1){

                DrawTexture(fundo,0,0,WHITE);
                DrawTexture(fundo1,0,0,WHITE);
                DrawRectangleRec(player, BLUE);
            }
        

            else  if(cenaAtual == 2){
                DrawTexture(sala,0,0,WHITE);
                DrawTexture(sala1,0,0,WHITE);
                DrawRectangleRec(player, BLUE);
        
            }


            else if(cenaAtual == 3){

                DrawTexture(fora,0,0,WHITE );
                DrawTexture(fora1,0,0,WHITE );
                DrawRectangleRec(player, BLUE);

            }

              else if(cenaAtual == 4){

                DrawTexture(fora2,0,0,WHITE );
                DrawRectangleRec(player, BLUE);

            }

              else if(cenaAtual == 5){

                DrawTexture(casavizin,0,0,WHITE );
                DrawTexture(casavizin1,0,0,WHITE );
                DrawRectangleRec(player, BLUE);

            }
             
            else if(cenaAtual == 6){

                DrawTexture(fora3,0,0,WHITE);
                DrawRectangleRec(player, BLUE);
                DrawTexture(fora4,0,0,WHITE);
            }
              else if(cenaAtual == 7){

                DrawTexture(salav,0,0,WHITE );
                DrawRectangleRec(player, BLUE);

            }
              else if(cenaAtual == 8){

                DrawTexture(cozinhav,0,0,WHITE );
                DrawRectangleRec(player, BLUE);

            }
              else if(cenaAtual == 9){

                DrawTexture(quarto,0,0,WHITE );
                DrawRectangleRec(player, BLUE);
            }
              else if(cenaAtual == 10){

                DrawTexture(fora,0,0,BLUE );
                DrawRectangleRec(player, BLUE);

            }
            int x = colisao(player, cenas[cenaAtual]);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
