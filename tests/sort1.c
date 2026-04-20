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

	int tmp;
/*
   内层循环，i=0时，
   j从0循环到length-1（因为j要和j+1对比)
   寻找一个最小值
   外层，i应该控制范围比内层  
*/
	int flag=0;

	for(int i = 0; i<LENGTH-1;i++)
	{
			for( int j = 0; j<LENGTH-1-i; j++)
			{
					flag =0;
					if(arr[j]>arr[j+1])
					{				
							tmp = arr[j];
							arr[j] = arr[j+1];
							arr[j+1] = tmp;
							flag=1;				
					}
			
			}
	if(flag ==0) break;
	}

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


		

	
