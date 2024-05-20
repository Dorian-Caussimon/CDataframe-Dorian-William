#include "Cddataframe.h"
int main()
{
    CDATAFRAME *cdf = NULL;
    int selection, running = 1,case1 = 0,case2 = 0, case3 = 0, case4 = 0,case5 = 0,nb_col = 0 , pos = 0,pos_row = 0, pos_col =0;
    char name[100] ,file_name_csv[100];
    printf("===Bienvenue dans le Cdataframe de William et Dorian===\n");

    while(running == 1 ) {
        printf("\nTaper 1 pour tout ce qui est relier a l'alimentation d'un dataframe \n"
               "Taper 2 pour tout ce qui est affichages d'un dataframe\n"
               "Taper 3 pour les operation usuelles\n"
               "Taper 4 pour tout ce qui est analyse est statistiques\n"
               "Taper 5 pour tout cer qui a un raport avec les fichier CSV\n"
               "Taper 6 pour sortir du programe\n"
               "Selectioner la fonctionalite desire :");
        scanf("%d",&selection);

        switch (selection) {
            case 1:
                printf("1- Creation d'un CDataframe vide\n"
                       "2 - Creation d'un CDataframe par l'utilisateur\n"
                       "3 - Supprimer le Cdataframe\n"
                       "Selectioner la fonctionalite desire :");
                       scanf("%d",&case1);
                switch (case1) {
                    case 1:
                        printf("Nombre de colonne :");
                        while (nb_col<= 0){
                            scanf("%d",&nb_col);
                        }
                        ENUM_TYPE *cdftype =  fill(nb_col);
                         cdf = create_cdataframe(cdftype,nb_col);
                        break;
                    case 2:
                        cdf = create_dataframe_by_user();
                        break;
                    case 3:
                        delete_cdataframe(&cdf);
                        break;
                    default:
                        printf("Mauvaise valeur\n");
                        break;
                }
                break;

            case 2:
                printf("1-Afficher tout le CDataframe\n"
                       "2- Afficher une partie du CDataframe selon une limite fournie\n"
                       "Selectioner la fonctionalite desire :");
                scanf("%d",&case2);
                switch (case2) {
                    case 1:
                        full_printCdataframe(cdf);
                        break;
                    case 2:
                        print_a_part_of_Cdataframe(cdf);
                        break;
                    default:
                        printf("Mauvaise valeur\n");
                        break;
                }
                break;

            case 3:
                printf("1- jouter une ligne de valeurs au CDataframe\n"
                       "2- Supprimer une ligne de valeurs du CDataframe\n"
                       "3- Ajouter une colonne apres une colonne deja existante au CDataframe\n"
                       "4- Supprimer une colonne du CDataframe\n"
                       "5- Renommer le titre d’une colonne du CDataframe\n"
                       "6- Vérifier l’existence d’une valeur (recherche) dans le CDataframe\n"
                       "7- Accéder/remplacer la valeur se trouvant dans une cellule du CDataframe en utilisant son numero de ligne et de colonne\n"
                       "8 - Afficher les noms des colonnes\n"
                       "Selectioner la fonctionalite desire :");
                scanf("%d",&case3);
                switch (case3) {
                    case 1:
                        printf("Position ou insere la ligne");
                        scanf("%d",&pos);
                        insert_CDF_line_after(cdf,pos);
                        break;
                    case 2:
                        printf("Position ou supprimer la ligne ");
                        scanf("%d",&pos);
                        del_CDF_line(cdf,pos);
                        break;
                    case 3:
                        printf("Nom de la colonne existante pour insertion de la nouvelle");
                        scanf("%s",name);
                        insert_column_cdf_after(cdf ,name);
                        break;
                    case 4:
                        printf("Nom de la colonne existante pour supresion");
                        scanf("%s",name);
                        delete_column_cdf(cdf, name);
                        break;
                    case 5:
                        printf("Nom de la colonne existante pour la renommer");
                        scanf("%s",name);
                        rename_col(cdf,name);
                        break;
                    case 6:
                        reshears_occurence_CDF(cdf);
                        break;
                    case 7:
                        printf("Inséré la ligne ou se trouve la valeur a modifier");
                        scanf("%d",&pos_row);
                        printf("Inséré la colonne ou se trouve la valeur a modifier");
                        scanf("%d",&pos_col);
                        replace_value_cdf(cdf,pos_row,pos_col);
                        break;
                    case 8:
                        name_col(cdf,0,(cdf->size)-1);
                        break;
                    default:
                        printf("Mauvaise valeur\n");
                        break;

                }
                break;

            case 4:
                printf("1- Afficher le nombre de colonnes et de lignes\n"
                       "2- Nombre de cellules egales a x \n"
                       "3- Nombre de cellules contenant une valeur superieure a x \n"
                       "4- Nombre de cellules contenant une valeur inferieure a x\n"
                       "Selectioner la fonctionalite desire :");
                scanf("%d",&case4);
                switch (case4) {
                    case 1:
                        print_col_and_row(cdf);
                        break;
                    case 2:
                        reshears_occurence_CDF(cdf);
                        break;
                    case 3:
                        count_val_sup_CDF(cdf);
                        break;
                    case 4:
                        count_val_inf_CDF(cdf);
                        break;
                    default:
                        printf("Mauvaise valeur\n");
                        break;

                }
                break;
            case 5:
                printf("1- Pour importer des données d'un fichier CSV\n"
                       "2- Pour exporter le Dataframe sous CSV\n"
                       "Selectioner la fonctionalite desire :");
                       scanf("%d",&case5);
                switch (case5) {
                    case 1:
                        printf("fonctionalité indisponile");
                        break;
                    case 2:
                        printf("Veuiller saisir un nom pour le fichier CSV:");
                        scanf("%s",file_name_csv);
                        save_into_csv(cdf,file_name_csv);
                        break;
                    default:
                        printf("Mauvaise valeur\n");
                        break;
                }
                break;
            case 6:
                printf("Merci d'avoir utiliser notre programe");
                running = 0;
                break;

            default:
                printf("Mauvaise valeur\n");
                break;
        }
    }
    return 0;

}
