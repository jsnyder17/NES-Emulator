#include "CPU.h"
#include "Bus.h"

CPU::CPU(Bus *bus) 
{   
    this->bus = bus;
    
    instructionTable[0x00][0x00] = { "BRK", 2, 8, aMode::IMPLIED, &BRK(this) };      instructionTable[0x00][0x01] = { "ORA", 2, 6, aMode::INDIRECT, &ORA(this) };           instructionTable[0x00][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x00][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x00][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x00][0x05] = { "ORA", 2, 3, aMode::ZEROPAGE, &ORA(this) };           instructionTable[0x00][0x06] = { "ASL", 2, 5, aMode::ZEROPAGE, &ASL(this) };           instructionTable[0x00][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x00][0x08] = { "PHP", 1, 3, aMode::IMPLIED, &PHP(this) };          instructionTable[0x00][0x09] = { "ORA", 2, 2, aMode::IMMEDIATE, &ORA(this) };        instructionTable[0x00][0x0A] = { "ASL", 1, 2, aMode::ABSOLUTE, &ASL(this) };         instructionTable[0x00][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x00][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x00][0x0D] = { "ORA", 3, 4, aMode::ABSOLUTE, &ORA(this) };       instructionTable[0x00][0x0E] = { "ASL", 3, 6, aMode::ABSOLUTE, &ASL(this) };          instructionTable[0x00][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x01][0x00] = { "BPL", 2, 2, aMode::RELATIVE, &BPL(this) };     instructionTable[0x01][0x01] = { "ORA", 2, 5, aMode::INDIRECT_Y, &ORA(this) };         instructionTable[0x01][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x01][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x01][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x01][0x05] = { "ORA", 2, 4, aMode::ZEROPAGE_X, &ORA(this) };         instructionTable[0x01][0x06] = { "ASL", 2, 6, aMode::ZEROPAGE_X, &ASL(this) };         instructionTable[0x01][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x01][0x08] = { "CLC", 1, 2, aMode::IMPLIED, &CLC(this) };          instructionTable[0x01][0x09] = { "ORA", 3, 4, aMode::ABS_Y, &ORA(this) };            instructionTable[0x01][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x01][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x01][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x01][0x0D] = { "ORA", 3, 4, aMode::ABS_X, &ORA(this) };          instructionTable[0x01][0x0E] = { "ASL", 3, 7, aMode::ABS_X, &ASL(this) };             instructionTable[0x01][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x02][0x00] = { "JSR", 3, 6, aMode::ABSOLUTE, &JSR(this) };     instructionTable[0x02][0x01] = { "AND", 2, 6, aMode::INDIRECT, &AND(this) };           instructionTable[0x02][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x02][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x02][0x04] = { "BIT", 2, 3, aMode::ZEROPAGE, &BIT(this) };       instructionTable[0x02][0x05] = { "AND", 2, 3, aMode::ZEROPAGE, &AND(this) };           instructionTable[0x02][0x06] = { "ROL", 2, 6, aMode::ZEROPAGE, &ROL(this) };           instructionTable[0x02][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x02][0x08] = { "PLP", 1, 4, aMode::IMPLIED, &PLP(this) };          instructionTable[0x02][0x09] = { "AND", 2, 2, aMode::IMMEDIATE, &AND(this) };        instructionTable[0x02][0x0A] = { "ROL", 1, 2, aMode::ABSOLUTE, &ROL(this) };         instructionTable[0x02][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x02][0x0C] = { "BIT", 3, 4, aMode::ABSOLUTE, &BIT(this) };         instructionTable[0x02][0x0D] = { "AND", 3, 4, aMode::ABSOLUTE, &AND(this) };       instructionTable[0x02][0x0E] = { "ROL", 3, 6, aMode::ABSOLUTE, &ROL(this) };          instructionTable[0x02][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x03][0x00] = { "BMI", 2, 2, aMode::RELATIVE, &BMI(this) };     instructionTable[0x03][0x01] = { "AND", 2, 5, aMode::INDIRECT_Y, &AND(this) };         instructionTable[0x03][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x03][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x03][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x03][0x05] = { "AND", 2, 4, aMode::ZEROPAGE_X, &AND(this) };         instructionTable[0x03][0x06] = { "ROL", 2, 6, aMode::ZEROPAGE_X, &ROL(this) };         instructionTable[0x03][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x03][0x08] = { "SEC", 1, 2, aMode::IMPLIED, &SEC(this) };          instructionTable[0x03][0x09] = { "AND", 3, 4, aMode::ABS_Y, &AND(this) };            instructionTable[0x03][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x03][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x03][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x03][0x0D] = { "AND", 3, 4, aMode::ABS_X, &AND(this) };          instructionTable[0x03][0x0E] = { "ROL", 3, 7, aMode::ABS_X, &ROL(this) };             instructionTable[0x03][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x04][0x00] = { "RTI", 1, 7, aMode::IMPLIED, &RTI(this) };      instructionTable[0x04][0x01] = { "EOR", 2, 6, aMode::INDIRECT, &EOR(this) };           instructionTable[0x04][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x04][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x04][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x04][0x05] = { "EOR", 2, 3, aMode::ZEROPAGE, &EOR(this) };           instructionTable[0x04][0x06] = { "LSR", 2, 5, aMode::ZEROPAGE, &LSR(this) };           instructionTable[0x04][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x04][0x08] = { "PHA", 1, 3, aMode::IMPLIED, &PHA(this) };          instructionTable[0x04][0x09] = { "EOR", 2, 2, aMode::IMMEDIATE, &EOR(this) };        instructionTable[0x04][0x0A] = { "LSR", 1, 2, aMode::ABSOLUTE, &LSR(this) };         instructionTable[0x04][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x04][0x0C] = { "JMP", 3, 3, aMode::ABSOLUTE, &JMP(this) };         instructionTable[0x04][0x0D] = { "EOR", 3, 4, aMode::ABSOLUTE, &EOR(this) };       instructionTable[0x04][0x0E] = { "LSR", 3, 6, aMode::ABSOLUTE, &LSR(this) };          instructionTable[0x04][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x05][0x00] = { "BVC", 2, 2, aMode::RELATIVE, &BVC(this) };     instructionTable[0x05][0x01] = { "EOR", 2, 5, aMode::INDIRECT_Y, &EOR(this) };         instructionTable[0x05][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x05][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x05][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x05][0x05] = { "EOR", 2, 4, aMode::ZEROPAGE_X, &EOR(this)};          instructionTable[0x05][0x06] = { "LSR", 2, 6, aMode::ZEROPAGE_X, &LSR(this) };         instructionTable[0x05][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x05][0x08] = { "CLI", 1, 2, aMode::IMPLIED, &CLI(this) };          instructionTable[0x05][0x09] = { "EOR", 3, 4, aMode::ABS_Y, &EOR(this) };            instructionTable[0x05][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x05][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x05][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x05][0x0D] = { "EOR", 3, 4, aMode::ABS_X, &EOR(this) };          instructionTable[0x05][0x0E] = { "LSR", 3, 7, aMode::ABS_X, &LSR(this) };             instructionTable[0x05][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x06][0x00] = { "RTS", 1, 6, aMode::IMPLIED, &RTS(this) };      instructionTable[0x06][0x01] = { "ADC", 2, 6, aMode::INDIRECT, &ADC(this) };           instructionTable[0x06][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x06][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x06][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x06][0x05] = { "ADC", 2, 3, aMode::ZEROPAGE, &ADC(this) };           instructionTable[0x06][0x06] = { "ROR", 2, 5, aMode::ZEROPAGE, &ROR(this) };           instructionTable[0x06][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x06][0x08] = { "PLA", 1, 4, aMode::IMPLIED, &PLA(this) };          instructionTable[0x06][0x09] = { "ADC", 2, 2, aMode::IMMEDIATE, &ADC(this) };        instructionTable[0x06][0x0A] = { "ROR", 1, 2, aMode::ABSOLUTE, &ROR(this) };         instructionTable[0x06][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x06][0x0C] = { "JMP", 3, 5, aMode::INDIRECT, &JMP(this) };         instructionTable[0x06][0x0D] = { "ADC", 3, 4, aMode::ABSOLUTE, &ADC(this) };       instructionTable[0x06][0x0E] = { "ROR", 3, 6, aMode::ABSOLUTE, &ROR(this) };          instructionTable[0x06][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x07][0x00] = { "BVS", 2, 2, aMode::RELATIVE, &BVS(this) };     instructionTable[0x07][0x01] = { "ADC", 2, 5, aMode::INDIRECT_Y, &ADC(this) };         instructionTable[0x07][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x07][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x07][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x07][0x05] = { "ADC", 2, 4, aMode::ZEROPAGE_X, &ADC(this) };         instructionTable[0x07][0x06] = { "ROR", 2, 6, aMode::ZEROPAGE_X, &ROR(this) };         instructionTable[0x07][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x07][0x08] = { "SEI", 1, 2, aMode::IMPLIED, &SEI(this) };          instructionTable[0x07][0x09] = { "ADC", 3, 4, aMode::ABS_Y, &ADC(this) };            instructionTable[0x07][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x07][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x07][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x07][0x0D] = { "ADC", 3, 4, aMode::ABS_X, &ADC(this) };          instructionTable[0x07][0x0E] = { "ROR", 3, 7, aMode::ABS_X, &ROR(this) };             instructionTable[0x07][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x08][0x00] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x08][0x01] = { "STA", 2, 6, aMode::INDIRECT, &STA(this) };           instructionTable[0x08][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x08][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x08][0x04] = { "STY", 2, 3, aMode::ZEROPAGE, &STY(this) };       instructionTable[0x08][0x05] = { "STA", 2, 3, aMode::ZEROPAGE, &STA(this) };           instructionTable[0x08][0x06] = { "STX", 2, 3, aMode::ZEROPAGE, &STX(this) };           instructionTable[0x08][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x08][0x08] = { "DEY", 1, 2, aMode::IMPLIED, &DEY(this) };          instructionTable[0x08][0x09] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x08][0x0A] = { "TXA", 1, 2, aMode::IMPLIED, &TXA(this) };          instructionTable[0x08][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x08][0x0C] = { "STY", 3, 4, aMode::ABSOLUTE, &STY(this) };         instructionTable[0x08][0x0D] = { "STA", 3, 4, aMode::ABSOLUTE, &STA(this) };       instructionTable[0x08][0x0E] = { "STX", 3, 4, aMode::ABSOLUTE, &STX(this) };          instructionTable[0x08][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x09][0x00] = { "BCC", 2, 2, aMode::RELATIVE, &BCC(this) };     instructionTable[0x09][0x01] = { "STA", 2, 6, aMode::INDIRECT_Y, &STA(this) };         instructionTable[0x09][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x09][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x09][0x04] = { "STY", 2, 4, aMode::ZEROPAGE_X, &STY(this) };     instructionTable[0x09][0x05] = { "STA", 2, 4, aMode::ZEROPAGE_X, &STA(this) };         instructionTable[0x09][0x06] = { "STX", 2, 4, aMode::ZEROPAGE_Y, &STX(this) };         instructionTable[0x09][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x09][0x08] = { "TYA", 1, 2, aMode::IMPLIED, &TYA(this) };          instructionTable[0x09][0x09] = { "STA", 3, 5, aMode::ABS_Y, &STA(this) };            instructionTable[0x09][0x0A] = { "TXS", 1, 2, aMode::IMPLIED, &TXS(this) };          instructionTable[0x09][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x09][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x09][0x0D] = { "STA", 3, 5, aMode::ABS_X, &STA(this) };          instructionTable[0x09][0x0E] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };            instructionTable[0x09][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x0A][0x00] = { "LDY", 2, 2, aMode::IMMEDIATE, &LDY(this) };    instructionTable[0x0A][0x01] = { "LDA", 2, 6, aMode::INDIRECT, &LDA(this) };           instructionTable[0x0A][0x02] = { "LDX", 2, 2, aMode::IMMEDIATE, &LDX(this)};           instructionTable[0x0A][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x0A][0x04] = { "LDY", 2, 3, aMode::ZEROPAGE, &LDY(this) };       instructionTable[0x0A][0x05] = { "LDA", 2, 3, aMode::ZEROPAGE, &LDA(this) };           instructionTable[0x0A][0x06] = { "LDX", 2, 3, aMode::ZEROPAGE, &LDX(this) };           instructionTable[0x0A][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x0A][0x08] = { "TAY", 1, 2, aMode::IMPLIED, &TAY(this) };          instructionTable[0x0A][0x09] = { "LDA", 2, 2, aMode::IMMEDIATE, &LDA(this) };        instructionTable[0x0A][0x0A] = { "TAX", 1, 2, aMode::IMPLIED, &TAX(this) };          instructionTable[0x0A][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x0A][0x0C] = { "LDY", 3, 4, aMode::ABSOLUTE, &LDY(this) };         instructionTable[0x0A][0x0D] = { "LDA", 3, 4, aMode::ABSOLUTE, &LDA(this) };       instructionTable[0x0A][0x0E] = { "LDX", 3, 4, aMode::ABSOLUTE, &LDX(this) };          instructionTable[0x0A][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x0B][0x00] = { "BCS", 2, 2, aMode::RELATIVE, &BCS(this) };     instructionTable[0x0B][0x01] = { "LDA", 2, 5, aMode::INDIRECT_Y, &LDA(this) };         instructionTable[0x0B][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x0B][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x0B][0x04] = { "LDY", 2, 3, aMode::ZEROPAGE_X, &LDY(this) };     instructionTable[0x0B][0x05] = { "LDA", 2, 4, aMode::ZEROPAGE_X, &LDA(this) };         instructionTable[0x0B][0x06] = { "LDX", 2, 4, aMode::ZEROPAGE_Y, &LDX(this) };         instructionTable[0x0B][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x0B][0x08] = { "CLV", 1, 2, aMode::IMPLIED, &CLV(this) };          instructionTable[0x0B][0x09] = { "LDA", 3, 4, aMode::ABS_Y, &LDA(this) };            instructionTable[0x0B][0x0A] = { "TSX", 1, 2, aMode::IMPLIED, &TSX(this) };          instructionTable[0x0B][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x0B][0x0C] = { "LDY", 3, 4, aMode::ABS_X, &LDY(this) };            instructionTable[0x0B][0x0D] = { "LDA", 3, 4, aMode::ABS_X, &LDY(this) };          instructionTable[0x0B][0x0E] = { "LDX", 3, 4, aMode::ABS_Y, &LDX(this) };             instructionTable[0x0B][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x0C][0x00] = { "CPY", 2, 2, aMode::IMMEDIATE, &CPY(this) };    instructionTable[0x0C][0x01] = { "CMP", 2, 6, aMode::INDIRECT, &CMP(this) };           instructionTable[0x0C][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x0C][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x0C][0x04] = { "CPY", 2, 3, aMode::ZEROPAGE, &CPY(this) };       instructionTable[0x0C][0x05] = { "CMP", 2, 3, aMode::ZEROPAGE, &CMP(this) };           instructionTable[0x0C][0x06] = { "DEC", 2, 5, aMode::ZEROPAGE, &DEC(this) };           instructionTable[0x0C][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x0C][0x08] = { "INY", 1, 2, aMode::IMPLIED, &INY(this) };          instructionTable[0x0C][0x09] = { "CMP", 2, 2, aMode::IMMEDIATE, &CMP(this) };        instructionTable[0x0C][0x0A] = { "DEX", 1, 2, aMode::IMPLIED, &DEX(this) };          instructionTable[0x0C][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x0C][0x0C] = { "CPY", 3, 4, aMode::ABSOLUTE, &CPY(this) };         instructionTable[0x0C][0x0D] = { "CMP", 3, 4, aMode::ABSOLUTE, &CMP(this) };       instructionTable[0x0C][0x0E] = { "DEC", 3, 6, aMode::ABSOLUTE, &DEC(this) };          instructionTable[0x0C][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x0D][0x00] = { "BNE", 2, 2, aMode::RELATIVE, &BNE(this) };     instructionTable[0x0D][0x01] = { "CMP", 2, 5, aMode::INDIRECT_Y, &CMP(this) };         instructionTable[0x0D][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x0D][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x0D][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x0D][0x05] = { "CMP", 2, 4, aMode::ZEROPAGE_X, &CMP(this) };         instructionTable[0x0D][0x06] = { "DEC", 2, 6, aMode::ZEROPAGE_X, &DEC(this) };         instructionTable[0x0D][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x0D][0x08] = { "CLD", 1, 2, aMode::IMPLIED, &CLD(this) };          instructionTable[0x0D][0x09] = { "CMP", 3, 4, aMode::ABS_Y, &CMP(this) };            instructionTable[0x0D][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x0D][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x0D][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x0D][0x0D] = { "CMP", 3, 4, aMode::ABS_X, &CMP(this) };          instructionTable[0x0D][0x0E] = { "DEC", 3, 7, aMode::ABS_X, &DEC(this) };             instructionTable[0x0D][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x0E][0x00] = { "CPX", 2, 2, aMode::IMMEDIATE, &CPX(this) };    instructionTable[0x0E][0x01] = { "SBC", 2, 6, aMode::INDIRECT, &SBC(this) };           instructionTable[0x0E][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x0E][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x0E][0x04] = { "CPX", 2, 3, aMode::ZEROPAGE, &CPX(this) };       instructionTable[0x0E][0x05] = { "SBC", 2, 3, aMode::ZEROPAGE, &SBC(this) };           instructionTable[0x0E][0x06] = { "INC", 2, 5, aMode::ZEROPAGE, &INC(this) };           instructionTable[0x0E][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x0E][0x08] = { "INX", 1, 2, aMode::IMPLIED, &INX(this) };          instructionTable[0x0E][0x09] = { "SBC", 2, 2, aMode::IMMEDIATE, &SBC(this) };        instructionTable[0x0E][0x0A] = { "NOP", 1, 2, aMode::IMPLIED, &NOP(this) };          instructionTable[0x0E][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x0E][0x0C] = { "CPX", 3, 4, aMode::ABSOLUTE, &CPX(this) };         instructionTable[0x0E][0x0D] = { "SBC", 3, 4, aMode::ABSOLUTE, &SBC(this) };       instructionTable[0x0E][0x0E] = { "INC", 3, 6, aMode::ABSOLUTE, &INC(this) };          instructionTable[0x0E][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
    instructionTable[0x0F][0x00] = { "BEQ", 2, 2, aMode::RELATIVE, &BEQ(this) };     instructionTable[0x0F][0x01] = { "SBC", 2, 5, aMode::INDIRECT_Y, &SBC(this) };         instructionTable[0x0F][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };             instructionTable[0x0F][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x0F][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };         instructionTable[0x0F][0x05] = { "SBC", 2, 4, aMode::ZEROPAGE_X, &SBC(this) };         instructionTable[0x0F][0x06] = { "INC", 2, 6, aMode::ZEROPAGE_X, &INC(this) };         instructionTable[0x0F][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x0F][0x08] = { "SED", 1, 2, aMode::IMPLIED, &SED(this) };          instructionTable[0x0F][0x09] = { "SBC", 3, 4, aMode::ABS_Y, &SBC(this) };            instructionTable[0x0F][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x0F][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };       instructionTable[0x0F][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };           instructionTable[0x0F][0x0D] = { "SBC", 3, 4, aMode::ABS_X, &SBC(this) };          instructionTable[0x0F][0x0E] = { "INC", 3, 7, aMode::ABS_X, &INC(this) };             instructionTable[0x0F][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH(this) };
}

