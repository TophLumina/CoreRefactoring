#pragma once

#include "../sturctures.hpp"

#include <initializer_list>

MATH_NAMESPACE_BEGIN

template <typename T>
struct vec<4, T>
{
    union
    {
        T c[4];
        T data[4];
        struct
        {
            T x, y, z, w;
        };
        struct
        {
            T r, g, b, a;
        };
        struct
        {
            T s, t, p, q;
        };
    };

    // --accessors-- //
    MATH_FUNCTION_QUALIFIERS LENGTH_TYPE size() const
    {
        return 4;
    }

    MATH_FUNCTION_QUALIFIERS T &operator[](LENGTH_TYPE i)
    {
        if (i < 0 || i >= 4)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("vec4"));
        }
        return c[i];
    }

    MATH_FUNCTION_QUALIFIERS T const &operator[](LENGTH_TYPE i) const
    {
        if (i < 0 || i >= 4)
        {
            throw std::out_of_range(OUT_OF_RANGE_MSG("vec4"));
        }
        return c[i];
    }

    // --implicit basic constructors-- //
    MATH_FUNCTION_QUALIFIERS vec() = default;
    MATH_FUNCTION_QUALIFIERS vec(const vec &v) = default;
    MATH_FUNCTION_QUALIFIERS vec &operator=(const vec &v) = default;
    MATH_FUNCTION_QUALIFIERS vec(vec &&v) = default;
    MATH_FUNCTION_QUALIFIERS vec &operator=(vec &&v) = default;

    // --explicit conversion constructors-- //
    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(U scalar) : x(static_cast<T>(scalar)), y(static_cast<T>(scalar)), z(static_cast<T>(scalar)), w(static_cast<T>(scalar)) {}

    template <typename U>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(const vec<4, U> &v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(v.w)) {}

    template <typename A, typename B>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(A x, const vec<3, B> &v) : x(static_cast<T>(x)), y(static_cast<T>(v.x)), z(static_cast<T>(v.y)), w(static_cast<T>(v.z)) {}

    template <typename A, typename B>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(const vec<3, A> &v, B w) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(w)) {}

    template <typename A, typename B>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(const vec<2, A> &v1, const vec<2, B> &v2) : x(static_cast<T>(v1.x)), y(static_cast<T>(v1.y)), z(static_cast<T>(v2.x)), w(static_cast<T>(v2.y)) {}

    template <typename A, typename B, typename C>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(A x, B y, const vec<2, C> &v) : x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(v.x)), w(static_cast<T>(v.y)) {}

    template <typename A, typename B, typename C>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(A x, const vec<2, B> &v, C w) : x(static_cast<T>(x)), y(static_cast<T>(v.x)), z(static_cast<T>(v.y)), w(static_cast<T>(w)) {}

    template <typename A, typename B, typename C>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(const vec<2, A> &v, B z, C w) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(z)), w(static_cast<T>(w)) {}

    template <typename A, typename B, typename C, typename D>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(A x, B y, C z, D w) : x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(z)), w(static_cast<T>(w)) {}

    template <typename A, typename B, typename C, typename D>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(const vec<1, A> &v1, B y, C z, D w) : x(static_cast<T>(v1.x)), y(static_cast<T>(y)), z(static_cast<T>(z)), w(static_cast<T>(w)) {}

    template <typename A, typename B, typename C, typename D>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(A x, const vec<1, B> &v2, C z, D w) : x(static_cast<T>(x)), y(static_cast<T>(v2.x)), z(static_cast<T>(z)), w(static_cast<T>(w)) {}

    template <typename A, typename B, typename C, typename D>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(A x, B y, const vec<1, C> &v3, D w) : x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(v3.x)), w(static_cast<T>(w)) {}

    template <typename A, typename B, typename C, typename D>
    MATH_FUNCTION_QUALIFIERS MATH_EXPLICIT vec(A x, B y, C z, const vec<1, D> &v4) : x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(z)), w(static_cast<T>(v4.x)) {}

    // --initialization list constructor-- //
    MATH_FUNCTION_QUALIFIERS vec(std::initializer_list<T> list)
    {
        if (list.size() != 4)
        {
            throw std::invalid_argument(INVALID_INITIALIZER_LIST_ARGS_MSG("vec4", list.size()));
        }
        auto it = list.begin();
        x = *it;
        y = *(++it);
        z = *(++it);
        w = *(++it);
    }

    // --unary arithmetic operators-- //
    MATH_FUNCTION_QUALIFIERS vec operator+() const
    {
        return *this;
    }

    MATH_FUNCTION_QUALIFIERS vec operator-() const
    {
        return vec(-x, -y, -z, -w);
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator+=(U scalar)
    {
        x += static_cast<T>(scalar);
        y += static_cast<T>(scalar);
        z += static_cast<T>(scalar);
        w += static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator+=(const vec<1, U> &v)
    {
        x += static_cast<T>(v.x);
        y += static_cast<T>(v.x);
        z += static_cast<T>(v.x);
        w += static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator+=(const vec<4, U> &v)
    {
        x += static_cast<T>(v.x);
        y += static_cast<T>(v.y);
        z += static_cast<T>(v.z);
        w += static_cast<T>(v.w);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator-=(U scalar)
    {
        x -= static_cast<T>(scalar);
        y -= static_cast<T>(scalar);
        z -= static_cast<T>(scalar);
        w -= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator-=(const vec<1, U> &v)
    {
        x -= static_cast<T>(v.x);
        y -= static_cast<T>(v.x);
        z -= static_cast<T>(v.x);
        w -= static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator-=(const vec<4, U> &v)
    {
        x -= static_cast<T>(v.x);
        y -= static_cast<T>(v.y);
        z -= static_cast<T>(v.z);
        w -= static_cast<T>(v.w);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator*=(U scalar)
    {
        x *= static_cast<T>(scalar);
        y *= static_cast<T>(scalar);
        z *= static_cast<T>(scalar);
        w *= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator*=(const vec<1, U> &v)
    {
        x *= static_cast<T>(v.x);
        y *= static_cast<T>(v.x);
        z *= static_cast<T>(v.x);
        w *= static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator*=(const vec<4, U> &v)
    {
        x *= static_cast<T>(v.x);
        y *= static_cast<T>(v.y);
        z *= static_cast<T>(v.z);
        w *= static_cast<T>(v.w);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator/=(U scalar)
    {
        x /= static_cast<T>(scalar);
        y /= static_cast<T>(scalar);
        z /= static_cast<T>(scalar);
        w /= static_cast<T>(scalar);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator/=(const vec<1, U> &v)
    {
        x /= static_cast<T>(v.x);
        y /= static_cast<T>(v.x);
        z /= static_cast<T>(v.x);
        w /= static_cast<T>(v.x);
        return *this;
    }

    template <typename U>
    MATH_FUNCTION_QUALIFIERS vec &operator/=(const vec<4, U> &v)
    {
        x /= static_cast<T>(v.x);
        y /= static_cast<T>(v.y);
        z /= static_cast<T>(v.z);
        w /= static_cast<T>(v.w);
        return *this;
    }

    // --increment and decrement operators-- //
    MATH_FUNCTION_QUALIFIERS vec &operator++()
    {
        static_assert(std::is_integral<T>::value, "vec4<T>::operator++(): T must be an integral type.");

        ++x;
        ++y;
        ++z;
        ++w;
        return *this;
    }

    MATH_FUNCTION_QUALIFIERS vec operator++(int)
    {
        static_assert(std::is_integral<T>::value, "vec4<T>::operator++(int): T must be an integral type.");

        vec temp(*this);
        ++*this;
        return temp;
    }

    MATH_FUNCTION_QUALIFIERS vec &operator--()
    {
        static_assert(std::is_integral<T>::value, "vec4<T>::operator--(): T must be an integral type.");

        --x;
        --y;
        --z;
        --w;
        return *this;
    }

    MATH_FUNCTION_QUALIFIERS vec operator--(int)
    {
        static_assert(std::is_integral<T>::value, "vec4<T>::operator--(int): T must be an integral type.");

        vec temp(*this);
        --*this;
        return temp;
    }

    // TODO:: implement bit operators

    // --binary arithmetic operators-- //
    friend MATH_FUNCTION_QUALIFIERS vec operator+(const vec &v, T scalar)
    {
        return {v.x + scalar, v.y + scalar, v.z + scalar, v.w + scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator+(T scalar, const vec &v)
    {
        return {scalar + v.x, scalar + v.y, scalar + v.z, scalar + v.w};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator+(const vec<1, T> &v1, const vec &v2)
    {
        return {v1.x + v2.x, v1.x + v2.y, v1.x + v2.z, v1.x + v2.w};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator+(const vec &v1, const vec<1, T> &v2)
    {
        return {v1.x + v2.x, v1.y + v2.x, v1.z + v2.x, v1.w + v2.x};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator+(const vec &v1, const vec &v2)
    {
        return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator-(const vec &v, T scalar)
    {
        return {v.x - scalar, v.y - scalar, v.z - scalar, v.w - scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator-(T scalar, const vec &v)
    {
        return {scalar - v.x, scalar - v.y, scalar - v.z, scalar - v.w};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator-(const vec<1, T> &v1, const vec &v2)
    {
        return {v1.x - v2.x, v1.x - v2.y, v1.x - v2.z, v1.x - v2.w};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator-(const vec &v1, const vec<1, T> &v2)
    {
        return {v1.x - v2.x, v1.y - v2.x, v1.z - v2.x, v1.w - v2.x};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator-(const vec &v1, const vec &v2)
    {
        return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator*(const vec &v, T scalar)
    {
        return {v.x * scalar, v.y * scalar, v.z * scalar, v.w * scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator*(T scalar, const vec &v)
    {
        return {scalar * v.x, scalar * v.y, scalar * v.z, scalar * v.w};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator*(const vec<1, T> &v1, const vec &v2)
    {
        return {v1.x * v2.x, v1.x * v2.y, v1.x * v2.z, v1.x * v2.w};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator*(const vec &v1, const vec<1, T> &v2)
    {
        return {v1.x * v2.x, v1.y * v2.x, v1.z * v2.x, v1.w * v2.x};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator*(const vec &v1, const vec &v2)
    {
        return {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator/(const vec &v, T scalar)
    {
        return {v.x / scalar, v.y / scalar, v.z / scalar, v.w / scalar};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator/(T scalar, const vec &v)
    {
        return {scalar / v.x, scalar / v.y, scalar / v.z, scalar / v.w};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator/(const vec<1, T> &v1, const vec &v2)
    {
        return {v1.x / v2.x, v1.x / v2.y, v1.x / v2.z, v1.x / v2.w};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator/(const vec &v1, const vec<1, T> &v2)
    {
        return {v1.x / v2.x, v1.y / v2.x, v1.z / v2.x, v1.w / v2.x};
    }

    friend MATH_FUNCTION_QUALIFIERS vec operator/(const vec &v1, const vec &v2)
    {
        return {v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w};
    }

    // --comparison operators-- //
    friend MATH_FUNCTION_QUALIFIERS bool operator==(const vec &v1, const vec &v2)
    {
        return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w;
    }

    friend MATH_FUNCTION_QUALIFIERS bool operator!=(const vec &v1, const vec &v2)
    {
        return !(v1 == v2);
    }
};

// --stream operators-- //
#ifdef MATH_IOS
template <typename T>
std::ostream &operator<<(std::ostream &os, const vec<4, T> &v)
{
    os << "vec4<" << typeid(T).name() << ">(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
    return os;
}
#endif

#ifdef MATH_TEMPLATE_ALIASES
using vec4i = vec<4, int>;
using vec4u = vec<4, unsigned>;
using vec4f = vec<4, float>;
using vec4d = vec<4, double>;
#endif

MATH_NAMESPACE_END