#include <cpu.h>
#include <stdio.h>

uint8_t memory[0x10000]; // Simulated memory space

static uint8_t read8(uint16_t addr) {
    return memory[addr];
}

static void write8(uint16_t addr, uint8_t value) {
    memory[addr] = value;
}

uint16_t cpu_get_bc(CPU *cpu) {
    return (cpu->B << 8) | cpu->C;
}

void cpu_set_bc(CPU *cpu, uint16_t value) {
    cpu->B = (value >> 8) & 0xFF;
    cpu->C = value & 0xFF;
}

// Initialize the CPU registers
void cpu_init(CPU *cpu) {
    cpu->A = 0x01;
    cpu->F = 0xB0;
    cpu->B = 0x00;
    cpu->C = 0x13;
    cpu->D = 0x00;
    cpu->E = 0xD8;
    cpu->H = 0x01;
    cpu->L = 0x4D;
    cpu->SP = 0xFFFF; // Initialize Stack Pointer to a default value
    cpu->PC = 0x0000; // Initialize Program Counter to a default value
}



