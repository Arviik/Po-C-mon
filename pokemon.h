//
// Created by totof on 21/09/2023.
//

#ifndef PO_C_MON_POKEMON_H
#define PO_C_MON_POKEMON_H

double pocmonType (char* typeOne, char* typetwo);

typedef struct {
    char *name;
    double hp;
    double hp_max;
    int attack;
    int defense;
    int speed;
    char *type;
}Pokemon;
Pokemon* newPokemon(char *name,double hp,double hp_max,int attack,int defense,int speed,char *type);
Pokemon* starter();
double losthp(Pokemon *pokemon_attacker,Pokemon *pokemon_attacked);
Pokemon* change_pokemon(Pokemon **equipe);
int  healhp (Pokemon *pokemon_ally,Pokemon *pokemon_wild,Pokemon **equipe);
void team_hp_reset (Pokemon **equipe);
int check_team(Pokemon **equipe);
int fight(Pokemon *pokemon_ally,Pokemon *pokemon_wild,Pokemon **equipe);
int run_away(Pokemon *pokemon_ally,Pokemon *pokemon_wild,Pokemon **equipe);
int pokeball(Pokemon *pokemon_ally,Pokemon *pokemon_wild,Pokemon **equipe);
Pokemon* show_team(Pokemon **equipe);
void team_hp_reset (Pokemon **equipe);
void pokedex_update(Pokemon *pokemon_wild,Pokemon **pokedex);
void pokedex_show(Pokemon **pokedex);
#endif //PO_C_MON_POKEMON_H
