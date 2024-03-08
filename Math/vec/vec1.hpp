#pragma once

#include "../sturctures.hpp"

#include <initializer_list>

MATH_NAMESPACE_BEGIN

template <typename T>
struct vec<1, T>
{
    union
    {
        T c[1];
        T x;
        T r;
        T s;
    };

    // --accessors-- //
    MATH_CONSTEXPR LENGTH_TYPE size() const
    {
        return 1;
    }

    MATH_CONSTEXPR T &operator[](LENGTH_TYPE i)
    {
        if (i < 0 || i >= 1)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("vec1"));
        }
        return c[i];
    }

    MATH_CONSTEXPR T const &operator[](LENGTH_TYPE i) const
    {
        if (i < 0 || i >= 1)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("vec1"));
        }
        return c[i];
    }

    // --implicit basic constructors-- //
    MATH_CONSTEXPR vec() = default;
    MATH_CONSTEXPR vec(const vec &v) = default;
    MATH_CONSTEXPR vec &operator=(const vec &v) = default;
    MATH_CONSTEXPR vec(vec &&v) = default;
    MATH_CONSTEXPR vec &operator=(vec &&v) = default;

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

    // --initializer list constructor-- //
    MATH_CONSTEXPR vec(std::initializer_list<T> list)
    {
        if (list.size() != 1)
        {
            throw std::invalid_argument(INVALID_INITIALIZER_LIST_ARGS_MSG("vec1", list.size()));
        }
        auto it = list.begin();
        x = *it;
    }

    // --unary arithmetic operators-- //
    MATH_CONSTEXPR vec operator+() const
    {
        return *this;
    }

    MATH_CONSTEXPR vec operator-() const
    {
        return vec(-x);
    }

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

// --stream operators-- //
template <typename T>
std::ostream &operator<<(std::ostream &os, const vec<1, T> &v)
{
    os << "vec1<" << typeid(T).name() << ">(" << v.x << ")";
    return os;
}

#ifdef MATH_TEMPLATE_ALIASES
using vec1i = vec<1, int>;
using vec1u = vec<1, unsigned int>;
using vec1f = vec<1, float>;
using vec1d = vec<1, double>;
#endif

MATH_NAMESPACE_END