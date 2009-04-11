dnl Configuration for the toplevel directory of GNU libunistring
dnl Copyright (C) 2009 Free Software Foundation, Inc.
dnl
dnl This program is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program.  If not, see <http://www.gnu.org/licenses/>.

dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT
AC_CONFIG_SRCDIR([lib/Makefile.am])
AC_CONFIG_AUX_DIR([build-aux])
. $srcdir/version.sh
AM_INIT_AUTOMAKE([libunistring], [$VERSION_NUMBER])
AM_CONFIG_HEADER([config.h])

dnl Override automake's tar command used for creating distributions.
am__tar='${AMTAR} chof - --owner=root --group=root "$$tardir"'

dnl Checks for basic programs.

AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_MKDIR_P

dnl Check for host type.

AC_CANONICAL_HOST

dnl Checks that augment the CPPFLAGS.

gl_EARLY

dnl Checks for compiler output filename suffixes.

AC_OBJEXT
AC_EXEEXT

dnl Check for build configuration.

LT_INIT([win32-dll])

dnl Checks for types, header files, functions and declarations.

gl_INIT

dnl Check for tools needed for formatting the documentation.
ac_aux_dir_abs=`cd $ac_aux_dir && pwd`
AC_PATH_PROG([TEXI2DVI], [texi2dvi], [$ac_aux_dir_abs/missing texi2dvi])
AC_PATH_PROG([DVIPS], [dvips], [$ac_aux_dir_abs/missing dvips])
AC_PATH_PROG([PERL], [perl], [$ac_aux_dir_abs/missing perl])

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([doc/Makefile],
                [FIX_MAKEFILE_DISTRIB])
AC_CONFIG_FILES([gnulib-local/Makefile])
AC_CONFIG_FILES([lib/Makefile])
AC_CONFIG_FILES([tests/Makefile])
AC_OUTPUT
