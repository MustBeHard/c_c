/*------------------

一个用户数据链表为主链：个人id，姓名，生日，通讯信息指针数组（可以挂载多个不同信息的内存地址）

通讯信息链表下含有：个人id用于检查匹配，字符串电邮，字符串电话，字符串地址

|-----|    |-----|    |-----|
|用户1|    |用户2|    |用户3|
|-----|    |-----|    |-----|
   ！
struct User_{
	int id;
	char* username;
	char* birthday;
	Struct Contact_ * contact_of_user;
	struct User_ * next;
	struct User_ * pre;
}

struct Contact_{
	int id;
	char * email;
	char * phone;
	char * address;
	index char; // a b c d e .....
	  
}




需要用到的函数：
一个动态可扩展长度的字符串输入：
一个节点构建函数;
链表构建函数;

因为要做两种节点，是否需要函数指针？

需要一个index索引来加快查找 删除 修改和增加/插入

最后一个显示函数

