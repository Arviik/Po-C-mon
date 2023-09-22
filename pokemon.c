#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"
#include <time.h>
double pocmonType (char* typeOne, char* typetwo){
    int oneIndice = 0;
    int twoIndice = 0;
    if (strcmp(typeOne,"Feu") == 0){
        oneIndice = 1;
    } else if (strcmp(typeOne,"Eau") == 0){
        oneIndice = 2;
    }else if (strcmp(typeOne,"Plante") == 0){
        oneIndice = 3;
    }else if (strcmp(typeOne,"Electrik") == 0){
        oneIndice = 4;
    }else if (strcmp(typeOne,"Glace") == 0){
        oneIndice = 5;
    }else if (strcmp(typeOne,"Combat") == 0){
        oneIndice = 6;
    }else if (strcmp(typeOne,"Poison") == 0){
        oneIndice = 7;
    }else if (strcmp(typeOne,"Sol") == 0){
        oneIndice = 8;
    }else if (strcmp(typeOne,"Vol") == 0){
        oneIndice = 9;
    }else if (strcmp(typeOne,"Psy") == 0){
        oneIndice = 10;
    }else if (strcmp(typeOne,"Insecte") == 0){
        oneIndice = 11;
    }else if (strcmp(typeOne,"Roche") == 0){
        oneIndice = 12;
    }else if (strcmp(typeOne,"Spectre") == 0){
        oneIndice = 13;
    }else if (strcmp(typeOne,"Dragon") == 0){
        oneIndice = 14;
    }else if (strcmp(typeOne,"Tenebres") == 0){
        oneIndice = 15;
    }else if (strcmp(typeOne,"Acier") == 0){
        oneIndice = 16;
    }

    if (strcmp(typetwo,"Feu") == 0){
        twoIndice = 1;
    }else if (strcmp(typetwo,"Eau") == 0){
        twoIndice = 2;
    }else if (strcmp(typetwo,"Plante") == 0){
        twoIndice = 3;
    }else if (strcmp(typetwo,"Electrik") == 0){
        twoIndice = 4;
    }else if (strcmp(typetwo,"Glace") == 0){
        twoIndice = 5;
    }else if (strcmp(typetwo,"Combat") == 0){
        twoIndice = 6;
    }else if (strcmp(typetwo,"Poison") == 0){
        twoIndice = 7;
    }else if (strcmp(typetwo,"Sol") == 0){
        twoIndice = 8;
    }else if (strcmp(typetwo,"Vol") == 0){
        twoIndice = 9;
    }else if (strcmp(typetwo,"Psy") == 0){
        twoIndice = 10;
    }else if (strcmp(typetwo,"Insecte") == 0){
        twoIndice = 11;
    }else if (strcmp(typetwo,"Roche") == 0){
        twoIndice = 12;
    }else if (strcmp(typetwo,"Spectre") == 0){
        twoIndice = 13;
    }else if (strcmp(typetwo,"Dragon") == 0){
        twoIndice = 14;
    }else if (strcmp(typetwo,"Tenebres") == 0){
        twoIndice = 15;
    }else if (strcmp(typetwo,"Acier") == 0){
        twoIndice = 16;
    }

    
    double typeMatrix[17][17] = {
            {1,1,1,1,1,1,1,1,1,1,1,1,1./2,0,1,1,1./2},
            {1,1./2,1./2,2,1,2,1,1,1,1,1,2,1./2,1,1./2,1,2},
            {1,2,1./2,1./2,1,1,1,1,2,1,1,1,2,1,1./2,1,1},
            {1,1./2,2,1./2,1,1,1,1./2,2,1./2,1,1./2,2,1,1./2,1,1./2},
            {1,1,2,1./2,1./2,1,1,1,0,2,1,1,1,1,1./2,1,1},
            {1,1./2,1./2,2,1,1./2,1,1,2,2,1,1,1,1,2,1,1./2},
            {2,1,1,1,1,2,1,1./2,1,1./2,1./2,1./2,2,0,1,2,2},
            {1,1,1,2,1,1,1,1./2,1./2,1,1,1,1./2,1./2,1,1,0},
            {1,2,1,1./2,2,1,1,2,1,0,1,1./2,2,1,1,1,2},
            {1,1,1,2,1./2,1,2,1,1,1,1,2,1./2,1,1,1,1./2},
            {1,1,1,1,1,1,2,2,1,1,1./2,1,1,1,1,0,1./2},
            {1,1./2,1,2,1,1,1./2,1./2,1,1./2,2,1,1,1./2,1,2,1./2},
            {1,2,1,1,1,2,1./2,1,1./2,2,1,2,1,1,1,1,1./2},
            {0,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1./2,1./2},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1./2},
            {1,1,1,1,1,1,1./2,1,1,1,2,1,1,2,1,1./2,1./2},
            {1,1./2,1./2,1,1,2,1,1,1,1,1,1,2,1,1,1,1./2}
    };
    return typeMatrix[oneIndice][twoIndice];
}

