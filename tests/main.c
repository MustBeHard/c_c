#include <time.h>

#include "myfunc.h"

int main(){
srand(time(NULL));
	User * head = NULL;
	create_link(&head,5);
	show_link(head);

return 0;

}	
