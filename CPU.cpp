#include "CPU.h"
#include "Bus.h"

CPU::CPU(Bus *bus) 
{   
    this->bus = bus;
    
    instructionTable[0x00][0x00] = { "BRK", 2, 8, aMode::IMPLIED, &BRK};       instructionTable[0x00][0x01] = { "ORA", 2, 6, aMode::INDIRECT, &ORA };           instructionTable[0x00][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x00][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x00][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x00][0x05] = { "ORA", 2, 3, aMode::ZEROPAGE, &ORA };           instructionTable[0x00][0x06] = { "ASL", 2, 5, aMode::ZEROPAGE, &ASL };           instructionTable[0x00][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x00][0x08] = { "PHP", 1, 3, aMode::IMPLIED, &PHP };          instructionTable[0x00][0x09] = { "ORA", 2, 2, aMode::IMMEDIATE, &ORA };        instructionTable[0x00][0x0A] = { "ASL", 1, 2, aMode::ABSOLUTE, &ASL };         instructionTable[0x00][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x00][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x00][0x0D] = { "ORA", 3, 4, aMode::ABSOLUTE, &ORA };       instructionTable[0x00][0x0E] = { "ASL", 3, 6, aMode::ABSOLUTE, &ASL };          instructionTable[0x00][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x01][0x00] = { "BPL", 2, 2, aMode::RELATIVE, &BPL };     instructionTable[0x01][0x01] = { "ORA", 2, 5, aMode::INDIRECT_Y, &ORA };         instructionTable[0x01][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x01][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x01][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x01][0x05] = { "ORA", 2, 4, aMode::ZEROPAGE_X, &ORA };         instructionTable[0x01][0x06] = { "ASL", 2, 6, aMode::ZEROPAGE_X, &ASL };         instructionTable[0x01][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x01][0x08] = { "CLC", 1, 2, aMode::IMPLIED, &CLC };          instructionTable[0x01][0x09] = { "ORA", 3, 4, aMode::ABS_Y, &ORA };            instructionTable[0x01][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x01][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x01][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x01][0x0D] = { "ORA", 3, 4, aMode::ABS_X, &ORA };          instructionTable[0x01][0x0E] = { "ASL", 3, 7, aMode::ABS_X, &ASL };             instructionTable[0x01][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x02][0x00] = { "JSR", 3, 6, aMode::ABSOLUTE, &JSR};      instructionTable[0x02][0x01] = { "AND", 2, 6, aMode::INDIRECT, &AND };           instructionTable[0x02][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x02][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x02][0x04] = { "BIT", 2, 3, aMode::ZEROPAGE, &BIT };       instructionTable[0x02][0x05] = { "AND", 2, 3, aMode::ZEROPAGE, &AND };           instructionTable[0x02][0x06] = { "ROL", 2, 6, aMode::ZEROPAGE, &ROL };           instructionTable[0x02][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x02][0x08] = { "PLP", 1, 4, aMode::IMPLIED, &PLP };          instructionTable[0x02][0x09] = { "AND", 2, 2, aMode::IMMEDIATE, &AND };        instructionTable[0x02][0x0A] = { "ROL", 1, 2, aMode::ABSOLUTE, &ROL };         instructionTable[0x02][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x02][0x0C] = { "BIT", 3, 4, aMode::ABSOLUTE, &BIT };         instructionTable[0x02][0x0D] = { "AND", 3, 4, aMode::ABSOLUTE, &AND };       instructionTable[0x02][0x0E] = { "ROL", 3, 6, aMode::ABSOLUTE, &ROL };          instructionTable[0x02][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x03][0x00] = { "BMI", 2, 2, aMode::RELATIVE, &BMI };     instructionTable[0x03][0x01] = { "AND", 2, 5, aMode::INDIRECT_Y, &AND };         instructionTable[0x03][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x03][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x03][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x03][0x05] = { "AND", 2, 4, aMode::ZEROPAGE_X, &AND };         instructionTable[0x03][0x06] = { "ROL", 2, 6, aMode::ZEROPAGE_X, &ROL };         instructionTable[0x03][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x03][0x08] = { "SEC", 1, 2, aMode::IMPLIED, &SEC };          instructionTable[0x03][0x09] = { "AND", 3, 4, aMode::ABS_Y, &AND };            instructionTable[0x03][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x03][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x03][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x03][0x0D] = { "AND", 3, 4, aMode::ABS_X, &AND };          instructionTable[0x03][0x0E] = { "ROL", 3, 7, aMode::ABS_X, &ROL };             instructionTable[0x03][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x04][0x00] = { "RTI", 1, 7, aMode::IMPLIED, &RTI };      instructionTable[0x04][0x01] = { "EOR", 2, 6, aMode::INDIRECT, &EOR };           instructionTable[0x04][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x04][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x04][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x04][0x05] = { "EOR", 2, 3, aMode::ZEROPAGE, &EOR };           instructionTable[0x04][0x06] = { "LSR", 2, 5, aMode::ZEROPAGE, &LSR };           instructionTable[0x04][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x04][0x08] = { "PHA", 1, 3, aMode::IMPLIED, &PHA };          instructionTable[0x04][0x09] = { "EOR", 2, 2, aMode::IMMEDIATE, &EOR };        instructionTable[0x04][0x0A] = { "LSR", 1, 2, aMode::ABSOLUTE, &LSR };         instructionTable[0x04][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x04][0x0C] = { "JMP", 3, 3, aMode::ABSOLUTE, &JMP };         instructionTable[0x04][0x0D] = { "EOR", 3, 4, aMode::ABSOLUTE, &EOR };       instructionTable[0x04][0x0E] = { "LSR", 3, 6, aMode::ABSOLUTE, &LSR };          instructionTable[0x04][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x05][0x00] = { "BVC", 2, 2, aMode::RELATIVE, &BVC };     instructionTable[0x05][0x01] = { "EOR", 2, 5, aMode::INDIRECT_Y, &EOR };         instructionTable[0x05][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x05][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x05][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x05][0x05] = { "EOR", 2, 4, aMode::ZEROPAGE_X, &EOR};          instructionTable[0x05][0x06] = { "LSR", 2, 6, aMode::ZEROPAGE_X, &LSR };         instructionTable[0x05][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x05][0x08] = { "CLI", 1, 2, aMode::IMPLIED, &CLI };          instructionTable[0x05][0x09] = { "EOR", 3, 4, aMode::ABS_Y, &EOR };            instructionTable[0x05][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x05][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x05][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x05][0x0D] = { "EOR", 3, 4, aMode::ABS_X, &EOR };          instructionTable[0x05][0x0E] = { "LSR", 3, 7, aMode::ABS_X, &LSR };             instructionTable[0x05][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x06][0x00] = { "RTS", 1, 6, aMode::IMPLIED, &RTS };      instructionTable[0x06][0x01] = { "ADC", 2, 6, aMode::INDIRECT, &ADC };           instructionTable[0x06][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x06][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x06][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x06][0x05] = { "ADC", 2, 3, aMode::ZEROPAGE, &ADC };           instructionTable[0x06][0x06] = { "ROR", 2, 5, aMode::ZEROPAGE, &ROR };           instructionTable[0x06][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x06][0x08] = { "PLA", 1, 4, aMode::IMPLIED, &PLA };          instructionTable[0x06][0x09] = { "ADC", 2, 2, aMode::IMMEDIATE, &ADC };        instructionTable[0x06][0x0A] = { "ROR", 1, 2, aMode::ABSOLUTE, &ROR };         instructionTable[0x06][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x06][0x0C] = { "JMP", 3, 5, aMode::INDIRECT, &JMP };         instructionTable[0x06][0x0D] = { "ADC", 3, 4, aMode::ABSOLUTE, &ADC };       instructionTable[0x06][0x0E] = { "ROR", 3, 6, aMode::ABSOLUTE, &ROR };          instructionTable[0x06][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x07][0x00] = { "BVS", 2, 2, aMode::RELATIVE, &BVS };     instructionTable[0x07][0x01] = { "ADC", 2, 5, aMode::INDIRECT_Y, &ADC };         instructionTable[0x07][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x07][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x07][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x07][0x05] = { "ADC", 2, 4, aMode::ZEROPAGE_X, &ADC };         instructionTable[0x07][0x06] = { "ROR", 2, 6, aMode::ZEROPAGE_X, &ROR };         instructionTable[0x07][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x07][0x08] = { "SEI", 1, 2, aMode::IMPLIED, &SEI };          instructionTable[0x07][0x09] = { "ADC", 3, 4, aMode::ABS_Y, &ADC };            instructionTable[0x07][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x07][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x07][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x07][0x0D] = { "ADC", 3, 4, aMode::ABS_X, &ADC };          instructionTable[0x07][0x0E] = { "ROR", 3, 7, aMode::ABS_X, &ROR };             instructionTable[0x07][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x08][0x00] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x08][0x01] = { "STA", 2, 6, aMode::INDIRECT, &STA };           instructionTable[0x08][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x08][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x08][0x04] = { "STY", 2, 3, aMode::ZEROPAGE, &STY };       instructionTable[0x08][0x05] = { "STA", 2, 3, aMode::ZEROPAGE, &STA };           instructionTable[0x08][0x06] = { "STX", 2, 3, aMode::ZEROPAGE, &STX };           instructionTable[0x08][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x08][0x08] = { "DEY", 1, 2, aMode::IMPLIED, &DEY };          instructionTable[0x08][0x09] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x08][0x0A] = { "TXA", 1, 2, aMode::IMPLIED, &TXA };          instructionTable[0x08][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x08][0x0C] = { "STY", 3, 4, aMode::ABSOLUTE, &STY };         instructionTable[0x08][0x0D] = { "STA", 3, 4, aMode::ABSOLUTE, &STA };       instructionTable[0x08][0x0E] = { "STX", 3, 4, aMode::ABSOLUTE, &STX };          instructionTable[0x08][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x09][0x00] = { "BCC", 2, 2, aMode::RELATIVE, &BCC };     instructionTable[0x09][0x01] = { "STA", 2, 6, aMode::INDIRECT_Y, &STA };         instructionTable[0x09][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x09][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x09][0x04] = { "STY", 2, 4, aMode::ZEROPAGE_X, &STY };     instructionTable[0x09][0x05] = { "STA", 2, 4, aMode::ZEROPAGE_X, &STA };         instructionTable[0x09][0x06] = { "STX", 2, 4, aMode::ZEROPAGE_Y, &STX };         instructionTable[0x09][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x09][0x08] = { "TYA", 1, 2, aMode::IMPLIED, &TYA };          instructionTable[0x09][0x09] = { "STA", 3, 5, aMode::ABS_Y, &STA };            instructionTable[0x09][0x0A] = { "TXS", 1, 2, aMode::IMPLIED, &TXS };          instructionTable[0x09][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x09][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x09][0x0D] = { "STA", 3, 5, aMode::ABS_X, &STA };          instructionTable[0x09][0x0E] = { "NAH", 0, 0, aMode::CRINGE, &NAH };            instructionTable[0x09][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x0A][0x00] = { "LDY", 2, 2, aMode::IMMEDIATE, &LDY };    instructionTable[0x0A][0x01] = { "LDA", 2, 6, aMode::INDIRECT, &LDA };           instructionTable[0x0A][0x02] = { "LDX", 2, 2, aMode::IMMEDIATE, &LDX};           instructionTable[0x0A][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x0A][0x04] = { "LDY", 2, 3, aMode::ZEROPAGE, &LDY };       instructionTable[0x0A][0x05] = { "LDA", 2, 3, aMode::ZEROPAGE, &LDA };           instructionTable[0x0A][0x06] = { "LDX", 2, 3, aMode::ZEROPAGE, &LDX };           instructionTable[0x0A][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x0A][0x08] = { "TAY", 1, 2, aMode::IMPLIED, &TAY };          instructionTable[0x0A][0x09] = { "LDA", 2, 2, aMode::IMMEDIATE, &LDA };        instructionTable[0x0A][0x0A] = { "TAX", 1, 2, aMode::IMPLIED, &TAX };          instructionTable[0x0A][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x0A][0x0C] = { "LDY", 3, 4, aMode::ABSOLUTE, &LDY };         instructionTable[0x0A][0x0D] = { "LDA", 3, 4, aMode::ABSOLUTE, &LDA };       instructionTable[0x0A][0x0E] = { "LDX", 3, 4, aMode::ABSOLUTE, &LDX };          instructionTable[0x0A][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x0B][0x00] = { "BCS", 2, 2, aMode::RELATIVE, &BCS };     instructionTable[0x0B][0x01] = { "LDA", 2, 5, aMode::INDIRECT_Y, &LDA };         instructionTable[0x0B][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x0B][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x0B][0x04] = { "LDY", 2, 3, aMode::ZEROPAGE_X, &LDY };     instructionTable[0x0B][0x05] = { "LDA", 2, 4, aMode::ZEROPAGE_X, &LDA };         instructionTable[0x0B][0x06] = { "LDX", 2, 4, aMode::ZEROPAGE_Y, &LDX };         instructionTable[0x0B][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x0B][0x08] = { "CLV", 1, 2, aMode::IMPLIED, &CLV };          instructionTable[0x0B][0x09] = { "LDA", 3, 4, aMode::ABS_Y, &LDA };            instructionTable[0x0B][0x0A] = { "TSX", 1, 2, aMode::IMPLIED, &TSX };          instructionTable[0x0B][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x0B][0x0C] = { "LDY", 3, 4, aMode::ABS_X, &LDY };            instructionTable[0x0B][0x0D] = { "LDA", 3, 4, aMode::ABS_X, &LDY };          instructionTable[0x0B][0x0E] = { "LDX", 3, 4, aMode::ABS_Y, &LDX };             instructionTable[0x0B][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x0C][0x00] = { "CPY", 2, 2, aMode::IMMEDIATE, &CPY };    instructionTable[0x0C][0x01] = { "CMP", 2, 6, aMode::INDIRECT, &CMP };           instructionTable[0x0C][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x0C][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x0C][0x04] = { "CPY", 2, 3, aMode::ZEROPAGE, &CPY };       instructionTable[0x0C][0x05] = { "CMP", 2, 3, aMode::ZEROPAGE, &CMP };           instructionTable[0x0C][0x06] = { "DEC", 2, 5, aMode::ZEROPAGE, &DEC };           instructionTable[0x0C][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x0C][0x08] = { "INY", 1, 2, aMode::IMPLIED, &INY };          instructionTable[0x0C][0x09] = { "CMP", 2, 2, aMode::IMMEDIATE, &CMP };        instructionTable[0x0C][0x0A] = { "DEX", 1, 2, aMode::IMPLIED, &DEX };          instructionTable[0x0C][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x0C][0x0C] = { "CPY", 3, 4, aMode::ABSOLUTE, &CPY };         instructionTable[0x0C][0x0D] = { "CMP", 3, 4, aMode::ABSOLUTE, &CMP };       instructionTable[0x0C][0x0E] = { "DEC", 3, 6, aMode::ABSOLUTE, &DEC };          instructionTable[0x0C][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x0D][0x00] = { "BNE", 2, 2, aMode::RELATIVE, &BNE };     instructionTable[0x0D][0x01] = { "CMP", 2, 5, aMode::INDIRECT_Y, &CMP };         instructionTable[0x0D][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x0D][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x0D][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x0D][0x05] = { "CMP", 2, 4, aMode::ZEROPAGE_X, &CMP };         instructionTable[0x0D][0x06] = { "DEC", 2, 6, aMode::ZEROPAGE_X, &DEC };         instructionTable[0x0D][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x0D][0x08] = { "CLD", 1, 2, aMode::IMPLIED, &CLD };          instructionTable[0x0D][0x09] = { "CMP", 3, 4, aMode::ABS_Y, &CMP };            instructionTable[0x0D][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x0D][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x0D][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x0D][0x0D] = { "CMP", 3, 4, aMode::ABS_X, &CMP };          instructionTable[0x0D][0x0E] = { "DEC", 3, 7, aMode::ABS_X, &DEC };             instructionTable[0x0D][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x0E][0x00] = { "CPX", 2, 2, aMode::IMMEDIATE, &CPX };    instructionTable[0x0E][0x01] = { "SBC", 2, 6, aMode::INDIRECT, &SBC };           instructionTable[0x0E][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x0E][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x0E][0x04] = { "CPX", 2, 3, aMode::ZEROPAGE, &CPX };       instructionTable[0x0E][0x05] = { "SBC", 2, 3, aMode::ZEROPAGE, &SBC };           instructionTable[0x0E][0x06] = { "INC", 2, 5, aMode::ZEROPAGE, &INC };           instructionTable[0x0E][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x0E][0x08] = { "INX", 1, 2, aMode::IMPLIED, &INX };          instructionTable[0x0E][0x09] = { "SBC", 2, 2, aMode::IMMEDIATE, &SBC };        instructionTable[0x0E][0x0A] = { "NOP", 1, 2, aMode::IMPLIED, &NOP };          instructionTable[0x0E][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x0E][0x0C] = { "CPX", 3, 4, aMode::ABSOLUTE, &CPX };         instructionTable[0x0E][0x0D] = { "SBC", 3, 4, aMode::ABSOLUTE, &SBC };       instructionTable[0x0E][0x0E] = { "INC", 3, 6, aMode::ABSOLUTE, &INC };          instructionTable[0x0E][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
    instructionTable[0x0F][0x00] = { "BEQ", 2, 2, aMode::RELATIVE, &BEQ };     instructionTable[0x0F][0x01] = { "SBC", 2, 5, aMode::INDIRECT_Y, &SBC };         instructionTable[0x0F][0x02] = { "NAH", 0, 0, aMode::CRINGE, &NAH };             instructionTable[0x0F][0x03] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x0F][0x04] = { "NAH", 0, 0, aMode::CRINGE, &NAH };         instructionTable[0x0F][0x05] = { "SBC", 2, 4, aMode::ZEROPAGE_X, &SBC };         instructionTable[0x0F][0x06] = { "INC", 2, 6, aMode::ZEROPAGE_X, &INC };         instructionTable[0x0F][0x07] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x0F][0x08] = { "SED", 1, 2, aMode::IMPLIED, &SED };          instructionTable[0x0F][0x09] = { "SBC", 3, 4, aMode::ABS_Y, &SBC };            instructionTable[0x0F][0x0A] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x0F][0x0B] = { "NAH", 0, 0, aMode::CRINGE, &NAH };       instructionTable[0x0F][0x0C] = { "NAH", 0, 0, aMode::CRINGE, &NAH };           instructionTable[0x0F][0x0D] = { "SBC", 3, 4, aMode::ABS_X, &SBC };          instructionTable[0x0F][0x0E] = { "INC", 3, 7, aMode::ABS_X, &INC };             instructionTable[0x0F][0x0F] = { "NAH", 0, 0, aMode::CRINGE, &NAH };
}

