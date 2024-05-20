#define REALLOC_SIZE 256; //(Utilisation : Réallocation)
#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include <string.h>
typedef enum enum_type{
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
    char *title; // titre de la colone
    unsigned int logical_size; //size
    unsigned int physical_size; // max_size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
// index valid
// 0 : no index
// -1 : invalid index
// 1 : valid index
    int valid_index;
// direction de tri Ascendant ou Déscendant
// 0 : ASC
// 1 : DESC
    int sort_dir;
} COLUMN;

COLUMN *create_column(ENUM_TYPE type, char *title);

int insert_value(COLUMN *col, void *value);

void delete_column(COLUMN **col);

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

int number_occurence(COLUMN *col, char *x);

int sup_val(COLUMN *col, void *x);

int inf_val(COLUMN *col, void *x);

COLUMN *create_column_by_user(ENUM_TYPE coltype);

void add_value_after_pos(COLUMN *col, int nb_row);

void del_value_pos(COLUMN *col, int nb_row);

void user_value(COLUMN *col);

void print_col(COLUMN* col);
#ifndef DATAFRAME_C_FUNCTION_H
#define DATAFRAME_C_FUNCTION_H

#endif //DATAFRAME_C_FUNCTION_H