Pokemon* newPokemon(char *name,double hp,double hp_max,int attack,int defense,int speed,char *type){
    Pokemon *newPokemon= malloc(sizeof (Pokemon));
    newPokemon->name= malloc(sizeof(char)*(strlen(name)+1));
    strcpy(newPokemon->name,name);
    newPokemon->hp=hp;
    newPokemon->hp_max=hp_max;
    newPokemon->attack=attack;
    newPokemon->defense=defense;
    newPokemon->speed=speed;
    newPokemon->type=malloc(sizeof(char)*(strlen(type)+1));
    strcpy(newPokemon->type,type);
    return newPokemon;
}
Pokemon* starter(){
    int choice;
    Pokemon *Bulbizarre= newPokemon("Bulbizarre",90,90,49,24,45,"Plante");
    Pokemon *Salameche= newPokemon("Salameche",78,78,52,21,65,"Feu");
    Pokemon *Carapuce= newPokemon("Carapuce",88,88,48,32,43,"Eau");
    Pokemon *Starter;
    printf("Veuillez choisir un Starter 0 : Bulbizarre 1 : Salameche 2 : Carapuce \n");
    fflush(stdin);
    scanf("%d",&choice);
    switch (choice) {
        case 0:
            Starter=Bulbizarre;
            break;
        case 1:
            Starter=Salameche;
            break;
        case 2:
            Starter=Carapuce;
            break;
        default:
            starter();
    }
    return Starter;
}
double losthp(Pokemon *pokemon_attacker,Pokemon *pokemon_attacked){
    double bonus_type= pocmonType(pokemon_attacker->type,pokemon_attacked->type);
    float hp_lost=(pokemon_attacker->attack-pokemon_attacked->defense)*bonus_type;
    return hp_lost;
}

