//
// Created by Ugo on 22/09/2023.
//

#ifndef PO_C_MON_POKEMON_H
#define PO_C_MON_POKEMON_H

typedef struct {
    char *name;
    int pv;
    int attaque;
    int defense;
    int vitesse;
    char *type;
} Pokemon;

typedef struct {
    Pokemon *tab;
    int size;
} PokemonArray;

Pokemon *new_pokemon(const char *name, int pv, int attaque, int defense, int vitesse, const char *type);

void free_pokemon(Pokemon *pokemon);

PokemonArray *new_pokemon_array();

void free_pokemon_array(PokemonArray *pokemonArray);

void add_pokemon_to_array(PokemonArray *pokemonArray, const Pokemon *pokemon);

Pokemon get_pokemon_from_array(const PokemonArray *pokemonArray, int index);

PokemonArray *get_pokemon_array_from_csv();

#endif //PO_C_MON_POKEMON_H
