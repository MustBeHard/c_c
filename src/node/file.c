#include "tool.h"

void write_to_db(Contact * con){

	if(!con)
	exit;

	FILE * fpw = fopen("contact.txt","a");

	if(!fpw){
	printf("FILE not found!\n");
	}
	int i;

	for(i=0;i<con->count;i++){

		fprintf(fpw,"%d,%s,%s,%d\n",con->index[i]->id,con->index[i]->username,con->index[i]->email,con->index[i]->data);
	}
	fclose(fpw);
printf("Data has been writting into database!\n");
}


void read_db(Contact * con){

	if(!con) exit;

	FILE * fpr = fopen("contact.txt","r");

	char id,data;
	char username[Name_Size],email[Mail_Size];

	while(	fscanf(fpr,"%[^,],%[^,],%[^,],%d%*c",&id,username,email,&data)==4){

		printf("ID:%d Name:%s Mail:%s Data:%d\n",id,username,email,data);

	}
printf("That will be all.\n");
}
