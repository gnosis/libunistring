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
  unicase.h

#AM_CPPFLAGS =

# Rules generated and collected by gnulib-tool.
include Makefile.gnulib

# Libtool's library version information for libunistring.
# See the libtool documentation, section "Library interface versions".
LTV_CURRENT=0
LTV_REVISION=0
LTV_AGE=0

# How to build libunistring.la.
libunistring_la_LDFLAGS += \
  -version-info $(LTV_CURRENT):$(LTV_REVISION):$(LTV_AGE) \
  -rpath $(libdir)
