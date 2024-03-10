#pragma once

#include "../sturctures.hpp"

#include <initializer_list>

MATH_NAMESPACE_BEGIN

template <typename T>
struct vec<3, T>
{
    union
    {
        T c[3];
        T data[3];
        struct
        {
            T x, y, z;
        };
        struct
        {
            T r, g, b;
        };
        struct
        {
            T s, t, p;
        };
    };

    // --accessors-- //
    MATH_CONSTEXPR LENGTH_TYPE size() const
    {
        return 3;
    }

    MATH_CONSTEXPR T &operator[](LENGTH_TYPE i)
    {
        if (i < 0 || i >= 3)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("vec3"));
        }
        return c[i];
    }

    MATH_CONSTEXPR T const &operator[](LENGTH_TYPE i) const
    {
        if (i < 0 || i >= 3)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("vec3"));
        }
        return c[i];
    }

    // --implicit basic constructors-- //
    MATH_CONSTEXPR vec() = default;
    MATH_CONSTEXPR vec(const vec &v) = default;
    MATH_CONSTEXPR vec &operator=(const vec &v) = default;
    MATH_CONSTEXPR vec(vec &&v) = default;
    MATH_CONSTEXPR vec &operator=(vec &&v) = default;

    // TODO :: replace all constructors with initializer list

    // --explicit conversion constructors-- //
    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(U scalar) : x(static_cast<T>(scalar)), y(static_cast<T>(scalar)), z(static_cast<T>(scalar)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<3, U> &v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)) {}

    template <typename U>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<4, U> &v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)) {}

    template <typename A, typename B>
    MATH_CONSTEXPR MATH_EXPLICIT vec(A x, const vec<2, B> &v) : x(static_cast<T>(x)), y(static_cast<T>(v.x)), z(static_cast<T>(v.y)) {}

    template <typename A, typename B>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<2, A> &v, B z) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(z)) {}

    template <typename A, typename B, typename C>
    MATH_CONSTEXPR MATH_EXPLICIT vec(A x, B y, C z) : x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(z)) {}

    template <typename A, typename B, typename C>
    MATH_CONSTEXPR MATH_EXPLICIT vec(const vec<1, A> &v, B y, C z) : x(static_cast<T>(v.x)), y(static_cast<T>(y)), z(static_cast<T>(z)) {}

    template <typename A, typename B, typename C>
    MATH_CONSTEXPR MATH_EXPLICIT vec(A x, const vec<1, B> &v, C z) : x(static_cast<T>(x)), y(static_cast<T>(v.x)), z(static_cast<T>(z)) {}

    template <typename A, typename B, typename C>
    MATH_CONSTEXPR MATH_EXPLICIT vec(A x, B y, const vec<1, C> &v) : x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(v.x)) {}

    // --initialization list constructor-- //
    MATH_CONSTEXPR vec(std::initializer_list<T> list)
    {
        if (list.size() != 3)
        {
            throw std::invalid_argument(INVALID_INITIALIZER_LIST_ARGS_MSG("vec3", list.size()));
        }
        auto it = list.begin();
        x = *it;
        y = *(++it);
        z = *(++it);
    }

    // --unary arithmetic operators-- //
    MATH_CONSTEXPR vec operator+() const
    {
        return *this;
    }

    MATH_CONSTEXPR vec operator-() const
    {
        return vec(-x, -y, -z);
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator+=(U scalar)
    {
        x += static_cast<T>(scalar);
        y += static_cast<T>(scalar);
        z += static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator+=(const vec<1, U> &v)
    {
        x += static_cast<T>(v.x);
        y += static_cast<T>(v.x);
        z += static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator+=(const vec<3, U> &v)
    {
        x += static_cast<T>(v.x);
        y += static_cast<T>(v.y);
        z += static_cast<T>(v.z);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator-=(U scalar)
    {
        x -= static_cast<T>(scalar);
        y -= static_cast<T>(scalar);
        z -= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator-=(const vec<1, U> &v)
    {
        x -= static_cast<T>(v.x);
        y -= static_cast<T>(v.x);
        z -= static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator-=(const vec<3, U> &v)
    {
        x -= static_cast<T>(v.x);
        y -= static_cast<T>(v.y);
        z -= static_cast<T>(v.z);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator*=(U scalar)
    {
        x *= static_cast<T>(scalar);
        y *= static_cast<T>(scalar);
        z *= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator*=(const vec<1, U> &v)
    {
        x *= static_cast<T>(v.x);
        y *= static_cast<T>(v.x);
        z *= static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator*=(const vec<3, U> &v)
    {
        x *= static_cast<T>(v.x);
        y *= static_cast<T>(v.y);
        z *= static_cast<T>(v.z);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator/=(U scalar)
    {
        x /= static_cast<T>(scalar);
        y /= static_cast<T>(scalar);
        z /= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator/=(const vec<1, U> &v)
    {
        x /= static_cast<T>(v.x);
        y /= static_cast<T>(v.x);
        z /= static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_CONSTEXPR vec &operator/=(const vec<3, U> &v)
    {
        x /= static_cast<T>(v.x);
        y /= static_cast<T>(v.y);
        z /= static_cast<T>(v.z);
        return *this;
    }

    // --increment and decrement operators-- //
    MATH_CONSTEXPR vec &operator++()
    {
        ++x;
        ++y;
        ++z;
        return *this;
    }

    MATH_CONSTEXPR vec operator++(int)
    {
        vec temp(*this);
        ++(*this);
        return temp;
    }

    MATH_CONSTEXPR vec &operator--()
    {
        --x;
        --y;
        --z;
        return *this;
    }

    MATH_CONSTEXPR vec operator--(int)
    {
        vec temp(*this);
        --(*this);
        return temp;
    }

    // TODO:: implement bit operators

    // --binary arithmetic operators-- //
    friend MATH_CONSTEXPR vec operator+(const vec &v, T scalar)
    {
        return vec(v.x + scalar, v.y + scalar, v.z + scalar);
    }

    friend MATH_CONSTEXPR vec operator+(T scalar, const vec &v)
    {
        return vec(scalar + v.x, scalar + v.y, scalar + v.z);
    }

    friend MATH_CONSTEXPR vec operator+(const vec<1, T> &v1, const vec &v2)
    {
        return vec(v1.x + v2.x, v1.x + v2.y, v1.x + v2.z);
    }

    friend MATH_CONSTEXPR vec operator+(const vec &v1, const vec<1, T> &v2)
    {
        return vec(v1.x + v2.x, v1.y + v2.x, v1.z + v2.x);
    }

    friend MATH_CONSTEXPR vec operator+(const vec &v1, const vec &v2)
    {
        return vec(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }

    friend MATH_CONSTEXPR vec operator-(const vec &v, T scalar)
    {
        return vec(v.x - scalar, v.y - scalar, v.z - scalar);
    }

    friend MATH_CONSTEXPR vec operator-(T scalar, const vec &v)
    {
        return vec(scalar - v.x, scalar - v.y, scalar - v.z);
    }

    friend MATH_CONSTEXPR vec operator-(const vec<1, T> &v1, const vec &v2)
    {
        return vec(v1.x - v2.x, v1.x - v2.y, v1.x - v2.z);
    }

    friend MATH_CONSTEXPR vec operator-(const vec &v1, const vec<1, T> &v2)
    {
        return vec(v1.x - v2.x, v1.y - v2.x, v1.z - v2.x);
    }

    friend MATH_CONSTEXPR vec operator-(const vec &v1, const vec &v2)
    {
        return vec(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    }

    friend MATH_CONSTEXPR vec operator*(const vec &v, T scalar)
    {
        return vec(v.x * scalar, v.y * scalar, v.z * scalar);
    }

    friend MATH_CONSTEXPR vec operator*(T scalar, const vec &v)
    {
        return vec(scalar * v.x, scalar * v.y, scalar * v.z);
    }

    friend MATH_CONSTEXPR vec operator*(const vec<1, T> &v1, const vec &v2)
    {
        return vec(v1.x * v2.x, v1.x * v2.y, v1.x * v2.z);
    }

    friend MATH_CONSTEXPR vec operator*(const vec &v1, const vec<1, T> &v2)
    {
        return vec(v1.x * v2.x, v1.y * v2.x, v1.z * v2.x);
    }

    friend MATH_CONSTEXPR vec operator*(const vec &v1, const vec &v2)
    {
        return vec(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
    }

    friend MATH_CONSTEXPR vec operator/(const vec &v, T scalar)
    {
        return vec(v.x / scalar, v.y / scalar, v.z / scalar);
    }

    friend MATH_CONSTEXPR vec operator/(T scalar, const vec &v)
    {
        return vec(scalar / v.x, scalar / v.y, scalar / v.z);
    }

    friend MATH_CONSTEXPR vec operator/(const vec<1, T> &v1, const vec &v2)
    {
        return vec(v1.x / v2.x, v1.x / v2.y, v1.x / v2.z);
    }

    friend MATH_CONSTEXPR vec operator/(const vec &v1, const vec<1, T> &v2)
    {
        return vec(v1.x / v2.x, v1.y / v2.x, v1.z / v2.x);
    }

    friend MATH_CONSTEXPR vec operator/(const vec &v1, const vec &v2)
    {
        return vec(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
    }

    // --comparison operators-- //
    friend MATH_CONSTEXPR bool operator==(const vec &v1, const vec &v2)
    {
        return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
    }

    friend MATH_CONSTEXPR bool operator!=(const vec &v1, const vec &v2)
    {
        return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z;
    }
};

// --stream operators-- //
template <typename T>
std::ostream &operator<<(std::ostream &os, const vec<3, T> &v)
{
    os << "vec3<" << typeid(T).name() << ">(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

#ifdef MATH_TEMPLATE_ALIASES
using vec3i = vec<3, int>;
using vec3u = vec<3, unsigned>;
using vec3f = vec<3, float>;
using vec3d = vec<3, double>;
#endif

MATH_NAMESPACE_END