#include <stdlib.h>
#include <stdio.h>

// would usually be included in a header file
int fun(int a, int b);
int fun2 (int a, int b);

int main()
{
	printf("%d\n", fun(2,3));
	printf("%d\n", fun2(2,3));  // Obtains  "undefined reference to `fun2'" since fun2 is static
    return 0;
}
