Google Summer of Code 2020 Coding exercise
==========================================

### Goal: Implement a very basic thesaurus 

Your task is to provide the missing implementation for functions and structures
in synonyms_impl.c. The basic usage might look like this:

```
  Synonyms *s;

  if (!(s = synonyms_init())) {
      /* error */
  }

  if (synonyms_define(s, "synonym", "alternative", "equivalent", NULL) < 0) {
      /* error */
  }

  char ** list = synonyms_get(s, "synonym");

  // @list is now an array of strings, terminated by NULL and looks like this:
  // list[0] = "alternative"
  // list[1] = "equivalent"
  // list[2] = NULL

  stringlist_free(list);

  synonyms_free(s);
```

_Note: an array of strings terminated by an explicit NULL element is often
referred to as string list. NULL serves as a sentinel so that anybody working
with the string list knows when to stop processing._

#### Steps:
The design of `Synonyms` structure is completely up to you, just like algorithms
used. You can introduce new internal functions, extend **_stringlist.c_** (and/or
**_stringlist.h_**) for any functions or macros you want. However, you can use
standard C library only. If you allocate any memory, do not forget to free it
once no longer needed.

The `synonyms_define()` function defines synonyms for a given word (argument #2)
and allows to define multiple synonyms at once. The list of synonyms must be
terminated by NULL. However, it is also possible to define synonyms in separate
steps. For instance:

  `synonyms_define(s, "synonym", "alternative", "equivalent", NULL);`

is equivalent to:
```
  synonyms_define(s, "synonym", "alternative", NULL);
  synonyms_define(s, "synonym", "equivalent", NULL);
```
Please note that synonyms are transitive, thus if A is a synonym of B and B is a
synonym of C then A is a synonym of C, in other words:

  `synonyms_define(s, "synonym", "alternative", "equivalent", NULL);`

is equivalent to:
```
  synonyms_define(s, "synonym", "alternative", NULL);
  synonyms_define(s, "alternative", "equivalent", NULL);
```
Bear in mind that synonyms are also reflexive, that is, if a word A is a
synonym of B then the reverse is also true: B is a synonym of A. However, by
the definition of synonym: a word cannot be a synonym of itself.

Feel free to ask any questions.
