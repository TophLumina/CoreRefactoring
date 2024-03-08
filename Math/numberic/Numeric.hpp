#pragma once

#include "../Config.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>

MATH_NAMESPACE_BEGIN

template <typename T>
static MATH_CONSTEXPR T abs(T const &x)
{
    return x < 0 ? -x : x;
}

template <typename T>
static MATH_CONSTEXPR T min(T const &x, T const &y)
{
    return x < y ? x : y;
}

template <typename T>
static MATH_CONSTEXPR T max(T const &x, T const &y)
{
    return x > y ? x : y;
}

template <typename T>
static MATH_CONSTEXPR T ceil(T const &x)
{
    return std::ceil(x);
}

template <typename T>
static MATH_CONSTEXPR T floor(T const &x)
{
    return std::floor(x);
}

template <typename T>
static MATH_CONSTEXPR T round(T const &x)
{
    return std::round(x);
}

template <typename T>
static MATH_CONSTEXPR T clamp(T const &x, T const &min, T const &max)
{
    return x < min ? min : x > max ? max
                                   : x;
}

template <typename T>
static MATH_CONSTEXPR T saturate(T const &x)
{
    return clamp(x, 0, 1);
}

template <typename T>
static MATH_CONSTEXPR T linear_lerp(T const &x, T const &y, T const &a)
{
    return x + a * (y - x);
}

template <typename T>
static MATH_CONSTEXPR T quadratic_lerp(T const &x, T const &y, T const &a)
{
    T const t = (a - x) / (y - x);
    return t * t * (3 - 2 * t);
}

template <typename T>
static MATH_CONSTEXPR T cubic_lerp(T const &x, T const &y, T const &a)
{
    T const t = (a - x) / (y - x);
    return t * t * t * (t * (t * 6 - 15) + 10);
}

template <typename T>
static MATH_CONSTEXPR T radians(T const &degrees)
{
    return degrees * static_cast<T>(M_PI / 180);
}

template <typename T>
static MATH_CONSTEXPR T degrees(T const &radians)
{
    return radians * static_cast<T>(180 / M_PI);
}

template <typename T>
static MATH_CONSTEXPR T sin(T const &x)
{
    return std::sin(x);
}

template <typename T>
static MATH_CONSTEXPR T cos(T const &x)
{
    return std::cos(x);
}

template <typename T>
static MATH_CONSTEXPR T tan(T const &x)
{
    return std::tan(x);
}

template <typename T>
static MATH_CONSTEXPR T asin(T const &x)
{
    return std::asin(x);
}

template <typename T>
static MATH_CONSTEXPR T acos(T const &x)
{
    return std::acos(x);
}

template <typename T>
static MATH_CONSTEXPR T atan(T const &x)
{
    return std::atan(x);
}

template <typename T>
static MATH_CONSTEXPR T atan2(T const &y, T const &x)
{
    return std::atan2(y, x);
}

template <typename T>
static MATH_CONSTEXPR T sqrt(T const &x)
{
    return std::sqrt(x);
}

template <typename T>
static MATH_CONSTEXPR T pow(T const &x, T const &y)
{
    return std::pow(x, y);
}

template <typename T>
static MATH_CONSTEXPR T exp(T const &x)
{
    return std::exp(x);
}

template <typename T>
static MATH_CONSTEXPR T log(T const &x)
{
    return std::log(x);
}

template <typename T>
static MATH_CONSTEXPR T log10(T const &x)
{
    return std::log10(x);
}

template <typename T>
static MATH_CONSTEXPR T log2(T const &x)
{
    return std::log2(x);
}

MATH_NAMESPACE_END
