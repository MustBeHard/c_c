#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 100

void show(int * iarr, int num){
for(int i=0;i<num;i++){
	printf("%d \t ",iarr[i]);
}
printf("\n");
}

int * get_arr( int size ){
	int * x = (int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){	
		x[i] = rand()%10000;
	}
return x;
}

void bubble(int *  arr , int num){
	int i,j;
	for(i = 0; i<num-1;i++){
		for(j = 0; j<num-i-1; j++){
			 if(arr[j]>arr[j+1]){
				int tmp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = tmp;
					}
				}
			}
}

void choose(int *arr,int num){

	int i,j,key;
	
	for (i =0; i<num-1; i++){
		key = i;
		// asume i is the bigest for now
		for(j =i+1;j<num;j++){
		//switch
			if(arr[key]>arr[j])
				key = j;
		}

		int tmp = arr[key];
		arr[key] = arr[i];
		arr[i] = tmp;

		}
}

void insert(int * arr, int num){
	//seperat the whole array : sorted unsorted
	int j,i, key;

	for(i=1;i<num;i++){	
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j] >key){
			arr[j+1] = arr[j];
			j--;
			}
		arr[j+1] = key;
		
		}
}
void bub(int * arr, int num){
	int i,j;
	int tmp;
	for(i = 0;i<num-1;i++){
		for(j=0;j<num-i-1;j++){
			if(arr[j]>arr[j+1]){
					tmp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = tmp;
					
					}
				}
			}

}

void shell(int * arr, int num){

	int gap, j,i;

	for(gap = num/2;gap>0;gap = gap/2)

		for(i = gap; i<num;i = i+gay)

			j = gap
			



















}
int main(){
srand(time(NULL));
int * arr;
arr = get_arr(SIZE);
clock_t start,stop;


insert(arr,SIZE);

show(arr,SIZE);
return 0;
}
