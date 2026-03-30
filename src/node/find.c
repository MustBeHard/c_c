#include "tool.h"

void find_user_by_name(char* keyname,Contact * con){
	
int i ;
int flag = 1;

for(i=0;i<con->count;i++){
		if(  strcmp ( con->index[i]->username,keyname ) ==0 ){
		printf("ID:%d : Name:%16s :Mail:%s \n", con->index[i]->id,con->index[i]->username,con->index[i]->email);
}else{
	flag = 0;
	//if can not find the keyname ; 
}
}	

if(flag ==1 ){
	printf("\nResult completed!\n");
}else{
	// we can try another one;
	for(i = 0;i<con->count;i++){
	if(strstr(con->index[i]->username, keyname)){
		flag = 0;
		printf("ID:%d : Name:%16s :Mail:%s \n", con->index[i]->id,con->index[i]->username,con->index[i]->email);
		}	
		flag = 1;// results exist!
		}
	}
	if(flag==1) printf("\nNo contacts of \" %s \" found.\n",keyname);

}	



