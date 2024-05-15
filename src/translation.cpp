#include "translation.h"

ErrorCode translateBinary (JIT* jit)
{
    AssertSoft (jit, NULL_PTR);


}

ErrorCode translateCommand (JIT* jit)
{
    AssertSoft (jit, NULL_PTR);

    int8_t cmd = jit->src_bin[jit->src_ip] & MASK_CMD;

    ErrorCode translateError = OK;

    switch (cmd)
    {
        case CMD_PUSH:
        case CMD_POP:

            RETURN_ERROR(translateError, translateMemory (jit, cmd));

            return OK;

        case CMD_ADD:
        case CMD_SUB:
        case CMD_MUL:
        case CMD_DIV:
        
            RETURN_ERROR(translateError, translateArithmetic (jit, cmd));

            return OK;
        
        case CMD_JMP:

            RETURN_ERROR(translateError, translateJump (jit) );

        case CMD_JA:
        case CMD_JAE:
        case CMD_JB:
        case CMD_JBE:
        case CMD_JE:
        case CMD_JNE:

            RETURN_ERROR()

    }


    return OK;
}

ErrorCode translateArithmetic (JIT* jit, int8_t cmd)
{

    return OK;
}

ErrorCode translateMemory (JIT* jit, int8_t cmd)
{

    return OK;
}

ErrorCode translateJump (JIT* jit)
{

    return OK;
}

ErrorCode translateCondJump (JIT* jit)
{

    return OK;
}
