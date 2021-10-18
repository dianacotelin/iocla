#include <stdio.h>
#include <stdlib.h>

void print_binary(int number, int nr_bits)
{
	/* TODO  */
	int i;
	for( i = 1 << nr_bits; i > 0; i = i/ 2){
		if (number & i)
			printf ("1");
		else 
			printf("0");
	}

	
}

void check_parity(int *numbers, int n)
{

	/* TODO */
	if ( n == 0){
                printf("0b");
		print_binary (*numbers, 7);
	}
	else
                printf("0x%08x", *numbers);
	printf("\n");

        

}

int main()
{
	/* TODO: Test functions */
	int v[5] = {214, 71, 84, 134, 86};
	int parity;
	for ( int i = 0; i < 5; i++){
		if (*(v+i) % 2 == 0)
			parity = 0;
		else
			parity = 1;
		check_parity(v+i, parity);
	}

	return 0;
}

