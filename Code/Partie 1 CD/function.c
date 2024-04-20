#include "function.h"
#include <stdio.h>
#include <stdlib.h>


COLUMN *create_column(char *title)
{
    COLUMN *col = (COLUMN*) malloc(sizeof (COLUMN));
    col-> title = *title; //donne le titre a la colone
    col->logical_size = 0; // donne une taille logique de départ
    col->physical_size = 10; // taille physique de départ
    col->data = (int*)malloc(col->physical_size * sizeof (int));
    return col;
}
int insert_value(COLUMN  *col, int value)
{
    if (col == NULL){
        return 0;
    }
    if (col->logical_size >= col->physical_size){
        col->physical_size = col->physical_size + REALLOC_SIZE;
        col-> data = realloc((col->data),col->physical_size);
    }
    col->data[col->logical_size]=value;
    col->logical_size++;
    return 1;
}
void delete_column(COLUMN **col)
{
    free((*col)->data);
    free(*col);
    *col = NULL;
}
void print_col(COLUMN *col)
{
    //printf("%s\n",&col->title);
    for (int i = 0; i < col->logical_size;i++){
        printf("[%d] : %d\n", i, col->data[i]);
    }
}
int search_occurrences_incol(COLUMN *col, int val)
{
    int cpt = 0;
    for (int i = 0 ; i < col->logical_size ; i++){
        if (col->data[i] == val){
            cpt ++;
        }
    }
    return cpt;
}
int pos_val(COLUMN *col, int val)
{
    if (val > col->logical_size){
        printf("value not valid");
        return 0;
    }
    int value = 0;
    value = col->data[val];
    return value;
}
int sup_val(COLUMN *col, int val)
{
    int cpt = 0;
    for (int i = 0 ; i < col->logical_size ; i++){
        if (col->data[i] > val){
            cpt ++;
        }
    }
    return cpt;
}
int inf_val(COLUMN *col, int val)
{
    int cpt = 0;
    for (int i = 0 ; i < col->logical_size ; i++){
        if (col->data[i] < val){
            cpt ++;
        }
    }
    return cpt;
}
/*--------------------------------------------------------------Fonction CDdatafame----------------------------------------------*/
CDdataframe *create_cddataframe()
{
    CDdataframe *df = (CDdataframe*) malloc(sizeof(CDdataframe));
    df->col = NULL;
    return df;
}
void fill_CDdataframe(CDdataframe *df)
{
    int val = 0,value = 0;
    printf("enter nb of colum :");
    scanf("%d\n",&val);
    df->col = (COLUMN**) malloc(val*sizeof(COLUMN*));
    df->num_col = val;
    for (int i = 0 ; i < df->num_col;i++){
        for (int j = 0; j < df->col[i]->logical_size;j++){
            printf("Enter a value: ");
            scanf("%d\n",&value);
            insert_value(df->col[i],value);
        }
    }
}
void print_CDdatafram(CDdataframe *df)
{
    for(int i = 0; i < df->num_col; i++){
            print_col(df->col[i]);

    }
}