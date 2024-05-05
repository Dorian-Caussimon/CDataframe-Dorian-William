#include "Tri.h"
static void ascendant (COLUMN *col)
{

}
static void descendant(COLUMN *col)
{

}
void sort(COLUMN *col, int sort_dir)
{
    if (col == NULL || col->logical_size <= 1 ){
        return;
    }
    (sort_dir == 0) ? ascendant(col) : descendant(col);

}
void insertionSort(COLUMN *col) //acs
{

    int j = 0;
    for (int i = 2; i < col->logical_size; i++) {
        COL_TYPE *value = col->data[i];
        j = i - 1;
        while (j >= 0 && *((int *) col->data[j]) > *((int *) value)) {
            col->data[j + 1] = col->data[j];
            j--;
        }

        col->data[j + 1] = value;
    }
}