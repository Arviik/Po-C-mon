#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pokedex.h"

Pokemon *new_pokemon(const char *name, int pv, int attaque, int defense, int vitesse, const char *type) {
    Pokemon *pokemon = malloc(sizeof(Pokemon));
    pokemon->name = malloc(sizeof(char) * strlen(name) + 1);
    strcpy(pokemon->name, name);
    pokemon->pv = pv;
    pokemon->attaque = attaque;
    pokemon->defense = defense;
    pokemon->vitesse = vitesse;
    pokemon->type = malloc(sizeof(char) * strlen(type) + 1);
    strcpy(pokemon->type, type);
    return pokemon;
}

void free_pokemon(Pokemon *pokemon) {
    free(pokemon->name);
    free(pokemon->type);
    free(pokemon);
}

PokemonArray *new_pokemon_array() {
    PokemonArray *pokemonArray = malloc(sizeof(PokemonArray));
    pokemonArray->tab = NULL;
    pokemonArray->size = 0;
    return pokemonArray;
}

void free_pokemon_array(PokemonArray *pokemonArray) {
    for (int i = 0; i < pokemonArray->size; i++) {
        free_pokemon(&pokemonArray->tab[i]);
    }
    free(pokemonArray);
}

void add_pokemon_to_array(PokemonArray *pokemonArray, const Pokemon *pokemon) {
    Pokemon *buffer = malloc(sizeof(Pokemon) * (pokemonArray->size + 1));
    for (int i = 0; i < pokemonArray->size; i++) {
        buffer[i] = pokemonArray->tab[i];
    }
    buffer[pokemonArray->size] = *pokemon;
    pokemonArray->tab = buffer;
    pokemonArray->size++;
}

Pokemon get_pokemon_from_array(const PokemonArray *pokemonArray, int index) {
    return pokemonArray->tab[index];
}

PokemonArray *get_pokemon_array_from_csv() {
    FILE *f = fopen("../poCmon.csv", "rb");
    if (f != NULL) {
        PokemonArray *pokemonArray = new_pokemon_array();
        int nbRows = 0;
        char c = fgetc(f);
        while (c != EOF) {
            if (c == '\n') {
                nbRows++;
            }
            c = fgetc(f);
        }
        rewind(f);
        do {
            c = fgetc(f);
        } while (c != '\n');
        for (int i = 0; i < nbRows; i++) {
            char **buffer = malloc(sizeof(char *) * 6);
            for (int j = 0; j < 6; j++) {
                int stringLen = 0;
                do {
                    c = fgetc(f);
                    stringLen++;
                }while (c != ';' && c != '\n' && c != EOF);
                if (c == EOF) {
                    fseek(f, ftell(f) + 1, SEEK_SET);
                }
                fseek(f, ftell(f) - stringLen, SEEK_SET);
                buffer[j] = malloc(sizeof(char) * stringLen);
                for (int k = 0; k < stringLen; k++) {
                    buffer[j][k] = fgetc(f);
                }
                buffer[j][stringLen - 1] = '\0';
            }
            add_pokemon_to_array(
                    pokemonArray,
                    new_pokemon(
                            buffer[0],
                            atoi(buffer[1]),
                            atoi(buffer[2]),
                            atoi(buffer[3]),
                            atoi(buffer[4]),
                            buffer[5]
                    )
            );
        }
        fclose(f);
        return pokemonArray;
    } else {
        return NULL;
    }
}
