#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* delete_first(char *s, char *pattern){
	char * pch;
	pch = strstr(s, pattern);

	int len_patt = strlen(pattern);
	int len_first = pch - s;
	char *result = malloc(40);
	strncpy(result, s, len_first);
	strcpy(result + len_first, pch+len_patt);

	return result;



}

int main(){
	char *s = "Ana are mere";
	char *pattern = "re";

	// Decomentati linia dupa ce ati implementat functia delete_first.
	printf("%s\n", delete_first(s, pattern));

	return 0;
}
