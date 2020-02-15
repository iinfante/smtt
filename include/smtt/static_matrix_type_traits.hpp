#ifndef SMTT_STATIC_MATRIX_TYPE_TRAITS_HPP
#define SMTT_STATIC_MATRIX_TYPE_TRAITS_HPP

#include <type_traits>

namespace smtt
{

// Primary template as default for all types.
template <typename T, typename = void>
struct has_data_field : std::false_type
{
};

// Partial specialization for types that has a public array named data.
template <typename T>
struct has_data_field<
        T,
        typename std::enable_if<
                std::is_array<decltype(T::data)>::value
            >::type
    > : std::true_type
{
};

}

#endif
