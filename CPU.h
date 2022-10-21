/*
 * I hope you all have a lot of fun reading this :)
 */

#include <stdint.h>
#include <string>

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

typedef struct instruction {
    std::string name;           // name of the instruction
    uint8_t numbytes;           // the number of bytes the instruction uses
    uint8_t numcycles;          // the number of cycles it takes for the instruction to complete
    aMode addressingMode;       // the addressing mode used by the cycle
    uint8_t(CPU::*operation)();      // function pointer to the appropriate opcode function 

} instruction_t;

class CPU {
    public:
        CPU(Bus *bus);
        virtual ~CPU();

        // BEHOLD! FUNCTIONS!
        uint8_t ADC(); uint8_t AND(); uint8_t ASL();
        uint8_t BCC(); uint8_t BCS(); uint8_t BEQ(); uint8_t BIT(); uint8_t BMI(); uint8_t BNE(); uint8_t BPL(); uint8_t BRK(); uint8_t BVC(); uint8_t BVS();
        uint8_t CLC(); uint8_t CLD(); uint8_t CLI(); uint8_t CLV(); uint8_t CMP(); uint8_t CPX(); uint8_t CPY();
        uint8_t DEC(); uint8_t DEX(); uint8_t DEY(); 
        uint8_t EOR(); 
        uint8_t INC(); uint8_t INX(); uint8_t INY();
        uint8_t JMP(); uint8_t JSR();
        uint8_t LDA(); uint8_t LDX(); uint8_t LDY(); uint8_t LSR();
        uint8_t NOP(); 
        uint8_t ORA();
        uint8_t PHA(); uint8_t PHP(); uint8_t PLA(); uint8_t PLP();
        uint8_t ROL(); uint8_t ROR(); uint8_t RTI(); uint8_t RTS();
        uint8_t SBC(); uint8_t SEC(); uint8_t SED(); uint8_t SEI(); uint8_t STA(); uint8_t STX(); uint8_t STY();
        uint8_t TAX(); uint8_t TAY(); uint8_t TSX(); uint8_t TXA(); uint8_t TXS(); uint8_t TYA();
        uint8_t NAH();

        // We bussin 
        void writeBus(uint16_t address, uint8_t data);     // Functioin to write data to the bus
        uint16_t readBus(uint16_t address);                 // Function to read data from the bus from the specified address 

        // Instruction set matrix 
        instruction_t instructionTable[16][16];     // Just wait until you get to read the .cpp file :) 

        // Registers 
        uint8_t reg_X;
        uint8_t reg_Y;
        uint8_t reg_A;
        uint8_t r_PS;
        uint16_t r_PC;

        // Pointer to the bus instance 
        Bus *bus;
};