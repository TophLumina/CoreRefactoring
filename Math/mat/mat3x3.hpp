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
        T data[9];
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

    // TODO :: replace all constructors with initializer list

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

    // --unary arithmetic operators-- //
    MATH_CONSTEXPR mat3x3<T> operator+() const
    {
        return *this;
    }

    MATH_CONSTEXPR mat3x3<T> operator-() const
    {
        return {-m00, -m01, -m02, -m10, -m11, -m12, -m20, -m21, -m22};
    }

    template <typename U>
    MATH_CONSTEXPR mat3x3<T> &operator+=(U scalar)
    {
        m00 += static_cast<T>(scalar);
        m01 += static_cast<T>(scalar);
        m02 += static_cast<T>(scalar);
        m10 += static_cast<T>(scalar);
        m11 += static_cast<T>(scalar);
        m12 += static_cast<T>(scalar);
        m20 += static_cast<T>(scalar);
        m21 += static_cast<T>(scalar);
        m22 += static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat3x3<T> &operator+=(const mat3x3<U> &m)
    {
        m00 += static_cast<T>(m.m00);
        m01 += static_cast<T>(m.m01);
        m02 += static_cast<T>(m.m02);
        m10 += static_cast<T>(m.m10);
        m11 += static_cast<T>(m.m11);
        m12 += static_cast<T>(m.m12);
        m20 += static_cast<T>(m.m20);
        m21 += static_cast<T>(m.m21);
        m22 += static_cast<T>(m.m22);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat3x3<T> &operator-=(U scalar)
    {
        m00 -= static_cast<T>(scalar);
        m01 -= static_cast<T>(scalar);
        m02 -= static_cast<T>(scalar);
        m10 -= static_cast<T>(scalar);
        m11 -= static_cast<T>(scalar);
        m12 -= static_cast<T>(scalar);
        m20 -= static_cast<T>(scalar);
        m21 -= static_cast<T>(scalar);
        m22 -= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat3x3<T> &operator-=(const mat3x3<U> &m)
    {
        m00 -= static_cast<T>(m.m00);
        m01 -= static_cast<T>(m.m01);
        m02 -= static_cast<T>(m.m02);
        m10 -= static_cast<T>(m.m10);
        m11 -= static_cast<T>(m.m11);
        m12 -= static_cast<T>(m.m12);
        m20 -= static_cast<T>(m.m20);
        m21 -= static_cast<T>(m.m21);
        m22 -= static_cast<T>(m.m22);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat3x3<T> &operator*=(U scalar)
    {
        m00 *= static_cast<T>(scalar);
        m01 *= static_cast<T>(scalar);
        m02 *= static_cast<T>(scalar);
        m10 *= static_cast<T>(scalar);
        m11 *= static_cast<T>(scalar);
        m12 *= static_cast<T>(scalar);
        m20 *= static_cast<T>(scalar);
        m21 *= static_cast<T>(scalar);
        m22 *= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat3x3<T> &operator*=(const mat3x3<U> &m)
    {
        m00 *= static_cast<T>(m.m00);
        m01 *= static_cast<T>(m.m01);
        m02 *= static_cast<T>(m.m02);
        m10 *= static_cast<T>(m.m10);
        m11 *= static_cast<T>(m.m11);
        m12 *= static_cast<T>(m.m12);
        m20 *= static_cast<T>(m.m20);
        m21 *= static_cast<T>(m.m21);
        m22 *= static_cast<T>(m.m22);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat3x3<T> &operator/=(U scalar)
    {
        m00 /= static_cast<T>(scalar);
        m01 /= static_cast<T>(scalar);
        m02 /= static_cast<T>(scalar);
        m10 /= static_cast<T>(scalar);
        m11 /= static_cast<T>(scalar);
        m12 /= static_cast<T>(scalar);
        m20 /= static_cast<T>(scalar);
        m21 /= static_cast<T>(scalar);
        m22 /= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat3x3<T> &operator/=(const mat3x3<U> &m)
    {
        m00 /= static_cast<T>(m.m00);
        m01 /= static_cast<T>(m.m01);
        m02 /= static_cast<T>(m.m02);
        m10 /= static_cast<T>(m.m10);
        m11 /= static_cast<T>(m.m11);
        m12 /= static_cast<T>(m.m12);
        m20 /= static_cast<T>(m.m20);
        m21 /= static_cast<T>(m.m21);
        m22 /= static_cast<T>(m.m22);
        return *this;
    }

    // --increment and decrement operators-- //
    MATH_CONSTEXPR mat3x3<T> &operator++()
    {
        ++m00;
        ++m01;
        ++m02;
        ++m10;
        ++m11;
        ++m12;
        ++m20;
        ++m21;
        ++m22;
        return *this;
    }

    MATH_CONSTEXPR mat3x3<T> operator++(int)
    {
        mat temp(*this);
        ++*this;
        return temp;
    }

    MATH_CONSTEXPR mat3x3<T> &operator--()
    {
        --m00;
        --m01;
        --m02;
        --m10;
        --m11;
        --m12;
        --m20;
        --m21;
        --m22;
        return *this;
    }

    MATH_CONSTEXPR mat3x3<T> operator--(int)
    {
        mat temp(*this);
        --*this;
        return temp;
    }

    // --binary arithmetic operators-- //
    friend MATH_CONSTEXPR mat3x3<T> operator+(const mat3x3<T> &m, T scalar)
    {
        return {m.m00 + scalar, m.m01 + scalar, m.m02 + scalar, m.m10 + scalar, m.m11 + scalar, m.m12 + scalar, m.m20 + scalar, m.m21 + scalar, m.m22 + scalar};
    }

    friend MATH_CONSTEXPR mat3x3<T> operator+(T scalar, const mat3x3<T> &m)
    {
        return {scalar + m.m00, scalar + m.m01, scalar + m.m02, scalar + m.m10, scalar + m.m11, scalar + m.m12, scalar + m.m20, scalar + m.m21, scalar + m.m22};
    }

    friend MATH_CONSTEXPR mat3x3<T> operator+(const mat3x3<T> &m1, const mat3x3<T> &m2)
    {
        return {m1.m00 + m2.m00, m1.m01 + m2.m01, m1.m02 + m2.m02, m1.m10 + m2.m10, m1.m11 + m2.m11, m1.m12 + m2.m12, m1.m20 + m2.m20, m1.m21 + m2.m21, m1.m22 + m2.m22};
    }

    friend MATH_CONSTEXPR mat3x3<T> operator-(const mat3x3<T> &m, T scalar)
    {
        return {m.m00 - scalar, m.m01 - scalar, m.m02 - scalar, m.m10 - scalar, m.m11 - scalar, m.m12 - scalar, m.m20 - scalar, m.m21 - scalar, m.m22 - scalar};
    }

    friend MATH_CONSTEXPR mat3x3<T> operator-(T scalar, const mat3x3<T> &m)
    {
        return {scalar - m.m00, scalar - m.m01, scalar - m.m02, scalar - m.m10, scalar - m.m11, scalar - m.m12, scalar - m.m20, scalar - m.m21, scalar - m.m22};
    }

    friend MATH_CONSTEXPR mat3x3<T> operator-(const mat3x3<T> &m1, const mat3x3<T> &m2)
    {
        return {m1.m00 - m2.m00, m1.m01 - m2.m01, m1.m02 - m2.m02, m1.m10 - m2.m10, m1.m11 - m2.m11, m1.m12 - m2.m12, m1.m20 - m2.m20, m1.m21 - m2.m21, m1.m22 - m2.m22};
    }

    friend MATH_CONSTEXPR mat3x3<T> operator*(const mat3x3<T> &m, T scalar)
    {
        return {m.m00 * scalar, m.m01 * scalar, m.m02 * scalar, m.m10 * scalar, m.m11 * scalar, m.m12 * scalar, m.m20 * scalar, m.m21 * scalar, m.m22 * scalar};
    }

    friend MATH_CONSTEXPR mat3x3<T> operator*(T scalar, const mat3x3<T> &m)
    {
        return {scalar * m.m00, scalar * m.m01, scalar * m.m02, scalar * m.m10, scalar * m.m11, scalar * m.m12, scalar * m.m20, scalar * m.m21, scalar * m.m22};
    }

    friend MATH_CONSTEXPR vec<3, T> operator*(const mat3x3<T> &m, const vec<3, T> &v)
    {
        return {m.m00 * v.x + m.m01 * v.y + m.m02 * v.z, m.m10 * v.x + m.m11 * v.y + m.m12 * v.z, m.m20 * v.x + m.m21 * v.y + m.m22 * v.z};
    }

    friend MATH_CONSTEXPR vec<3, T> operator*(const vec<3, T> &v, const mat3x3<T> &m)
    {
        return {v.x * m.m00 + v.y * m.m10 + v.z * m.m20, v.x * m.m01 + v.y * m.m11 + v.z * m.m21, v.x * m.m02 + v.y * m.m12 + v.z * m.m22};
    }

    friend MATH_CONSTEXPR mat3x3<T> operator*(const mat3x3<T> &m1, const mat3x3<T> &m2)
    {
        return {m1.m00 * m2.m00 + m1.m01 * m2.m10 + m1.m02 * m2.m20, m1.m00 * m2.m01 + m1.m01 * m2.m11 + m1.m02 * m2.m21, m1.m00 * m2.m02 + m1.m01 * m2.m12 + m1.m02 * m2.m22,
                m1.m10 * m2.m00 + m1.m11 * m2.m10 + m1.m12 * m2.m20, m1.m10 * m2.m01 + m1.m11 * m2.m11 + m1.m12 * m2.m21, m1.m10 * m2.m02 + m1.m11 * m2.m12 + m1.m12 * m2.m22,
                m1.m20 * m2.m00 + m1.m21 * m2.m10 + m1.m22 * m2.m20, m1.m20 * m2.m01 + m1.m21 * m2.m11 + m1.m22 * m2.m21, m1.m20 * m2.m02 + m1.m21 * m2.m12 + m1.m22 * m2.m22};
    }

    friend MATH_CONSTEXPR mat3x3<T> operator/(const mat3x3<T> &m, T scalar)
    {
        return {m.m00 / scalar, m.m01 / scalar, m.m02 / scalar, m.m10 / scalar, m.m11 / scalar, m.m12 / scalar, m.m20 / scalar, m.m21 / scalar, m.m22 / scalar};
    }

    friend MATH_CONSTEXPR mat3x3<T> operator/(T scalar, const mat3x3<T> &m)
    {
        return {scalar / m.m00, scalar / m.m01, scalar / m.m02, scalar / m.m10, scalar / m.m11, scalar / m.m12, scalar / m.m20, scalar / m.m21, scalar / m.m22};
    }

    friend MATH_CONSTEXPR mat3x3<T> operator/(const mat3x3<T> &m1, const mat3x3<T> &m2)
    {
        return {m1.m00 / m2.m00, m1.m01 / m2.m01, m1.m02 / m2.m02, m1.m10 / m2.m10, m1.m11 / m2.m11, m1.m12 / m2.m12, m1.m20 / m2.m20, m1.m21 / m2.m21, m1.m22 / m2.m22};
    }

    // --comparison operators-- //
    friend MATH_CONSTEXPR bool operator==(const mat3x3<T> &m1, const mat3x3<T> &m2)
    {
        return m1.m00 == m2.m00 && m1.m01 == m2.m01 && m1.m02 == m2.m02 && m1.m10 == m2.m10 && m1.m11 == m2.m11 && m1.m12 == m2.m12 && m1.m20 == m2.m20 && m1.m21 == m2.m21 && m1.m22 == m2.m22;
    }

    friend MATH_CONSTEXPR bool operator!=(const mat3x3<T> &m1, const mat3x3<T> &m2)
    {
        return m1.m00 != m2.m00 || m1.m01 != m2.m01 || m1.m02 != m2.m02 || m1.m10 != m2.m10 || m1.m11 != m2.m11 || m1.m12 != m2.m12 || m1.m20 != m2.m20 || m1.m21 != m2.m21 || m1.m22 != m2.m22;
    }
};

// --stream operators-- //
#ifdef MATH_IOS
template <typename T>
std::ostream &operator<<(std::ostream &os, const mat3x3<T> &m)
{
    os << "mat3x3<" << typeid(T).name() << ">(" << m.m00 << ", " << m.m01 << ", " << m.m02 << ", "
                                                << m.m10 << ", " << m.m11 << ", " << m.m12 << ", "
                                                << m.m20 << ", " << m.m21 << ", " << m.m22 << ")";
}
#endif

#ifdef MATH_TEMPLATE_ALIASES
using mat3x3i = mat3x3<int>;
using mat3x3u = mat3x3<unsigned int>;
using mat3x3f = mat3x3<float>;
using mat3x3d = mat3x3<double>;
#endif

MATH_NAMESPACE_END