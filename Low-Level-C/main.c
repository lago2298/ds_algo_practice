#include <stdio.h>

extern int val;
char *s = "hello";

int main()
{
	*(s+2) = 't';  // string literals are stored in read only memory?- so can't write to it
	printf("value: %d\n", val);
	printf("string: %s", s);
	return 0;
}