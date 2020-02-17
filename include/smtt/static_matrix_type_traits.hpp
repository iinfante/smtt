/*
 * Copyright 2020 Ismael Infante
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef SMTT_STATIC_MATRIX_TYPE_TRAITS_HPP
#define SMTT_STATIC_MATRIX_TYPE_TRAITS_HPP

#include <type_traits>
#include <cstddef>

namespace smtt
{

namespace detail
{

// Primary template as default for all types.
template <typename T, typename = void>
struct has_data_field : std::false_type
{
};

// Partial specialization for types that have a public array named data.
template <typename T>
struct has_data_field<
        T,
        typename std::enable_if<
                std::is_array<decltype(T::data)>::value
            >::type
    > : std::true_type
{
};

// Primary template as default for all types.
template <typename T, typename = void>
struct has_size_field : std::false_type
{
};

// Partial specialization for types that have a public array named size.
template <typename T>
struct has_size_field<
        T,
        typename std::enable_if<
                std::is_array<decltype(T::size)>::value
            >::type
    > : std::true_type
{
};

}

// Primary template as default for all types.
template <typename T, typename = void>
struct is_static_matrix : std::false_type
{
};

// Partial specialization for types that have array fields named data and size.
template <typename T>
struct is_static_matrix<
        T,
        typename std::enable_if<
                smtt::detail::has_data_field<T>::value &&
                smtt::detail::has_size_field<T>::value
            >::type
    > : std::true_type
{
};

// Primary template as default for all types.
template <typename T, size_t N, typename = void>
struct is_static_matrix_ndim : std::false_type
{
};

// Partial specialization for static matrix with N dimensions.
template <typename T, size_t N>
struct is_static_matrix_ndim<
        T,
        N,
        typename std::enable_if<
                is_static_matrix<T>::value &&
                std::extent<decltype(T::size)>::value == N
            >::type
    > : std::true_type
{
};

}

#endif
