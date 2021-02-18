#include <stdio.h>

int process(int i, int j, int k) {
	return i+j+k;
}

int main (void) {
	int i, j, k, nread;
	
	puts("Enter 3 integer for adding.");
	
	nread = scanf("%d %d %d", &i, &j, &k);
	
	#ifdef DEBUG
		puts("\n\n---- DEBUG INFO ----");
		fprintf(stderr, "Number of integre reads = %i\n", nread);
		fprintf(stderr, "i=%i, j=%i, k=%i\n", i, j, k);
		puts("-------------------\n");
	#endif //DEBUG
	
	printf("Total of 3 integer is: %i\n", process(i, j, k));
	return 0;
}
