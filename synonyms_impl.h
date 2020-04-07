/*
 * synonyms_impl.h: Header file exporting synonyms functions
 *
 * Before modifying this file read README.
 */

#ifndef __SYNONYMS_IMPL_H__
# define __SYNONYMS_IMPL_H__

# define NULL_TERMINATED __attribute__((__sentinel__))

typedef struct _Synonyms Synonyms;

Synonyms *
synonyms_init(void);

void
synonyms_free(Synonyms *s);

int
synonyms_append(Synonyms *s,
                const char *word, ...)
    NULL_TERMINATED;

char **
synonyms_get(Synonyms *s,
             const char *word);

#endif /* __SYNONYMS_IMPL_H__ */
