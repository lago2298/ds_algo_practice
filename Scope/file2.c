#include <stdlib.h>
#include <stdio.h>

// functions by default are GLOBAL and can be used in other files
int fun(int a, int b)
{
	return a+b;
}

// can only be used in this file
static int fun2 (int a, int b)
{
	return a*b;
}