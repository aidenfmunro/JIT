#include "utils.h"

size_t getFileSize (const char* filename)
{
    AssertSoft(filename, NULL_PTR);

    struct stat stats = {};
    
    stat(filename, &stats);

    return stats.st_size;
}