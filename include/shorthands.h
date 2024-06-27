#ifndef SHORTHANDS_H
#define SHORTHANDS_H

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned long ulong;

#define REPEAT(n, expr)                  \
    do {                                 \
        for (size_t i = 0; i < n; i++) { \
            expr                         \
        }                                \
    } while (0)

#define RUNBLOCK(expr) \
    do {               \
        expr           \
    } while (0)

#endif
