#include "raylib.h"
#include <stdio.h>
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


    

    int cena = 0;
    
    int cenaja = 1;

    float VelUp = 5;
    float VelDonw = 5;
    float VelLeft = 5;
    float VelRight = 5;
    float VelPadrao = 5;

    int xcloud = 0;

    SetTargetFPS(60);           
  

    
    while (!WindowShouldClose())   
    {
        // Update
        //---------------------------------------0------------------------------------------
        // TODO: Update your variables here

        if (IsKeyDown(KEY_RIGHT)&& position.x<1850) position.x += VelRight;
        if (IsKeyDown(KEY_LEFT)&& position.x>20) position.x -= VelLeft;
        if (IsKeyDown(KEY_UP)&& position.y>220) position.y -= VelUp;
        if (IsKeyDown(KEY_DOWN)&& position.y<1050) position.y += VelDonw;
        if (IsKeyDown(KEY_M)) {VelPadrao+=0.5;}
        if (IsKeyDown(KEY_N)){VelPadrao-=0.5;}
        if (IsKeyDown(KEY_P)) cena=0;

        VelUp=VelPadrao;
        VelLeft=VelPadrao;
        VelDonw=VelPadrao;
        VelRight=VelPadrao;


        xcloud++;
        if(xcloud>1850){xcloud=-1920;}

        if(cena == 0){

            VelUp=0;
            VelLeft=0;
            VelDonw=0;
            VelRight=0;
            if (IsKeyDown(KEY_S)) {cena=cenaja;VelUp=5;VelLeft=5;VelDonw=5;VelRight=5;}

        }

        else  if(cena == 1){

            cenaja=1;

            if(position.x<=25){

               // cena = 0;
                //position.x=1825;

            }

            else if(position.x>=1830){

                if(position.y<=650&&position.y>=460){
                cena = 2;
                position.x=25;
                position.y=720;}

            }

            else if(position.y>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(position.y<=230){

             //  cena = 1;
              //  position.y=1040;

            }


        }
      
        else  if(cena == 2){

            cenaja=2;

            if(position.x<=25){

                 if(position.y<=800&&position.y>=560){
                cena = 1;
                position.x=1825;
                position.y=630;
                }

            }

            else if(position.x>=1830){

                //cena = 2;
               // position.x=20;

            }

            else if(position.y>=1045){

                 if(position.x<=590&&position.x>=350){
                cena = 3;
                position.y=545;
                position.x=905;
                 }
            }

            else if(position.y<=230){

             //  cena = 1;
              //  position.y=1040;

            }


        }

        else  if(cena == 3){

            cenaja=3;

            if(position.x<=25){

                cena = 4;
                position.x=1825;

            }

            else if(position.x>=1830){

                //cena = 2;
               // position.x=20;

            }

            else if(position.y>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(position.y<=489){

             if(position.x<=950&&position.x>=830){
              cena = 2;
              position.y=1040;
              position.x=434;
             }

            }

            else if(position.y<=627){

                if(position.x>=655&&position.x<=835){

                    VelUp=0;
                }
               // else VelUp = 5;
                if(position.x>=1027&&position.x<=1310){

                    VelUp=0;
                }
               // else VelUp = 5;



            }


        }
        
        else  if(cena == 4){

            cenaja=4;

            if(position.x<=25){

                cena = 5;
                position.x=1825;

            }

            else if(position.x>=1830){

                cena = 3;
                position.x=20;

            }

            else if(position.y>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(position.y<=230){

              //cena = 2;
              //position.y=1040;

            }


        }

        else  if(cena == 5){

            cenaja=5;

            if(position.x<=25){

                cena = 6;
                position.x=1825;

            }

            else if(position.x>=1830){

                cena = 4;
                position.x=20;

            }

            else if(position.y>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(position.y<=230){

              cena = 7;
              position.y=1040;

            }


        }

        else  if(cena == 6){

            cenaja=6;

            if(position.x<=25){

               // cena = 4;
              //  position.x=1825;

            }

            else if(position.x>=1830){

                cena = 5;
                position.x=20;

            }

            else if(position.y>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(position.y<=230){

             // cena = 7;
             // position.y=1040;

            }


        }
        
        else  if(cena == 7){

            cenaja=7;

            if(position.x<=25){

                cena = 8;
                position.x=1825;

            }

            else if(position.x>=1830){

              //  cena = 5;
               // position.x=20;

            }

            else if(position.y>=1045){

                cena = 5;
               position.y=676;
               position.x=534;

            }

            else if(position.y<=230){

              if(position.x>=1487&&position.x<=1743){ 
              cena = 9;
              position.y=1040;
              position.x=1724;
              }

            }


        }
        
        else  if(cena == 8){

            cenaja=8;

            if(position.x<=25){

                //cena = 4;
                //position.x=1825;

            }

            else if(position.x>=1830){

                cena = 7;
                position.x=20;

            }

            else if(position.y>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(position.y<=230){

              //cena = 2;
              //position.y=1040;

            }


        }

        else  if(cena == 9){

            cenaja=9;

            if(position.x<=25){

                //cena = 4;
                //position.x=1825;

            }

            else if(position.x>=1830){

                //cena = 2;
               // position.x=20;

            }

            else if(position.y>=1045){

                if(position.x>=1500&&position.x<=1760){ 

                cena = 7;
                position.y=255;
                position.x=1578;
                }

            }

            else if(position.y<=230){

              cena = 2;
              position.y=1040;

            }


        }

        printf("X=%.1f ",position.x);
        printf("Y=%.1f ",position.y);
        printf("Cena=%d\n",cena);
        //----------------------------------------------------------------------------------

        // Draw

        //----------------------------------------------------------------------------------
        BeginDrawing();

             ClearBackground(BLUE);
                   
            if(cena==0 ){

                     DrawTexture(mn1,0,0,WHITE);
                     DrawTexture(mn3,0,0,WHITE);
                     DrawTexture(mn5,xcloud,0,WHITE);
                     DrawTexture(mn5,-1920+xcloud,0,WHITE);
                     DrawTexture(mn4,0,0,WHITE);
                     DrawTexture(mn2,0,0,WHITE);
  
        }
            
            else if(cena == 1){

                DrawTexture(fundo,0,0,WHITE);
                 DrawTexture(fundo1,0,0,WHITE);
                DrawCircle(position.x,position.y,50,RED);
                
                
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
                 DrawCircle(position.x,position.y,50,GREEN);

            }
              else if(cena==9){

                DrawTexture(quarto,0,0,WHITE );
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
