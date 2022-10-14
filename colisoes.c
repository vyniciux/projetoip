#include "raylib.h"
#include "colisoes.h"
#include <stdio.h>
#include <stdlib.h>

void criarCenas(Cenas **cenas){
    int i;

    for(i=0;i<10;i++){
        (*cenas)[i].codigoCena = i;
    }

    //-----------------------INÍCIO DA DECLARAÇÃO DAS PORTAS-----------------------------------------

    (*cenas)[0].qtdPortas = 0;
    (*cenas)[1].qtdPortas = 1;
    (*cenas)[2].qtdPortas = 2;
    (*cenas)[3].qtdPortas = 2;
    (*cenas)[4].qtdPortas = 2;
    (*cenas)[5].qtdPortas = 3;
    (*cenas)[6].qtdPortas = 1;
    (*cenas)[7].qtdPortas = 2;
    (*cenas)[8].qtdPortas = 0;
    (*cenas)[9].qtdPortas = 1;

    Porta portas1[1] = {{{1900, 535, 60, 190}, 1, 2, 1, 60.0, 690.0}};
    (*cenas)[1].portas = (Porta *) calloc((*cenas)[1].qtdPortas, sizeof(Porta));
    for(i=0;i<(*cenas)[1].qtdPortas;i++){
        ((*cenas)[1].portas)[i] = portas1[i];
    }

    Porta portas2[2] = {{{0, 625, 20, 180}, 2, 1, 1, 1795.0, 610.0},
                        {{295, 1000, 255, 20}, 2, 3, 1, 878.0, 602.0}
                       };
    (*cenas)[2].portas = (Porta *) calloc((*cenas)[2].qtdPortas, sizeof(Porta));
    for(i=0;i<(*cenas)[2].qtdPortas;i++){
        ((*cenas)[2].portas)[i] = portas2[i];
    }

    Porta portas3[2] = {{{803, 567, 150, 17}, 3, 2, 1, 415.0, 960.0},
                        {{0, 0, 10, 1080}, 3, 4, 1, 1860.0, 520.0}
                       };
    (*cenas)[3].portas = (Porta *) calloc((*cenas)[3].qtdPortas, sizeof(Porta));
    for(i=0;i<(*cenas)[3].qtdPortas;i++){
        ((*cenas)[3].portas)[i] = portas3[i];
    }

    Porta portas4[2] = {{{1910, 0, 20, 1080}, 4, 3, 1, 20.0, 520.0},
                        {{0, 0, 10, 1080}, 4, 5, 1, 1880.0, 520.0}
                       };
    (*cenas)[4].portas = (Porta *) calloc((*cenas)[4].qtdPortas, sizeof(Porta));
    for(i=0;i<(*cenas)[4].qtdPortas;i++){
        ((*cenas)[4].portas)[i] = portas4[i];
    }

    Porta portas5[3] = {{{1910, 0, 20, 1080}, 5, 4, 1, 20.0, 520.0},
                        {{0, 0, 10, 1080}, 5, 6, 1, 1880.0, 520.0},
                        {{480, 620, 135, 25}, 5, 7, 1, 945.0, 1050.0}
                       };
    (*cenas)[5].portas = (Porta *) calloc((*cenas)[5].qtdPortas, sizeof(Porta));
    for(i=0;i<(*cenas)[5].qtdPortas;i++){
        ((*cenas)[5].portas)[i] = portas5[i];
    }

    Porta portas6[1] = {{{1910, 0, 10, 1080}, 6, 5, 1, 20.0, 520.0}};
    (*cenas)[6].portas = (Porta *) calloc((*cenas)[6].qtdPortas, sizeof(Porta));
    for(i=0;i<(*cenas)[6].qtdPortas;i++){
        ((*cenas)[6].portas)[i] = portas6[i];
    }

    Porta portas7[2] = {{{1450, 220, 255, 5}, 7, 9, 1, 1685.0, 965.0},
                        {{0, 0, 10, 1080}, 7, 8, 1, 1880.0, 520.0}
                       };
    (*cenas)[7].portas = (Porta *) calloc((*cenas)[7].qtdPortas, sizeof(Porta));
    for(i=0;i<(*cenas)[7].qtdPortas;i++){
        ((*cenas)[7].portas)[i] = portas7[i];
    }

    Porta portas9[1] = {{{1585, 1050, 240, 10}, 9, 7, 1, 1555.0, 235.0}};
    (*cenas)[9].portas = (Porta *) calloc((*cenas)[9].qtdPortas, sizeof(Porta));
    for(i=0;i<(*cenas)[9].qtdPortas;i++){
        ((*cenas)[9].portas)[i] = portas9[i];
    }

    //-----------------------FIM DA DECLARAÇÃO DAS PORTAS-----------------------------------------

    //-----------------------INÍCIO DA DECLARAÇÃO DOS OBSTÁCULOS-----------------------------------------
    (*cenas)[0].qtdObstaculos = 0;
    (*cenas)[1].qtdObstaculos = 3;
    (*cenas)[2].qtdObstaculos = 3;
    (*cenas)[3].qtdObstaculos = 5;
    (*cenas)[4].qtdObstaculos = 0;
    (*cenas)[5].qtdObstaculos = 3;
    (*cenas)[6].qtdObstaculos = 4;
    (*cenas)[7].qtdObstaculos = 0;
    (*cenas)[8].qtdObstaculos = 0;
    (*cenas)[9].qtdObstaculos = 4;

    Rectangle obstaculos1[3]= {{160, 220, 370, 505}, 
                               {710, 220, 220, 155}, 
                               {1545, 220, 255, 105}
                              };
    (*cenas)[1].obstaculos = (Rectangle *) calloc((*cenas)[1].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(*cenas)[1].qtdObstaculos; i++){
        ((*cenas)[1].obstaculos)[i] = obstaculos1[i];
    }

    Rectangle obstaculos2[3] = {{1150, 295, 180, 170}, 
                                {1665, 295, 176, 170},
                                {1365, 265, 260, 185}
                               };
    (*cenas)[2].obstaculos = (Rectangle *) calloc((*cenas)[2].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(*cenas)[2].qtdObstaculos; i++){
        ((*cenas)[2].obstaculos)[i] = obstaculos2[i];
    }

    Rectangle obstaculos3[5] = {{1350, 220, 370, 275}, 
                                {1720, 220, 130, 220},
                                {985, 220, 365, 450},
                                {618, 220, 182, 450},
                                {618, 220, 732, 345}
                               };
    (*cenas)[3].obstaculos = (Rectangle *) calloc((*cenas)[3].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(*cenas)[3].qtdObstaculos; i++){
        ((*cenas)[3].obstaculos)[i] = obstaculos3[i];
    }

    Rectangle obstaculos5[3] = {{20, 220, 115, 80}, 
                                {135, 220, 840, 420},
                                {975, 220, 320, 315},
                               };
    (*cenas)[5].obstaculos = (Rectangle *) calloc((*cenas)[5].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(*cenas)[5].qtdObstaculos; i++){
        ((*cenas)[5].obstaculos)[i] = obstaculos5[i];
    }

    Rectangle obstaculos6[4] = {{440, 535, 145, 145}, 
                               {870, 535, 138, 145},
                               {425, 800, 138, 145},
                               {855, 810, 138, 140}
                              };
    (*cenas)[6].obstaculos = (Rectangle *) calloc((*cenas)[6].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(*cenas)[6].qtdObstaculos; i++){
        ((*cenas)[6].obstaculos)[i] = obstaculos6[i];
    }


    Rectangle obstaculos9[4] = {{1295, 220, 130, 225}, 
                               {1295, 665, 130, 415},
                               {440, 220, 365, 475},
                               {75, 220, 250, 220}
                              };
    (*cenas)[9].obstaculos = (Rectangle *) calloc((*cenas)[9].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(*cenas)[9].qtdObstaculos; i++){
        ((*cenas)[9].obstaculos)[i] = obstaculos9[i];
    }
    //-----------------------INÍCIO DA DECLARAÇÃO DOS OBSTÁCULOS-----------------------------------------
}

int colisao(Rectangle player, Cenas cena){
    int i;
    if(cena.qtdObstaculos==0) return 0;
    for(i=0;i<cena.qtdObstaculos;i++){
        if(CheckCollisionRecs(player, cena.obstaculos[i])) return 1;
    }
    return 0;
}

int trocarCena(Rectangle player, float *x, float *y, Cenas cena, int *cenaAtual){
    int i;
    for(i=0;i<cena.qtdPortas;i++){
        if(CheckCollisionRecs(player, (cena.portas[i]).area)==1){
            if((cena.portas[i]).check==1) {
                *cenaAtual = (cena.portas[i]).destino;
                *x = (cena.portas[i]).destinoX;
                *y = (cena.portas[i]).destinoY;
                return 1;
            }
        }
    }
    return 0;
}
