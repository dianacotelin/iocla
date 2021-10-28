#include <stdio.h>

int main(void)
{
	int v[] =  {1, 2, 15, 51, 53, 66, 202, 7000};
	int dest = v[2]; /* 15 */
	int start = 0;
	int end = sizeof(v) / sizeof(int) - 1;
	int middle;
	int result = 0;
	
start: 
	middle = start + (end - start)/2;

	if(start>end){
		printf("Not found!\n");
		return -1;
	}
	
	if(v[middle] == dest){
		printf("%d\n", middle);
		return 0;
	}

	if(dest<v[middle]){
		end = middle -1;	
		goto start;
	}
	if (dest>v[middle]){
		start = middle +1;
		goto start;
	}

		return 0;
	/* TODO: Implement binary search */



}
