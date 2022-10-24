#ifndef PPU_H
#define PPU_H

#include "Bus.h"

class PPU {
    public:
        PPU();
        virtual ~PPU();

        Bus *bus;
};

#endif