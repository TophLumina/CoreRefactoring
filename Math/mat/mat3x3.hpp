#pragma once

#include "../Config.hpp"
#include "../sturctures.hpp"

#include <initializer_list>

MATH_NAMESPACE_BEGIN

template <typename T>
struct mat3x3
{
    union
    {
        vec<3, T> c[3];
        struct
        {
            T m00, m01, m02;
            T m10, m11, m12;
            T m20, m21, m22;
        };
    };

    // --accessors-- //
    MATH_CONSTEXPR LENGTH_TYPE size() const
    {
        return 3;
    }

    MATH_CONSTEXPR vec<3, T> &operator[](LENGTH_TYPE i)
    {
        if (i < 0 || i >= 3)
        {
            throw std::out_of_range("Index out of range");
        }
        return c[i];
    }

    MATH_CONSTEXPR const vec<3, T> &operator[](LENGTH_TYPE i) const
    {
        if (i < 0 || i >= 3)
        {
            throw std::out_of_range("Index out of range");
        }
        return c[i];
    }

    // --implicit basic constructors-- //
    MATH_CONSTEXPR mat3x3() = default;
    MATH_CONSTEXPR mat3x3(const mat3x3<T> &m) = default;
    MATH_CONSTEXPR mat3x3<T> &operator=(const mat3x3<T> &m) = default;
    MATH_CONSTEXPR mat3x3(mat3x3<T> &&m) = default;
    MATH_CONSTEXPR mat3x3<T> &operator=(mat3x3<T> &&m) = default;

    // --explicit conversion constructors-- //
    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat3x3(U scalar) : m00(static_cast<T>(scalar)), m01(static_cast<T>(0)), m02(static_cast<T>(0)),
                                                    m10(static_cast<T>(0)), m11(static_cast<T>(scalar)), m12(static_cast<T>(0)),
                                                    m20(static_cast<T>(0)), m21(static_cast<T>(0)), m22(static_cast<T>(scalar)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat3x3(const mat<2, 2, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(0)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(0)),
                                                                 m20(static_cast<T>(0)), m21(static_cast<T>(0)), m22(static_cast<T>(1)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat3x3(const mat<3, 2, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(0)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(0)),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(1)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat3x3(const mat<4, 2, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(0)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(0)),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(1)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat3x3(const mat<2, 3, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)),
                                                                 m20(static_cast<T>(0)), m21(static_cast<T>(0)), m22(static_cast<T>(1)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat3x3(const mat<3, 3, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(m.m22)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat3x3(const mat<4, 3, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(m.m22)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat3x3(const mat<2, 4, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(0)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(0)),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(1)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat3x3(const mat<3, 4, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(m.m22)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat3x3(const mat<4, 4, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(m.m22)) {}

    // --initializer list constructor-- //
    MATH_CONSTEXPR mat3x3(std::initializer_list<T> list)
    {
        if (list.size() != 9)
        {
            throw std::invalid_argument("Invalid list size");
        }
        auto it = list.begin();
        m00 = *it++;
        m01 = *it++;
        m02 = *it++;
        m10 = *it++;
        m11 = *it++;
        m12 = *it++;
        m20 = *it++;
        m21 = *it++;
        m22 = *it;
    }

    MATH_CONSTEXPR mat3x3(std::initializer_list<vector<3, T>> list)
    {
        if (list.size() != 3)
        {
            throw std::invalid_argument("Invalid list size");
        }
        auto it = list.begin();
        c[0] = *it++;
        c[1] = *it++;
        c[2] = *it;
    }

    
};

MATH_NAMESPACE_END