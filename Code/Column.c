#include "Column.h"

//Permet de choisir la bonne entrée pour la saisie de valeur de l'utilisateur dans certaines fonctions
void user_value(COLUMN *col)
{
    if (col == NULL){ // vérification
        printf("Colonne vide");
        return;
    }
    unsigned int v1;
    int v2;
    char v3;
    float v4;
    double v5;
    char *v6;

    switch (col->column_type) { // vérifie le type de la colonne
        case UINT:
            scanf("%d", &v1);
            insert_value(col,&v1);
            break;
        case INT:
            scanf("%d",&v2);
            insert_value(col,&v2);
            break;
        case CHAR:
            scanf(" %c",&v3);
            insert_value(col,&v3);
            break;
        case FLOAT:
            scanf("%f",&v4);
            insert_value(col,&v4);
            break;
        case DOUBLE:
            scanf("%lf",&v5);
            insert_value(col,&v5);
            break;
        case STRING:
            scanf(" %s",v6);
            insert_value(col,v6);
            break;
        default:
            printf("ERROR");
    }
}

//Permet de créer une colonne vide et initialise toute les valeurs de départ
COLUMN *create_column(ENUM_TYPE type, char *title)
{
    COLUMN *col= (COLUMN*) malloc(sizeof(COLUMN));
    col -> title = title;
    col -> logical_size = 0;
    col -> physical_size = 0;
    col -> data = NULL;
    col -> column_type = type;
    col -> sort_dir = 0;
    return col;
}

// Permet d'insérer une valeur dans la colonne
int insert_value(COLUMN *col,void *value)
{
    if (col == NULL){
        printf("Colonne vide");
        return 0;
    }

    if (col->logical_size >= col->physical_size) { // réalocation de la mémoir si besoin
        col->physical_size = col->physical_size + REALLOC_SIZE
        col->data = realloc(col->data, col->physical_size * sizeof(COL_TYPE *));
        if (col->data == NULL) {
            return 0;
        }
    }
    // Allocation de mémoire pour stocker la valeur
    if (value != NULL) {
        switch (col->column_type) { // vérifie le type de la colonne et alloue la mémoir nécessaire
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
                col->data[col->logical_size] = malloc(strlen((char *)value) + 1);
                strcpy((char *)col->data[col->logical_size], (char *)value);
                break;
            case STRUCTURE:
                col->data[col->logical_size] = (COL_TYPE*) malloc(sizeof(200));
                col->data[col->logical_size] = value;
                break;
            default:
                break;

        }
        col->logical_size++;
        return 1;
    }
    col->data[col->logical_size] = value;
    col->logical_size++;
    return 1;
}

// Peremet la suppresion d'une colonne
void delete_column(COLUMN **col)
{
    for (int i = 0; i < (*col)->logical_size ; i++){
        free(((*col)->data[i])); // Libère la mémoire de chaque case
    }
    //((*col)->title == NULL)? : free((*col)->title),(*col)->title = NULL;
    //((*col)->index == NULL)? : free((*col)->index),(*col)->index = NULL;
    free((*col)->data);
    (*col)->data = NULL;
    free(*col);
    *col = NULL;
}

