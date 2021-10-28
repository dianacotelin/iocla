#include <stdio.h>

void main(void)
{
	int v[] = {4, 1, 2, -17, 15, 22, 6, 2};
	int max;
	int i;
	int end = sizeof(v) / sizeof(int) - 1;
	/* TODO: Implement finding the maximum value in the vector */
	max = v[0];
	i = 1;


start:
	if(i > end){
		printf("%d\n", max);
		return;
	}
	if(v[i]>max){
		max = v[i];
	}
	i++;
	goto start;

}
