#ifndef CPU_H
#define CPU_H

#include <stdint.h>

// CPU Register structure
typedef struct {
    uint8_t A,F;
    uint8_t B,C;
    uint8_t D,E;
    uint8_t H,L;
    uint16_t SP, PC; // Stack Pointer and Program Counter
} CPU;

void cpu_init(CPU *cpu);
void cpu_step(CPU *cpu);

uint16_t cpu_get_bc(CPU *cpu);
void cpu_set_bc(CPU *cpu, uint16_t value);

#endif