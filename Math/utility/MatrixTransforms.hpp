#pragma once

#include "../include/mat.h"

MATH_NAMESPACE_BEGIN
MATRIX_NAMESPACE_BEGIN

// 3D Rendering specified Matrix functions

// TODO::row major to column major
template <typename T>
static MATH_FUNCTION_QUALIFIERS mat<4, 4, T> translate(mat<4, 4, T> const &m, vec<3, T> const &v)
{
    mat<4, 4, T> result = transpose(m);
    result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
    return transpose(result);
}

template <typename T>
static MATH_FUNCTION_QUALIFIERS mat<4, 4, T> rotation(mat<4, 4, T> const &m, T angle, vec<3, T> const &v)
{
    T a = angle;
    T c = cos(a);
    T s = sin(a);
    vec<3, T> axis = normalize(v);
    vec<3, T> temp = (1 - c) * axis;

    mat<4, 4, T> rotate = mat<4, 4, T>(1);
    rotate[0][0] = c + temp[0] * axis[0];
    rotate[0][1] = 0 + temp[0] * axis[1] + s * axis[2];
    rotate[0][2] = 0 + temp[0] * axis[2] - s * axis[1];

    rotate[1][0] = 0 + temp[1] * axis[0] - s * axis[2];
    rotate[1][1] = c + temp[1] * axis[1];
    rotate[1][2] = 0 + temp[1] * axis[2] + s * axis[0];

    rotate[2][0] = 0 + temp[2] * axis[0] + s * axis[1];
    rotate[2][1] = 0 + temp[2] * axis[1] - s * axis[0];
    rotate[2][2] = c + temp[2] * axis[2];

    mat<4, 4, T> result = m * transpose(rotate);
    return result;
}

template <typename T>
static MATH_FUNCTION_QUALIFIERS mat<4, 4, T> scale(mat<4, 4, T> const &m, vec<3, T> const &v)
{
    mat<4, 4, T> result = transpose(m);
    result[0] = m[0] * v[0];
    result[1] = m[1] * v[1];
    result[2] = m[2] * v[2];
    return transpose(result);
}

MATRIX_NAMESPACE_END
MATH_NAMESPACE_END