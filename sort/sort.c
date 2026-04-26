#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int arr[],int len);
void insert(int arr[], int len);
void choose(int arr[],int len);


void generate_array(int arr[],int len);
void print_array(int arr[], int len);



int main()
{
	srand(time(NULL));	//time seed
	int len =100;
	int sample[len];
	generate_array(sample,len);

	print_array(sample,len);
	choose(sample,len);
	print_array(sample,len);

	return 0;
}

/*////////////////////////
  Function choose sort

\************************/
void choose(int arr[], int len)
{
	int note;
	for(int i=0; i<len-1;i++)
	{
	note = i;	
		for(int j = i+1;j<len;j++)
		{
			if(arr[j]>arr[note])
			{
				note = j;
			}
		}
		int tmp = arr[note];
		arr[note] = arr[i];
		arr[i] = tmp;
	
	}

printf("\n\033[37mCHOOSE - SORT FINISHED\033[0m\n");
}
/************************************\
  Function : generate array   require "time.h"
  Generate an array with random numbers;
  return void; function;
\************************************/
void generate_array(int arr[],int len)
{
	for(int i = 0; i<len; i++)
	{
		arr[i] = rand()%999;

	}
}

/**************************************
  Function : print array
  print an array 
\*************************************/
void print_array(int arr[],int len)
{
//	printf("\033[31m\n---------------ARRAY---SAMPLE----------------\n");
	int note=1;
	for(int i = 0; i<len; i++,note++)
	{
		printf("%d\t",arr[i]);
		if(note%10==0)
			printf("\n");
	}
//	printf("----------------------------------------------\n\033[0m");
}
/**************************************
  Function: bubble sort

***************************************/

void bubble(int arr[],int len)
{
	for(int i = 0; i<len-1;i++)
	{
		for(int j = 0;j<len-i-1;j++)
		{	
			if(arr[j]>arr[j+1])
			{
			int tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
			}
		}
	}
printf("\n\033[37mBUBBLE SORT FINISHED\033[0m\n");
}

/****************************

 FUNCTION INSERT SORT

 ****************************/
void insert(int arr[],int len)
{
	for(int i=1;i<len;i++)
	{
		// set the limit from 1....len
		int j = i-1;
		int note = arr[j+1];

		while(j>=0 && arr[j]>note){
		// if arr[j] bigger than the mark-note, switch
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = note;
	}

printf("\n\033[36mINSERT SORT FINISHED\033[0m\n");
}





























