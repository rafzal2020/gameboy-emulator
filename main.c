#include <stdio.h>
#include <stdint.h>

int main(void) {
    FILE* f = fopen("tests/cpu_instrs.gb", "rb");
    uint8_t byte;
    int i = 0;
    while (fread(&byte, 1, 1, f)) {
        printf("0x%04X: 0x%02X\n", i++, byte);
    }
}