Pokemon* change_pokemon(Pokemon **equipe){

    for (int i = 0; i < 6; ++i) {
        if(equipe[i]->hp!=0){
            printf("%d: %s %.0f pv\n",i,equipe[i]->name,equipe[i]->hp);
        }
    }
    int choose_pokemon;
    fflush(stdin);
    printf("choisissez le pokemon a envoye au combat : \n");
    scanf("%d",&choose_pokemon);
    return equipe[choose_pokemon];

}
Pokemon* pokedex(Pokemon *pokemon_wild,Pokemon **pokedex){
    int exist=0;
    int count=0;
    for (int i = 0; i < 30; ++i) {
        if(pokedex[i]->name==pokemon_wild->name){
            exist=1;
        }
        if(pokedex[i]->hp!=0){
            count++;
        }
    }
    if(exist==0){
        pokedex[count]=pokemon_wild;
    }
}
int check_team(Pokemon **equipe){
    int count=0;

    for (int i = 0; i < 6; ++i) {
        if(equipe[i]->hp==0){
            count++;
        }
    }
    if(count==5){
        return -1;
    }
    else if(count==0){
        return 2;
    }
    else if(count>0 && count<5){
        return 3;
    }
    else{
        return 0;
    }

}
//entre les refereneces(&) des deux pokemon
int fight(Pokemon *pokemon_ally,Pokemon *pokemon_wild,Pokemon **equipe){
    if(pokemon_ally->speed>=pokemon_wild->speed){
        pokemon_wild->hp-=losthp(pokemon_ally,pokemon_wild);
        printf("Le pokemon ennemie a perdu %.0f HP il a desormais %.0f / .0%f HP\n",losthp(pokemon_ally,pokemon_wild),pokemon_wild->hp,pokemon_wild->hp_max);
        if(pokemon_wild->hp<=0){
            printf("Le pokemon sauvage est mort \n");
            return 1;
        } else{
            pokemon_ally->hp-=losthp(pokemon_wild,pokemon_ally);
            printf("Votre pokemon a perdu %.0f HP il a desormais %.0f / %.0f HP\n",losthp(pokemon_wild,pokemon_ally),pokemon_ally->hp,pokemon_ally->hp_max);
            if(pokemon_ally->hp<=0){
                printf("Votre pokemon est mort \n");
                if(check_team(equipe)==0){
                    pokemon_ally= change_pokemon(equipe);
                } else{
                    return -1;
                }

            } else{
            return 0;
            }

        }
    } else if(pokemon_ally->speed<pokemon_wild->speed){
        pokemon_ally->hp-=losthp(pokemon_wild,pokemon_ally);
        printf("Votre pokemon a perdu %.0f hp il a desormais %.0f / %.0f\n",losthp(pokemon_wild,pokemon_ally),pokemon_ally->hp,pokemon_ally->hp_max);
        if(pokemon_ally->hp<=0){
            printf("Votre pokemon est mort \n");
            if(check_team(equipe)==0){
                pokemon_ally= change_pokemon(equipe);
            } else{
                return -1;
            }

        } else{
            pokemon_wild->hp-=losthp(pokemon_ally,pokemon_wild);
            printf("Le pokemon ennemie a perdu %.0f hp il a desormais %.0f / %.0f\n",losthp(pokemon_ally,pokemon_wild),pokemon_wild->hp,pokemon_wild->hp_max);
            if(pokemon_wild->hp<=0){
                printf("Le pokemon sauvage est mort \n");
                return 1;
            } else{
            return 0;
            }
        }
    }
}
int run_away(Pokemon *pokemon_ally,Pokemon *pokemon_wild,Pokemon **equipe){
    time_t t;
    int n=5;
    srand((unsigned) time(&t));
    printf("%d ",rand()%2);
        if(rand()%2==1){
            printf("Vous avez réussi a fuir\n");
            return 1;
        }
        else{
            pokemon_ally->hp-=losthp(pokemon_wild,pokemon_ally);
            printf("Votre pokemon a perdu %f hp il a desormais %f / %f\n",losthp(pokemon_wild,pokemon_ally),pokemon_ally->hp,pokemon_ally->hp_max);
            if(pokemon_ally->hp<=0){
                printf("Votre pokemon est mort \n");
                if(check_team(equipe)==0){
                    pokemon_ally= change_pokemon(equipe);
                } else{
                    return -1;
                }

            } else{
            return 0;
            }
        }

}
int  healhp (Pokemon *pokemon_ally,Pokemon *pokemon_wild,Pokemon **equipe){
    pokemon_ally->hp += pokemon_ally->hp_max * 0.5;
    if(pokemon_ally->hp>pokemon_ally->hp_max){
        pokemon_ally->hp=pokemon_ally->hp_max;
    }
    pokemon_ally->hp-=losthp(pokemon_wild,pokemon_ally);
    printf("Votre pokemon a perdu %f hp il a desormais %f / %f\n",losthp(pokemon_wild,pokemon_ally),pokemon_ally->hp,pokemon_ally->hp_max);
    if(pokemon_ally->hp<=0){
        printf("Votre pokemon est mort \n");
        if(check_team(equipe)==0){
            pokemon_ally= change_pokemon(equipe);
        } else{
            return -1;
        }

    } else{
        return 0;
    }
}

void team_hp_reset (Pokemon **equipe){
    for(int  i = 0 ; i < 6; i++){
        equipe[i]->hp = equipe[i]->hp_max;
    }
}


int pokeball(Pokemon *pokemon_ally,Pokemon *pokemon_wild,Pokemon **equipe){
    time_t t;
    srand((unsigned) time(&t));
    printf("%d ",rand()%4);
    if(rand()%4==1){
        printf("Vous avez réussi a capturer le pokemon!\n");
        if(check_team(equipe)==2){
            printf("Vous avez atteint le nombre de pokemon maximum dans votre equipe \n");
            for (int i = 0; i < 6; ++i) {
                if(equipe[i]->hp!=0){
                    printf("%d: %s %.0f pv\n",i,equipe[i]->name,equipe[i]->hp);
                }
            }
            int choose_pokemon;
            fflush(stdin);
            printf("choisissez le pokemon a relacher : \n");
            scanf("%d",&choose_pokemon);
            equipe[choose_pokemon]=pokemon_wild;

        } else if(check_team(equipe)==3){
            int count=0;
            for (int i = 0; i < 6; ++i) {
                if(equipe[i]->hp!=0){
                    count++;
                }
            }
            equipe[count]=pokemon_wild;

        }
        return 1;
    }
    else{
        pokemon_ally->hp-=losthp(pokemon_wild,pokemon_ally);
        printf("Votre pokemon a perdu %f hp il a desormais %f / %f\n",losthp(pokemon_wild,pokemon_ally),pokemon_ally->hp,pokemon_ally->hp_max);
        if(pokemon_ally->hp<=0){
            printf("Votre pokemon est mort \n");
            if(check_team(equipe)==0){
                pokemon_ally= change_pokemon(equipe);
            } else{
                return -1;
            }

        } else{
            return 0;
        }
    }
}

