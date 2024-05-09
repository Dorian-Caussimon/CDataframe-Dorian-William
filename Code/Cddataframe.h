#include "Column.h"
#include "list.h"


/**
* Création d'un dataframe
*/
typedef struct cdataframe{
ENUM_TYPE *cdataframe_type; // liste de type
int size;
list *list;
}CDATAFRAME;

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
/**
* @brief: Column deletion
* param1: Pointer to the CDataframe to delete
*/
void delete_cdataframe(CDATAFRAME **cdf);

/**
* @breif: Delete column by name
* @param1: Pointer to the CDataframe
* @param2: Column name
*/
void delete_column_cdf(CDATAFRAME *cdf, char *col_name);
/**
* @brief: Number of columns
* @param1: Point to the CDataframe
* @return: Number of columns in the CDataframe
*/
int get_cdataframe_cols_size(CDATAFRAME *cdf);
/**
 * @brief: Permet de crée un cdf avec des saisie utilisateur
 * @param: Pointer to the CDataframe
 */
CDATAFRAME *create_dataframe_by_user();
/**
 *
 * @param cdf : pointer vers le dataframe
 * @brief : permet d'afficher le data frame selon les envis de l'utilisateur
 */
void printCdataframe(CDATAFRAME *cdf);
void print_col_and_row(CDATAFRAME *cdf);
void reshears_occurence_CDF(CDATAFRAME *cdf);
void name_col(CDATAFRAME *cdf, int nb_col);
void insert_column_cdf(CDATAFRAME *cdf,  char *col_name);
void insert_CDF_line(CDATAFRAME *cdf, int nb_row);
void del_CDF_line(CDATAFRAME *cdf, int pos);
void rename_col(CDATAFRAME *cdf, char *col_name_replace);
void insert_CDF_line_after(CDATAFRAME *cdf, int pos);
void replace_value_cdf(CDATAFRAME *cdf, int pos_row, int pos_col);
void count_val_inf_CDF(CDATAFRAME *cdf);
void count_val_sup_CDF(CDATAFRAME *cdf);
#ifndef CDATAFRAME_DORIAN_WILLIAM_CDDATAFRAME_H
#define CDATAFRAME_DORIAN_WILLIAM_CDDATAFRAME_H

#endif //CDATAFRAME_DORIAN_WILLIAM_CDDATAFRAME_H
