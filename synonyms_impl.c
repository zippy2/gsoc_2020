/*
 * synonyms_impl.c: Implementation of synonyms functions
 *
 * Before modifying this file read README.
 */

#include <stdlib.h>

#include "synonyms_impl.h"

struct _Synonyms {
    /* Implement me */
};


/**
 * synonyms_init:
 *
 * Returns: an instance of synonyms dictionary, or
 *          NULL on error (with errno set properly).
 */
Synonyms *
synonyms_init(void)
{
    /* Implement me */
    return NULL;
}


/**
 * synonyms_free:
 * @s: instance of synonyms dictionary
 *
 * Frees previously allocated dictionary. If @s is NULL then this
 * is NO-OP.
 */
void
synonyms_free(Synonyms *s)
{
    /* Implement me */
}


/**
 * synonyms_define:
 * @s: instance of synonyms dictionary
 * @word: a word to add to the dictionary
 * @args: a list of synonyms
 *
 * For given @word, add it to the dictionary and define its synonyms. If the
 * @word already exists in the dictionary then just extend its list of
 * synonyms.
 *
 * Returns 0 on success, -1 otherwise.
 */
int
synonyms_define(Synonyms *s,
                const char *word, ...)
{
    return -1;
}


/*
 * is_synonym:
 * @s: instance of synonyms dictionary
 * @w1: a word
 * @w2: a word
 *
 * Checks whether @w1 is defined synonym of @w2 (or vice versa).
 */
bool
is_synonym(Synonyms *s,
           const char *w1,
           const char *w2)
{
    /* Implement me */
    return false;
}


/**
 * synonyms_get:
 * @s: instance of synonyms dictionary
 * @word: a word
 *
 * Returns: a string list of defined synonyms for @word, or
 *          NULL if no synonym was defined or an error occurred.
 */
char **
synonyms_get(Synonyms *s,
             const char *word)
{
    /* Implement me */
    return NULL;
}
