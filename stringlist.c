/*
 * stringlist.c: Implementation of string list helpers
 *
 * Before modifying this file read README.
 */

#include <stdlib.h>

#include "stringlist.h"

void
stringlist_free(char **list)
{
    char **tmp = list;

    while (tmp && *tmp) {
        free(*tmp);
        tmp++;
    }
    free(list);
}
