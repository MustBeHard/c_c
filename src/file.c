#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



#define SIZE 10

int main(){
srand(time(NULL));

FILE *fp = fopen("rec.txt","a");
char ch ;
char * s;
int len=16;
printf("I am gonna input words:\n");
int i = 0;

	char * tmp = (char*)malloc(sizeof(char)*len);
	s = tmp;

while( (ch=getchar())!='\n' && ch!=EOF&& i< 1024){
	s[i] = ch;	
	i++;
	if(i==len-1){
	s[i] = '\0';
	len *=2;
	char * big  = (char*)malloc(sizeof(char)*len);
	memcpy(big,s,i);
	s = big;
	tmp = big;
	}
}
s[i] = '\0';

int key = 0;
for(key = 0; key<i; key++){
	putc(s[key],fp);
}
putc('\r',fp);
putc('\n',fp);

printf("\n%s\n",s);

fclose(fp);
return 0;
}


	
