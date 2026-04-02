#include "tool.h"

char* get_str(int len){
	int i=0;
	char ch;
printf("\033[0;43mWHat you want to put in your file:\033[0m\n");

	char * ori = (char*)malloc(sizeof(char)*len);
	char * note = ori;

	while( (ch = getchar())!='\n' &&  ch!=EOF){
		
		note[i] = ch;
		i++;
		
		if(i>=len-1){
			len*=2;
			char* new = (char*)malloc(sizeof(char)*len);
			memcpy(new,note,i);
			free(note);
			note = new;
				
		}			
		
	}	
	note[i] = '\0';	
printf("\n%s\n",note);
return note;
}		
			
void write_file(char * filename,int num){

	FILE * fp = fopen(filename,"w");
	char * words  = get_str(num);
	int i = 0;

	printf("FILENAME:%s\n",filename);

	while(words[i]!='\0'){
		putc(words[i],fp);
		i++;
	}
putc('\n',fp);
	
	fclose(fp);

}

void write2b(char * filename , int num){
	FILE * fp = fopen(filename,"ab");
	char *words = get_str(num);
	int len = strlen(words);
	fwrite(words,len,1,fp);
	putc('\n',fp);
	fclose(fp);

}	









