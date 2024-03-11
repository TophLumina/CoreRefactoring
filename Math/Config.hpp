#pragma once

#include <iostream>
#include <typeinfo>

#define MATH_NAMESPACE_BEGIN namespace Math {
#define MATH_NAMESPACE_END }

#ifdef MATH_SUPPORT_CONSTEXPR
    #define MATH_CONSTEXPR constexpr
#else
    #define MATH_CONSTEXPR
#endif

#ifdef MATH_FORCE_EXPLICIT
    #define MATH_EXPLICIT explicit
#else
    #define MATH_EXPLICIT
#endif

// FUNCS IN HEADERS ARE INLINE BY DEFAULT
#ifdef MATH_FORCE_INLINE
    #define MATH_INLINE inline
#else
    #define MATH_INLINE
#endif

#define MATH_FUNCTION_QUALIFIERS MATH_CONSTEXPR MATH_INLINE

#define _RANDOM_DEVICE_