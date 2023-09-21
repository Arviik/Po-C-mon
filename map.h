//
// Created by kmaign02 on 21/09/2023.
//

#ifndef PO_C_MON_MAP_H
#define PO_C_MON_MAP_H

typedef struct Player{
    int currentX;
    int currentY;
}Player;

struct Player* newPlayer(int startX, int startY);
void showMap(char ** map, Player *player);
void setSpawnPoint(char ** map, Player *player);
int updateMovement(char **map, Player *player, char command);
char** generateMap(Player *player);

#endif //PO_C_MON_MAP_H
