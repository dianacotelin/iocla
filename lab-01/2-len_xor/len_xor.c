#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *str)
{
	/* TODO */	
	int len = 0;
	while(*str++) len++;
	return len;
}

void equality_check(const char *str)
{
	/* TODO */
	int i = 0;
	int len = my_strlen(str);
	for(i = 0; i < my_strlen(str); i++) {
		if(!(*(str + i) ^ *(str + ((i + (2<<i)))% len)))
			printf("equal at %p val %c idx %d\n", str + i, *(str + i), i);
	}
}

int main(void)
{
	/* TODO: Test functions */
	printf("Len = %d\n", my_strlen("ababababaccbacbacbacbacbac"));
	equality_check("ababababacccbacbacbacbacbabc");
	return 0;
}

