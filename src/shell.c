#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 50

int* generate_arr(int num);
void shell_sort( int * arr, int num);
void show_array(int* arr, int num);

int main(){

srand(time(NULL));
int * arr = generate_arr(SIZE);

shell_sort(arr,SIZE);
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

*/
void shell_sort(int * arr, int num){

	int dist;

	for(dist = num/2; dist>0; dist=dist/2){

		for(int i=dist;i<num;i++){
			int key = arr[i];int j = i-dist;
			while(j>=0 && key<arr[j]){
				arr[j+dist] = arr[j];
				j = j -dist;
			}
			arr[j+dist] = key;
		}
}
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
