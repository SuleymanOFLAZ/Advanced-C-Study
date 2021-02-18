#include <stdio.h>

int main(){
	#ifdef MY_MACRO
		puts("MY_MACRO is defined.");
	#endif
	// This is a test file for compile option via terminal
	int i = 0;
	char c = -10;
	printf("Char = %i\n", c);
	printf("Hello World!\n");
	return 0;
}
