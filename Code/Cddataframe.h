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

void printCdataframe(CDATAFRAME *cdf);

#ifndef CDATAFRAME_DORIAN_WILLIAM_CDDATAFRAME_H
#define CDATAFRAME_DORIAN_WILLIAM_CDDATAFRAME_H

#endif //CDATAFRAME_DORIAN_WILLIAM_CDDATAFRAME_H
