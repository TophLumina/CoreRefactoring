#pragma once

#include "../Config.hpp"
#include "../sturctures.hpp"

#include <initializer_list>

MATH_NAMESPACE_BEGIN

template <typename T>
struct mat2x2
{
    union
    {
        vec<2, T> c[2];
        T data[4];
        struct
        {
            // Stored in column major order
            // source matrix:
            // | m00 m10 |
            // | m01 m11 |
            T m00, m01;
            T m10, m11;
        };
    };

    // --accessors-- //
    MATH_FUNCTION_QUALIFIERS LENGTH_TYPE size() const
    {
        return 2;
    }

    MATH_FUNCTION_QUALIFIERS vec<2, T> &operator[](LENGTH_TYPE i)
    {
        if (i < 0 || i >= 2)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("mat2x2"));
        }
        return c[i];
    }

    MATH_FUNCTION_QUALIFIERS vec<2, T> const &operator[](LENGTH_TYPE i) const
    {
        if (i < 0 || i >= 2)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("mat2x2"));
        }
        return c[i];
    }

    // --implicit basic constructors-- //
    MATH_FUNCTION_QUALIFIERS mat2x2() = default;
    MATH_FUNCTION_QUALIFIERS mat2x2(const mat2x2 &m) = default;
    MATH_FUNCTION_QUALIFIERS mat2x2 &operator=(const mat2x2 &m) = default;
    MATH_FUNCTION_QUALIFIERS mat2x2(mat2x2 &&m) = default;
    MATH_FUNCTION_QUALIFIERS mat2x2 &operator=(mat2x2 &&m) = default;

    // --explicit conversion constructors-- //
    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat2x2(U scalar) : m00(static_cast<T>(scalar)), m01(static_cast<T>(0)),
                                                              m10(static_cast<T>(0)), m11(static_cast<T>(scalar)) {}

    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat2x2(const mat2x2<U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                                        m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat2x2(const mat<3, 3, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                                           m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat2x2(const mat<4, 4, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                                           m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat2x2(U m00, U m01, U m10, U m11) : m00(static_cast<T>(m00)), m01(static_cast<T>(m01)),
                                                                                m10(static_cast<T>(m10)), m11(static_cast<T>(m11)) {}

    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT mat2x2(const vec<2, U> v0, vec<2, U> v1) : m00(static_cast<T>(v0.x)), m01(static_cast<T>(v0.y)),
                                                                                      m10(static_cast<T>(v1.x)), m11(static_cast<T>(v1.y)) {}

    // --initialization list constructors-- //
    MATH_FUNCTION_QUALIFIERS mat2x2(std::initializer_list<T> list)
    {
        if (list.size() < 4)
        {
            throw std::invalid_argument(INVALID_INITIALIZER_LIST_ARGS_MSG("mat2x2", list.size()));
        }
        auto it = list.begin();
        m00 = *it++;
        m01 = *it++;
        m10 = *it++;
        m11 = *it;
    }

    MATH_FUNCTION_QUALIFIERS mat2x2(std::initializer_list<vec<2, T>> list)
    {
        if (list.size() < 2)
        {
            throw std::invalid_argument(INVALID_INITIALIZER_LIST_ARGS_MSG("mat2x2", list.size()));
        }
        auto it = list.begin();
        c[0] = *it++;
        c[1] = *it;
    }

    // --unary arithmetic operators-- //
    MATH_FUNCTION_QUALIFIERS mat2x2 operator+() const
    {
        return *this;
    }

    MATH_FUNCTION_QUALIFIERS mat2x2 operator-() const
    {
        return mat2x2(-m00, -m01, -m10, -m11);
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat2x2 &operator+=(U scalar)
    {
        m00 += static_cast<T>(scalar);
        m01 += static_cast<T>(scalar);
        m10 += static_cast<T>(scalar);
        m11 += static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat2x2 &operator+=(const mat2x2<U> &m)
    {
        m00 += static_cast<T>(m.m00);
        m01 += static_cast<T>(m.m01);
        m10 += static_cast<T>(m.m10);
        m11 += static_cast<T>(m.m11);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat2x2 &operator-=(U scalar)
    {
        m00 -= static_cast<T>(scalar);
        m01 -= static_cast<T>(scalar);
        m10 -= static_cast<T>(scalar);
        m11 -= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat2x2 &operator-=(const mat2x2<U> &m)
    {
        m00 -= static_cast<T>(m.m00);
        m01 -= static_cast<T>(m.m01);
        m10 -= static_cast<T>(m.m10);
        m11 -= static_cast<T>(m.m11);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat2x2 &operator*=(U scalar)
    {
        m00 *= static_cast<T>(scalar);
        m01 *= static_cast<T>(scalar);
        m10 *= static_cast<T>(scalar);
        m11 *= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat2x2 &operator*=(const mat2x2<U> &m)
    {
        m00 *= static_cast<T>(m.m00);
        m01 *= static_cast<T>(m.m01);
        m10 *= static_cast<T>(m.m10);
        m11 *= static_cast<T>(m.m11);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat2x2 &operator/=(U scalar)
    {
        m00 /= static_cast<T>(scalar);
        m01 /= static_cast<T>(scalar);
        m10 /= static_cast<T>(scalar);
        m11 /= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS mat2x2 &operator/=(const mat2x2<U> &m)
    {
        m00 /= static_cast<T>(m.m00);
        m01 /= static_cast<T>(m.m01);
        m10 /= static_cast<T>(m.m10);
        m11 /= static_cast<T>(m.m11);
        return *this;
    }

    // --increment and decrement operators-- //
    MATH_FUNCTION_QUALIFIERS mat2x2 &operator++()
    {
        static_assert(std::is_integral<T>::value, "mat2x2<T>::operator++(): T must be an integral type.");

        ++m00;
        ++m01;
        ++m10;
        ++m11;
        return *this;
    }

    MATH_FUNCTION_QUALIFIERS mat2x2 operator++(int)
    {
        static_assert(std::is_integral<T>::value, "mat2x2<T>::operator++(int): T must be an integral type.");

        mat2x2 temp(*this);
        ++*this;
        return temp;
    }

    MATH_FUNCTION_QUALIFIERS mat2x2 &operator--()
    {
        static_assert(std::is_integral<T>::value, "mat2x2<T>::operator--(): T must be an integral type.");

        --m00;
        --m01;
        --m10;
        --m11;
        return *this;
    }

    MATH_FUNCTION_QUALIFIERS mat2x2 operator--(int)
    {
        static_assert(std::is_integral<T>::value, "mat2x2<T>::operator--(int): T must be an integral type.");

        mat2x2 temp(*this);
        --*this;
        return temp;
    }

    // --binary arithmetic operators-- //
    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator+(const mat2x2 &m, T scalar)
    {
        return {m.m00 + scalar, m.m01 + scalar, m.m10 + scalar, m.m11 + scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator+(T scalar, const mat2x2 &m)
    {
        return {scalar + m.m00, scalar + m.m01, scalar + m.m10, scalar + m.m11};
    }

    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator+(const mat2x2 &m1, const mat2x2 &m2)
    {
        return {m1.m00 + m2.m00, m1.m01 + m2.m01, m1.m10 + m2.m10, m1.m11 + m2.m11};
    }

    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator-(const mat2x2 &m, T scalar)
    {
        return {m.m00 - scalar, m.m01 - scalar, m.m10 - scalar, m.m11 - scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator-(T scalar, const mat2x2 &m)
    {
        return {scalar - m.m00, scalar - m.m01, scalar - m.m10, scalar - m.m11};
    }

    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator-(const mat2x2 &m1, const mat2x2 &m2)
    {
        return {m1.m00 - m2.m00, m1.m01 - m2.m01, m1.m10 - m2.m10, m1.m11 - m2.m11};
    }

    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator*(const mat2x2 &m, T scalar)
    {
        return {m.m00 * scalar, m.m01 * scalar, m.m10 * scalar, m.m11 * scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator*(T scalar, const mat2x2 &m)
    {
        return {scalar * m.m00, scalar * m.m01, scalar * m.m10, scalar * m.m11};
    }

    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator*(const mat2x2 &m1, const mat2x2 &m2)
    {
        return mat2x2(m1.m00 * m2.m00, m1.m01 * m2.m01, m1.m10 * m2.m10, m1.m11 * m2.m11);
    }

    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator/(const mat2x2 &m, T scalar)
    {
        return mat2x2(m.m00 / scalar, m.m01 / scalar, m.m10 / scalar, m.m11 / scalar);
    }

    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator/(T scalar, const mat2x2 &m)
    {
        return mat2x2(scalar / m.m00, scalar / m.m01, scalar / m.m10, scalar / m.m11);
    }

    friend MATH_FUNCTION_QUALIFIERS mat2x2 operator/(const mat2x2 &m1, const mat2x2 &m2)
    {
        return mat2x2(m1.m00 / m2.m00, m1.m01 / m2.m01, m1.m10 / m2.m10, m1.m11 / m2.m11);
    }

    // --comparison operators-- //
    friend MATH_FUNCTION_QUALIFIERS bool operator==(const mat2x2 &m1, const mat2x2 &m2)
    {
        return m1.m00 == m2.m00 && m1.m01 == m2.m01 && m1.m10 == m2.m10 && m1.m11 == m2.m11;
    }

    friend MATH_FUNCTION_QUALIFIERS bool operator!=(const mat2x2 &m1, const mat2x2 &m2)
    {
        return m1.m00 != m2.m00 || m1.m01 != m2.m01 || m1.m10 != m2.m10 || m1.m11 != m2.m11;
    }
};

// --stream operators-- //
#ifdef MATH_IOS
template <typename T>
std::ostream &operator<<(std::ostream &os, const mat2x2<T> &m)
{
    os << "mat2x2<" << typeid(T).name() << ">{" << '\n'
       << m.m00 << ", " << m.m10 << ", " << '\n'
       << m.m01 << ", " << m.m11 << "}";
    return os;
}
#endif

#ifdef MATH_TEMPLATE_ALIASES
using mat2x2i = mat2x2<int>;
using mat2x2u = mat2x2<unsigned int>;
using mat2x2f = mat2x2<float>;
using mat2x2d = mat2x2<double>;
#endif

MATH_NAMESPACE_END