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
        vec<4, T> c[4];
        T data[16];
        struct
        {
            // Stored in column major order
            // source matrix:
            // | m00 m10 m20 m30 |
            // | m01 m11 m21 m31 |
            // | m02 m12 m22 m32 |
            // | m03 m13 m23 m33 |
            T m00, m01, m02, m03;
            T m10, m11, m12, m13;
            T m20, m21, m22, m23;
            T m30, m31, m32, m33;
        };
    };

    // --accessors-- //
    MATH_FUNCTION_QUALIFIERS LENGTH_TYPE size() const
    {
        return 4;
    }

    MATH_FUNCTION_QUALIFIERS vec<4, T> &operator[](LENGTH_TYPE i)
    {
        if (i < 0 || i >= 4)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("mat4x4"));
        }
        return c[i];
    }

    MATH_FUNCTION_QUALIFIERS vec<4, T> const &operator[](LENGTH_TYPE i) const
    {
        if (i < 0 || i >= 4)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("mat4x4"));
        }
        return c[i];
    }

    // --implicit basic constructors-- //
    MATH_FUNCTION_QUALIFIERS mat4x4() = default;
    MATH_FUNCTION_QUALIFIERS mat4x4(const mat4x4 &m) = default;
    MATH_FUNCTION_QUALIFIERS mat4x4 &operator=(const mat4x4 &m) = default;
    MATH_FUNCTION_QUALIFIERS mat4x4(mat4x4 &&m) = default;
    MATH_FUNCTION_QUALIFIERS mat4x4 &operator=(mat4x4 &&m) = default;

    // --explicit conversion constructors-- //
    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat4x4(U scalar) : m00(scalar), m01(scalar), m02(scalar), m03(scalar),
                                                              m10(scalar), m11(scalar), m12(scalar), m13(scalar),
                                                              m20(scalar), m21(scalar), m22(scalar), m23(scalar),
                                                              m30(scalar), m31(scalar), m32(scalar), m33(scalar) {}

    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat4x4(const mat<2, 2, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(0), m03(0),
                                                                           m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(0), m13(0),
                                                                           m20(0), m21(0), m22(1), m23(0),
                                                                           m30(0), m31(0), m32(0), m33(1) {}

    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat4x4(const mat<3, 3, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)), m03(0),
                                                                           m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)), m13(0),
                                                                           m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(m.m22)), m23(0),
                                                                           m30(0), m31(0), m32(0), m33(1) {}

    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat4x4(const mat<4, 4, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)), m02(static_cast<T>(m.m02)), m03(static_cast<T>(m.m03)),
                                                                           m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)), m12(static_cast<T>(m.m12)), m13(static_cast<T>(m.m13)),
                                                                           m20(static_cast<T>(m.m20)), m21(static_cast<T>(m.m21)), m22(static_cast<T>(m.m22)), m23(static_cast<T>(m.m23)),
                                                                           m30(static_cast<T>(m.m30)), m31(static_cast<T>(m.m31)), m32(static_cast<T>(m.m32)), m33(static_cast<T>(m.m33)) {}

    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat4x4(U m00, U m01, U m02, U m03,
                                                  U m10, U m11, U m12, U m13,
                                                  U m20, U m21, U m22, U m23,
                                                  U m30, U m31, U m32, U m33) : m00(static_cast<T>(m00)), m01(static_cast<T>(m01)), m02(static_cast<T>(m02)), m03(static_cast<T>(m03)),
                                                                                m10(static_cast<T>(m10)), m11(static_cast<T>(m11)), m12(static_cast<T>(m12)), m13(static_cast<T>(m13)),
                                                                                m20(static_cast<T>(m20)), m21(static_cast<T>(m21)), m22(static_cast<T>(m22)), m23(static_cast<T>(m23)),
                                                                                m30(static_cast<T>(m30)), m31(static_cast<T>(m31)), m32(static_cast<T>(m32)), m33(static_cast<T>(m33)) {}

    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat4x4(const vec<4, U> &v0, const vec<4, U> &v1, const vec<4, U> &v2, const vec<4, U> &v3) : c{v0, v1, v2, v3} {}

    // --initializer list constructor-- //
    MATH_FUNCTION_QUALIFIERS mat4x4(std::initializer_list<T> list)
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

    MATH_FUNCTION_QUALIFIERS mat4x4(std::initializer_list<vec<4, T>> list)
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

    // --unary arithmetic operators-- //
    MATH_FUNCTION_QUALIFIERS mat4x4 operator+() const
    {
        return *this;
    }

    MATH_FUNCTION_QUALIFIERS mat4x4 operator-() const
    {
        return mat4x4(-m00, -m01, -m02, -m03,
                      -m10, -m11, -m12, -m13,
                      -m20, -m21, -m22, -m23,
                      -m30, -m31, -m32, -m33);
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat4x4 &operator+=(U scalar)
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

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat4x4 &operator+=(const mat4x4<U> &m)
    {
        m00 += m.m00;
        m01 += m.m01;
        m02 += m.m02;
        m03 += m.m03;
        m10 += m.m10;
        m11 += m.m11;
        m12 += m.m12;
        m13 += m.m13;
        m20 += m.m20;
        m21 += m.m21;
        m22 += m.m22;
        m23 += m.m23;
        m30 += m.m30;
        m31 += m.m31;
        m32 += m.m32;
        m33 += m.m33;
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat4x4 &operator-=(U scalar)
    {
        m00 -= scalar;
        m01 -= scalar;
        m02 -= scalar;
        m03 -= scalar;
        m10 -= scalar;
        m11 -= scalar;
        m12 -= scalar;
        m13 -= scalar;
        m20 -= scalar;
        m21 -= scalar;
        m22 -= scalar;
        m23 -= scalar;
        m30 -= scalar;
        m31 -= scalar;
        m32 -= scalar;
        m33 -= scalar;
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat4x4 &operator-=(const mat4x4<U> &m)
    {
        m00 -= m.m00;
        m01 -= m.m01;
        m02 -= m.m02;
        m03 -= m.m03;
        m10 -= m.m10;
        m11 -= m.m11;
        m12 -= m.m12;
        m13 -= m.m13;
        m20 -= m.m20;
        m21 -= m.m21;
        m22 -= m.m22;
        m23 -= m.m23;
        m30 -= m.m30;
        m31 -= m.m31;
        m32 -= m.m32;
        m33 -= m.m33;
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat4x4 &operator*=(U scalar)
    {
        m00 *= scalar;
        m01 *= scalar;
        m02 *= scalar;
        m03 *= scalar;
        m10 *= scalar;
        m11 *= scalar;
        m12 *= scalar;
        m13 *= scalar;
        m20 *= scalar;
        m21 *= scalar;
        m22 *= scalar;
        m23 *= scalar;
        m30 *= scalar;
        m31 *= scalar;
        m32 *= scalar;
        m33 *= scalar;
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat4x4 &operator*=(const mat4x4<U> &m)
    {
        m00 *= m.m00;
        m01 *= m.m01;
        m02 *= m.m02;
        m03 *= m.m03;
        m10 *= m.m10;
        m11 *= m.m11;
        m12 *= m.m12;
        m13 *= m.m13;
        m20 *= m.m20;
        m21 *= m.m21;
        m22 *= m.m22;
        m23 *= m.m23;
        m30 *= m.m30;
        m31 *= m.m31;
        m32 *= m.m32;
        m33 *= m.m33;
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat4x4 &operator/=(U scalar)
    {
        m00 /= scalar;
        m01 /= scalar;
        m02 /= scalar;
        m03 /= scalar;
        m10 /= scalar;
        m11 /= scalar;
        m12 /= scalar;
        m13 /= scalar;
        m20 /= scalar;
        m21 /= scalar;
        m22 /= scalar;
        m23 /= scalar;
        m30 /= scalar;
        m31 /= scalar;
        m32 /= scalar;
        m33 /= scalar;
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat4x4 &operator/=(const mat4x4<U> &m)
    {
        m00 /= m.m00;
        m01 /= m.m01;
        m02 /= m.m02;
        m03 /= m.m03;
        m10 /= m.m10;
        m11 /= m.m11;
        m12 /= m.m12;
        m13 /= m.m13;
        m20 /= m.m20;
        m21 /= m.m21;
        m22 /= m.m22;
        m23 /= m.m23;
        m30 /= m.m30;
        m31 /= m.m31;
        m32 /= m.m32;
        m33 /= m.m33;
        return *this;
    }

    // --increment and decrement operators-- //
    MATH_FUNCTION_QUALIFIERS mat4x4 &operator++()
    {
        static_assert(std::is_integral<T>::value, "mat4x4<T>::operator++(): T must be an integral type.");

        ++m00;
        ++m01;
        ++m02;
        ++m03;
        ++m10;
        ++m11;
        ++m12;
        ++m13;
        ++m20;
        ++m21;
        ++m22;
        ++m23;
        ++m30;
        ++m31;
        ++m32;
        ++m33;
        return *this;
    }

    MATH_FUNCTION_QUALIFIERS mat4x4 operator++(int)
    {
        static_assert(std::is_integral<T>::value, "mat4x4<T>::operator++(int): T must be an integral type.");

        mat4x4 temp(*this);
        ++*this;
        return temp;
    }

    MATH_FUNCTION_QUALIFIERS mat4x4 &operator--()
    {
        static_assert(std::is_integral<T>::value, "mat4x4<T>::operator--(): T must be an integral type.");

        --m00;
        --m01;
        --m02;
        --m03;
        --m10;
        --m11;
        --m12;
        --m13;
        --m20;
        --m21;
        --m22;
        --m23;
        --m30;
        --m31;
        --m32;
        --m33;
        return *this;
    }

    MATH_FUNCTION_QUALIFIERS mat4x4 operator--(int)
    {
        static_assert(std::is_integral<T>::value, "mat4x4<T>::operator--(int): T must be an integral type.");

        mat4x4 temp(*this);
        --*this;
        return temp;
    }

    // --binary arithmetic operators-- //
    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator+(const mat4x4 &m, T scalar)
    {
        return {m.m00 + scalar, m.m01 + scalar, m.m02 + scalar, m.m03 + scalar,
                m.m10 + scalar, m.m11 + scalar, m.m12 + scalar, m.m13 + scalar,
                m.m20 + scalar, m.m21 + scalar, m.m22 + scalar, m.m23 + scalar,
                m.m30 + scalar, m.m31 + scalar, m.m32 + scalar, m.m33 + scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator+(T scalar, const mat4x4 &m)
    {
        return {m.m00 + scalar, m.m01 + scalar, m.m02 + scalar, m.m03 + scalar,
                m.m10 + scalar, m.m11 + scalar, m.m12 + scalar, m.m13 + scalar,
                m.m20 + scalar, m.m21 + scalar, m.m22 + scalar, m.m23 + scalar,
                m.m30 + scalar, m.m31 + scalar, m.m32 + scalar, m.m33 + scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator+(const mat4x4 &m1, const mat4x4 &m2)
    {
        return {m1.m00 + m2.m00, m1.m01 + m2.m01, m1.m02 + m2.m02, m1.m03 + m2.m03,
                m1.m10 + m2.m10, m1.m11 + m2.m11, m1.m12 + m2.m12, m1.m13 + m2.m13,
                m1.m20 + m2.m20, m1.m21 + m2.m21, m1.m22 + m2.m22, m1.m23 + m2.m23,
                m1.m30 + m2.m30, m1.m31 + m2.m31, m1.m32 + m2.m32, m1.m33 + m2.m33};
    }

    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator-(const mat4x4 &m, T scalar)
    {
        return {m.m00 - scalar, m.m01 - scalar, m.m02 - scalar, m.m03 - scalar,
                m.m10 - scalar, m.m11 - scalar, m.m12 - scalar, m.m13 - scalar,
                m.m20 - scalar, m.m21 - scalar, m.m22 - scalar, m.m23 - scalar,
                m.m30 - scalar, m.m31 - scalar, m.m32 - scalar, m.m33 - scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator-(T scalar, const mat4x4 &m)
    {
        return {scalar - m.m00, scalar - m.m01, scalar - m.m02, scalar - m.m03,
                scalar - m.m10, scalar - m.m11, scalar - m.m12, scalar - m.m13,
                scalar - m.m20, scalar - m.m21, scalar - m.m22, scalar - m.m23,
                scalar - m.m30, scalar - m.m31, scalar - m.m32, scalar - m.m33};
    }

    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator-(const mat4x4 &m1, const mat4x4 &m2)
    {
        return {m1.m00 - m2.m00, m1.m01 - m2.m01, m1.m02 - m2.m02, m1.m03 - m2.m03,
                m1.m10 - m2.m10, m1.m11 - m2.m11, m1.m12 - m2.m12, m1.m13 - m2.m13,
                m1.m20 - m2.m20, m1.m21 - m2.m21, m1.m22 - m2.m22, m1.m23 - m2.m23,
                m1.m30 - m2.m30, m1.m31 - m2.m31, m1.m32 - m2.m32, m1.m33 - m2.m33};
    }

    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator*(const mat4x4 &m, T scalar)
    {
        return {m.m00 * scalar, m.m01 * scalar, m.m02 * scalar, m.m03 * scalar,
                m.m10 * scalar, m.m11 * scalar, m.m12 * scalar, m.m13 * scalar,
                m.m20 * scalar, m.m21 * scalar, m.m22 * scalar, m.m23 * scalar,
                m.m30 * scalar, m.m31 * scalar, m.m32 * scalar, m.m33 * scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator*(T scalar, const mat4x4 &m)
    {
        return {m.m00 * scalar, m.m01 * scalar, m.m02 * scalar, m.m03 * scalar,
                m.m10 * scalar, m.m11 * scalar, m.m12 * scalar, m.m13 * scalar,
                m.m20 * scalar, m.m21 * scalar, m.m22 * scalar, m.m23 * scalar,
                m.m30 * scalar, m.m31 * scalar, m.m32 * scalar, m.m33 * scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator*(const mat4x4 &m1, const mat4x4 &m2)
    {
        return {m1.m00 * m2.m00, m1.m01 * m2.m01, m1.m02 * m2.m02, m1.m03 * m2.m03,
                m1.m10 * m2.m10, m1.m11 * m2.m11, m1.m12 * m2.m12, m1.m13 * m2.m13,
                m1.m20 * m2.m20, m1.m21 * m2.m21, m1.m22 * m2.m22, m1.m23 * m2.m23,
                m1.m30 * m2.m30, m1.m31 * m2.m31, m1.m32 * m2.m32, m1.m33 * m2.m33};
    }

    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator/(const mat4x4 &m, T scalar)
    {
        return {m.m00 / scalar, m.m01 / scalar, m.m02 / scalar, m.m03 / scalar,
                m.m10 / scalar, m.m11 / scalar, m.m12 / scalar, m.m13 / scalar,
                m.m20 / scalar, m.m21 / scalar, m.m22 / scalar, m.m23 / scalar,
                m.m30 / scalar, m.m31 / scalar, m.m32 / scalar, m.m33 / scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator/(T scalar, const mat4x4 &m)
    {
        return {scalar / m.m00, scalar / m.m01, scalar / m.m02, scalar / m.m03,
                scalar / m.m10, scalar / m.m11, scalar / m.m12, scalar / m.m13,
                scalar / m.m20, scalar / m.m21, scalar / m.m22, scalar / m.m23,
                scalar / m.m30, scalar / m.m31, scalar / m.m32, scalar / m.m33};
    }

    friend MATH_FUNCTION_QUALIFIERS mat4x4 operator/(const mat4x4 &m1, const mat4x4 &m2)
    {
        return {m1.m00 / m2.m00, m1.m01 / m2.m01, m1.m02 / m2.m02, m1.m03 / m2.m03,
                m1.m10 / m2.m10, m1.m11 / m2.m11, m1.m12 / m2.m12, m1.m13 / m2.m13,
                m1.m20 / m2.m20, m1.m21 / m2.m21, m1.m22 / m2.m22, m1.m23 / m2.m23,
                m1.m30 / m2.m30, m1.m31 / m2.m31, m1.m32 / m2.m32, m1.m33 / m2.m33};
    }

    // --comparison operators-- //
    friend MATH_FUNCTION_QUALIFIERS bool operator==(const mat4x4 &m1, const mat4x4 &m2)
    {
        return m1.m00 == m2.m00 && m1.m01 == m2.m01 && m1.m02 == m2.m02 && m1.m03 == m2.m03 &&
               m1.m10 == m2.m10 && m1.m11 == m2.m11 && m1.m12 == m2.m12 && m1.m13 == m2.m13 &&
               m1.m20 == m2.m20 && m1.m21 == m2.m21 && m1.m22 == m2.m22 && m1.m23 == m2.m23 &&
               m1.m30 == m2.m30 && m1.m31 == m2.m31 && m1.m32 == m2.m32 && m1.m33 == m2.m33;
    }

    friend MATH_FUNCTION_QUALIFIERS bool operator!=(const mat4x4 &m1, const mat4x4 &m2)
    {
        return m1.m00 != m2.m00 || m1.m01 != m2.m01 || m1.m02 != m2.m02 || m1.m03 != m2.m03 ||
               m1.m10 != m2.m10 || m1.m11 != m2.m11 || m1.m12 != m2.m12 || m1.m13 != m2.m13 ||
               m1.m20 != m2.m20 || m1.m21 != m2.m21 || m1.m22 != m2.m22 || m1.m23 != m2.m23 ||
               m1.m30 != m2.m30 || m1.m31 != m2.m31 || m1.m32 != m2.m32 || m1.m33 != m2.m33;
    }
};

// --stream operators-- //
#ifdef MATH_IOS
template <typename T>
std::ostream &operator<<(std::ostream &os, const mat4x4<T> &m)
{
    os << "mat4x4<" << typeid(T).name() << ">{" << '\n'
       << m.m00 << ", " << m.m01 << ", " << m.m02 << ", " << m.m03 << ", " << '\n'
       << m.m10 << ", " << m.m11 << ", " << m.m12 << ", " << m.m13 << ", " << '\n'
       << m.m20 << ", " << m.m21 << ", " << m.m22 << ", " << m.m23 << ", " << '\n'
       << m.m30 << ", " << m.m31 << ", " << m.m32 << ", " << m.m33 << "}";
    return os;
}
#endif

#ifdef MATH_TEMPLATE_ALIASES
using mat4x4i = mat4x4<int>;
using mat4x4u = mat4x4<unsigned int>;
using mat4x4f = mat4x4<float>;
using mat4x4d = mat4x4<double>;
#endif

MATH_NAMESPACE_END