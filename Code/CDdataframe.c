#include "Cddataframe.h"

// Permet de remplir les différents tripes de chaque colonne pour le dataframe
ENUM_TYPE *fill(int size){
    int value;
    ENUM_TYPE cdftype[size];
    printf("Veuiller saisir le type de donne contenue dans la colonne, 1 pour UNIT , 2-INT, 3-CHAR, 4-FLOAT, 5-DOUBLE, 6-STRING, 7-STRUCTURE\n");// recueillir info utilisateu
    for (int i = 0; i < size ;i++){
        printf("Colonne [%d] :",i+1);// faire une saisie sécurisé-----------------------------------
        scanf("%d",&value);
        cdftype[i] = value+1; // +1 pour s'alligner avec l'enum type
    }
    return cdftype;
}

//Création d'un dataframe vide et initialise les caractéristiques de base
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size)
{
    CDATAFRAME *cdf = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
    cdf->cdataframe_type = cdftype;
    cdf->size = size;
    cdf->list = lst_create_list();
    return cdf;
}

//Création d'un dataframe grâce à des saisies utilisateurs
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

//Permet de supprimer les donnée dans un dataframe
void delete_cdataframe(CDATAFRAME **cdf)
{
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }
    lnode *node = (*cdf)->list->head;
    for (int i = 0 ; i < (*cdf)->size; i++){ //supprime chaque colonne
        delete_column(node->data);
    }
    lst_delete_list((*cdf)->list); // suprime la liste
    free(*cdf); // libère l'espaces allouer pour le cdf
    cdf = NULL;
}

//Permet d'obteniure le nombre de ligne maximal dans le cdf
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
    return max; // Colonne avec la plus longue taille
}

//Permet d'afficher les nom des colonnes
void name_col(CDATAFRAME *cdf, int nb_col_start, int nb_col_end){
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }
    lnode *node = cdf->list->head;
    COLUMN *col;
    for (int j = 0; j < nb_col_start; j++){
        node = node->next;
    }
    for (int i = nb_col_start ; i <= nb_col_end  ;i++){ // affichage des nom des collone
        col = node->data;
        printf("| %s |",col->title);
        node = node->next;
    }
}

//Permet d'afficher une partie du dataframe
void print_a_part_of_Cdataframe(CDATAFRAME *cdf)
{
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }

    char str[20];
    int max = max_row_col_cdf(cdf), nb_col_start = 0,nb_col_end = 0, nb_row_start = 0 , nb_row_end = 0;

    lnode *node;
    COLUMN *col;
    printf("Afficher le CDdataframe a partire de la colonne :"); // choix du nb de colonne a afficher
    scanf("%d",&nb_col_start);
    while (nb_col_start <= 0 || nb_col_start > cdf->size){ // saisie sécuriser pour les colonne
        printf("Valleur incorecte, ressaisir  la valeur :");
        scanf("%d",&nb_col_start);
    }
    printf("jusqu'a la colonne :");
    scanf("%d",&nb_col_end);
    while (nb_col_end < nb_col_start || nb_col_end > cdf->size){ // saisie sécuriser pour les colonne
        printf("Valleur incorecte, ressaisir  la valeur :");
        scanf("%d",&nb_col_end);
    }

    printf("Afficher le Cdataframe a partire de la ligne:");// choix du nb de ligne a afficher
    scanf("%d",&nb_row_start);
    while(nb_row_start <= 0 || nb_row_start > max){ // saisie sécuriser pour les ligne
        printf("Valleur incorecte, ressaisir  la valeur :");
        scanf("%d",&nb_row_start);
    }
    printf("Jusqu'a la ligne :");
    scanf("%d",&nb_row_end);
    while(nb_row_end < nb_row_start || nb_row_end > max){ // saisie sécuriser pour les ligne
        printf("Valleur incorecte, ressaisir  la valeur :");
        scanf("%d",&nb_row_end);
    }
    printf("%d %d %d %d\n",nb_col_start,nb_col_end,nb_row_start,nb_row_end);
    nb_col_start--;nb_col_end--;nb_row_start--;nb_row_end--; // -1 pour s'alligner avec le cdf
    printf("%d %d %d %d\n",nb_col_start,nb_col_end,nb_row_start,nb_row_end);
    name_col(cdf,nb_col_start,nb_col_end); // affiche le nom des col

    for (int i = nb_row_start ; i <= nb_row_end; i++){
        node = cdf->list->head; // initialise le pointeur en tete de liste

        for (int k = 0; k < nb_col_start; k ++){
            node = node->next;
        }

        printf("\n");
        for(int j = nb_col_start ; j <= nb_col_end; j++){
            col = node->data;
            convert_value(col,i,str,20);
            printf("|  %s  |", str);
            node = node->next;
        }
    }
    printf("\n");
}

//Permet d'afficher le dataframe en entier
void full_printCdataframe(CDATAFRAME *cdf)
{
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }
    char str[20];
    int max = max_row_col_cdf(cdf);

    lnode *node = NULL;
    COLUMN *col = NULL;
    name_col(cdf,0,(cdf->size)-1); // afiche le nom des col
    for (int i = 0 ; i <= max-1; i++){
        node = cdf->list->head;
        printf("\n");
        for(int j = 0 ; j < cdf->size; j++){
            col = node->data;
            convert_value(col,i,str,20);
            printf("|  %s  |", str);
            node = node->next;
        }
    }
    printf("\n");
}