uint8_t CPU::ADC(CPU *cpu)
{
    switch(currInstruction.addressingMode) {
        case aMode::IMMEDIATE:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
        case aMode::ABS_Y:
            break;
        case aMode::X_INDIRECT:
            break;
        case aMode::INDIRECT_Y:
            break;
    }

    return 0;
}

uint8_t CPU::AND(CPU *cpu) {
    switch (currInstruction.addressingMode) {
        case aMode::IMMEDIATE:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
        case aMode::ABS_Y:
            break;
        case aMode::X_INDIRECT:
            break;
        case aMode::INDIRECT_Y:
            break;
    }

    return 0;
}

uint8_t CPU::ASL(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::ACCUMULATOR:
            break;
        case aMode::ZEROPAGE:  
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
    }

    return 0;
}

uint8_t CPU::BCC(CPU *cpu) 
{
    // only addressing mode is relative 

    return 0;
}

uint8_t CPU::BCS(CPU *cpu) 
{
    // only addressing mode is relative 

    return 0;
}

uint8_t CPU::BEQ(CPU *cpu)
{
    // only addressing mode is relative 

    return 0;
}

uint8_t CPU::BIT(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::ZEROPAGE:
            break;
        case aMode::ABSOLUTE:
            break;
    }

    return 0;
}

