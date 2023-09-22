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
    Pokemon **pokedex= calloc(30,sizeof(Pokemon));
    for (int i = 0; i < 30; ++i) {
        equipe[i]= calloc(1,sizeof(Pokemon));

    }
    equipe[0]=starter();
    Pokemon *current_pokemon=equipe[0];

    //Génération du joueur et de la map
    Player *player = newPlayer(0, 0);
    char ** map = generatePerlin();
    setSpawnPoint(map, player);
    updateMovement(map, player, ' ');


    short gameOver = 0;
    //Boucle de jeu
    while(!gameOver){
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
                        printf("\nVeuillez choisir une action possible\n");
                    }
                } while (action > 4 || action < 1);

                int roundResult = 0;
                switch (action) {
                    case 1:
                        roundResult = fight(current_pokemon, fightingPokemon, equipe);
                        if (roundResult == 1){
                            printf("\nVous avez gagnez le combat !");
                            isFighting = 0;
                        }else if(roundResult == -1){
                            printf("\nVous n'avez plus de pokemon dans votre equipe!\n           - GAME OVER - ");
                            isFighting = 0;
                            gameOver = 1;

                        }
                        break;
                    case 2:
                        roundResult = healhp(current_pokemon, fightingPokemon, equipe);
                        if(roundResult == -1){
                            printf("\nVous n'avez plus de pokemon dans votre equipe!\n           - GAME OVER - ");
                            isFighting = 0;
                            gameOver = 1;
                        }
                        break;
                    case 3:
                        roundResult = run_away(current_pokemon, fightingPokemon, equipe);
                        if (roundResult == 1){
                            printf("\nVous avez fuis le combat !");
                            isFighting  = 0;
                        }else if(roundResult == -1){
                            printf("\nVous n'avez plus de pokemon dans votre equipe!\n           - GAME OVER - ");
                            isFighting = 0;
                            gameOver = 1;
                        }
                        break;
                    case 4:
                        printf("\n Vous lancez votre pokeball");
                        roundResult=pokeball(current_pokemon,fightingPokemon,equipe);
                        if (roundResult == 1){
                            printf("\nVous avez capturer le pokemon !");
                            isFighting  = 0;
                        }else if(roundResult == -1){
                            printf("\nVous n'avez plus de pokemon dans votre equipe!\n           - GAME OVER - ");
                            isFighting = 0;
                            gameOver = 1;
                        }
                        break;
                }

            }while (isFighting);
        }
    }
    return 0;
}
