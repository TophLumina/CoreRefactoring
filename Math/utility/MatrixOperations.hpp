#pragma once

#include "../include/mat.h"

MATH_NAMESPACE_BEGIN
MATRIX_NAMESPACE_BEGIN

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS mat<M, N, T> abs(mat<M, N, T> const &m)
{
    mat<M, N, T> result;
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        for (LENGTH_TYPE j = 0; j < N; ++j)
        {
            result[i][j] = abs(m[i][j]);
        }
    }
    return result;
}

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS mat<M, N, T> random_range(mat<M, N, T> const &min, mat<M, N, T> const &max)
{
    mat<M, N, T> result;
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        for (LENGTH_TYPE j = 0; j < N; ++j)
        {
            result[i][j] = random_range(min[i][j], max[i][j]);
        }
    }
    return result;
}

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS mat<M, N, T> min(mat<M, N, T> const &m, mat<M, N, T> const &n)
{
    mat<M, N, T> result;
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        for (LENGTH_TYPE j = 0; j < N; ++j)
        {
            result[i][j] = min(m[i][j], n[i][j]);
        }
    }
    return result;
}

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS mat<M, N, T> max(mat<M, N, T> const &m, mat<M, N, T> const &n)
{
    mat<M, N, T> result;
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        for (LENGTH_TYPE j = 0; j < N; ++j)
        {
            result[i][j] = max(m[i][j], n[i][j]);
        }
    }
    return result;
}

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS mat<M, N, T> clamp(mat<M, N, T> const &m, mat<M, N, T> const &min, mat<M, N, T> const &max)
{
    mat<M, N, T> result;
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        for (LENGTH_TYPE j = 0; j < N; ++j)
        {
            result[i][j] = clamp(m[i][j], min[i][j], max[i][j]);
        }
    }
    return result;
}

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS mat<M, N, T> saturate(mat<M, N, T> const &m)
{
    mat<M, N, T> result;
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        for (LENGTH_TYPE j = 0; j < N; ++j)
        {
            result[i][j] = saturate(m[i][j]);
        }
    }
    return result;
}

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS mat<M, N, T> linear_lerp(mat<M, N, T> const &m, mat<M, N, T> const &n, mat<M, N, T> const &a)
{
    mat<M, N, T> result;
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        for (LENGTH_TYPE j = 0; j < N; ++j)
        {
            result[i][j] = linear_lerp(m[i][j], n[i][j], a[i][j]);
        }
    }
    return result;
}

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS mat<N, M, T> transpose(mat<M, N, T> const &m)
{
    mat<N, M, T> result;
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        for (LENGTH_TYPE j = 0; j < N; ++j)
        {
            result[j][i] = m[i][j];
        }
    }
    return result;
}

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS T determinant(mat<M, N, T> const &m)
{
    static_assert(M == N, "determinant is only defined for square matrices");
    T result = 0;
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        T product = 1;
        for (LENGTH_TYPE j = 0; j < M; ++j)
        {
            product *= m[j][(i + j) % M];
        }
        result += product;
    }
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        T product = 1;
        for (LENGTH_TYPE j = 0; j < M; ++j)
        {
            product *= m[j][(i - j + M) % M];
        }
        result -= product;
    }
    return result;
}

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS mat<M, N, T> adjugate(mat<M, N, T> const &m)
{
    static_assert(M == N, "adjugate is only defined for square matrices");
    mat<M, N, T> result;
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        for (LENGTH_TYPE j = 0; j < N; ++j)
        {
            result[i][j] = determinant(minor(m, j, i)) * ((i + j) % 2 == 0 ? 1 : -1);
        }
    }
    return result;
}

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS mat<M, N, T> inverse(mat<M, N, T> const &m)
{
    static_assert(M == N, "inverse is only defined for square matrices");
    T const det = determinant(m);
    if (det == 0)
    {
        throw std::runtime_error("matrix is not invertible");
    }
    return adjugate(m) / det;
}

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_FUNCTION_QUALIFIERS vec<M, T> operator*(mat<M, N, T> const &m, vec<N, T> const &v)
{
    vec<M, T> result;
    for (LENGTH_TYPE i = 0; i < M; ++i)
    {
        for (LENGTH_TYPE j = 0; j < N; ++j)
        {
            result[i] += m[j][i] * v[j];
        }
    }
    return result;
}

MATRIX_NAMESPACE_END
MATH_NAMESPACE_END