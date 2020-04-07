/*
 * This file should stay unchanged.
 * Read README for more info.
 */

#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "synonyms_impl.h"
#include "stringlist.h"

#define ERROR(...) \
do { \
    fprintf(stderr, "ERROR %s:%d : ", __FUNCTION__, __LINE__); \
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, "\n"); \
} while (0)


#define SYS_ERROR(...) \
do { \
    char ebuf[1024]; \
    strerror_r(errno, ebuf, sizeof(ebuf)); \
    fprintf(stderr, "System error %s:%d : ", __FUNCTION__, __LINE__); \
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, " : %s\n", ebuf); \
    fprintf(stderr, "\n"); \
} while (0)


#define SYNONYMS_DEFINE(s, word, ...) \
do { \
    if (synonyms_define(s, word, __VA_ARGS__) < 0) { \
        ERROR("Unable to define synonym for \"" word "\""); \
        goto cleanup; \
    } \
} while (0)


#define IS_SYNONYM(s, word1, word2, expect) \
do { \
    if (is_synonym(s, word1, word2) != expect) { \
        ERROR("Unexpected is_synonym(\"" word1 "\", \"" word2 "\") retval"); \
        goto cleanup; \
    } \
} while(0)


#define SYNONYMS_CHECK(s, word, expect) \
do { \
    if (synonyms_check(s, word, expect) < 0) \
        goto cleanup; \
} while (0)


#define STREQ(a, b) (strcmp(a, b) == 0)


static int
synonyms_check(Synonyms *s,
               const char *word,
               const char *expect)
{
    char **list = synonyms_get(s, word);
    char **tmp;
    int ret = -1;

    if (!list) {
        if (expect) {
            ERROR("Expected a synonym for \"%s\" but got nothing", word);
            goto cleanup;
        }
    } else {
        if (!expect) {
            ERROR("Expected nothing for \"%s\" but got a list", word);
            goto cleanup;
        }
    }

    tmp = list;
    while (tmp) {
        if (STREQ(*tmp, expect)) {
            /* Found */
            ret = 0;
            goto cleanup;
        }

        tmp++;
    }

    ERROR("Expected synonym \"%s\" for word \"%s\" not found", expect, word);

 cleanup:
    stringlist_free(list);
    return ret;
}


int main(int argc, char *argv[])
{
    int ret = EXIT_FAILURE;
    Synonyms *s = NULL;

    if (!setlocale(LC_ALL, "")) {
        SYS_ERROR("Unable to set locale");
        goto cleanup;
    }

    if (!(s = synonyms_init())) {
        SYS_ERROR("Unable to initialize synonyms dictionary");
        goto cleanup;
    }

    SYNONYMS_DEFINE(s, "synonym", "alternative", "equivalent", NULL);
    SYNONYMS_DEFINE(s, "virtual", "simulated", NULL);
    SYNONYMS_DEFINE(s, "student", "pupil", NULL);
    SYNONYMS_DEFINE(s, "pupil", "schoolchild", NULL);

    IS_SYNONYM(s, "synonym", "alternative", true);
    IS_SYNONYM(s, "alternative", "synonym", true);
    IS_SYNONYM(s, "synonym", "virtual", false);
    IS_SYNONYM(s, "virtual", "virtual", false);

    SYNONYMS_CHECK(s, "synonym", "alternative");
    SYNONYMS_CHECK(s, "equivalent", "synonym");
    SYNONYMS_CHECK(s, "schoolchild", "student");

    ret = EXIT_SUCCESS;
 cleanup:
    synonyms_free(s);
    return ret;
}
