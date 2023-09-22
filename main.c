#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

#include <stdlib.h>
#include "map.h"

int main() {
    printf("Po-C-mon!\n");

    Pokemon **equipe= calloc(6,sizeof(Pokemon));
    for (int i = 0; i < 6; ++i) {
        equipe[i]= calloc(1,sizeof(Pokemon));

    }

    equipe[0]=starter();
    Pokemon *current_pokemon=equipe[0];
    equipe[1]=newPokemon("Carapuce",88,88,48,32,43,"Eau");
    current_pokemon=change_pokemon(equipe);
    current_pokemon->hp-=losthp(current_pokemon,newPokemon("Salameche",78,78,52,21,65,"Feu"));
    printf("%s %f",equipe[1]->name,equipe[1]->hp);


    //Génération du joueur et de la map
    Player *player = newPlayer(0, 0);
    char ** map = generatePerlin();
    setSpawnPoint(map, player);
    updateMovement(map, player, ' ');

    //Boucle de jeu
    while(1){
        char command;
        fflush(stdin);
        scanf("%c", &command);
        fflush(stdin);
        int fightAgainst = updateMovement(map, player, command);
        if(fightAgainst != -1){
            printf("FIGHT AGAINST POKEMON N° : %d", fightAgainst) ;
            short isFighting = 1;
            Pokemon *fightingPokemon = newPokemon("Salameche",78,78,52,21,65,"Feu");
            int action;
            do{
                printf("Que voulez vous faire ?\n 1 - Attaquer 2 - Soigner 3 - Fuir 4 - Pokeball\n");
                do {
                    fflush(stdin);
                    scanf("%d", &action);
                    if (action > 4 || action < 1){
                        printf("Veuillez choisir une action possible");
                    }
                } while (action > 4 || action < 1);

                int roundResult;
                switch (action) {
                    case 1:
                        roundResult = fight(current_pokemon, fightingPokemon, equipe);
                        if (roundResult){
                            printf("Vous avez gagnez le combat !");
                            isFighting = 0;
                        }
                        break;
                    case 2:
                        healhp(current_pokemon->hp_max, current_pokemon->hp);
                        break;
                    case 3:

                        break;
                    case 4:

                        break;
                }

            }while (isFighting);
        }
    }
    return 0;
}
