#ifndef MEMORY_H
#define MEMORY_H

#include "Bus.h"

class Memory  {
    public:
        Memory();
        virtual ~Memory();

        Bus *bus;
};

#endif