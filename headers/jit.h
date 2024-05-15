#ifndef JIT_H
#define JIT_H

#include <stdio.h>
#include <inttypes.h>

#include "errors.h"
#include "utils.h"

//

const size_t EXPAND_SIZE_TO_86    = 8;

const size_t DEFAULT_JIT_RAM_SIZE = 4000;

//

struct JIT
{  
    int8_t*  x86_bin;
    int8_t*  src_bin;

    size_t   x86_ip;
    size_t   src_ip;

    size_t   x86_binSize;
    size_t   src_binSize;

    int32_t* jitRAM;
};

//

ErrorCode CreateJIT        (JIT* jit, const char* inFileName);

ErrorCode DestroyJIT       (JIT* jit);

ErrorCode ReadSourceBinary (JIT* jit, const char* inFileName);

ErrorCode CreateBuffer     (JIT* jit);

ErrorCode CreateRAM        (JIT* jit);

#endif