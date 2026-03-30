#include "tool.h"


int main(){

srand(time(NULL));

Contact * con =NULL;
printf("---------------------\n");
con = (Contact*)malloc(sizeof(Contact));


con = create_contact(5);
printf("--------------------------------------------\n");
show_contact(con);


bubble_sort(con);
printf("---------after bubble -------------\n");

show_contact(con);

//printf("******* FIND A NAME ********\n");
//char * key ;
//key = get_string(Name_Size,"name");


//write_to_db(con);
//read_db(con);
//free_contact(con);

return 0;
}
