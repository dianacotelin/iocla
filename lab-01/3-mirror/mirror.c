#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mirror(char *s)
{
	int bg = 0;
	int end = strlen(s) -1;
	char aux;

	while(bg<end){
		aux = *(s + bg);
		*(s + bg) = *(s + end);
		*(s + end) = aux;
		bg++;
		end--;
	}
	printf("%s\n", s);
}

int main()
{
	/* TODO: Test function */
	char *p = malloc(128);
	sprintf(p, "%s", "AnaAreMere");
	mirror(p);
	free(p);
	return 0;
}

