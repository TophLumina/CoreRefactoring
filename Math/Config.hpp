#pragma once

#ifdef _MATH_DEBUG_
#include <iostream>
#include <typeinfo>
#endif

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