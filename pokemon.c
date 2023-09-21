#include <stdio.h>
#include <string.h>
#include "pokemon.h"

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
    printf("%d : %d \n", oneIndice, twoIndice);
    return typeMatrix[oneIndice][twoIndice];
}