uint8_t CPU::BMI(CPU *cpu)
{
    // only addressing mode is relative

    return 0;
}

uint8_t CPU::BNE(CPU *cpu) 
{
    // only addressing mode is relative

    return 0;
}

uint8_t CPU::BPL(CPU *cpu) 
{
    // only addressing mode is relative

    return 0;
}

uint8_t CPU::BRK(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::BVC(CPU *cpu) 
{
    // only addressing mode is relative

    return 0;
}

uint8_t CPU::BVS(CPU *cpu) 
{
    // only addressing mode is relative

    return 0;
}

uint8_t CPU::CLC(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::CLD(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::CLI(CPU *cpu)
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::CLV(CPU *cpu)
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::CMP(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::IMMEDIATE:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
        case aMode::ABS_Y:
            break;
        case aMode::X_INDIRECT:
            break;
        case aMode::INDIRECT_Y:
            break;
    }

    return 0;
}

uint8_t CPU::CPX(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::IMMEDIATE:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ABSOLUTE:
            break;
    }

    return 0;
}

uint8_t CPU::CPY(CPU *cpu)
{
    switch (currInstruction.addressingMode) {
        case aMode::IMMEDIATE:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ABSOLUTE:
            break;
    }

    return 0;
}

uint8_t CPU::DEC(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
    }

    return 0;
}

