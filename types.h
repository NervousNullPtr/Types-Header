// Modified stdint.h by altering typenames.

/* Copyright (C) 1997-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
   
/*
 *        ISO C99: 7.18 Integer types <stdint.h>
 */
#ifndef _TYPES_H
#define _TYPES_H       1
#include <features.h>
#include <bits/wchar.h>
#include <bits/wordsize.h>

// Signed Integral
#ifndef __i8_defined
# define __i8_defined
typedef signed char i8;
typedef short int   i16;
typedef int         i32;
# if __WORDSIZE == 64
typedef long int    i64;
# else
__extension__
typedef long long int i64;
# endif
#endif

// Unsigned Integral
typedef unsigned char      u8;
typedef unsigned short int u16;
#ifndef __uint32_t_defined
typedef unsigned int       u32;
# define __uint32_t_defined
#endif
#if __WORDSIZE == 64
typedef unsigned long int u64;
#else
__extension__
typedef unsigned long long int u64;
#endif

// Signed Least
typedef signed char i8_least;
typedef short int   i16_least;
typedef int         i32_least;
#if __WORDSIZE == 64
typedef long int    i64_least;
#else
__extension__
typedef long long int i64;
#endif

// Unsigned Least
typedef unsigned char      u8_least;
typedef unsigned short int u16_least;
typedef unsigned int       u32_least;
#if __WORDSIZE == 64
typedef unsigned long int  u64_least;
#else
__extension__
typedef unsigned long long int u64_least;
#endif

// Signed Fast
typedef signed char i8_fast;
#if __WORDSIZE == 64
typedef long int    i16_fast;
typedef long int    i32_fast;
typedef long int    i64_fast;
#else
typedef int         i16_fast;
typedef int         i32_fast;
__extension__
typedef long long int i64_fast;
#endif

// Unsigned Fast
typedef unsigned char     u8_fast;
#if __WORDSIZE == 64
typedef unsigned long int u16_fast;
typedef unsigned long int u32_fast;
typedef unsigned long int u64_fast;
#else
typedef unsigned int      u16_fast;
typedef unsigned int      u32_fast;
__extension__
typedef unsigned long long int u64_fast;
#endif

// Void Pointers
#if __WORDSIZE == 64
# ifndef __intptr_t_defined
typedef long int isize;
#  define __intptr_t_defined
# endif
typedef unsigned long int usize;
#else
# ifndef __intptr_t_defined
typedef int isize;
#  define __intptr_t_defined
# endif
typedef unsigned int usize;
#endif

// Signed Max Integral
#if __WORDSIZE == 64
typedef long int               i64_max;
typedef unsigned long int      u64_max;
#else
__extension__
typedef long long int          i64_max;
__extension__
typedef unsigned long long int u64_max;
#endif
# if __WORDSIZE == 64
#  define __INT64_C(c)  c ## L
#  define __UINT64_C(c) c ## UL
# else
#  define __INT64_C(c)  c ## LL
#  define __UINT64_C(c) c ## ULL
# endif

// Signed Min Integral
# define I8_MIN  (-128)
# define I16_MIN (-32767-1)
# define I32_MIN (-2147483647-1)
# define I64_MIN (-__INT64_C(9223372036854775807)-1)

// Signed Max Integral
# define I8_MAX  (127)
# define I16_MAX (32767)
# define I32_MAX (2147483647)
# define I64_MAX (__INT64_C(9223372036854775807))

// Unsgiend Max Integral
# define U8_MAX  (255)
# define U16_MAX (65535)
# define U32_MAX (4294967295U)
# define U64_MAX (__UINT64_C(18446744073709551615))

// Signed Min Integral
# define I8_LEAST_MIN  (-128)
# define I16_LEAST_MIN (-32767-1)
# define I32_LEAST_MIN (-2147483647-1)
# define I64_LEAST_MIN (-__INT64_C(9223372036854775807)-1)

// Signed Max Integral
# define I8_LEAST_MAX  (127)
# define I16_LEAST_MAX (32767)
# define I32_LEAST_MAX (2147483647)
# define I64_LEAST_MAX (__INT64_C(9223372036854775807))

