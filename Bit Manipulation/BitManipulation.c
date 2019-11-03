//
//  main.c
//
//
//

#include <stdio.h>

int count_ones(int n)
{
	int count = 0;
	printf("Value of %d in hex: %04x\n", n, n);
    while(n) 
	{
		n = n&(n-1);
		count++;
	}
	return count;
}

int main()
{
    printf("Number of ones: %d\n", count_ones(7));
    return 0;
}
