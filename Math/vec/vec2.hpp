#pragma once

#include "../sturctures.hpp"

MATH_NAMESPACE_BEGIN

template <typename T>
struct vec<2, T>
{
    union
    {
        struct
        {
            T x, y;
        };
        struct
        {
            T r, g;
        };
        struct
        {
            T s, t;
        };
    };

    // --accessors-- //
    MATH_CONSTEXPR LENGTH_TYPE size() const
    {
        return 2;
    }

    MATH_CONSTEXPR T &operator[](LENGTH_TYPE i)
    {
        try
        {
            if (i < 0 || i >= 2)
            {
                throw std::out_of_range(OUT_OF_RANGE_MSG("vec2"));
            }
            return *(reinterpret_cast<T*>(reinterpret_cast<char*>(this) + offsetof(vec, x)) + i);
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << e.what();
            return *(reinterpret_cast<T*>(reinterpret_cast<char*>(this) + offsetof(vec, x)));
        }
    }

    MATH_CONSTEXPR T const &operator[](LENGTH_TYPE i) const
    {
        try
        {
            if (i < 0 || i >= 2)
            {
                throw std::out_of_range(OUT_OF_RANGE_MSG("vec2"));
            }
            return *(reinterpret_cast<T const *>(reinterpret_cast<char const *>(this) + offsetof(vec, x)) + i);
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << e.what();
            return *(reinterpret_cast<T const *>(reinterpret_cast<char const *>(this) + offsetof(vec, x)));
        }
    }

    // --implicit basic constructors-- //
    MATH_CONSTEXPR vec() = default;
    MATH_CONSTEXPR vec(const vec &v) = default;
    MATH_CONSTEXPR vec &operator=(const vec &v) = default;
    MATH_CONSTEXPR vec(vec &&v) = default;
    MATH_CONSTEXPR vec &operator=(vec &&v) = default;

    // --explicit conversion constructors-- //
    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(U scalar) : x(static_cast<T>(scalar)), y(static_cast<T>(scalar)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<2, U> &v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<3, U> &v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<4, U> &v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

    template <typename A, typename B>
    MATH_CONSTEXPR MATH_EXPLICIT vec(A x, B y) : x(static_cast<T>(x)), y(static_cast<T>(y)) {}

    template <typename A, typename B>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<1, A> &v, B y) : x(static_cast<T>(v.x)), y(static_cast<T>(y)) {}

    template <typename A, typename B>
    MATH_CONSTEXPR MATH_EXPLICIT vec(A x, const vec<1, B> &v) : x(static_cast<T>(x)), y(static_cast<T>(v.x)) {}

    // --unary arithmetic operators-- //
    MATH_CONSTEXPR vec operator+() const
    {
        return *this;
    }

