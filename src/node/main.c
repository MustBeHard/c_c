#include "tool.h"


int main(){

srand(time(NULL));

Contact * con =NULL;
printf("---------------------\n");
con = create_contact(5);
show_contact(con);

return 0;
}
