//
//  main.c
//
//
//

#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint8_t bit_num = 32; // saves current bit position
    // reversed number
    uint32_t reversed = 0;
    
    while (bit_num > 0)
    {
        bit_num--;
        // obtain least significant bit
        uint8_t current_bit = n&1;
        printf("current bit: %u\n", current_bit);
        if (current_bit == 1)
        {
            reversed = reversed | ((uint32_t)1 << bit_num);
            printf("reversed: %u\n", reversed);
        }
        // right shift one place
        n = n >>1;
    }
    return reversed;
    
}

int main()
{
    printf("Number of ones: %u\n", reverseBits(7));
    return 0;
}