//Permet d'afficher le nombre de colonnes et de lignes
void print_col_and_row(CDATAFRAME *cdf)
{
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }
    int value;
    COLUMN *col;
    lnode *nod = cdf->list->head;
    printf("Il y a %d colonnes veuiller choisir en une pour avoir son nombre de ligne : ", cdf->size);
    scanf("%d",&value);

    for(int i = 1 ; i < value; i++){
        nod = nod->next;
    }
    col = nod->data;
    printf("%d", col->logical_size);
}

//Permet de chercher les occurence dans le dataframe
void reshears_occurence_CDF(CDATAFRAME *cdf)
{
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }
    int nb = 0;
    lnode *node = cdf->list->head;
    char value[20]; // utilisatiuon d'un char car la comparaison vas se fair avec une valeur de ce type grace au convert value
    printf("Veuiller entré une valeur a rechercher : ");
    scanf("%s", value);
    for (int i = 0 ; i< cdf->size;i++){
        nb += number_occurence(node->data,value);
        node = node->next;
    }
    (nb == 0)? printf("il n'y a pas la valeur dans le dataframe"):
    printf("il y a %d fois la valeur %s dans le cdf",nb,value);
}

// Permet de supprimer une colonne du dataframe
void delete_column_cdf(CDATAFRAME *cdf, char *col_name)
{

    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL || col_name == NULL)
    {
        printf("CDF Vide");
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

// Permet d'insérer une colonne dans le dataframe après une colonne déjà  existante
void insert_column_cdf_after(CDATAFRAME *cdf, char *col_name)
{
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL || col_name == NULL)
    {
        printf("CDF Vide");
        return;
    }

    lnode *node = cdf->list->head;
    COLUMN *col = NULL;
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

// Permet d'insérer une ligne dans le dataframe après une ligne précise
void insert_CDF_line_after(CDATAFRAME *cdf, int pos)
{
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }
    lnode *node = cdf->list->head;
    for (int i = 0 ; i < cdf->size; i++){
        add_value_after_pos(node->data,pos);
        node = node->next;
    }
}

// Permet de supprimer une ligne précise du dataframe
void del_CDF_line(CDATAFRAME *cdf, int pos)
{
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }
    lnode *node = cdf->list->head;
    for (int i = 0 ; i < cdf->size; i++){
        del_value_pos(node->data,pos);
        node = node->next;
    }
}

// Permet de renomer une colonne du dataframe
void rename_col(CDATAFRAME *cdf, char *col_name_replace)
{
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }
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

// Permet de remplacer une valeur précise du dataframe
void replace_value_cdf(CDATAFRAME *cdf, int pos_row, int pos_col)
{
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }
    unsigned int keeper;
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

// Permet de compter les valeurs supérieures à une valeur x
void count_val_sup_CDF(CDATAFRAME *cdf){
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }
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

// Permet de compter les valeurs inférieur à une valeur x
void count_val_inf_CDF(CDATAFRAME *cdf){
    if (cdf == NULL){
        printf("CDF Vide");
        return;
    }
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

//non foctionelle
CDATAFRAME* load_from_csv(char *file_name, ENUM_TYPE *dftype, int size)
{
    int val1;
    unsigned int val2;
    float val3;
    double val4;
    char val5;
    FILE *file;
    CDATAFRAME *cdf = create_cdataframe(dftype, size); // création du cdf
    COLUMN *col = NULL;
    lnode *newnode = NULL,*node = NULL;
    char*title = "Column", path[50];
    sprintf(path,"..\\CSV\\%s",file_name);
    file = fopen(path,"r");
    if (file == NULL){ // verifier si le fichier a bien été
        printf("Impossible d'ouvrir le fichier %s",file_name);
        return cdf;
    }

    for (int i = 0 ; i < size; i++ ){ // creation des colonne et implementation des col dans le cdf
        //sprintf(title,"Colonne[%d]",i+1);
        col = NULL;
        col = create_column(dftype[i], title);
        newnode = lst_create_lnode(col);
        lst_insert_tail(cdf->list,newnode);
    }
    free(newnode);

    char ligne[MAX_LINE_LENGHT]; // Buffer pour stocker chaque ligne lue
    while (fgets(ligne, MAX_LINE_LENGHT, file) != NULL) {
        node = cdf->list->head;
        char *valeur = strtok(ligne, ","); // Séparer la ligne en valeurs séparées par les virgules
        while (valeur != NULL) {
            col = node->data;
            switch (col->column_type){
                case INT:
                    val1 = atoi(valeur);
                    insert_value(col,&val1);
                    break;
                case UINT:
                    val2 = strtoll(valeur,NULL,10);
                    insert_value(col,&val2);
                    break;
                case FLOAT:
                    val3 = atof(valeur);
                    insert_value(col,&val3);
                    break;
                case DOUBLE:
                     val4 = strtod(valeur,NULL);
                    insert_value(col,&val4);
                    break;
                case CHAR:
                    val5 = valeur[0];
                    insert_value(col,&val5);
                    break;
                case STRING:
                    insert_value(col , (char*)valeur);
                    break;
                default:
                    break;
            }
            printf("here\n");
            valeur = strtok(NULL, ","); // Passer à la valeur suivante
            node = node->next;
        }
    }
    fclose(file);
    return cdf;

}