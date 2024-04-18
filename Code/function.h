#include <stdio.h>
#include <stdlib.h>
#define REALLOC_SIZE 256; //(Utilisation : Réallocation)
typedef struct // (Type) Colonne d'un CDataframe
{
    char title;
    int logical_size;
    int physical_size;
    int *data;
} COLUMN;

/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
*/
COLUMN *create_column(char *title);

/**
* @brief Add a new value to a column
* @param1 : Pointer to a column
* @param2 : The value to be added
* @return : 1 if the value is added 0 otherwise
*/
int insert_value(COLUMN *col, int value);

/**
* @brief : Free allocated memory
* @param1 : Pointer to a column
*/
void delete_column(COLUMN **col);

/**
* @brief: Print a column content
* @param: Pointer to a column
*/
void print_col(COLUMN *col);
#ifndef DATAFRAME_C_FUNCTION_H
#define DATAFRAME_C_FUNCTION_H

#endif //DATAFRAME_C_FUNCTION_H
