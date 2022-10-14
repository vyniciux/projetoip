#ifndef PLAYER
#define PLAYER
#include <stdio.h>
#include <stdbool.h>

typedef struct Player {
    float posX; // = position.x
    float posY;
    bool key[5]; //numero de fases
    bool itens[5];
} Player;

#endif