//Permet de convertir une valeur en chaîne de caractère si besoin de l'afficher ou de la comparer, Chaine de caractère crée grace a la fonction snprintf
void convert_value(COLUMN* col, unsigned long long int i, char *str, int size) {
    if (col->data[i] == NULL) {
        strcpy(str, "NULL");
        return;
    }
        switch (col->column_type) { // Verification du type de la colonne
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

//Permet de calculer le nombre d'occurrences d'une valeur dans une colonne
int number_occurence(COLUMN *col ,  char *x)
{
    char str[20];
    int cpt = 0;
    for (int i = 0; i < col->logical_size; i++) { // Boucle pour parcourire la colonne
        convert_value(col, i, str, 20);
        if (strcmp(str, x) == 0) {
            cpt++;
        }
    }
    return cpt;
}

//Permet de calculer le nombre de valeur supérieur a une valeur x dans une colonne
int sup_val(COLUMN *col, void *x)
{
    int cpt = 0;

    if (col == NULL || col->logical_size == 0) {
        return cpt;
    }

    for (unsigned int i = 0; i < col->logical_size; i++) { // compare selon le type
        switch (col->column_type) {
            case UINT:
                if (*((unsigned int *)col->data[i]) > *((unsigned int *)x)) {
                    cpt++;
                }
                break;
            case INT:
                if (*((int *)col->data[i]) > *((int *)x)) {
                    cpt++;
                }
                break;
            case CHAR:
                if (*((char *)col->data[i]) > *((char *)x)) {
                    cpt++;
                }
                break;
            case FLOAT:
                if (*((float *)col->data[i]) > *((float *)x)) {
                    cpt++;
                }
                break;
            case DOUBLE:
                if (*((double *)col->data[i]) > *((double *)x)) {
                    cpt++;
                }
                break;
            case STRING:
                if (strcmp((char *)col->data[i], (char *)x) > 0) {
                    cpt++;
                }
                break;
            default:
                break;
        }
    }

    return cpt;
}

//Permet de calculer le nombre de valeur inférieur a une valeur x dans une colonne
int inf_val(COLUMN *col, void *x)
{
    int count = 0;

    if (col == NULL || col->logical_size == 0) {
        return count;
    }

    for (unsigned int i = 0; i < col->logical_size; i++) { // compare selon le type
        switch (col->column_type) {
            case UINT:
                if (*((unsigned int *)col->data[i]) > *((unsigned int *)x)) {
                    count++;
                }
                break;
            case INT:
                if (*((int *)col->data[i]) > *((int *)x)) {
                    count++;
                }
                break;
            case CHAR:
                if (*((char *)col->data[i]) > *((char *)x)) {
                    count++;
                }
                break;
            case FLOAT:
                if (*((float *)col->data[i]) > *((float *)x)) {
                    count++;
                }
                break;
            case DOUBLE:
                if (*((double *)col->data[i]) > *((double *)x)) {
                    count++;
                }
                break;
            case STRING:
                if (strcmp((char *)col->data[i], (char *)x) > 0) {
                    count++;
                }
                break;
            default:
                break;
        }
    }

    return count;
}

// Permet de créer une colonne avec des saisis d'utilisateurs
COLUMN *create_column_by_user(ENUM_TYPE coltype)
{
    char *name = (char*) malloc(sizeof (char*));
    int nb_raw = 0;
    printf("Choisi un nom pour la colonne:");
    scanf("%s",name);

    while (nb_raw <= 0){
        printf("Nombre de ligne voulue :");
        scanf("%d",&nb_raw);
    }
    COLUMN *col = create_column(coltype,name);

    for (int j = 0 ; j < nb_raw ; j++){
        printf("Ligne [%d] :",j+1);
        user_value(col);
    }
    return col;
}

//Permet d'ajouter une valeur après une certaine position dans la colonne
void add_value_after_pos(COLUMN *col, int pos)
{
    if (col == NULL || pos <= 0){ // verification
        return;
    }
    unsigned int keeper = col->logical_size;

    for (unsigned int i = col->logical_size; i > pos ; i--){ // boucle qui parcoure la colonne pour décaler les donnée est inséré la valeur
        col->data[i] = col->data[i-1];
    }
    col->logical_size = pos;
    printf(" saisir la valeur a ajouter a la ligne :");
    user_value(col);
    col->logical_size = keeper+1;
}

//Permet de supprimer une valeur a une certaine position dans la colonne
void del_value_pos(COLUMN *col, int pos)
{
    if (col == NULL || pos <= 0){
        return;
    }
    for (int i = pos-1; i < col->logical_size ; i++){ // boucle qui parcoure la colonne pour supprimer la valeur
        col->data[i] = col->data[i+1];
    }
    col->logical_size--;
}