    MATH_CONSTEXPR vec operator-() const
    {
        return vec(-x, -y);
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator+=(U scalar)
    {
        x += static_cast<T>(scalar);
        y += static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator+=(const vec<1, U> &v)
    {
        x += static_cast<T>(v.x);
        y += static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator+=(const vec<2, U> &v)
    {
        x += static_cast<T>(v.x);
        y += static_cast<T>(v.y);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator-=(U scalar)
    {
        x -= static_cast<T>(scalar);
        y -= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator-=(const vec<1, U> &v)
    {
        x -= static_cast<T>(v.x);
        y -= static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator-=(const vec<2, U> &v)
    {
        x -= static_cast<T>(v.x);
        y -= static_cast<T>(v.y);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator*=(U scalar)
    {
        x *= static_cast<T>(scalar);
        y *= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator*=(const vec<1, U> &v)
    {
        x *= static_cast<T>(v.x);
        y *= static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator*=(const vec<2, U> &v)
    {
        x *= static_cast<T>(v.x);
        y *= static_cast<T>(v.y);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator/=(U scalar)
    {
        x /= static_cast<T>(scalar);
        y /= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator/=(const vec<1, U> &v)
    {
        x /= static_cast<T>(v.x);
        y /= static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator/=(const vec<2, U> &v)
    {
        x /= static_cast<T>(v.x);
        y /= static_cast<T>(v.y);
        return *this;
    }

    // --increment and decrement operators-- //
    MATH_CONSTEXPR vec &operator++()
    {
        ++x;
        ++y;
        return *this;
    }

    MATH_CONSTEXPR vec operator++(int)
    {
        vec temp(*this);
        ++*this;
        return temp;
    }

    MATH_CONSTEXPR vec &operator--()
    {
        --x;
        --y;
        return *this;
    }

    MATH_CONSTEXPR vec operator--(int)
    {
        vec temp(*this);
        --*this;
        return temp;
    }

    // TODO:: implement bit operators

    // --binary arithmetic operators-- //
    friend MATH_CONSTEXPR vec operator+(const vec &v, T scalar)
    {
        return vec(v.x + scalar, v.y + scalar);
    }

    friend MATH_CONSTEXPR vec operator+(T scalar, const vec &v)
    {
        return vec(scalar + v.x, scalar + v.y);
    }

    friend MATH_CONSTEXPR vec operator+(const vec<1, T> &v1, const vec &v2)
    {
        return vec(v1.x + v2.x, v1.x + v2.y);
    }

    friend MATH_CONSTEXPR vec operator+(const vec &v1, const vec<1, T> &v2)
    {
        return vec(v1.x + v2.x, v1.y + v2.x);
    }

    friend MATH_CONSTEXPR vec operator+(const vec &v1, const vec &v2)
    {
        return vec(v1.x + v2.x, v1.y + v2.y);
    }

    friend MATH_CONSTEXPR vec operator-(const vec &v, T scalar)
    {
        return vec(v.x - scalar, v.y - scalar);
    }

    friend MATH_CONSTEXPR vec operator-(T scalar, const vec &v)
    {
        return vec(scalar - v.x, scalar - v.y);
    }

    friend MATH_CONSTEXPR vec operator-(const vec<1, T> &v1, const vec &v2)
    {
        return vec(v1.x - v2.x, v1.x - v2.y);
    }

    friend MATH_CONSTEXPR vec operator-(const vec &v1, const vec<1, T> &v2)
    {
        return vec(v1.x - v2.x, v1.y - v2.x);
    }

    friend MATH_CONSTEXPR vec operator-(const vec &v1, const vec &v2)
    {
        return vec(v1.x - v2.x, v1.y - v2.y);
    }

    friend MATH_CONSTEXPR vec operator*(const vec &v, T scalar)
    {
        return vec(v.x * scalar, v.y * scalar);
    }

    friend MATH_CONSTEXPR vec operator*(T scalar, const vec &v)
    {
        return vec(scalar * v.x, scalar * v.y);
    }

    friend MATH_CONSTEXPR vec operator*(const vec<1, T> &v1, const vec &v2)
    {
        return vec(v1.x * v2.x, v1.x * v2.y);
    }

    friend MATH_CONSTEXPR vec operator*(const vec &v1, const vec<1, T> &v2)
    {
        return vec(v1.x * v2.x, v1.y * v2.x);
    }

    friend MATH_CONSTEXPR vec operator*(const vec &v1, const vec &v2)
    {
        return vec(v1.x * v2.x, v1.y * v2.y);
    }

    friend MATH_CONSTEXPR vec operator/(const vec &v, T scalar)
    {
        return vec(v.x / scalar, v.y / scalar);
    }

    friend MATH_CONSTEXPR vec operator/(T scalar, const vec &v)
    {
        return vec(scalar / v.x, scalar / v.y);
    }

    friend MATH_CONSTEXPR vec operator/(const vec<1, T> &v1, const vec &v2)
    {
        return vec(v1.x / v2.x, v1.x / v2.y);
    }

    friend MATH_CONSTEXPR vec operator/(const vec &v1, const vec<1, T> &v2)
    {
        return vec(v1.x / v2.x, v1.y / v2.x);
    }

    friend MATH_CONSTEXPR vec operator/(const vec &v1, const vec &v2)
    {
        return vec(v1.x / v2.x, v1.y / v2.y);
    }

    // --comparison operators-- //
    MATH_CONSTEXPR bool operator==(const vec &v) const
    {
        return x == v.x && y == v.y;
    }

    MATH_CONSTEXPR bool operator!=(const vec &v) const
    {
        return x != v.x || y != v.y;
    }
};

#ifdef _MATH_DEBUG_
// --stream operators-- //
template <typename T>
std::ostream &operator<<(std::ostream &os, const vec<2, T> &v)
{
    os << "vec2<" << typeid(T).name() << ">(" << v.x << ", " << v.y << ")";
    return os;
}
#endif

#ifdef MATH_TEMPLATE_ALIASES
using vec2i = vec<2, int>;
using vec2u = vec<2, unsigned>;
using vec2f = vec<2, float>;
using vec2d = vec<2, double>;
#endif

MATH_NAMESPACE_END