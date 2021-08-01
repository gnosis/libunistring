/* Common macro definitions for C include files.
   Copyright (C) 2008-2021 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#ifndef _UNISTRING_CDEFS_H
#define _UNISTRING_CDEFS_H

/* _GL_UNUSED_PARAMETER is a marker that can be prepended to function parameter
   declarations for parameters that are not used.  This helps to reduce
   warnings, such as from GCC -Wunused-parameter.  The syntax is as follows:
       _GL_UNUSED_PARAMETER type param
   or more generally
       _GL_UNUSED_PARAMETER param_decl
   For example:
       _GL_UNUSED_PARAMETER int param
       _GL_UNUSED_PARAMETER int *(*param) (void)
 */
#ifndef _GL_UNUSED_PARAMETER
# define _GL_UNUSED_PARAMETER _UC_ATTRIBUTE_MAYBE_UNUSED
#endif

/* The definitions below are taken from gnulib/m4/gnulib-common.m4,
   with prefix _UC instead of prefix _GL.  */

/* True if the compiler says it groks GNU C version MAJOR.MINOR.  */
#if defined __GNUC__ && defined __GNUC_MINOR__
# define _UC_GNUC_PREREQ(major, minor) \
    ((major) < __GNUC__ + ((minor) <= __GNUC_MINOR__))
#else
# define _UC_GNUC_PREREQ(major, minor) 0
#endif

#if (defined __has_attribute \
     && (!defined __clang_minor__ \
         || 3 < __clang_major__ + (5 <= __clang_minor__)))
# define _UC_HAS_ATTRIBUTE(attr) __has_attribute (__##attr##__)
#else
# define _UC_HAS_ATTRIBUTE(attr) _UC_ATTR_##attr
# define _UC_ATTR_unused _UC_GNUC_PREREQ (2, 7)
#endif

#ifdef __has_c_attribute
# define _GL_HAS_C_ATTRIBUTE(attr) __has_c_attribute (__##attr##__)
#else
# define _GL_HAS_C_ATTRIBUTE(attr) 0
#endif

#if _GL_HAS_C_ATTRIBUTE (maybe_unused)
# define _UC_ATTRIBUTE_MAYBE_UNUSED [[__maybe_unused__]]
#else
# define _UC_ATTRIBUTE_MAYBE_UNUSED _UC_ATTRIBUTE_UNUSED
#endif

#if _UC_HAS_ATTRIBUTE (unused)
# define _UC_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#else
# define _UC_ATTRIBUTE_UNUSED
#endif

#endif /* _UNISTRING_CDEFS_H */
