#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 50

int* generate_arr(int num);
void insert_sort( int * arr, int num);
void show_array(int* arr, int num);

int main(){

srand(time(NULL));
int * arr = generate_arr(SIZE);

insert_sort(arr,SIZE);

show_array(arr,SIZE);

return 0;
}

int * generate_arr(int num){

	int * x = (int*) malloc( sizeof(int) * num);
	for(int i = 0; i<num; i++){
		x[i] = rand()%1000;
	}
return x;
}
/**************
插入排序，用外层划定一个范围，比如0 1 2,然后再内层把2号摘出来，依次去和1号 0号比较，如果前面的都小于他，各自后移一位，如果遇到大于等于的，把key填入其后（此处一定要+1）
内层要从紧挨着的前一位 i-1 （j）开始比较 

for ( i = 1; i<num; i++)
	key = arr[i];  这是要比较的数字，从整个数组第1位开始
	for(j = i-1;arr[j] < key, j>=0; j--)
		如果只要仍然是比key小，则j+1 = j ，顺便j--
		arr[j+1] = arr[j]
		}
	条件失败，跳出内层循环，这时候找到的arr[j]>=key 直接把j+1 = key即可
	然后i增加一位


		


*/
void insert_sort(int * arr, int num){

	for(int i=1;i<num;i++){
		int key = arr[i];int j = i-1;
		while(key<arr[j] && j>=0){
				arr[j+1] = arr[j];
				j--;
		}
		arr[j+1] = key;
}
/*
	int i=1;
	while(i<num){
	int	j = i-1; int key = arr[i];
	 while (j>=0){
		if( key>arr[j]){
				break;
	}	
		arr[j+1] = arr[j];
		j--;
	}	
	arr[j+1] = key;
	i++;
}			
*/
}

void show_array(int * arr, int num){
int count =1;
printf("\n\033[36m********************************************\n");
	for(int x=0;x<num;x++,count++){
		printf("%d \t",arr[x]);
		if(count%5==0) printf("\n");
}

printf("********************************************\033[0m\n");
}
