#include <stdio.h>
#include <stdlib.h>

int main() {
	char *str = NULL;
/* stored in read only part of date segment */
	str = "GfG";
	
	/*Problem: trying to modify read only memory*/
	*(str + 1) = 'n';
	return 0;
}
