#include <stdio.h>

extern int val;
char *s = "hello";
char t[] = "hello";

int main()
{
	//*(s+2) = 't';  // string literals are stored in read only memory?- so can't write to it
	t[3] = 'x';
	printf("value: %d\n", val);
	printf("string: %s", t);
	return 0;
}