#include "cpu.h"
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

void cpu_step(CPU *cpu) {
    // get the opcodes from the program and load them into memory
    uint8_t opcode = read8(cpu->PC++);

    switch(opcode) {
        case 0x00: // NOP
            printf("NOP executed at PC: 0x%04X\n", cpu->PC - 1);
            break;
        case 0x01: // LD BC,nn
            // show b and c registers before loading
            printf("LD BC,nn executed at PC: 0x%04X\n", cpu->PC - 1);
            printf("Before LD BC,nn: B = 0x%02X, C = 0x%02X\n", cpu->B, cpu->C);
            cpu_set_bc(cpu, (read8(cpu->PC++) << 8) | read8(cpu->PC++));
            // show the value loaded into BC
            printf("LD BC,nn executed with value 0x%04X at PC: 0x%04X\n", cpu_get_bc(cpu), cpu->PC - 2);
            printf("LD BC,nn executed at PC: 0x%04X\n", cpu->PC - 2);
            break;
        case 0xAF: // XOR A
            cpu->A ^= cpu->A; // A = A XOR A
            cpu->F = (cpu->A == 0) ? 0x80 : 0x00; // Set Z flag if A is zero
            // show the result of the XOR operation
            printf("XOR A executed, A = 0x%02X, F = 0x%02X at PC: 0x%04X\n", cpu->A, cpu->F, cpu->PC - 1);
            break;
        default:
            fprintf(stderr, "Unknown opcode: 0x%02X at PC: 0x%04X\n", opcode, cpu->PC - 1);
            break;
    }
}



