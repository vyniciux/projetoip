#include "raylib.h"
#include "colisoes.h"
#include <stdio.h>
#include <stdlib.h>

void criarCenas(Cenas **cenas){
    int i;

    for(i=0;i<10;i++){
        (*cenas)[i].codigoCena = i;
    }
//1820 535   1820 725  1 porta 
//20 625 30 805   180 = delta    2 portas  295 1000 550 1000    delta=255

    (*cenas)[0].qtdPortas = 0;
    (*cenas)[1].qtdPortas = 1;
    (*cenas)[2].qtdPortas = 2;
    (*cenas)[3].qtdPortas = 2;
    (*cenas)[4].qtdPortas = 0;
    (*cenas)[5].qtdPortas = 0;
    (*cenas)[6].qtdPortas = 0;
    (*cenas)[7].qtdPortas = 0;
    (*cenas)[8].qtdPortas = 0;
    (*cenas)[9].qtdPortas = 0;

    Porta portas1[1] = {{{1860, 535, 60, 190}, 1, 2, 1, 75.0, 690.0}};
    (*cenas)[1].portas = (Porta *) calloc((*cenas)[1].qtdPortas, sizeof(Porta));
    for(i=0;i<(*cenas)[1].qtdPortas;i++){
        ((*cenas)[1].portas)[i] = portas1[i];
    }

    Porta portas2[2] = {{{20, 625, 40, 180}, 2, 1, 1, 1795.0, 610.0},
                        {{295, 1000, 255, 40}, 2, 3, 1, 878.0, 602.0}
                       };
    (*cenas)[2].portas = (Porta *) calloc((*cenas)[2].qtdPortas, sizeof(Porta));
    for(i=0;i<(*cenas)[2].qtdPortas;i++){
        ((*cenas)[2].portas)[i] = portas2[i];
    }

    Porta portas3[2] = {{{803, 567, 150, 17}, 3, 2, 1, 415.0, 960.0},
                        {{0, 0, 30, 1080}, 3, 4, 1, 1880.0, 520.0}
                       };
    (*cenas)[3].portas = (Porta *) calloc((*cenas)[3].qtdPortas, sizeof(Porta));
    for(i=0;i<(*cenas)[3].qtdPortas;i++){
        ((*cenas)[3].portas)[i] = portas3[i];
    }

    (*cenas)[0].qtdObstaculos = 0;
    (*cenas)[1].qtdObstaculos = 3;
    (*cenas)[2].qtdObstaculos = 3;
    (*cenas)[3].qtdObstaculos = 5;
    (*cenas)[4].qtdObstaculos = 0;
    (*cenas)[5].qtdObstaculos = 3;
    (*cenas)[6].qtdObstaculos = 4;
    (*cenas)[7].qtdObstaculos = 0;
    (*cenas)[8].qtdObstaculos = 0;
    (*cenas)[9].qtdObstaculos = 0;

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
