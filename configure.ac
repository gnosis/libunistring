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

gl_WOE32_DLL

LT_INIT([win32-dll])

dnl Checks for types, header files, functions and declarations.

gl_INIT

dnl Compilation on mingw and Cygwin needs special Makefile rules, because
dnl 1. when we install a shared library, we must arrange to export
dnl    auxiliary pointer variables for every exported variable,
dnl 2. when we install a shared library and a static library simultaneously,
dnl    the include file specifies __declspec(dllimport) and therefore we
dnl    must arrange to define the auxiliary pointer variables for the
dnl    exported variables _also_ in the static library.
if test "$enable_shared" = yes; then
  case "$host_os" in
    mingw* | cygwin*) is_woe32dll=yes ;;
    *) is_woe32dll=no ;;
  esac
else
  is_woe32dll=no
fi
AM_CONDITIONAL([WOE32DLL], [test $is_woe32dll = yes])
if test $is_woe32dll = yes; then
  DLL_VARIABLE='__declspec (dllimport)'
else
  DLL_VARIABLE=
fi
AC_SUBST([DLL_VARIABLE])

dnl Check for prerequisites of exported.sh.
gt_GLOBAL_SYMBOL_PIPE

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
AC_CONFIG_FILES([lib/exported.sh])
AC_CONFIG_FILES([lib/unistring/woe32dll.h:lib/unistring/woe32dll.in.h])
AC_CONFIG_FILES([tests/Makefile])
AC_OUTPUT
