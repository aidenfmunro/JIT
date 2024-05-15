#ifndef ERRORS_H
#define ERRORS_H

typedef int ErrorCode;

enum Error
{
    OK,
    NULL_PTR,
    NO_MEMORY,
    UNABLE_TO_OPEN_FILE,
    UNABLE_TO_READ_FILE,
    UNABLE_TO_WRITE_FILE,
    DESTROYED,
};

#endif