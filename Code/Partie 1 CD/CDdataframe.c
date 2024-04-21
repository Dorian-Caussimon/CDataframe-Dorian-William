#include "Cddataframe.h"
#include "Column.h"
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