## Makefile for the lib subdirectory of GNU libunistring.
## Copyright (C) 2009 Free Software Foundation, Inc.
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.

## Process this file with automake to produce Makefile.in.

AUTOMAKE_OPTIONS = 1.5 gnits subdir-objects no-dependencies
EXTRA_DIST =
BUILT_SOURCES =
MOSTLYCLEANFILES = core *.stackdump
CLEANFILES =
DISTCLEANFILES =
MAINTAINERCLEANFILES =
SUFFIXES =

lib_LTLIBRARIES = libunistring.la

nobase_include_HEADERS = \
  unitypes.h \
  unistr.h \
  uniconv.h \
  unistdio.h \
  uniname.h \
  unictype.h \
  uniwidth.h \
  uniwbrk.h \
  unilbrk.h \
  uninorm.h \
  unicase.h \
  unistring/inline.h \
  unistring/woe32dll.h

noinst_HEADERS = \
  unistring-notinline.h

AM_CPPFLAGS = -DIN_LIBUNISTRING

# Rules generated and collected by gnulib-tool.
include Makefile.gnulib

# The <stdbool.h> and <stdint.h> replacements that can be installed.
nobase_nodist_include_HEADERS = \
  unistring/stdbool.h \
  unistring/stdint.h

unistring/stdbool.h : $(STDBOOL_H)
	@MKDIR_P@ unistring
	rm -f $@-t $@
	if test -n '$(STDBOOL_H)'; then \
	  cp stdbool.h $@-t; \
	else \
	  { echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */'; \
	    echo '#include <stdbool.h>'; \
	  } > $@-t; \
	fi
	mv $@-t $@
BUILT_SOURCES    += unistring/stdbool.h
MOSTLYCLEANFILES += unistring/stdbool.h-t
CLEANFILES       += unistring/stdbool.h

unistring/stdint.h : $(STDINT_H) stdint.mini.h
	@MKDIR_P@ unistring
	rm -f $@-t $@
	if test -n '$(STDINT_H)'; then \
	  { echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */'; \
	    sed -e 's/@''HAVE_STDINT_H''@/$(HAVE_STDINT_H)/g' \
	        -e 's|@''INCLUDE_NEXT''@|$(INCLUDE_NEXT)|g' \
	        -e 's|@''PRAGMA_SYSTEM_HEADER''@|@PRAGMA_SYSTEM_HEADER@|g' \
	        -e 's|@''NEXT_STDINT_H''@|$(NEXT_STDINT_H)|g' \
	        -e 's/@''HAVE_SYS_TYPES_H''@/$(HAVE_SYS_TYPES_H)/g' \
	        -e 's/@''HAVE_INTTYPES_H''@/$(HAVE_INTTYPES_H)/g' \
	        -e 's/@''HAVE_SYS_INTTYPES_H''@/$(HAVE_SYS_INTTYPES_H)/g' \
	        -e 's/@''HAVE_SYS_BITYPES_H''@/$(HAVE_SYS_BITYPES_H)/g' \
	        -e 's/include_next/include/' \
	        < $(srcdir)/stdint.mini.h; \
	  } > $@-t; \
	else \
	  { echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */'; \
	    echo '#include <stdint.h>'; \
	  } > $@-t; \
	fi
	mv $@-t $@
BUILT_SOURCES    += unistring/stdint.h
MOSTLYCLEANFILES += unistring/stdint.h-t
CLEANFILES       += unistring/stdint.h
EXTRA_DIST       += stdint.mini.h

# localcharset.h is not public, but its contents is documented.
nobase_nodist_include_HEADERS += unistring/localcharset.h
unistring/localcharset.h : localcharset.h
	@MKDIR_P@ unistring
	rm -f $@-t $@
	cp $(srcdir)/localcharset.h $@-t
	mv $@-t $@
BUILT_SOURCES    += unistring/localcharset.h
MOSTLYCLEANFILES += unistring/localcharset.h-t
CLEANFILES       += unistring/localcharset.h

# iconeh.h is not public, but its contents is documented.
nobase_nodist_include_HEADERS += unistring/iconveh.h
unistring/iconveh.h : iconveh.h
	@MKDIR_P@ unistring
	rm -f $@-t $@
	cp $(srcdir)/iconveh.h $@-t
	mv $@-t $@
BUILT_SOURCES    += unistring/iconveh.h
MOSTLYCLEANFILES += unistring/iconveh.h-t
CLEANFILES       += unistring/iconveh.h

