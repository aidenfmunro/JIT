#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "errors.h"

size_t getFileSize (const char* filename);

#define RETURN_ERROR(error, func)                                                                            \
    error = func;                                                                                            \
                                                                                                             \ 
    if (error)                                                                                               \
        return error;                                                                                        \

#define CheckPointerValidation(pointer)                                                                      \
    do                                                                                                       \
    {                                                                                                        \
        if (!isPointerValid(&pointer))                                                                       \
        {                                                                                                    \
            return INVALID_PTR;                                                                              \
        }                                                                                                    \
    } while(0);

#define SafeCalloc(var, nmemb, type, error)                                                                  \
    type* var = (type*)calloc(nmemb, sizeof(type));                                                          \
                                                                                                             \
    if (!var)                                                                                                \
        return error;

#define SafeRealloc(var, type, ptr, size)                                                                    \
    type* var = (type*)realloc(ptr, size);                                                                   \
                                                                                                             \
    if (!var)                                                                                                \
        return NO_MEMORY_AVAILABLE;

#define AssertSoft(expression, error, ...)                                                                   \
if (!(expression))                                                                                           \
{                                                                                                            \
    do                                                                                                       \
    {                                                                                                        \
        fprintf(stderr, "%s in %s in %s in line: %d\n", #error, __FILE__, __PRETTY_FUNCTION__, __LINE__);    \
        __VA_ARGS__;                                                                                         \
        return error;                                                                                        \
    } while(0);                                                                                              \
}

#define myOpen(filename, mode, fileVar)                                                                      \
        FILE* fileVar = fopen(filename, mode);                                                               \
                                                                                                             \
        if (fileVar == NULL)                                                                                 \
        {                                                                                                    \
            printf("Unable to open file <%s>!\n", filename);                                                 \
            return UNABLE_TO_OPEN_FILE;                                                                      \
        }

#define myRead(pointer, elemSize, fileSize, fileVar)                                                         \
        if (fread(pointer, elemSize, fileSize, fileVar) == 0)                                                \
        {                                                                                                    \
            printf("Unable to read file!\n");                                                                \
            return UNABLE_TO_READ_FILE;                                                                      \
        }

#define myWrite(pointer, elemSize, fileSize, fileVar)                                                        \
        if (fwrite(pointer, elemSize, fileSize, fileVar) == 0)                                               \
        {                                                                                                    \
            printf("Unable to wrirte to file!\n");                                                           \
            return UNABLE_TO_WRITE_FILE;                                                                     \
        }                 


#define myClose(fileVar)                                                                                     \
        fclose(fileVar);    
    
#endif 