uint8_t CPU::DEX(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::DEY(CPU *cpu)
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::EOR(CPU *cpu)
{
    switch (currInstruction.addressingMode) {
        case aMode::IMMEDIATE:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
        case aMode::ABS_Y:
            break;
        case aMode::X_INDIRECT:
            break;
        case aMode::INDIRECT_Y:
            break;
    }

    return 0;
}

uint8_t CPU::INC(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
    }

    return 0;
}

uint8_t CPU::INX(CPU *cpu) 
{
    // only addressing mode is implied 

    return 0;
}

uint8_t CPU::INY(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::JMP(CPU *cpu)
{
    switch (currInstruction.addressingMode) {
        case aMode::ABSOLUTE:
            break;
        case aMode::INDIRECT:
            break;
    }

    return 0;
}

uint8_t CPU::JSR(CPU *cpu) 
{
    // only addressing mode is absolute
    
    return 0;
}

uint8_t CPU::LDA(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::IMMEDIATE:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
        case aMode::ABS_Y:
            break;
        case aMode::X_INDIRECT:
            break;
        case aMode::INDIRECT_Y:
            break;
    }

    return 0;
}

uint8_t CPU::LDX(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::IMMEDIATE:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_Y:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_Y:
            break;
    }

    return 0;
}

uint8_t CPU::LDY(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::IMMEDIATE:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
    }

    return 0;
}

