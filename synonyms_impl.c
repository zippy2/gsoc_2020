/*
 * synonyms_impl.c: Implementation of synonyms functions
 *
 * Before modifying this file read README.
 */

#include <stdlib.h>

#include "synonyms_impl.h"

struct _Synonyms {

};


Synonyms *
synonyms_init(void)
{
    return calloc(1, sizeof(Synonyms));
}


void
synonyms_free(Synonyms *s)
{
    if (!s)
        return;

    free(s);
}


int
synonyms_append(Synonyms *s,
                const char *word, ...)
{
    return 0;
}


char **
synonyms_get(Synonyms *s,
             const char *word)
{
    return NULL;
}
