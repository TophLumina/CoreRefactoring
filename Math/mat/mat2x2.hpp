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
            T m00, m01;
            T m10, m11;
        };
    };

    // --accessors-- //
    MATH_CONSTEXPR LENGTH_TYPE size() const
    {
        return 2;
    }

    MATH_CONSTEXPR vec<2, T> &operator[](LENGTH_TYPE i)
    {
        if (i < 0 || i >= 2)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("mat2x2"));
        }
        return c[i];
    }

    MATH_CONSTEXPR vec<2, T> const &operator[](LENGTH_TYPE i) const
    {
        if (i < 0 || i >= 2)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("mat2x2"));
        }
        return c[i];
    }

    // --implicit basic constructors-- //
    MATH_CONSTEXPR mat2x2() = default;
    MATH_CONSTEXPR mat2x2(const mat2x2 &m) = default;
    MATH_CONSTEXPR mat2x2 &operator=(const mat2x2 &m) = default;
    MATH_CONSTEXPR mat2x2(mat2x2 &&m) = default;
    MATH_CONSTEXPR mat2x2 &operator=(mat2x2 &&m) = default;

    // --explicit conversion constructors-- //
    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat2x2(U scalar) : m00(static_cast<T>(scalar)), m01(static_cast<T>(0)),
                                                    m10(static_cast<T>(0)), m11(static_cast<T>(scalar)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat2x2(const mat2x2<U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                              m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat2x2(const mat<3, 2, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat2x2(const mat<4, 2, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat2x2(const mat<2, 3, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat2x2(const mat<3, 3, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat2x2(const mat<4, 3, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat2x2(const mat<2, 4, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat2x2(const mat<3, 4, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat2x2(const mat<4, 4, U> &m) : m00(static_cast<T>(m.m00)), m01(static_cast<T>(m.m01)),
                                                                 m10(static_cast<T>(m.m10)), m11(static_cast<T>(m.m11)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT mat2x2(const vec<2, U> v0, vec<2, U> v1) : m00(static_cast<T>(v0.x)), m01(static_cast<T>(v0.y)),
                                                                            m10(static_cast<T>(v1.x)), m11(static_cast<T>(v1.y)) {}

    // --initialization list constructors-- //
    MATH_CONSTEXPR mat2x2(std::initializer_list<T> list)
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

    MATH_CONSTEXPR mat2x2(std::initializer_list<vec<2, T>> list)
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
    MATH_CONSTEXPR mat2x2 operator+() const
    {
        return *this;
    }

    MATH_CONSTEXPR mat2x2 operator-() const
    {
        return mat2x2(-m00, -m01, -m10, -m11);
    }

    template <typename U>
    MATH_CONSTEXPR mat2x2 &operator+=(U scalar)
    {
        m00 += static_cast<T>(scalar);
        m01 += static_cast<T>(scalar);
        m10 += static_cast<T>(scalar);
        m11 += static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat2x2 &operator+=(const mat2x2<U> &m)
    {
        m00 += static_cast<T>(m.m00);
        m01 += static_cast<T>(m.m01);
        m10 += static_cast<T>(m.m10);
        m11 += static_cast<T>(m.m11);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat2x2 &operator-=(U scalar)
    {
        m00 -= static_cast<T>(scalar);
        m01 -= static_cast<T>(scalar);
        m10 -= static_cast<T>(scalar);
        m11 -= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat2x2 &operator-=(const mat2x2<U> &m)
    {
        m00 -= static_cast<T>(m.m00);
        m01 -= static_cast<T>(m.m01);
        m10 -= static_cast<T>(m.m10);
        m11 -= static_cast<T>(m.m11);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat2x2 &operator*=(U scalar)
    {
        m00 *= static_cast<T>(scalar);
        m01 *= static_cast<T>(scalar);
        m10 *= static_cast<T>(scalar);
        m11 *= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat2x2 &operator*=(const mat2x2<U> &m)
    {
        m00 *= static_cast<T>(m.m00);
        m01 *= static_cast<T>(m.m01);
        m10 *= static_cast<T>(m.m10);
        m11 *= static_cast<T>(m.m11);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat2x2 &operator/=(U scalar)
    {
        m00 /= static_cast<T>(scalar);
        m01 /= static_cast<T>(scalar);
        m10 /= static_cast<T>(scalar);
        m11 /= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR mat2x2 &operator/=(const mat2x2<U> &m)
    {
        m00 /= static_cast<T>(m.m00);
        m01 /= static_cast<T>(m.m01);
        m10 /= static_cast<T>(m.m10);
        m11 /= static_cast<T>(m.m11);
        return *this;
    }

    // --increment and decrement operators-- //
    MATH_CONSTEXPR mat2x2 &operator++()
    {
        ++m00;
        ++m01;
        ++m10;
        ++m11;
        return *this;
    }

    MATH_CONSTEXPR mat2x2 operator++(int)
    {
        mat2x2 temp(*this);
        ++*this;
        return temp;
    }

    MATH_CONSTEXPR mat2x2 &operator--()
    {
        --m00;
        --m01;
        --m10;
        --m11;
        return *this;
    }

    MATH_CONSTEXPR mat2x2 operator--(int)
    {
        mat2x2 temp(*this);
        --*this;
        return temp;
    }

    // --binary arithmetic operators-- //
    friend MATH_CONSTEXPR mat2x2 operator+(const mat2x2 &m, T scalar)
    {
        return mat2x2(m.m00 + scalar, m.m01 + scalar, m.m10 + scalar, m.m11 + scalar);
    }

    friend MATH_CONSTEXPR mat2x2 operator+(T scalar, const mat2x2 &m)
    {
        return mat2x2(scalar + m.m00, scalar + m.m01, scalar + m.m10, scalar + m.m11);
    }

    friend MATH_CONSTEXPR mat2x2 operator+(const mat2x2 &m1, const mat2x2 &m2)
    {
        return mat2x2(m1.m00 + m2.m00, m1.m01 + m2.m01, m1.m10 + m2.m10, m1.m11 + m2.m11);
    }

    friend MATH_CONSTEXPR mat2x2 operator-(const mat2x2 &m, T scalar)
    {
        return mat2x2(m.m00 - scalar, m.m01 - scalar, m.m10 - scalar, m.m11 - scalar);
    }

    friend MATH_CONSTEXPR mat2x2 operator-(T scalar, const mat2x2 &m)
    {
        return mat2x2(scalar - m.m00, scalar - m.m01, scalar - m.m10, scalar - m.m11);
    }

    friend MATH_CONSTEXPR mat2x2 operator-(const mat2x2 &m1, const mat2x2 &m2)
    {
        return mat2x2(m1.m00 - m2.m00, m1.m01 - m2.m01, m1.m10 - m2.m10, m1.m11 - m2.m11);
    }

    friend MATH_CONSTEXPR mat2x2 operator*(const mat2x2 &m, T scalar)
    {
        return mat2x2(m.m00 * scalar, m.m01 * scalar, m.m10 * scalar, m.m11 * scalar);
    }

    friend MATH_CONSTEXPR mat2x2 operator*(T scalar, const mat2x2 &m)
    {
        return mat2x2(scalar * m.m00, scalar * m.m01, scalar * m.m10, scalar * m.m11);
    }

    friend MATH_CONSTEXPR vec<2, T> operator*(const mat2x2 &m, const vec<2, T> &v)
    {
        return vec<2, T>(m.m00 * v.x + m.m01 * v.y, m.m10 * v.x + m.m11 * v.y);
    }

    friend MATH_CONSTEXPR mat2x2 operator*(const mat2x2 &m1, const mat2x2 &m2)
    {
        return mat2x2(m1.m00 * m2.m00 + m1.m01 * m2.m10, m1.m00 * m2.m01 + m1.m01 * m2.m11,
                      m1.m10 * m2.m00 + m1.m11 * m2.m10, m1.m10 * m2.m01 + m1.m11 * m2.m11);
    }

    friend MATH_CONSTEXPR mat2x2 operator/(const mat2x2 &m, T scalar)
    {
        return mat2x2(m.m00 / scalar, m.m01 / scalar, m.m10 / scalar, m.m11 / scalar);
    }

    friend MATH_CONSTEXPR mat2x2 operator/(T scalar, const mat2x2 &m)
    {
        return mat2x2(scalar / m.m00, scalar / m.m01, scalar / m.m10, scalar / m.m11);
    }

    friend MATH_CONSTEXPR mat2x2 operator/(const mat2x2 &m1, const mat2x2 &m2)
    {
        return mat2x2(m1.m00 / m2.m00, m1.m01 / m2.m01, m1.m10 / m2.m10, m1.m11 / m2.m11);
    }

    // --comparison operators-- //
    friend MATH_CONSTEXPR bool operator==(const mat2x2 &m1, const mat2x2 &m2)
    {
        return m1.m00 == m2.m00 && m1.m01 == m2.m01 && m1.m10 == m2.m10 && m1.m11 == m2.m11;
    }

    friend MATH_CONSTEXPR bool operator!=(const mat2x2 &m1, const mat2x2 &m2)
    {
        return m1.m00 != m2.m00 || m1.m01 != m2.m01 || m1.m10 != m2.m10 || m1.m11 != m2.m11;
    }
};

// --stream operators-- //
template <typename T>
std::ostream &operator<<(std::ostream &os, const mat2x2<T> &m)
{
    os << "mat2x2<" << typeid(T).name() << ">(" << m.m00 << ", " << m.m01 << ", "
                                                << m.m10 << ", " << m.m11 << ")";
    return os;
}

#ifdef MATH_TEMPLATE_ALIASES
using mat2x2i = mat2x2<int>;
using mat2x2u = mat2x2<unsigned int>;
using mat2x2f = mat2x2<float>;
using mat2x2d = mat2x2<double>;
#endif

MATH_NAMESPACE_END