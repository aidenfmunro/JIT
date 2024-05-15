#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "jit.h"

const unsigned char MAKS_IMM   = (1 << 5);

const unsigned char MASK_REG   = (1 << 6);

const unsigned char MASK_RAM   = (1 << 7);

const unsigned char MASK_CMD   = 0x1F;


enum Command
{
    #define DEF_COMMAND(name, num, code) CMD_ ## name = num,

    #include "commands.h"

    #undef DEF_COMMAND

};

#endif