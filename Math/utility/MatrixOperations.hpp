#pragma once

#include "../mat/mat.hpp"

MATH_NAMESPACE_BEGIN

template <LENGTH_TYPE M, LENGTH_TYPE N, typename T>
static MATH_CONSTEXPR mat<M, N, T> abs(mat<M, N, T> const &m)
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
static MATH_CONSTEXPR mat<M, N, T> random_range(mat<M, N, T> const &min, mat<M, N, T> const &max)
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
static MATH_CONSTEXPR mat<M, N, T> min(mat<M, N, T> const &m, mat<M, N, T> const &n)
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
static MATH_CONSTEXPR mat<M, N, T> max(mat<M, N, T> const &m, mat<M, N, T> const &n)
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
static MATH_CONSTEXPR mat<M, N, T> clamp(mat<M, N, T> const &m, mat<M, N, T> const &min, mat<M, N, T> const &max)
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
static MATH_CONSTEXPR mat<M, N, T> saturate(mat<M, N, T> const &m)
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

MATH_NAMESPACE_END