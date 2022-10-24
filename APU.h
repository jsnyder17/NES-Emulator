#ifndef APU_H
#define APU_H

#include "Bus.h"

class APU {
    public:
        APU();
        virtual ~APU();

        Bus *bus;
};

#endif