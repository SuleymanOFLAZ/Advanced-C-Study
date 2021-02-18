#include <stdio.h>
#include <stdlib.h>

struct new {
	int one;
	int two;
	int three;
};

struct new foo(struct new x){
	++x.two;
	return x;
}

int main() {
	struct new foo();
	
	foo().one = 4;
	
	printf("%d", foo.one);
}
	