uint8_t CPU::ADC()
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
        case aMode::INDIRECT_X:
            break;
        case aMode::INDIRECT_Y:
            break;
    }

    return 0;
}

uint8_t CPU::AND() {
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
        case aMode::INDIRECT_X:
            break;
        case aMode::INDIRECT_Y:
            break;
    }

    return 0;
}

uint8_t CPU::ASL() 
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

uint8_t CPU::BCC() 
{
    // only addressing mode is relative 

    return 0;
}

uint8_t CPU::BCS() 
{
    // only addressing mode is relative 

    return 0;
}

uint8_t CPU::BEQ()
{
    // only addressing mode is relative 

    return 0;
}

uint8_t CPU::BIT() 
{
    switch (currInstruction.addressingMode) {
        case aMode::ZEROPAGE:
            break;
        case aMode::ABSOLUTE:
            break;
    }

    return 0;
}

uint8_t CPU::BMI()
{
    // only addressing mode is relative

    return 0;
}

uint8_t CPU::BNE() 
{
    // only addressing mode is relative

    return 0;
}

uint8_t CPU::BPL() 
{
    // only addressing mode is relative

    return 0;
}

uint8_t CPU::BRK() 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::BVC() 
{
    // only addressing mode is relative

    return 0;
}

uint8_t CPU::BVS() 
{
    // only addressing mode is relative

    return 0;
}

uint8_t CPU::CLC() 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::CLD() 
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::CLI()
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::CLV()
{
    // only addressing mode is implied

    return 0;
}

uint8_t CPU::CMP() 
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
        case aMode::INDIRECT_X:
            break;
        case aMode::INDIRECT_Y:
            break;
    }

    return 0;
}

uint8_t CPU::CPX() 
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

uint8_t CPU::CPY()
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

uint8_t CPU::DEC() 
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