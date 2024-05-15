#include "jit.h"

ErrorCode ReadSourceBinary (JIT* jit, const char* inFileName)
{
    AssertSoft (jit,        NULL_PTR);
    AssertSoft (inFileName, NULL_PTR);

    size_t inFileSize = getFileSize (inFileName);

    jit->src_binSize = inFileSize;

    SafeCalloc (temp_bin, inFileSize, int8_t, NO_MEMORY);

    jit->src_bin      = temp_bin;

    myOpen  (inFileName, "rb", src_binFile);
    
    myRead  (jit->src_bin, sizeof (int8_t), jit->src_binSize, src_binFile);

    myClose (src_binFile);
    
    return OK;
}

ErrorCode CreateJIT (JIT* jit, const char* inFileName)
{
    AssertSoft (jit,        NULL_PTR);
    AssertSoft (inFileName, NULL_PTR);

    ErrorCode jitError = OK;

    RETURN_ERROR(jitError, ReadSourceBinary (jit, inFileName));

    RETURN_ERROR(jitError, CreateRAM        (jit));

    RETURN_ERROR(jitError, CreateBuffer     (jit));

    jit->src_ip = 0;

    jit->x86_ip = 0;

    return OK;
}

ErrorCode CreateBuffer (JIT* jit)
{
    AssertSoft (jit, NULL_PTR);

    size_t x86_binSize = jit->src_binSize * EXPAND_SIZE_TO_86;

    SafeCalloc (temp_bin, x86_binSize, int8_t, NO_MEMORY);

    jit->x86_bin     = temp_bin;

    jit->x86_binSize = x86_binSize;

    return OK;
}

ErrorCode CreateRAM (JIT* jit)
{
    AssertSoft (jit, NULL_PTR);

    SafeCalloc(tempRam, DEFAULT_JIT_RAM_SIZE, int32_t, NO_MEMORY);

    jit->jitRAM = tempRam;

    return OK;
}

ErrorCode DestroyJIT (JIT* jit)
{
    AssertSoft (jit, DESTROYED);

    free (jit->src_bin);
    free (jit->x86_bin);
    
    free (jit->jitRAM);

    jit->src_binSize = 0;
    jit->x86_binSize = 0;

    jit->src_ip      = 0;
    jit->x86_ip      = 0;

    return OK;
}