uint8_t CPU::LSR(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::ACCUMULATOR:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
    }

    return 0;
}

uint8_t CPU::NOP(CPU *cpu)
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::ORA(CPU *cpu)
{
    switch (currInstruction.addressingMode) {
        case aMode::IMMEDIATE:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
        case aMode::ABS_Y:
            break;
        case aMode::X_INDIRECT:
            break;
        case aMode::INDIRECT_Y:
            break;
    }

    return 0;
}

uint8_t CPU::PHA(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::PHP(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::PLA(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::PLP(CPU *cpu)
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::ROL(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::ACCUMULATOR:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
    }

    return 0;
}

uint8_t CPU::ROR(CPU *cpu)
{
    switch (currInstruction.addressingMode) {
        case aMode::ACCUMULATOR:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
    }

    return 0;
}

uint8_t CPU::RTI(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::RTS(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::SBC(CPU *cpu)
{
    switch (currInstruction.addressingMode) {
        case aMode::IMMEDIATE:
            break;
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
        case aMode::ABS_Y:
            break;
        case aMode::X_INDIRECT:
            break;
        case aMode::INDIRECT_Y:
            break;
    }

    return 0;
}

uint8_t CPU::SEC(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::SED(CPU *cpu)
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::SEI(CPU *cpu)
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::STA(CPU *cpu)
{
    switch (currInstruction.addressingMode) {
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
        case aMode::ABS_X:
            break;
        case aMode::ABS_Y:
            break;
        case aMode::X_INDIRECT:
            break;
        case aMode::INDIRECT_Y:
            break;
    }

    return 0;
}

uint8_t CPU::STX(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_Y:
            break;
        case aMode::ABSOLUTE:
            break;
    }

    return 0;
}

uint8_t CPU::STY(CPU *cpu) 
{
    switch (currInstruction.addressingMode) {
        case aMode::ZEROPAGE:
            break;
        case aMode::ZEROPAGE_X:
            break;
        case aMode::ABSOLUTE:
            break;
    }

    return 0;
}

uint8_t CPU::TAX(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::TAY(CPU *cpu) 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::TSX(CPU *cpu)
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::TXA(CPU *cpu)
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::TXS(CPU *cpu)
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::TYA(CPU *cpu)
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::NAH(CPU *cpu)
{
    return 0;
}