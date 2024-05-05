#include "Cddataframe.h"

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size)
{
    CDATAFRAME *cdf = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
    cdf->cdataframe_type = cdftype;
    cdf->size = size;
    cdf->list = lst_create_list();
    return cdf;
}

CDATAFRAME *create_dataframe_by_user()
{
    int value = 0,nb_col = 0,nb_raw = 0;
    char name[20];
    printf("Veuiller saisir le nombre de colonne :"); // recueillir info utilisateu
    scanf("%d",&nb_col); // faire une saisie sécurisé-----------------------------------
    ENUM_TYPE cdftype[nb_col];

    printf("Veuiller saisir le type de donne contenue dans la colonne, 1 pour UNIT , 2-INT, 3-CHAR, 4-FLOAT, 5-DOUBLE, 6-STRING, 7-STRUCTURE\n");// recueillir info utilisateu
    for (int i = 0; i < nb_col ;i++){
        printf("Colonne [%d] :",i+1);// faire une saisie sécurisé-----------------------------------
        scanf("%d",&value);
        cdftype[i] = value+1; // +1 pour s'alligner avec l'enum type
    }
    CDATAFRAME *cdf = create_cdataframe(cdftype,nb_col);

    printf("======================= Remplissage des colonne =======================\n");
    for (int i = 0 ; i < nb_col;i++){
        COLUMN *col = create_column_by_user(cdf->cdataframe_type[i]);
        lnode *newnod = lst_create_lnode(col);
        lst_insert_tail(cdf->list,newnod);
    }
    return cdf;
}

void delete_cdataframe(CDATAFRAME **cdf)
{
    lst_delete_list((*cdf)->list);
    free(*cdf);
    cdf = NULL;
}
void delete_column_cdf(CDATAFRAME *cdf, char *col_name)
{}
int get_cdataframe_cols_size(CDATAFRAME *cdf)
{
    int size = cdf->size;
    return size;
}

void printCdataframe(CDATAFRAME *cdf)
{
    lnode *node = cdf->list->head;
    COLUMN *col;

    for (int i = 0 ; i < cdf->size; i++){
       col = node->data;
        print_col(col);
        node = node->next;
    }

}