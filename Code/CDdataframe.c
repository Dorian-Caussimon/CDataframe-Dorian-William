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
    int value = 0,nb_col = 0;
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

int get_cdataframe_cols_size(CDATAFRAME *cdf)
{
    int size = cdf->size;
    return size;
}
static int max_row_col_cdf(CDATAFRAME *cdf)
{
    int max = 0;
    COLUMN *col;
    lnode *node = cdf->list->head;
    for (int i = 0 ; i < cdf->size; i++){
        col = node->data;
        (max < col->logical_size)?max = col->logical_size: max;
        node = node->next;
    }
    return max;
}
void name_col(CDATAFRAME *cdf, int nb_col){
    lnode *node = cdf->list->head;
    COLUMN *col;
    for (int i = 0 ; i < nb_col;i++){ // affichage des nom des collone
        col = node->data;
        printf("| %s |",col->title);
        node = node->next;
    }
}
void printCdataframe(CDATAFRAME *cdf)
{
    char str[20];
    int max = max_row_col_cdf(cdf), nb_col = 0, nb_row;

    lnode *node;
    COLUMN *col;
    printf("Veuiller sasire le nombre de colonne a afficher :"); // choix du nb de colonne a afficher
    scanf("%d",&nb_col);
    while (nb_col <= 0 || nb_col > cdf->size){ // saisie sécuriser pour les colonne
        printf("Valleur incorecte, ressaisir  la valeur :");
        scanf("%d",&nb_col);
    }

    printf("veuiller saisir le nombre de ligne a afficher:");// choix du nb de ligne a afficher
    scanf("%d",&nb_row);
    while(nb_row <= 0 || nb_row > max){ // saisie sécuriser pour les ligne
        printf("Valleur incorecte, ressaisir  la valeur :");
        scanf("%d",&nb_row);
    }

    name_col(cdf,nb_col); // afiche le nom des col

    for (int i = 0 ; i < nb_row; i++){
        node = cdf->list->head;
        printf("\n");
        for(int j = 0 ; j < nb_col; j++){
            col = node->data;
            convert_value(col,i,str,20);
            printf("|  %s  |", str);
            node = node->next;
        }
    }
}
void print_col_and_row(CDATAFRAME *cdf)
{
    int value;
    COLUMN *col;
    lnode *nod = cdf->list->head;
    printf("Il y a %d colonnes veuiller choisir en une pour avoir son nombre de col : ", cdf->size);
    scanf("%d",&value);

    for(int i = 1 ; i < value; i++){
        nod = nod->next;
    }
    col = nod->data;
    printf("%d", col->logical_size);
}
void reshears_occurence_CDF(CDATAFRAME *cdf)
{
    int nb = 0;
    lnode *node = cdf->list->head;
    char value[20]; // utilisatiuon d'un char car la comparaison vas se fair avec une valeur de ce type grace au convert value
    printf("Veuiller entré une valeur : ");
    scanf("%s", value);
    for (int i = 0 ; i< cdf->size;i++){
        nb += number_occurence(node->data,value);
        node = node->next;
    }
    (nb == 0)? printf("il n'y a pas la valeur dans le dataframe"):
    printf("il y a %d fois la valeur %s dans le cdf",nb,value);
}

void delete_column_cdf(CDATAFRAME *cdf, char *col_name)
{
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL || col_name == NULL)
    {
        return;
    }

    lnode *node = cdf->list->head;
    COLUMN *col = NULL;
    list *list = cdf->list;

    while (node != NULL) {

        col = node->data;
        if (strcmp(col->title, col_name) == 0) {
            lst_delete_lnode(list, node);
            delete_column(&col);
            cdf->size--;
            return;
        }
        node = node->next;
    }

    printf("La colonne avec le nom %s n'a pas ete trouvee dans le dataframe.\n", col_name);
}
void insert_column_cdf(CDATAFRAME *cdf, char *col_name)
{
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL || col_name == NULL)
    {
        return;
    }

    lnode *node = cdf->list->head;
    COLUMN *col = NULL;
    list *list = cdf->list;
    ENUM_TYPE type;
    COLUMN *newcol = NULL;
    lnode *newnod = NULL;

    while (node != NULL) {
        col = node->data;
        if (strcmp(col->title, col_name) == 0) {
            printf("La colonne avec le nom %s n'a pas ete trouvee dans le dataframe.\n", col_name);
            printf("Type de la colonne a ajoute  1 -UNIT , 2-INT, 3-CHAR, 4-FLOAT, 5-DOUBLE, 6-STRING, 7-STRUCTURE\n:");
            scanf("%d",&type);
            newcol = create_column_by_user(type);
            newnod = lst_create_lnode(newcol);
            lst_insert_after(cdf->list,newnod,node);
            cdf->size++;
            return;
        }
        node = node->next;
    }
}

void insert_CDF_line_after(CDATAFRAME *cdf, int pos)
{
    lnode *node = cdf->list->head;
    for (int i = 0 ; i < cdf->size; i++){
        add_value_after_pos(node->data,pos);
        node = node->next;
    }
}
void del_CDF_line(CDATAFRAME *cdf, int pos)
{
    lnode *node = cdf->list->head;
    for (int i = 0 ; i < cdf->size; i++){
        del_value_pos(node->data,pos);
        node = node->next;
    }
}
void rename_col(CDATAFRAME *cdf, char *col_name_replace)
{
    lnode *node = cdf->list->head;
    COLUMN *col;
    char *str = (char*) malloc(sizeof(char*));
    printf("veuiller choisire le nouveaux nom de la colonne : ");
    scanf(" %s",str);
    for (int i = 0 ; i < cdf->size ;i++){
        col = node->data;
        if (strcmp(col->title, col_name_replace) == 0){
            col->title = str;
        }
    }
}
void replace_value_cdf(CDATAFRAME *cdf, int pos_row, int pos_col)
{
    unsigned int keeper = 0;
    lnode *node = cdf->list->head;
    COLUMN *col = NULL;
    for (int i = 0; i < pos_col-1 ; i++){
        node = node->next;
    }
    col = node->data;
    keeper = col->logical_size;
    col->logical_size = pos_row-1;
    printf("Saisir la valeur qui vas remplacer la valeur : ");
    user_value(col);
    col->logical_size = keeper;
}
void count_val_sup_CDF(CDATAFRAME *cdf) // a tester
{
    int cpt = 0;
    char *str = NULL;
    lnode *node = cdf->list->head;
    printf("Veuiller saisir la valeur pour la recherche : ");
    scanf("%s",str);
    for (int i = 0 ; i < cdf -> size; i++){
        cpt += sup_val(node->data,str);
        node = node->next;
    }
}
void count_val_inf_CDF(CDATAFRAME *cdf) // a tester
{
    int cpt = 0;
    char *str = NULL;
    lnode *node = cdf->list->head;
    printf("Veuiller saisir la valeur pour la recherche : ");
    scanf("%s",str);
    for (int i = 0 ; i < cdf -> size; i++){
        cpt += inf_val(node->data,str);
        node = node->next;
    }
}