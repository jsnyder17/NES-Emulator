#include "CPU.h"

CPU::CPU(Bus &bus) 
{   
    this->bus = bus;
    
    instructionTable[0x00][0x00] = { "BRK", 2, 8, IMPLIED, &BRK};       instructionTable[0x00][0x01] = { "ORA", 2, 6, INDIRECT, &ORA };           instructionTable[0x00][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x00][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x00][0x04] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x00][0x05] = { "ORA", 2, 3, ZEROPAGE, &ORA };           instructionTable[0x00][0x06] = { "ASL", 2, 5, ZEROPAGE, &ASL };
    instructionTable[0x01][0x00] = { "BPL", 2, 2, RELATIVE, &BPL };     instructionTable[0x01][0x01] = { "ORA", 2, 5, INDIRECT_Y, &ORA };         instructionTable[0x01][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x01][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x01][0x04] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x01][0x05] = { "ORA", 2, 4, ZEROPAGE_X, &ORA };         instructionTable[0x01][0x06] = { "ASL", 2, 6, ZEROPAGE_X, &ASL };
    instructionTable[0x02][0x00] = { "JSR", 3, 6, ABSOLUTE, &JSR};      instructionTable[0x02][0x01] = { "AND", 2, 6, X_INDIRECT, &AND };         instructionTable[0x02][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x02][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x02][0x04] = { "BIT", 2, 3, ZEROPAGE, &BIT };       instructionTable[0x02][0x05] = { "AND", 2, 3, ZEROPAGE, &AND };           instructionTable[0x02][0x06] = { "ROL", 2, 6, ZEROPAGE, &ROL }; 
    instructionTable[0x03][0x00] = { "BMI", 2, 2, RELATIVE, &BMI };     instructionTable[0x03][0x01] = { "AND", 2, 5, INDIRECT_Y, &AND };         instructionTable[0x03][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x03][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x03][0x04] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x03][0x05] = { "AND", 2, 4, ZEROPAGE_X, &AND };         instructionTable[0x03][0x06] = { "ROL", 2, 6, ZEROPAGE_X, &ROL }; 
    instructionTable[0x04][0x00] = { "RTI", 1, 7, IMPLIED, &RTI };      instructionTable[0x04][0x01] = { "EOR", 2, 6, X_INDIRECT, &EOR };         instructionTable[0x04][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x04][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x04][0x04] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x04][0x05] = { "EOR", 2, 3, ZEROPAGE, &EOR };           instructionTable[0x04][0x06] = { "LSR", 2, 5, ZEROPAGE, &LSR };
    instructionTable[0x05][0x00] = { "BVC", 2, 2, RELATIVE, &BVC };     instructionTable[0x05][0x01] = { "EOR", 2, 5, INDIRECT_Y, &EOR };         instructionTable[0x05][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x05][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x05][0x04] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x05][0x05] = { "EOR", 2, 4, ZEROPAGE_X, &EOR};          instructionTable[0x05][0x06] = { "LSR", 2, 6, ZEROPAGE_X, &LSR };
    instructionTable[0x06][0x00] = { "RTS", 1, 6, IMPLIED, &RTS };      instructionTable[0x06][0x01] = { "ADC", 2, 6, X_INDIRECT, &ADC };         instructionTable[0x06][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x06][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x06][0x04] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x06][0x05] = { "ADC", 2, 3, ZEROPAGE, &ADC };           instructionTable[0x06][0x06] = { "ROR", 2, 5, ZEROPAGE, &ROR };
    instructionTable[0x07][0x00] = { "BVS", 2, 2, RELATIVE, &BVS };     instructionTable[0x07][0x01] = { "ADC", 2, 5, INDIRECT_Y, &ADC };         instructionTable[0x07][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x07][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x07][0x04] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x07][0x05] = { "ADC", 2, 4, ZEROPAGE_X, &ADC };         instructionTable[0x07][0x06] = { "ROR", 2, 6, ZEROPAGE_X, &ROR };
    instructionTable[0x08][0x00] = { "NAH", 0, 0, CRINGE, &NAH };       instructionTable[0x08][0x01] = { "STA", 2, 6, X_INDIRECT, &STA };         instructionTable[0x08][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x08][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x08][0x04] = { "STY", 2, 3, ZEROPAGE, &STY };       instructionTable[0x08][0x05] = { "STA", 2, 3, ZEROPAGE, &STA };           instructionTable[0x08][0x06] = { "STX", 2, 3, ZEROPAGE, &STX };
    instructionTable[0x09][0x00] = { "BCC", 2, 2, RELATIVE, &BCC };     instructionTable[0x09][0x01] = { "STA", 2, 6, INDIRECT_Y, &STA };         instructionTable[0x09][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x09][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x09][0x04] = { "STY", 2, 4, ZEROPAGE_X, &STY };     instructionTable[0x09][0x05] = { "STA", 2, 4, ZEROPAGE_X, &STA };         instructionTable[0x09][0x06] = { "STX", 2, 4, ZEROPAGE_Y, &STX };
    instructionTable[0x0A][0x00] = { "LDY", 2, 2, IMMEDIATE, &LDY };    instructionTable[0x0A][0x01] = { "LDA", 2, 6, X_INDIRECT, &LDA };         instructionTable[0x0A][0x02] = { "LDX", 2, 2, IMMEDIATE, &LDX};           instructionTable[0x0A][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x0A][0x04] = { "LDY", 2, 3, ZEROPAGE, &LDY };       instructionTable[0x0A][0x05] = { "LDA", 2, 3, ZEROPAGE, &LDA };           instructionTable[0x0A][0x06] = { "LDX", 2, 3, ZEROPAGE, &LDX };
    instructionTable[0x0B][0x00] = { "BCS", 2, 2, RELATIVE, &BCS };     instructionTable[0x0B][0x01] = { "LDA", 2, 5, INDIRECT_Y, &LDA };         instructionTable[0x0B][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x0B][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x0B][0x04] = { "LDY", 2, 3, ZEROPAGE_X, &LDY };     instructionTable[0x0B][0x05] = { "LDA", 2, 4, ZEROPAGE_X, &LDA };         instructionTable[0x0B][0x06] = { "LDX", 2, 4, ZEROPAGE_Y, &LDX };
    instructionTable[0x0C][0x00] = { "CPY", 2, 2, IMMEDIATE, &CPY };    instructionTable[0x0C][0x01] = { "CMP", 2, 6, X_INDIRECT, &CMP };         instructionTable[0x0C][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x0C][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x0C][0x04] = { "CPY", 2, 3, ZEROPAGE, &CPY };       instructionTable[0x0C][0x05] = { "CMP", 2, 3, ZEROPAGE, &CMP };           instructionTable[0x0C][0x06] = { "DEC", 2, 5, ZEROPAGE, &DEC };
    instructionTable[0x0D][0x00] = { "BNE", 2, 2, RELATIVE, &BNE };     instructionTable[0x0D][0x01] = { "CMP", 2, 5, INDIRECT_Y, &CMP };         instructionTable[0x0D][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x0D][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x0D][0x04] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x0D][0x05] = { "CMP", 2, 4, ZEROPAGE_X, &CMP };         instructionTable[0x0D][0x06] = { "DEC", 2, 6, ZEROPAGE_X, &DEC };
    instructionTable[0x0E][0x00] = { "CPX", 2, 2, IMMEDIATE, &CPX };    instructionTable[0x0E][0x01] = { "SBC", 2, 6, X_INDIRECT, &SBC };         instructionTable[0x0E][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x0E][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x0E][0x04] = { "CPX", 2, 3, ZEROPAGE, &CPX };       instructionTable[0x0E][0x05] = { "SBC", 2, 3, ZEROPAGE, &SBC };           instructionTable[0x0E][0x06] = { "INC", 2, 5, ZEROPAGE, &INC };
    instructionTable[0x0F][0x00] = { "BEQ", 2, 2, RELATIVE, &BEQ };     instructionTable[0x0F][0x01] = { "SBC", 2, 5, INDIRECT_Y, &SBC };         instructionTable[0x0F][0x02] = { "NAH", 0, 0, CRINGE, &NAH };             instructionTable[0x0F][0x03] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x0F][0x04] = { "NAH", 0, 0, CRINGE, &NAH };         instructionTable[0x0F][0x05] = { "SBC", 2, 4, ZEROPAGE_X, &SBC };         instructionTable[0x0F][0x06] = { "INC", 2, 6, ZEROPAGE_X, &INC };
}