/*
 * I hope you all have a lot of fun reading this :)
 */

#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <string>

#include "Bus.h"

// enums for the different addressing modes 
enum aMode {
    ACCUMULATOR,
    ABSOLUTE,
    ABS_X,
    ABS_Y,
    IMMEDIATE,
    IMPLIED,
    INDIRECT,
    X_INDIRECT,
    INDIRECT_Y,
    RELATIVE,
    ZEROPAGE,
    ZEROPAGE_X,
    ZEROPAGE_Y,
    CRINGE
};

class CPU {
    public:
        CPU(Bus *bus);
        virtual ~CPU();

        typedef struct instruction {
            std::string name;                   // name of the instruction
            uint8_t numbytes;                   // the number of bytes the instruction uses
            uint8_t numcycles;                  // the number of cycles it takes for the instruction to complete
            aMode addressingMode;               // the addressing mode used by the cycle
            uint8_t(CPU::*operation)(*CPU);     // function pointer to the appropriate opcode function 

        } instruction_t;


        // BEHOLD! FUNCTIONS!
        uint8_t ADC(CPU *cpu); uint8_t AND(CPU *cpu); uint8_t ASL(CPU *cpu);
        uint8_t BCC(CPU *cpu); uint8_t BCS(CPU *cpu); uint8_t BEQ(CPU *cpu); uint8_t BIT(CPU *cpu); uint8_t BMI(CPU *cpu); uint8_t BNE(CPU *cpu); uint8_t BPL(CPU *cpu); uint8_t BRK(CPU *cpu); uint8_t BVC(CPU *cpu); uint8_t BVS(CPU *cpu);
        uint8_t CLC(CPU *cpu); uint8_t CLD(CPU *cpu); uint8_t CLI(CPU *cpu); uint8_t CLV(CPU *cpu); uint8_t CMP(CPU *cpu); uint8_t CPX(CPU *cpu); uint8_t CPY(CPU *cpu);
        uint8_t DEC(CPU *cpu); uint8_t DEX(CPU *cpu); uint8_t DEY(CPU *cpu); 
        uint8_t EOR(CPU *cpu); 
        uint8_t INC(CPU *cpu); uint8_t INX(CPU *cpu); uint8_t INY(CPU *cpu);
        uint8_t JMP(CPU *cpu); uint8_t JSR(CPU *cpu);
        uint8_t LDA(CPU *cpu); uint8_t LDX(CPU *cpu); uint8_t LDY(CPU *cpu); uint8_t LSR(CPU *cpu);
        uint8_t NOP(CPU *cpu); 
        uint8_t ORA(CPU *cpu);
        uint8_t PHA(CPU *cpu); uint8_t PHP(CPU *cpu); uint8_t PLA(CPU *cpu); uint8_t PLP(CPU *cpu);
        uint8_t ROL(CPU *cpu); uint8_t ROR(CPU *cpu); uint8_t RTI(CPU *cpu); uint8_t RTS(CPU *cpu);
        uint8_t SBC(CPU *cpu); uint8_t SEC(CPU *cpu); uint8_t SED(CPU *cpu); uint8_t SEI(CPU *cpu); uint8_t STA(CPU *cpu); uint8_t STX(CPU *cpu); uint8_t STY(CPU *cpu);
        uint8_t TAX(CPU *cpu); uint8_t TAY(CPU *cpu); uint8_t TSX(CPU *cpu); uint8_t TXA(CPU *cpu); uint8_t TXS(CPU *cpu); uint8_t TYA(CPU *cpu);
        uint8_t NAH(CPU *cpu);

        // We bussin 
        void writeBus(uint16_t address, uint8_t data);      // Functioin to write data to the bus
        uint16_t readBus(uint16_t address);                 // Function to read data from the bus from the specified address 

        // Instruction set matrix 
        instruction_t instructionTable[16][16];             // Just wait until you get to read the .cpp file :) 

        // Registers 
        uint8_t reg_X;
        uint8_t reg_Y;
        uint8_t reg_A;
        uint8_t r_PS;
        uint16_t r_PC;

        // Pointer to the bus instance 
        Bus *bus;

        // Current instruction
        instruction_t currInstruction;
};

#endif