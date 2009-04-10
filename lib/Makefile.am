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

include_HEADERS = \
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
  unistring-inline.h

noinst_HEADERS = \
  unistring-notinline.h

AM_CPPFLAGS = -DIN_LIBUNISTRING

# Rules generated and collected by gnulib-tool.
include Makefile.gnulib

# The <stdbool.h> and <stdint.h> replacements that can be installed.
nodist_include_HEADERS = \
  unistring-stdbool.h \
  unistring-stdint.h

unistring-stdbool.h : $(STDBOOL_H)
	rm -f $@-t $@
	if test -n '$(STDBOOL_H)'; then \
	  cp stdbool.h $@-t; \
	else \
	  { echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */'; \
	    echo '#include <stdbool.h>'; \
	  } > $@-t; \
	fi
	mv $@-t $@
BUILT_SOURCES    += unistring-stdbool.h
MOSTLYCLEANFILES += unistring-stdbool.h-t
CLEANFILES       += unistring-stdbool.h

unistring-stdint.h : $(STDINT_H) stdint.mini.h
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
BUILT_SOURCES    += unistring-stdint.h
MOSTLYCLEANFILES += unistring-stdint.h-t
CLEANFILES       += unistring-stdint.h
EXTRA_DIST       += stdint.mini.h

# localcharset.h is not public, but its contents is documented.
nodist_include_HEADERS += unistring-localcharset.h
unistring-localcharset.h : localcharset.h
	rm -f $@-t $@
	cp $(srcdir)/localcharset.h $@-t
	mv $@-t $@
BUILT_SOURCES    += unistring-localcharset.h
MOSTLYCLEANFILES += unistring-localcharset.h-t
CLEANFILES       += unistring-localcharset.h

# iconeh.h is not public, but its contents is documented.
nodist_include_HEADERS += unistring-iconveh.h
unistring-iconveh.h : iconveh.h
	rm -f $@-t $@
	cp $(srcdir)/iconveh.h $@-t
	mv $@-t $@
BUILT_SOURCES    += unistring-iconveh.h
MOSTLYCLEANFILES += unistring-iconveh.h-t
CLEANFILES       += unistring-iconveh.h

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
