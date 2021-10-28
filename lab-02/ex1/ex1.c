#include <stdio.h>

/**
 * Afisati adresele elementelor din vectorul "v" impreuna cu valorile
 * de la acestea.
 * Parcurgeti adresele, pe rand, din octet in octet,
 * din 2 in 2 octeti si apoi din 4 in 4.
 */

int main() {
    int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};

    unsigned char *char_ptr =(char*) &v;
	
    printf("Din 8 in 8");

    for(int i = 0; i < 20; i++){
    	printf("%p -> 0x%x\n", char_ptr, *char_ptr);
	*char_ptr++;
    }
	
 
    unsigned short *short_ptr =(short*) &v;

    printf("Din 2 in 2");

    for(int i = 0; i < 10; i++){
    	printf("%p -> 0x%x\n", short_ptr, *short_ptr);
	*short_ptr++;
    }

    unsigned int *int_ptr =(int*) &v;

    printf("Din 4 in 4");

    for(int i = 0; i < 5; i++){
    	printf("%p -> 0x%x\n", int_ptr, *int_ptr);
	*int_ptr++;
    }


    return 0;
}
