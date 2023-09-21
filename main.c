#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main() {
    printf("Po-C-mon!\n");

    //Génération du joueur et de la map
    Player *player = newPlayer(0, 0);
    char ** map = generateMap(player);
    setSpawnPoint(map, player);
    updateMovement(map, player, ' ');

    //Boucle de jeu
    while(1){
        char command;
        fflush(stdin);
        scanf("%c", &command);
        fflush(stdin);
        printf("FIGHT AGAINST POKEMON N° : %d", updateMovement(map, player, command));
    };
    return 0;
}
