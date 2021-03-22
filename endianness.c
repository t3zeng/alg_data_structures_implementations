#include <stdint.h>
#include <stdio.h>

int main() {
    uint16_t temp = 1;
    uint8_t *endian = &temp;
    printf("%d\n", *endian);
    return 0;
}