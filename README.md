Google Summer of Code 2020 Coding exercise
==========================================


Goal:

Implement very basic thesaurus. Your task is to provide missing implementation
for functions and structures in synonyms_impl.c. The basic usage might look
like this:

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

Note: an array of strings terminated by explicit NULL element is often referred
to as string list. NULL serves as a sentinel so that anybody working with the
string list knows when to stop.

Steps:
The design of _Synonyms structure is completely up to you, just like algorithms
used. You can introduce new internal functions, extend stringlist.c (and/or
stringlist.h) for any functions or macros you want. However, you can use
standard C library only. If you allocate any memory, do not forget to free it
once no longer needed.

The synonyms_define() function defines synonyms for given word (argument #2)
and allows to define multiple synonyms at once. The list of synonyms must be
terminated by NULL. However, it is also possible to define synonyms in separate
steps. For instance:

  synonyms_define(s, "synonym", "alternative", "equivalent", NULL);

is equivalent to:

  synonyms_define(s, "synonym", "alternative", NULL);
  synonyms_define(s, "synonym", "equivalent", NULL);

Moreover, synonyms are transitive. Therefore, if A is a synonym to B and B is s
synonym to C then A is a synonym to C. Therefore the following are equivalent:

  synonyms_define(s, "synonym", "alternative", "equivalent", NULL);

is equivalent to:

  synonyms_define(s, "synonym", "alternative", NULL);
  synonyms_define(s, "alternative", "equivalent", NULL);

Please note, that synonyms are reflexive, that is if a word A is a synonym to B
then the reverse is also true: B is a synonym to A. However, a word is not
synonym to itself.


Feel free to ask any questions.
