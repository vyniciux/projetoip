#include "raylib.h"
#include "colisoes.h"
#include <stdio.h>

float colisao(int* cena,float* x,float* y,float* Vel){

     if(*cena == 0){

            Vel[0]=0;
            Vel[1]=0;
            Vel[2]=0;
            Vel[3]=0;
            if (IsKeyDown(KEY_S)) {*cena=1;Vel[0]=5;Vel[1]=5;Vel[2]=5;Vel[3]=5;}
            printf("indo");
        }

        else  if(*cena == 1){

            if(*x<=25){

               // cena = 0;
                //position.x=1825;

            }

            else if(*x>=1830){

                if(*y<=650&&*y>=460){

                cena[0] = 2;
                *x=25;
                *y=720;
                
                }

            }

            else if(*y>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(*y<=230){

             //  cena = 1;
              //  position.y=1040;

            }


        }
      
        else  if(*cena == 2){
      
            if(*x<=25){

                 if(*y<=800&&*y>=560){
                *cena = 1;
                *x=1825;
                *y=630;
                }

            }

            else if(*x>=1830){

                //cena = 2;
               // position.x=20;

            }

            else if(*y>=1045){

                 if(*x<=590&&*x>=350){
                *cena = 3;
                *y=545;
                *x=905;
                 }
            }

            else if(*y<=230){

             //  cena = 1;
              //  position.y=1040;

            }


        }

        else  if(*cena == 3){

           

            if(*x<=25){

                *cena = 4;
                *x=1825;

            }

            else if(*x>=1830){

                //cena = 2;
               // position.x=20;

            }

            else if(*y>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(*y<=489){

             if(*x<=950&&*x>=830){
              *cena = 2;
              *y=1040;
              *x=434;
             }

            }

            else if(*y<=627){

                if(*x>=655&&*x<=835){

                    Vel[0]=0;
                }
               // else VelUp = 5;
                if(*x>=1027&&*x<=1310){

                    Vel[0]=0;
                }
               // else VelUp = 5;



            }


        }
        
        else  if(*cena == 4){

            
            if(*x<=25){

                *cena = 5;
               *x=1825;

            }

            else if(*x>=1830){

                *cena = 3;
                *x=20;

            }

            else if(*y>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(*y<=230){

              //cena = 2;
              //position.y=1040;

            }


        }

        else  if(*cena == 5){

            

            if(*x<=25){

                *cena = 6;
               *x=1825;

            }

            else if(*x>=1830){

                *cena = 4;
                *x=20;

            }

            else if(*x>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(*y<=230){

              *cena = 7;
             *y=1040;

            }


        }

        else  if(*cena == 6){

            

            if(*x<=25){

               // cena = 4;
              //  position.x=1825;

            }

            else if(*x>=1830){

                *cena = 5;
                *x=20;

            }

            else if(*y>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(*y<=230){

             // cena = 7;
             // position.y=1040;

            }


        }
       
        else  if(*cena == 7){

          
            if(*x<=25){

                *cena = 8;
                *x=1825;

            }

            else if(*x>=1830){

              //  cena = 5;
               // position.x=20;

            }

            else if(*y>=1045){

                *cena = 5;
               *y=676;
               *x=534;

            }

            else if(*y<=230){

              if(*x>=1487&&*x<=1743){ 
              *cena = 9;
              *y=1040;
              *x=1724;
              }

            }


        }
        
        else  if(*cena == 8){

            

            if(*x<=25){

                //cena = 4;
                //position.x=1825;

            }

            else if(*x>=1830){

                *cena = 7;
                *x=20;

            }

            else if(*y>=1045){

               // cena = 3;
                //position.y=255;

            }

            else if(*y<=230){

              //cena = 2;
              //position.y=1040;

            }


        }

        else  if(*cena == 9){

           

            if(*x<=25){

                //cena = 4;
                //position.x=1825;

            }

            else if(*x>=1830){

                //cena = 2;
               // position.x=20;

            }

            else if(*y>=1045){

                if(*x>=1500&&*x<=1760){ 

                *cena = 7;
                *y=255;
                *x=1578;
                }

            }

            else if(*y<=230){

              *cena = 2;
              *y=1040;

            }


        }

    
    
    


}


