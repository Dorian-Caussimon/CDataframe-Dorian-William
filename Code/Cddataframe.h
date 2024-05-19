#include "Column.h"
#include "list.h"
#define MAX_LINE_LENGHT 100

/**
* Création d'un dataframe
*/
typedef struct cdataframe{
ENUM_TYPE *cdataframe_type; // liste de type
int size;
list *list;
}CDATAFRAME;

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);

void delete_cdataframe(CDATAFRAME **cdf);

void delete_column_cdf(CDATAFRAME *cdf, char *col_name);

CDATAFRAME *create_dataframe_by_user();

void print_a_part_of_Cdataframe(CDATAFRAME *cdf);

void full_printCdataframe(CDATAFRAME *cdf);

void print_col_and_row(CDATAFRAME *cdf);

void reshears_occurence_CDF(CDATAFRAME *cdf);

void name_col(CDATAFRAME *cdf, int nb_col_start, int nb_col_end);

void insert_column_cdf_after(CDATAFRAME *cdf,  char *col_name);

void del_CDF_line(CDATAFRAME *cdf, int pos);

void rename_col(CDATAFRAME *cdf, char *col_name_replace);

void insert_CDF_line_after(CDATAFRAME *cdf, int pos);

void replace_value_cdf(CDATAFRAME *cdf, int pos_row, int pos_col);

void count_val_inf_CDF(CDATAFRAME *cdf);

void count_val_sup_CDF(CDATAFRAME *cdf);

CDATAFRAME* load_from_csv(char *file_name, ENUM_TYPE *dftype, int size);

ENUM_TYPE *fill(int size);

#ifndef CDATAFRAME_DORIAN_WILLIAM_CDDATAFRAME_H
#define CDATAFRAME_DORIAN_WILLIAM_CDDATAFRAME_H

#endif //CDATAFRAME_DORIAN_WILLIAM_CDDATAFRAME_H
