#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
	int age;
	char nickname[20];
}ExtraInfo;

typedef struct{
	char name[20];
	int type;
	ExtraInfo info;
}User;

void print_user_info(User* u){

	printf("姓名:%s | ",u->name);
	if(u->type ==0){
	printf("  年龄：%d \n",u->info.age);
}
	else{
	printf("  昵称： %s \n",u->info.nickname);
}
}

int main()
{
 User * u1 = (User*)malloc(sizeof(User));
strcpy(u1->name , "Jim Green");
u1->type = 0;
u1->info.age = 29;

printf("%s is %d years old.",u1->name,u1->info.age);

return 0;
}  
