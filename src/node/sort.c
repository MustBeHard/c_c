#include "tool.h"

void bubble_sort(Contact * con){

	if(!con) return;

	int i,j;

//	printf("The COUNT is %d\n",con->count);

	for(i=0;i<con->count-1;i++){

		for(j = 0; j<con->count-1-i; j++){
			if( strcmp(con->index[j]->username,con->index[j+1]->username) >0 ){
				void * tmp = con->index[j];
				con->index[j] = con->index[j+1];
				con->index[j+1] = tmp;
			}
		}
	}
}
