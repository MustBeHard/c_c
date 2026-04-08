#include "menu.h"

char * get_string(int num){
	char tmp=0;	
	int count=0;
	char * str = (char*) malloc (sizeof(char)*num);
	if(num ==0){
		str = "none";
		return str;
	}
printf("\033[32mInput here:>\033[0m");
	while( (tmp=getchar())!='\n' && tmp!=EOF && count<num-1){
		str[count] = tmp;
		count++;	
	}

if(tmp!='\n'&&tmp!=EOF){
	while( (tmp = getchar())!='\n'&& tmp!=EOF);
	}
str[count] = '\0';
return str;
}

char * get_string_engine( FieldConfig config){
	char raw[512];


	
	printf("\nGIve me a %s (length request < %d ):",config.label,config.max_len);

	if( scanf("%s",raw)!=1) continue; // if scanf failt, move on to the next circle

	int len = strlen(raw); // check the len;
	
	if( len<=config.max_len){
			return strdup(raw);
		}
	if(config.mode == MODE_CONFIRM){ 
			char suggestion[config.max_len+1];
			strncpy(suggestion,raw,max_len);
			suggestion[max_len+1] = '\0';
	
			// declare a new char array
			// copy the first max_len char to new array
			// and shutdown the door

			printf(" [%s] is too long, i suggest you to shrink it to %s\n",config.label,config.max_len);
			printf("1.shrink it ; 2.choose another on;\n");
			int c;
			scanf("%d",&c);
				
			if(c==1)	return strdup(suggestion);//complete the while from here

}else{
	// if config.mode  != CONFIRM , and mode ==  MODE_STRICT “必须符合长度” “不支持截断”
			if(config.mode  == MODE_STRICT){
		//非常严格的设定了
		printf("BIG ERROR: %s lebal has to short than %d, please retry.\n",config.label,config.max_len);
		}

	}

}
