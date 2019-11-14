#include <stdio.h>

#define MAX(A,B) ((A) > (B)) ? (A) : (B)
#define JACKETS 8734UL

#define DEVICE_IS_EMBEDDED 0

#ifdef DEVICE_IS_EMBEDDED
#define HI 2
#else 
#define DEVICE_IS_REGULAR
#error No embedded devices here
#endif

// b is bit from 0 to n-1
//ULL = 64 bit wide integer constant
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= (~((1ULL)<<(b))))
#define BIT_TOGGLE(a,b) ((a) ^= (1ULL<<(b)))

extern int val;
char *s = "hello";
char t[] = "hello";

int main()
{
	//*(s+2) = 't';  // string literals are stored in read only memory?- so can't write to it
	t[3] = 'x';
	printf("value: %d\n", val);
	printf("string: %s\n", t);
	int max = MAX(5,7);
	printf("max: %d\n", max);
	printf("jackets: %u\n", JACKETS);
	
	unsigned int a = 0x10;
	// set bit 3 of a
	unsigned int mask_set = (unsigned int)((0x1) << 2);
	printf("a: 0x%x; mask_set: 0x%x", a, mask_set);
	printf("set the bit: "); // use |
	a = a | mask_set;
	printf("a: 0x%x\n", a);
	
	// clear bit wiht &~
	a = a & (~mask_set);
	printf("a: 0x%x\n", a);
	
	BIT_SET(a,3);
	printf("a: 0x%x\n", a);
	BIT_CLEAR(a,3);
	printf("a: 0x%x\n", a);
	BIT_TOGGLE(a,3);
	printf("a: 0x%x\n", a);
	BIT_TOGGLE(a,3);
	printf("a: 0x%x\n", a);
	/*int a;
	int *a;
	int **a;
	int a[10];
	int *a[10]; // array of 10 pointers to integers
	int (*a)[10]; // pointer to array of 10 integers
	int (*a) (int a); // pointer to function that takes integer as argument and returns integer
	int (*a[10])(int a); // array of 10 pointers to functions*/
	return 0;
}