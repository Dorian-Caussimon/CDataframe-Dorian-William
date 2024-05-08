#include "Cddataframe.h"
int main()
{
    char str[5];
    COLUMN *mycol = create_column(INT, "My column");
    int a = 52, b = 44, c = 15, d = 18;
    insert_value(mycol, &a);
    insert_value(mycol, &b);
    insert_value(mycol, &c);
    insert_value(mycol, &d);
    del_value_pos(mycol,2);
    convert_value(mycol, 4, str, 5);
    printf("%s \n", str);

    delete_column(&mycol);
    return 0;
}
