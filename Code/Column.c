#include "Column.h"
#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>


COLUMN *create_column(ENUM_TYPE type, char *title)
{
    COLUMN *col= (COLUMN*) malloc(sizeof(COLUMN));
    col ->title = title;
    col -> logical_size = 0;
    col -> physical_size = 0;
    col -> data = NULL;
    col -> column_type = type;
    col->sort_dir = 0;
    return col;
}

int insert_value(COLUMN *col,void  *value)
{
    if (col == NULL) {
        return 0;
    }

    if (col->logical_size >= col->physical_size) {
        col->physical_size = col->physical_size + REALLOC_SIZE
        col->data = realloc(col->data, col->physical_size * sizeof(COL_TYPE *));
        if (col->data == NULL) {
            return 0;
        }
    }
    // Allocation de mémoire pour stocker la valeur
    if (value != NULL) {
        switch (col->column_type) {
            case UINT:
                col->data[col->logical_size] = (COL_TYPE *) malloc(sizeof(unsigned int));
                *((unsigned int *) col->data[col->logical_size]) = *((unsigned int *) value);
                break;
            case INT:
                col->data[col->logical_size] = (COL_TYPE *) malloc(sizeof(signed int));
                *((signed int *) col->data[col->logical_size]) = *((signed int *) value);
                break;
            case CHAR:
                col->data[col->logical_size] = (COL_TYPE *) malloc(sizeof(char));
                *((char *) col->data[col->logical_size]) = *((char *) value);
                break;
            case FLOAT:
                col->data[col->logical_size] = (COL_TYPE *) malloc(sizeof(float));
                *((float *) col->data[col->logical_size]) = *((float *) value);
                break;
            case DOUBLE:
                col->data[col->logical_size] = (COL_TYPE *) malloc(sizeof(double));
                *((double *) col->data[col->logical_size]) = *((double *) value);
                break;
            case STRING:
                col->data[col->logical_size] = (COL_TYPE *) malloc(sizeof(char *));
                *((char **) col->data[col->logical_size]) = (char *) value;
                break;
            case STRUCTURE:
                col->data[col->logical_size] = (COL_TYPE*) malloc(sizeof(200));
                col->data[col->logical_size] = value;
                break;

        }
        col->logical_size++;
        return 1;
    }
    col->data[col->logical_size] = value;
    col->logical_size++;
    return 1;
}

void delete_column(COLUMN **col)
{
    for (int i = 0; i < (*col)->logical_size ; i++){
        free(((*col)->data[i]));
    }
    //((*col)->title == NULL)? : free((*col)->title),(*col)->title = NULL;
    //((*col)->index == NULL)? : free((*col)->index),(*col)->index = NULL;
    free((*col)->data);
    (*col)->data = NULL;
    free(*col);
    *col = NULL;
}
void convert_value(COLUMN* col, unsigned long long int i, char *str, int size) {
    if (col->data[i] == NULL) {
        strcpy(str, "NULL");
        return;
    }
        switch (col->column_type) {
        case UINT:
            snprintf(str, size, "%d", *((unsigned int *) col->data[i]));
            break;
        case INT:
            snprintf(str, size, "%d", *((int *) col->data[i]));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char *) col->data[i]));
            break;
        case FLOAT:
            snprintf(str, size, "%f", *((float *) col->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", *((double *) col->data[i]));
            break;
        case STRING:
            snprintf(str, size, "%s", (char *) col->data[i]);
            break;
        default:
            printf("Conversion failed");
        }
        return;
}

void print_col(COLUMN* col){
    char str[10];
    for(int i = 0 ; i < col->logical_size ; i++){
        convert_value(col, i, str, 10);
        printf("[%d] : %s\n",i,str);
    }
}

int number_occurence(COLUMN *col , char *x)
{
    char str[10];
    int cpt = 0;
        for(int i = 0; i < col->logical_size ; i++){
            convert_value(col, i, str, 10);
            (str == x)? cpt ++ : cpt ;
        }
    return cpt;
}

int pos_val(COLUMN *col, char *x)
{
    char str[10];
    int cpt = 0;
    for(int i = 0; i < col->logical_size ; i++){
        convert_value(col, i, str, 10);
        (str == x)? cpt = i : cpt ;
    }
    return cpt;
}
int sup_val(COLUMN *col, char *x)
{
    char str[10];
    int cpt = 0;
    for(int i = 0; i < col->logical_size ; i++){
        convert_value(col, i, str, 10);
        (str >= x)? cpt ++ : cpt ;
    }
    return cpt;
}

int inf_val(COLUMN *col, char *x)
{
    char str[10];
    int cpt = 0;
    for(int i = 0; i < col->logical_size ; i++){
        convert_value(col, i, str, 10);
        (str <= x)? cpt ++ : cpt ;
    }
    return cpt;
}