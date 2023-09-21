#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"


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

    return 0;
}
