#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int my_strcmp(const char *s1, const char *s2){
	int idx = 0;
	while(*s1) {
		if(*(s1+idx) != *(s2 + idx)) {
			return *(s1+idx) - *(s2+idx);
		}
		idx++;
	}
	return 0;

}
void *my_memcpy(void *dest, const void *src, size_t n){
	char *pszDest = (char*)dest;
        const char *pszSource = (const char*)src;
        if((pszDest != NULL) && (pszSource != NULL)) {
                while(n){
                        *(pszDest++) = *(pszSource++);
                        --n;
                }

        }
        return dest;
}
char *my_strcpy(char *dest, const char *src) {
	char *start = dest;
	while(*src) {
		*(dest++) = *(src++);
	}
	return start;
}

int main() {
	char s1[] = "Abracadabra";
	char s2[] = "Abracababra";
	char src[] = "Learn IOCLA, you must!";
	char *dest = malloc(sizeof(src));

	/*
	Decomentati pe rand cate un assert pe masura ce implementati o functie.
	Daca functia voastra este implementata corect atunci asertia se va realiza
	cu succes. In caz contrar, programul va crapa.
	*/
	assert(my_strcmp(s1, s2) == strcmp(s1, s2));
	assert(my_memcpy(dest, src, sizeof(src)) == memcpy(dest, src, sizeof(src)));
	assert(my_strcpy(dest, src) == strcpy(dest, src));
	free(dest);

	return 0;
}
