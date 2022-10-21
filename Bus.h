#include "CPU.h"
#include "PPU.h"
#include "APU.h"
#include "Memory.h"
#include "Cartridge.h"

class Bus {
    public:
        Bus();
        virtual ~Bus();

        CPU *cpu;
        PPU *ppu;
        APU *apu;
        Memory *memory;
};