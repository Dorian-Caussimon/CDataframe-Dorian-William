#define REALLOC_SIZE 256; //(Utilisation : Réallocation)
#include <stdio.h>
#include <stdlib.h>

typedef enum enum_type
{
    NULLVAL = 1,
    UINT,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    STRING,
    STRUCTURE
} ENUM_TYPE;

typedef union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
}COL_TYPE;

typedef struct column {
    char *title;
    unsigned int logical_size; //size
    unsigned int physical_size; // max_size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
} COLUMN;

/**
* Create a new column
* @param1 : Column type
* @param2 : Column title
* @return : Pointer to the created column
*/
COLUMN *create_column(ENUM_TYPE type, char *title);

/**
* @brief: Insert a new value into a column
* @param1: Pointer to the column
* @param2: Pointer to the value to insert
* @return: 1 if the value is correctly inserted 0 otherwise
*/
int insert_value(COLUMN *col, void *value);
/**
* @brief: Free the space allocated by a column
* @param1: Pointer to the column
*/
void delete_column(COLUMN **col);
/**
* @brief: Convert a value into a string
* @param1: Pointer to the column
* @param2: Position of the value in the data array
* @param3: The string in which the value will be written
* @param4: Maximum size of the string
*/
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);






/**
* @brief: Display the content of a column
* @param: Pointer to the column to display
*/
void print_col(COLUMN* col);
/*

/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
/
COLUMN *create_column(char *title);

/**
* @brief Add a new value to a column
* @param1 : Pointer to a column
* @param2 : The value to be added
* @return : 1 if the value is added 0 otherwise
/
int insert_value(COLUMN *col, int value);

/**
* @brief : Free allocated memory
* @param1 : Pointer to a column
/
void delete_column(COLUMN **col);

/**
* @brief: Print a column content
* @param: Pointer to a column
/
void print_col(COLUMN *col);
int search_occurrences_incol(COLUMN *col, int val);
int pos_val(COLUMN *col, int val);
int sup_val(COLUMN *col, int val);
int inf_val(COLUMN *col, int val);
*/

#ifndef DATAFRAME_C_FUNCTION_H
#define DATAFRAME_C_FUNCTION_H

#endif //DATAFRAME_C_FUNCTION_H
