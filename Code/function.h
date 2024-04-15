// .h
#include <stdio.h>
#include <stdlib.h>

typedef struct // (Type) Colonne d'un CDataframe
{
    char title;
    int logical_size;
    int physical_size;
    int *data;
} COLUMN;

COLUMN create_column(char* title);

#ifndef DATAFRAME_C_FUNCTION_H
#define DATAFRAME_C_FUNCTION_H

#endif //DATAFRAME_C_FUNCTION_H
