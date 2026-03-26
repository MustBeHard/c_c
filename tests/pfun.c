#include <stdio.h>

void go(char * name){

	printf("%s is going.\n",name);
}


void eat(char * food){
	printf("I am eating %s\n",food);
}


int main(){
/*
void (*remote)(char *);
remote = go;
printf("procceding.......\n");
remote("Jim");
remote = eat;
remote("meat");
*/


void route(char * args, void(*remote)(char *)){
	
	printf("Route has initized.\n");
	remote(args);
}



route("Tom" , go);

return 0;

}
