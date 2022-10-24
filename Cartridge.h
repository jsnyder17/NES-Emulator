#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include "Bus.h"

class Cartridge {
    public:
        Cartridge();
        virtual ~Cartridge();

        Bus *bus;
};

#endif