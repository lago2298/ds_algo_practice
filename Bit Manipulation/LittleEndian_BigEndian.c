//
//  main.c
//
//  This program tells the user whether the machine is Little Endian (LSB [least significant byte] first) or Big Endian (MSB first)
//
//

#include <stdio.h>

#define LITTLE_ENDIAN 1
#define BIG_ENDIAN 0

int test()
{
    // Little Endian would display it as 0x62 0x61, Big Endian would display as 0x61 0x62
    int x = 0x6162;  // 0x61 = 'a', 0x62 = 'b'
    char *ptr_char = (char *)&x;
    return *ptr_char == 'b' ? LITTLE_ENDIAN : BIG_ENDIAN;
}

int main()
{
    printf("Result of Test: %s\n", test() == LITTLE_ENDIAN ? "Little Endian" : "Big Endian");
    return 0;
}
