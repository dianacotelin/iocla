#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	Functie generica pentru calcularea valorii maxime dintr-un array.
	n este dimensiunea array-ului
	element_size este dimensiunea unui element din array
	Se va parcurge vectorul arr, iar la fiecare iteratie sa va verifica
	daca functia compare intoarce 1, caz in care elementul curent va fi
	si cel maxim. 
	Pentru a folosi corect aritmetica pe pointeri vom inmulti indexul curent
	din parcurgere cu dimensiunea unui element.
	Astfel, pentru accesarea elementului curent avem:
	void *cur_element = (char *)arr + index * element_size;
*/

void *find_max(void *arr, int n, int element_size, 
				int (*compare)(const void *, const void *)) {
	void *max_elem = arr;
	int index = 0;
	while( index < n) {
		void *c_elem = (char *)arr + index* element_size;
		if(compare(max_elem, c_elem)){
		max_elem = (char *)arr + index * element_size;
		}
		index++;
	}	
	return max_elem;
}

/*
	a si b sunt doi pointeri la void, dar se specifica in enunt
	ca datele de la acele adrese sunt de tip int, asadar trebuie
	castati.
	Functia returneaza 1 daca valorea de la adresa lui a este mai
	mare decat cea de la adresa lui b, in caz contrar returneaza 0.
*/

int compare(const void *a, const void *b){
	const char* a1 = (const char*) a;
	const char* b1 = (const char*) b;
	if(*a1 < *b1){
		return 1;
	}
	return 0;
}

/*
	Se citeste de la tastatura un vector si se cere sa se afle
	elementul maxim folosind functia find_max.
	Rezultatul functiei find_max trebuie cast la int, spre exemplu:
	int *res = (*int) find_max(...);
*/
int main() {
	int n;
	scanf("%d", &n);

	int *arr = malloc(n * sizeof(*arr));

	for (int i = 0 ; i < n; ++i)
		scanf("%d", &arr[i]);       
	
	int *res = (int*)find_max(arr,n,sizeof(int),compare);
	printf("%d", *res);
	free(arr);
	return 0;
}
