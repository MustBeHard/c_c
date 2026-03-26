#include <stdio.h>
#include <stdlib.h>


char* get_str(int size){
char * res = (char*)malloc(sizeof(char));

int c;

int i =0;

printf("Input--------------------:\n");

while( (c=getchar())!='\n' && c!=EOF){
	if(i<size-1){

		res[i++] = (char)c;
		}
i}
	res[i] = '\0';
return res;

}


int main(int argc, char* argv[]){
int num=0;





return 0;
}
