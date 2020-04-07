PROGRAMS = synonyms

synonyms_SOURCES = synonyms.c synonyms_impl.c synonyms_impl.h stringlist.c stringlist.h
synonyms_LIBS =

CFLAGS=-std=gnu11 -Wall -Werror -O0 -ggdb

.PHONY: all clean

all: $(PROGRAMS)

define PROGRAM_template =
  $(1)_DEPS = $$($(1)_SOURCES:.c=.o)
  $(1): $$($(1)_DEPS) $$($(1)_LIBS:%=-l%)
  ALL_OBJS += $$(filter %.o,$$($(1)_DEPS))
endef

$(foreach prog,$(PROGRAMS),$(eval $(call PROGRAM_template,$(prog))))

clean:
	rm -f $(PROGRAMS) $(ALL_OBJS) tags

tags:
	ctags -R .
