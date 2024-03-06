#pragma once

#include "vec.hpp"

MATH_NAMESPACE_BEGIN

template <typename T>
struct vec<1, T>
{
    union
    {
        T x;
        T r;
        T s;
    };

    // --accessors-- //
    MATH_CONSTEXPR int length() const
    {
        return 1;
    }

    MATH_CONSTEXPR T &operator[](int i)
    {
        static_assert(i >= 0 && i < 1, "Index out of range");
        switch (i)
        {
        default:
        case 0:
            return x;
        }
    }

    MATH_CONSTEXPR T &operator[](int i) const
    {
        static_assert(i >= 0 && i < 1, "Index out of range");
        switch (i)
        {
        default:
        case 0:
            return x;
        }
    }

    // --implicit basic constructors-- //
    MATH_CONSTEXPR vec() = default;
    MATH_CONSTEXPR vec(const vec &v) = default;
    MATH_CONSTEXPR vec &operator=(const vec &v) = default;
    MATH_CONSTEXPR vec(vec &&v) = default;
    MATH_CONSTEXPR vec &operator=(vec &&v) = default;

    // --explicit basic constructors-- //
    MATH_CONSTEXPR MATH_EXPLICIT vec(T scalar) : x(static_cast<T>(scalar)) {}

    // --explicit conversion constructors-- //
    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(U scalar) : x(static_cast<T>(scalar)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<1, U> &v) : x(static_cast<T>(v.x)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<2, U> &v) : x(static_cast<T>(v.x)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<3, U> &v) : x(static_cast<T>(v.x)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<4, U> &v) : x(static_cast<T>(v.x)) {}

    // --unary arithmetic operators-- //
    template <typename U>
    MATH_CONSTEXPR vec &operator+=(U scalar)
    {
        x += static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator+=(const vec<1, U> &v)
    {
        x += static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator-=(U scalar)
    {
        x -= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator-=(const vec<1, U> &v)
    {
        x -= static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator*=(U scalar)
    {
        x *= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator*=(const vec<1, U> &v)
    {
        x *= static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator/=(U scalar)
    {
        x /= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator/=(const vec<1, U> &v)
    {
        x /= static_cast<T>(v.x);
        return *this;
    }

    // --increment and decrement operators-- //
    MATH_CONSTEXPR vec &operator++()
    {
        ++x;
        return *this;
    }

    MATH_CONSTEXPR vec operator++(int)
    {
        vec temp(*this);
        ++x;
        return temp;
    }

    MATH_CONSTEXPR vec &operator--()
    {
        --x;
        return *this;
    }

    MATH_CONSTEXPR vec operator--(int)
    {
        vec temp(*this);
        --x;
        return temp;
    }

    // TODO:: implement bit operators

    // --unary arithmetic operators-- //
    MATH_CONSTEXPR vec operator+() const
    {
        return *this;
    }

    MATH_CONSTEXPR vec operator-() const
    {
        return vec(-x);
    }

    // --binary arithmetic operators-- //
    friend MATH_CONSTEXPR vec operator+(const vec &v, T scalar)
    {
        return vec(x + scalar);
    }

    friend MATH_CONSTEXPR vec operator+(T scalar, const vec &v)
    {
        return vec(scalar + x);
    }

    friend MATH_CONSTEXPR vec operator+(const vec &v1, const vec &v2)
    {
        return vec(v1.x + v2.x);
    }

    friend MATH_CONSTEXPR vec operator-(const vec &v, T scalar)
    {
        return vec(x - scalar);
    }

    friend MATH_CONSTEXPR vec operator-(T scalar, const vec &v)
    {
        return vec(scalar - x);
    }

    friend MATH_CONSTEXPR vec operator-(const vec &v1, const vec &v2)
    {
        return vec(v1.x - v2.x);
    }

    friend MATH_CONSTEXPR vec operator*(const vec &v, T scalar)
    {
        return vec(v.x * scalar);
    }

    friend MATH_CONSTEXPR vec operator*(T scalar, const vec &v)
    {
        return vec(scalar * v.x);
    }

    friend MATH_CONSTEXPR vec operator*(const vec &v1, const vec &v2)
    {
        return vec(v1.x * v2.x);
    }

    friend MATH_CONSTEXPR vec operator/(const vec &v, T scalar)
    {
        return vec(v.x / scalar);
    }

    friend MATH_CONSTEXPR vec operator/(T scalar, const vec &v)
    {
        return vec(scalar / v.x);
    }

    friend MATH_CONSTEXPR vec operator/(const vec &v1, const vec &v2)
    {
        return vec(v1.x / v2.x);
    }

    // --comparison operators-- //
    MATH_CONSTEXPR bool operator==(const vec &v) const
    {
        return x == v.x;
    }

    MATH_CONSTEXPR bool operator!=(const vec &v) const
    {
        return x != v.x;
    }
};

#ifdef _MATH_DEBUG_
    // --stream operators-- //
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const vec<1, T> &v)
    {
        os << "vec1<" << typeid(T).name() << ">(" << v.x << ")";
        return os;
    }
#endif

using vec1i = vec<1, int>;
using vec1u = vec<1, unsigned int>;
using vec1f = vec<1, float>;
using vec1d = vec<1, double>;

MATH_NAMESPACE_END