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
            break;

    }
    col->logical_size++;
    return 1;
}

void delete_column(COLUMN **col)
{
    for (int i = 0; i < (*col)->logical_size ; i++){
        free(((*col)->data[i]));
    }
    free((*col)->title);
    free((*col)->data);
    free((*col)->index);
    free(*col);
    *col = NULL;
}
void convert_value(COLUMN* col, unsigned long long int i, char* str, int size){
    switch(col->column_type){
        case UINT:
            snprintf(str,size,"%d",*((unsigned int*)col->data[i]));
            break;
        case INT:
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char*)col->data[i]));
            break;
        case FLOAT:
            snprintf(str, size, "%f", *((float*)col->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", *((double*)col->data[i]));
            break;
        case STRING:
            snprintf(str, size, "%s", *((char**)col->data[i]));
            break;
        default:
            printf("Conversion failed");
    }
}

void print_col(COLUMN* col){

}
