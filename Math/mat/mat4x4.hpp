#pragma once

#include "../Config.hpp"
#include "../sturctures.hpp"

#include <initializer_list>

MATH_NAMESPACE_BEGIN

template <typename T>
struct mat4x4
{
    union
    {
        vec4<T> c[4];
        T data[16];
        struct
        {
            T m00, m01, m02, m03;
            T m10, m11, m12, m13;
            T m20, m21, m22, m23;
            T m30, m31, m32, m33;
        };
    };

    // --accessors-- //
    MATH_CONSTEXPR LENGTH_TYPE size() const
    {
        return 4;
    }

    MATH_CONSTEXPR vec4<T> &operator[](LENGTH_TYPE i)
    {
        if (i < 0 || i >= 4)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("mat4x4"));
        }
        return c[i];
    }

    MATH_CONSTEXPR vec4<T> const &operator[](LENGTH_TYPE i) const
    {
        if (i < 0 || i >= 4)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("mat4x4"));
        }
        return c[i];
    }

    // --implicit basic constructors-- //
    MATH_CONSTEXPR mat4x4() = default;
    MATH_CONSTEXPR mat4x4(const mat4x4 &m) = default;
    MATH_CONSTEXPR mat4x4 &operator=(const mat4x4 &m) = default;
    MATH_CONSTEXPR mat4x4(mat4x4 &&m) = default;
    MATH_CONSTEXPR mat4x4 &operator=(mat4x4 &&m) = default;

    // TODO :: replace all constructors with initializer list

    // --explicit conversion constructors-- //
    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat4x4(U scalar) : m00(scalar), m01(scalar), m02(scalar), m03(scalar),
                                                    m10(scalar), m11(scalar), m12(scalar), m13(scalar),
                                                    m20(scalar), m21(scalar), m22(scalar), m23(scalar),
                                                    m30(scalar), m31(scalar), m32(scalar), m33(scalar) {}
    
    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat4x4(const mat<2, 2 ,U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(0), m03(0),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(0), m13(0),
                                                                 m20(0), m21(0), m22(1), m23(0),
                                                                 m30(0), m31(0), m32(0), m33(1) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat4x4(const mat<3, 2, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(0), m03(0),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(0), m13(0),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(1), m23(0),
                                                                 m30(0), m31(0), m32(0), m33(1) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat4x4(const mat<4, 2, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(0), m03(0),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(0), m13(0),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(1), m23(0),
                                                                 m30(static_cast<T>(m.m30)), m31(static_cast<T>(m.m31)), m32(0), m33(1) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat4x4(const mat<2, 3, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)), m03(0),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)), m13(0),
                                                                 m20(0), m21(0), m22(1), m23(0),
                                                                 m30(0), m31(0), m32(0), m33(1) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat4x4(const mat<3, 3, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)), m03(0),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)), m13(0),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(m.m22)), m23(0),
                                                                 m30(0), m31(0), m32(0), m33(1) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat4x4(const mat<4, 3, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)), m03(0),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)), m13(0),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(m.m22)), m23(0),
                                                                 m30(static_cast<T>(m.m30)), m31(static_cast<T>(m.m31)), m32(static_cast<T>(m.m32)), m33(1) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat4x4(const mat<2, 4, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)), m03(static_cast<T>(m.m03)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)), m13(static_cast<T>(m.m13)),
                                                                 m20(0), m21(0), m22(1), m23(0),
                                                                 m30(0), m31(0), m32(0), m33(1) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat4x4(const mat<3, 4, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)), m03(static_cast<T>(m.m03)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)), m13(static_cast<T>(m.m13)),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(m.m22)), m23(static_cast<T>(m.m23)),
                                                                 m30(0), m31(0), m32(0), m33(1) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat4x4(const mat<4, 4, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)), m03(static_cast<T>(m.m03)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)), m13(static_cast<T>(m.m13)),
                                                                 m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(m.m22)), m23(static_cast<T>(m.m23)),
                                                                 m30(static_cast<T>(m.m30)), m31(static_cast<T>(m.m31)), m32(static_cast<T>(m.m32)), m33(static_cast<T>(m.m33)) {}

    // --initializer list constructor-- //
    MATH_CONSTEXPR mat4x4(std::initializer_list<T> list)
    {
        if (list.size() != 16)
        {
            throw std::invalid_argument(INVALID_INITIALIZER_LIST_ARGS_MSG("mat4x4", list.size()));
        }
        auto it = list.begin();
        m00 = *it++;
        m01 = *it++;
        m02 = *it++;
        m03 = *it++;
        m10 = *it++;
        m11 = *it++;
        m12 = *it++;
        m13 = *it++;
        m20 = *it++;
        m21 = *it++;
        m22 = *it++;
        m23 = *it++;
        m30 = *it++;
        m31 = *it++;
        m32 = *it++;
        m33 = *it;
    }

    MATH_CONSTEXPR mat4x4(std::initializer_list<<vec<4, T>> list)
    {
        if (list.size() != 4)
        {
            throw std::invalid_argument(INVALID_INITIALIZER_LIST_ARGS_MSG("vec4", list.size()));
        }
        auto it = list.begin();
        c[0] = *it++;
        c[1] = *it++;
        c[2] = *it++;
        c[3] = *it;
    }

    // TODO :: template this
    // --unary arithmetic operators-- //
    MATH_CONSTEXPR mat4x4 operator+() const
    {
        return *this;
    }

    MATH_CONSTEXPR mat4x4 operator-() const
    {
        return mat4x4(-m00, -m01, -m02, -m03,
                      -m10, -m11, -m12, -m13,
                      -m20, -m21, -m22, -m23,
                      -m30, -m31, -m32, -m33);
    }

    MATH_CONSTEXPR mat4x4 &operator+=(T scalar)
    {
        m00 += scalar;
        m01 += scalar;
        m02 += scalar;
        m03 += scalar;
        m10 += scalar;
        m11 += scalar;
        m12 += scalar;
        m13 += scalar;
        m20 += scalar;
        m21 += scalar;
        m22 += scalar;
        m23 += scalar;
        m30 += scalar;
        m31 += scalar;
        m32 += scalar;
        m33 += scalar;
        return *this;
    }
};

MATH_NAMESPACE_END