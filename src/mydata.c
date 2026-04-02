#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User_{
	int id;
	char* username;
	char* birthday;
	struct User_ * next;
	struct User_ * pre;
}User;

int main(){

FILE * fp = fopen("rec.bin","wb");
User*p = (User*)malloc(sizeof(User));

p->id = 20;
char * name = "Jojo";
p->username = name;
char * birth = "1999-09-23";
p->birthday = birth;

p->pre = NULL;
p->next = NULL;

// id int sizeof(int)
int len_id = sizeof(int);
fwrite( &(p->id),len_id,1,fp);
// username strlen(p->username)
int len_username = strlen(p->username)+1;
fwrite(&len_username,sizeof(int),1,fp);
fwrite((p->username),sizeof (char),len_username,fp);
//birthday the same
int len_birthday = strlen(p->birthday)+1;
fwrite(&len_birthday,sizeof(int),1,fp);
fwrite((p->birthday),sizeof(char),len_birthday,fp);

fclose(fp);

return 0;

}








/*------------------

一个用户数据链表为主链：个人id，姓名，生日，通讯信息指针数组（可以挂载多个不同信息的内存地址）

通讯信息链表下含有：个人id用于检查匹配，字符串电邮，字符串电话，字符串地址

|-----|    |-----|    |-----|
|用户1|    |用户2|    |用户3|
|-----|    |-----|    |-----|
   ！
*/


/*
需要用到的函数：
一个动态可扩展长度的字符串输入：
一个节点构建函数;
链表构建函数;

因为要做两种节点，是否需要函数指针？

需要一个index索引来加快查找 删除 修改和增加/插入

最后一个显示函数
typedef struct Contact_{
	int id;
	int count;
	struct User_ ** index;  
}Contact;
*/