# Directories that contain some CLEANFILES.
CLEANDIRS = 
CLEANDIRS_NOT_IN_SRCDIR = unistring
clean-local: clean-generic
	@for dir in '' $(CLEANDIRS); do \
	  if test -n "$$dir" && test -d $$dir; then \
	    echo "rmdir $$dir"; rmdir $$dir; \
	  fi; \
	done; \
	if test '$(srcdir)' != '.'; then \
	  for dir in '' $(CLEANDIRS_NOT_IN_SRCDIR); do \
	    if test -n "$$dir" && test -d $$dir; then \
	      echo "rmdir $$dir"; rmdir $$dir; \
	    fi; \
	  done; \
	fi; \
        :

# List of header files that get installed and that declared 'extern' symbols.
HEADERS_WITH_EXTERNS = \
  unitypes.h \
  unistr.h \
  uniconv.h \
  unistdio.h \
  uniname.h \
  unictype.h \
  uniwidth.h \
  uniwbrk.h \
  unilbrk.h \
  uninorm.h \
  unicase.h \
  localcharset.h \
  iconveh.h

# List of exported symbols.
# We extract it from the header files that get installed, removing symbols
# start with "_UC".
# This file has the same format as the one expected by the libtool option
# '-export-symbols', but we don't use this option, because it would prevent us
# from building some of the gnulib unit tests.
libunistring.sym : $(HEADERS_WITH_EXTERNS)
	for f in $(HEADERS_WITH_EXTERNS); do cat $(srcdir)/$$f; done \
	  | $(srcdir)/declared.sh | LC_ALL=C sort | LC_ALL=C uniq \
	  | grep -v '^_UC' \
	  > $@-t
	mv $@-t $@
# We distribute it because declared.sh relies on GNU sed.
MOSTLYCLEANFILES     += libunistring.sym-t
MAINTAINERCLEANFILES += libunistring.sym
EXTRA_DIST           += libunistring.sym

# Tell the mingw or Cygwin linker which symbols to export.
if WOE32DLL
libunistring_la_SOURCES += ../woe32dll/unistring-exports.c
libunistring_la_LDFLAGS += -Wl,--export-all-symbols
endif

# Hide undesired symbols that are defined by libunistring_la_SOURCES or
# libunistring_la_LIBADD from the global namespace, by prefixing them with
# "libunistring_".
all check install: config.h
config.h: $(BUILT_SOURCES) libunistring.sym
	{ echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */'; \
	  : "Avoid double inclusion, to avoid a warning about redefinitions."; \
	  echo '#ifndef UNISTRING_CONFIG_H'; \
	  echo '#define UNISTRING_CONFIG_H'; \
	  echo; \
	  echo '#include "../config.h"'; \
	  echo; \
	  echo '#endif /* UNISTRING_CONFIG_H */'; \
	} > config.h && \
	if test -n "$(HAVE_GLOBAL_SYMBOL_PIPE)"; then \
	  { \
	    for f in $(libunistring_la_SOURCES) $(libunistring_la_LIBADD); do \
	      case $$f in \
	        *.c | *.$(OBJEXT) | *.lo ) \
	          sf=`echo "$$f" | sed -e 's,\\.[^.]*$$,,'`.c; \
	          test -f $$sf || sf=$(srcdir)/$$sf; \
	          of=`echo "$$f" | sed -e 's,^.*/,,' -e 's,\\.[^.]*$$,,'`.$(OBJEXT); \
	          $(COMPILE) -c $$sf || { rm -f config.h; exit 1; }; \
	          sh ./exported.sh $$of 1>&5; \
	          rm -f $$of `echo "$$of" | sed -e 's,\\.$(OBJEXT)$$,.lo,'`; \
	          ;; \
	      esac; \
	    done; \
	  } 5>&1 \
	    | sed -e 's,.* ,,' | LC_ALL=C sort | LC_ALL=C uniq \
	    | LC_ALL=C join -v 1 - $(srcdir)/libunistring.sym \
	    | sed -e 's,^\(.*\)$$,#define \1 libunistring_\1,' > config.h-t && \
	  if test -f config.h; then \
	    cat config.h-t >> config.h; \
	    rm -f config.h-t; \
	  else \
	    rm -f config.h-t; \
	    exit 1; \
	  fi \
	fi
MOSTLYCLEANFILES += config.h config.h-t

# Libtool's library version information for libunistring.
# See the libtool documentation, section "Library interface versions".
LTV_CURRENT=0
LTV_REVISION=0
LTV_AGE=0

# How to build libunistring.la.
libunistring_la_LDFLAGS += \
  -version-info $(LTV_CURRENT):$(LTV_REVISION):$(LTV_AGE) \
  -rpath $(libdir) \
  @INTL_MACOSX_LIBS@ -no-undefined
