#pragma once

#include "../Config.hpp"
#include "Numeric.hpp"

#ifdef _RANDOM_DEVICE_
#include <random>
#endif

MATH_NAMESPACE_BEGIN

static struct Random
{
#ifndef _RANDOM_DEVICE_
    template <typename T>
    static MATH_CONSTEXPR T random_range(T const &min, T const &max)
    {
        return numeric::linear_lerp(min, max, static_cast<T>(rand()) / static_cast<T>(RAND_MAX));
    }
#else
    template <typename T>
    static MATH_CONSTEXPR T random_range(T const &min = std::numeric_limits<T>::min(), T const &max = std::numeric_limits<T>::max())
    {
        static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<T> dis(min, max);
        return dis(gen);
    }
#endif

    template <typename T>
    static MATH_CONSTEXPR T random(T const &max = std::numeric_limits<T>::max())
    {
        return Random::random_range(std::numeric_limits<T>::min(), max);
    }
};

MATH_NAMESPACE_END