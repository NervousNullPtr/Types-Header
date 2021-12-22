// Written by Maximilian Schleicher, December 2021.
// This file comes without any warranty.
#ifndef TYPES_H
   #define TYPES_H
   #include <stdint.h>

   typedef uint8_t  u8;
   typedef uint16_t u16;
   typedef uint32_t u32;
   typedef uint64_t u64;

   typedef int8_t  i8;
   typedef int16_t i16;
   typedef int32_t i32;
   typedef int64_t i64;

   typedef int_least8_t  i8_least;
   typedef int_least16_t i16_least;
   typedef int_least32_t i32_least;
   typedef int_least64_t i64_least;

   typedef uint_least8_t  u8_least;
   typedef uint_least16_t u16_least;
   typedef uint_least32_t u32_least;
   typedef uint_least64_t u64_least;

   typedef int_fast8_t  i8_fast;
   typedef int_fast16_t i16_fast;
   typedef int_fast32_t i32_fast;
   typedef int_fast64_t i64_fast;

   typedef uint_fast8_t  u8_fast;
   typedef uint_fast16_t u16_fast;
   typedef uint_fast32_t u32_fast;
   typedef uint_fast64_t u64_fast;

   typedef intptr_t  isize;
   typedef uintptr_t usize;

   typedef intmax_t  imax;
   typedef uintmax_t umax;

   typedef float       f32;
   typedef double      f64;

   #ifdef __GNUC__
      typedef __float128  f128;
   #endif

   #ifdef __clang__
      typedef long double f128;
   #endif
#endif // TYPES_H