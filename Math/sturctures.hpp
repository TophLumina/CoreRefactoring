#pragma once

#include "Config.hpp"

#include <stdexcept>
#include <string>

MATH_NAMESPACE_BEGIN

#define OUT_OF_RANGE_MSG(type_str) (std::string(type_str)) + " -> Index out of range" + '\t' + \
                                   "in FILE -> " + std::string(__FILE__) + '\t' + \
                                   "at FUNCTION -> " + std::string(__func__) + '\t' + \
                                   "on LINE -> " + std::to_string(__LINE__)

#define LENGTH_TYPE size_t

// Make sure that the struct is packed
template <LENGTH_TYPE L, typename T>
struct vec;
template <LENGTH_TYPE, LENGTH_TYPE, typename T>
struct mat;
template <LENGTH_TYPE, typename T>
struct qua;

MATH_NAMESPACE_END