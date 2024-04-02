// .h
#include <stdio.h>
#include <stdlib.h>


typedef struct // (Type) Colonne d'un CDataframe
{
    char titre;
    int taille_logique;
    int taille_physique;
    int *donnees;
} column;

#ifndef DATAFRAME_C_FUNCTION_H
#define DATAFRAME_C_FUNCTION_H

#endif //DATAFRAME_C_FUNCTION_H
