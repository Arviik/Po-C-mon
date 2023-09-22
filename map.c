#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "map.h"
#include "perlin.h"
const int x = 25;
const int y = 30;


Player *newPlayer(int startX, int startY){
    Player *player = malloc(sizeof(Player));
    player->currentX = startX;
    player->currentY = startY;
    return player;
}

char** generatePerlin(){

    char **map = calloc(x,sizeof(char *));
    for (int i = 0; i < x; ++i) {
        map[i] = calloc(y,sizeof(char));
    }

    for (int currentX = 0; currentX < x; ++currentX) {
        for (int currentY = 0; currentY < y; ++currentY) {
            float perlin = perlin2d(currentX, currentY, 0.1, 4);
            if(perlin > 0.7){
                map[currentX][currentY] = '#';
            }else if(perlin > 0.5){
                map[currentX][currentY] = ';';
            }else{
                map[currentX][currentY] = '.';
            }
        }
    }
    return map;
}

char** generateMap(){

    srand(time(0));

    char **map = calloc(x,sizeof(char *));
    for (int i = 0; i < x; ++i) {
        map[i] = calloc(y,sizeof(char));
    }

    char *randomChar = malloc(sizeof(char) * 100);

    for (int i = 0; i < 100; ++i) {
        if(i < 40
                ){
            randomChar[i] = '.';
        }else if(i < 80){
            randomChar[i] = ';';
        }else{
            randomChar[i] = '#';
        }

    }

    for (int currentX = 0; currentX < x; ++currentX) {
        for (int currentY = 0; currentY < y; ++currentY) {
            int random = rand() % 100;
            map[currentX][currentY] = randomChar[random];
            //map[currentX][currentY] = ';';
        }
    }

    return map;
}

void setSpawnPoint(char** map, Player *player){
    int randomX = rand()%x;
    int randomY = rand()%y;
    do {
        randomX = rand()%x;
        randomY = rand()%y;
        if(map[randomX][randomY] == '.'){
            player->currentX = randomX;
            player->currentY = randomY;
        }
    }while(map[randomX][randomY] != '.');
}

void changeMap(char** map, Player *player){
    srand(time(0));
    for (int currentX = 0; currentX < x; ++currentX) {
        for (int currentY = 0; currentY < y; ++currentY) {
            float perlin = perlin2d(currentX, currentY, (double)rand() / (double)RAND_MAX, 2);
            if(perlin > 0.7){
                map[currentX][currentY] = '#';
            }else if(perlin > 0.5){
                map[currentX][currentY] = ';';
            }else{
                map[currentX][currentY] = '.';
            }
        }
    }

    map[player->currentX][player->currentY] = '.';
}

void changeMapLegacy(char** map, Player *player){
    char *randomChar = malloc(sizeof(char) * 100);

    for (int i = 0; i < 100; ++i) {
        if(i < 40
                ){
            randomChar[i] = '.';
        }else if(i < 80){
            randomChar[i] = ';';
        }else{
            randomChar[i] = '#';
        }

    }

    for (int currentX = 0; currentX < x; ++currentX) {
        for (int currentY = 0; currentY < y; ++currentY) {
            int random = rand() % 100;
            map[currentX][currentY] = randomChar[random];
            //map[currentX][currentY] = ';';
        }
    }

    map[player->currentX][player->currentY] = '.';
}

void showMap(char ** map, Player *player){
    printf("\n");
    for (int currentX = 0; currentX < x; currentX++) {
        for (int currentY = 0; currentY < y; currentY++) {
            if(currentX == player->currentX && currentY == player->currentY){
                printf("@ ");
            }else{
                printf("%c ", map[currentX][currentY]);
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

int updateMovement(char** map,Player *player, char command){
    switch (command) {
        case 'z':
            if(player->currentX - 1 < 0){
                //if(map[x - 1][player->currentY] != '#') {
                    player->currentX = x - 1;
                changeMap(map, player);

                //}
            }else if(map[player->currentX - 1][player->currentY] != '#'){
                player->currentX--;
            }
            break;
        case 'q':
            if(player->currentY - 1 < 0){
                //if(map[player->currentX][y - 1] != '#') {
                    player->currentY = y - 1;
                changeMap(map, player);
                //}
            }else if(map[player->currentX][player->currentY - 1] != '#'){
                player->currentY--;
            }
            break;
        case 's':
            if(player->currentX + 1 >= x){
                //if(map[0][player->currentY] != '#') {
                    player->currentX = 0;
                changeMap(map, player);
                //}
            }else if(map[player->currentX + 1][player->currentY] != '#') {
                player->currentX++;
            }
            break;
        case'd':
            if(player->currentY + 1 >= y){
                //if(map[player->currentX][0] != '#') {
                    player->currentY = 0;
                //}
                changeMap(map, player);
            }else if(map[player->currentX][player->currentY + 1] != '#'){
                player->currentY++;
            }
            break;
        default:
            break;
    }
    showMap(map, player);

    if(map[player->currentX][player->currentY] == ';'){
        int random = rand()%5;
        if(!random){
            return rand()%11;
        }
    }

    return -1;
}