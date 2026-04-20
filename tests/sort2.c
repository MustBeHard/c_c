#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LENGTH 20


int main()
{
	srand(time(NULL));
	int trigger=0;

	int arr[LENGTH];
	for(int i=0;i<LENGTH;i++)
	{
		arr[i] =rand()%100;
	}

	printf("#----------------------\n");
	for(int i=0;i<LENGTH;i++)
	{		trigger++;
			printf("\033[32m%d:\033[0m%d\t",i,arr[i]);
			if(trigger%5==0)
					printf("\n");
	}
	printf("\n#----------------------\n");
/*******************
插入排序，从头开始，外层循环控制从1到len,内层循环控制从0到i+1
内层循环是在增加的，越来越大，但是如果有序，就会很快找到插入点。
最差是倒序

外层 i = 1; i<len; i++
内层 j=0; 比较j和j+1,所以内层一定不能越界，j最大时不能超过i-1


*******************/
	int tmp;
for( int i=1; i<LENGTH; i++)
{
	int j = i;
	tmp = arr[j+1]
	while(j>=0 | tmp>arr[j]){
			
j--;
			if(arr[j+1]>arr[j])
		{
			arr[j+1] = arr[j];
		}
	}

}
//*******************
	printf("#----------------------\n");
	for(int i=0;i<LENGTH;i++)
	{		trigger++;
			printf("\033[32m%d:\033[0m%d\t",i,arr[i]);
			if(trigger%5==0)
					printf("\n");
	}
	printf("\n#----------------------\n");
	return 0;
}


		

	