// Maximum of unsigned integral types having a minimum size.
# define U8_LEAST_MAX  (255)
# define U16_LEAST_MAX (65535)
# define U32_LEAST_MAX (4294967295U)
# define U64_LEAST_MAX (__UINT64_C(18446744073709551615))

// Minimum of fast signed integral types having a minimum size.
# define I8_FAST_MIN (-128)
# if __WORDSIZE == 64
#  define I16_FAST_MIN (-9223372036854775807L-1)
#  define I32_FAST_MIN (-9223372036854775807L-1)
# else
#  define I16_FAST_MIN (-2147483647-1)
#  define I32_FAST_MIN (-2147483647-1)
# endif
# define I64_FAST_MIN (-__INT64_C(9223372036854775807)-1)

// Maximum of fast signed integral types having a minimum size.
# define I8_FAST_MAX (127)
# if __WORDSIZE == 64
#  define I16_FAST_MAX (9223372036854775807L)
#  define I32_FAST_MAX (9223372036854775807L)
# else
#  define I16_FAST_MAX (2147483647)
#  define I32_FAST_MAX (2147483647)
# endif
# define I64_FAST_MAX (__INT64_C(9223372036854775807))

// Maximum of fast unsigned integral types having a minimum size.
# define U8_FAST_MAX (255)
# if __WORDSIZE == 64
#  define U16_FAST_MAX (18446744073709551615UL)
#  define U32_FAST_MAX (18446744073709551615UL)
# else
#  define U16_FAST_MAX (4294967295U)
#  define U32_FAST_MAX (4294967295U)
# endif
# define U64_FAST_MAX (__UINT64_C(18446744073709551615))

// Values to test for integral types holding `void *' pointer.
# if __WORDSIZE == 64
#  define ISIZE_MIN (-9223372036854775807L-1)
#  define ISIZE_MAX (9223372036854775807L)
#  define USIZE_MAX (18446744073709551615UL)
# else
#  define ISIZE_MIN (-2147483647-1)
#  define ISIZE_MAX (2147483647)
#  define USIZE_MAX (4294967295U)
# endif

// Minimum for largest signed integral type.
# define IMAX_MIN (-__INT64_C(9223372036854775807)-1)

// Maximum for largest signed integral type.
# define IMAX_MAX (__INT64_C(9223372036854775807))

// Maximum for largest unsigned integral type.
# define UMAX_MAX (__UINT64_C(18446744073709551615))

// Limits of other integer types.
// Limits of `ptrdiff_t' type.
# if __WORDSIZE == 64
#  define PTRDIFF_MIN (-9223372036854775807L-1)
#  define PTRDIFF_MAX (9223372036854775807L)
# else
#  define PTRDIFF_MIN (-2147483647-1)
#  define PTRDIFF_MAX (2147483647)
# endif

// Limits of `sig_atomic_t'.
# define SIG_ATOMIC_MIN (-2147483647-1)
# define SIG_ATOMIC_MAX (2147483647)

// Limit of `size_t' type.
# if __WORDSIZE == 64
#  define SIZE_MAX (18446744073709551615UL)
# else
#  ifdef __WORDSIZE32_SIZE_ULONG
#   define SIZE_MAX (4294967295UL)
#  else
#   define SIZE_MAX (4294967295U)
#  endif
# endif

// Limits of `wchar_t'.
# ifndef WCHAR_MIN

// These constants might also be defined in <wchar.h>.
#  define WCHAR_MIN __WCHAR_MIN
#  define WCHAR_MAX __WCHAR_MAX
# endif

// Limits of `wint_t'.
# define WINT_MIN (0u)
# define WINT_MAX (4294967295u)

// Signed
# define INT8_C(c) c
# define I16_C(c)  c
# define I32_C(c)  c
# if __WORDSIZE == 64
#  define I64_C(c) c ## L
# else
#  define I64_C(c) c ## LL
# endif

// Unsigned
# define U8_C(c)  c
# define U16_C(c) c
# define U32_C(c) c ## U
# if __WORDSIZE == 64
#  define U64_C(c) c ## UL
# else
#  define U64_C(c) c ## ULL
# endif

// Maximal Type
# if __WORDSIZE == 64
#  define IMAX_C(c) c ## L
#  define UMAX_C(c) c ## UL
# else
#  define IMAX_C(c) c ## LL
#  define UMAX_C(c) c ## ULL
# endif
#endif // types.h