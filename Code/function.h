// .h
#include <stdio.h>
#include <stdlib.h>


typedef struct // (Type) Colonne d'un CDataframe
{
    char title;
    int logical_size;
    int physique_size;
    int *data;
} column;

#ifndef DATAFRAME_C_FUNCTION_H
#define DATAFRAME_C_FUNCTION_H

#endif //DATAFRAME_C_FUNCTION_H
