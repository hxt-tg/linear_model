#include "errors.h"
#include <stdio.h>

void err(int ecode, const char *info){
    fprintf(stderr, "Error %d: %s.\n", ecode, info);
}

