#include <stdio.h>
#include <stdint.h>

#include "cpu.h"

extern uint8_t memory[0x10000]; // Simulated memory space
int load_rom(const char *filename);

int main(int argc, char *argv[]) {
    /*FILE* f = fopen("tests/cpu_instrs.gb", "rb");
    uint8_t byte;
    int i = 0;
    while (fread(&byte, 1, 1, f)) {
        printf("0x%04X: 0x%02X\n", i++, byte);
    }*/
   if (argc < 2) {
        fprintf(stderr, "Usage: %s <ROM file>\n", argv[0]);
        return 1;
    }

    if (!load_rom(argv[1])) {
        fprintf(stderr, "Failed to load ROM.\n");
        return 1;
    }

    CPU cpu;
    cpu_init(&cpu);

    // main loop
    for (int i = 0; i < 100000; ++i) {
        cpu_step(&cpu); // Assuming cpu_step is defined to execute one CPU instruction
    }

}
