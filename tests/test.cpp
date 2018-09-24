#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

void mytestfunc(void) {
	printf("mytestfunction inside main function\n");
}

int main() {
	
	int * ptr;
//	atexit(mytestfunc);

	ptr = (int *)malloc(4);
	printf("ptr is %p\n", ptr);
	*ptr = 4;
	free(ptr);

	ptr = (int *) malloc(8);
	printf("ptr is %p\n", ptr);
	ptr++;
	*ptr = 4;
}
