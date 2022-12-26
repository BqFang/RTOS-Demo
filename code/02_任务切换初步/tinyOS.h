#ifndef __TINYOS_H
#define __TINYOS_H

#include <stdint.h>


typedef uint32_t tTaskStack;

typedef struct _tTask {
    uint32_t *stack;
}tTask;


#endif /*__TINYOS_H */




