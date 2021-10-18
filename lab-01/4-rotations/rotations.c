#include <stdio.h>

void rotate_left(int *number, int bits)
{
	/* TODO */
	int aux;
	bits = bits % 31;

	while(bits){
	aux = (*number >> 31) & 1;
	*number = (*number << 1) | aux;
	bits--;
	}
	printf("%d\n", *number);
}

void rotate_right(int *number, int bits)
{
	/* TODO */
	int aux;
	bits = bits % 31;

	while(bits){
	aux = *number & 1;
        *number = (*number >>  1) & (~(1 << 31));
	*number = *number | (aux << 31);
	
	bits--;
	}
	 printf("%d\n", *number);
}

int main()
{
	/* TODO: Test functions */
	int *p; 
	int number = 0x80000000;
	p = &number;
	rotate_left(p, 1);
	rotate_right(p, 16);
	return 0;
}

