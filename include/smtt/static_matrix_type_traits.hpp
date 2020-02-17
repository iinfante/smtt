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

}

#endif
