#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern uint8_t memory[0x10000]; // Simulated memory space

int load_rom(const char *filename) {
    FILE *rom_file = fopen(filename, "rb");
    if (!rom_file) {
        fprintf(stderr, "Failed to open ROM file: %s\n", filename);
        return -1;
    }

    fseek(rom_file, 0, SEEK_END);
    long rom_size = ftell(rom_file);
    rewind(rom_file);

    if (rom_size > 0x10000) {
        fprintf(stderr, "ROM size exceeds memory limit.\n");
        fclose(rom_file);
        return -1;
    }
    fread(memory, 1, rom_size, rom_file);
    fclose(rom_file);

    return 1;
}