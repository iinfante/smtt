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

#include <smtt/static_matrix_type_traits.hpp>
#include <iostream>
#include <string>
#include <cstdlib>

// Primary template as default for all types.
template <typename T>
auto print(T const & t,
        typename std::enable_if<!smtt::is_static_matrix<T>::value>::type * = nullptr) -> void
{
    std::cout << t << '\n';
}

// Partial specialization for one dimension static matrix.
template <typename T>
auto print(T const & t,
        typename std::enable_if<smtt::is_static_matrix_ndim<T, 1>::value>::type * = nullptr) -> void
{
    for (int i = 0; i < t.size[0]; ++i)
    {
        std::cout << t.data[i] << ' ';
    }
    std::cout << '\n';
}

// Partial specialization for two dimension static matrix.
template <typename T>
auto print(T const & t,
        typename std::enable_if<smtt::is_static_matrix_ndim<T, 2>::value>::type * = nullptr) -> void
{
    for (int i = 0; i < t.size[0]; ++i)
    {
        for (int j = 0; j < t.size[1]; ++j)
        {
            std::cout << t.data[j + i * t.size[1]] << ' ';
        }
        std::cout << '\n';
    }
}

// Partial specialization for three dimension static matrix.
template <typename T>
auto print(T const & t,
        typename std::enable_if<smtt::is_static_matrix_ndim<T, 3>::value>::type * = nullptr) -> void
{
    for (int i = 0; i < t.size[0]; ++i)
    {
        for (int j = 0; j < t.size[1]; ++j)
        {
            for (int k = 0; k < t.size[2]; ++k)
            {
                std::cout << t.data[k + j * t.size[2] + i * t.size[2] * t.size[1]] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}

auto print_common_types() -> void
{
    print(1);
    print(std::string{"test"});
}

auto print_one_dimesion_static_matrix() -> void
{
    struct S
    {
        int data[5];
        int size[1];
    };

    S s{};

    s.size[0] = 3;

    s.data[0] = 1;
    s.data[1] = 2;
    s.data[2] = 3;

    print(s);
}

auto print_two_dimension_static_matrix() -> void
{
    struct T
    {
        int data[10];
        int size[2];
    };

    T t{};

    t.size[0] = 2;
    t.size[1] = 3;

    t.data[0] = 1;
    t.data[1] = 2;
    t.data[2] = 3;

    t.data[3] = 4;
    t.data[4] = 5;
    t.data[5] = 6;

    print(t);
}

auto print_three_dimension_static_matrix() -> void
{
    struct U
    {
        int data[30];
        int size[3];
    };

    U u{};

    u.size[0] = 2;
    u.size[1] = 3;
    u.size[2] = 4;


    u.data[0] = 1;
    u.data[1] = 2;
    u.data[2] = 3;
    u.data[3] = 4;

    u.data[4] = 5;
    u.data[5] = 6;
    u.data[6] = 7;
    u.data[7] = 8;

    u.data[8] = 9;
    u.data[9] = 10;
    u.data[10] = 11;
    u.data[11] = 12;
    

    u.data[12] = 13;
    u.data[13] = 14;
    u.data[14] = 15;
    u.data[15] = 16;

    u.data[16] = 17;
    u.data[17] = 18;
    u.data[18] = 19;
    u.data[19] = 20;

    u.data[20] = 21;
    u.data[21] = 22;
    u.data[22] = 23;
    u.data[23] = 24;


    print(u);
}

auto main() -> int
{
    print_common_types();
    std::cout << '\n';

    print_one_dimesion_static_matrix();
    std::cout << '\n';

    print_two_dimension_static_matrix();
    std::cout << '\n';

    print_three_dimension_static_matrix();
    std::cout << '\n';

    return EXIT_SUCCESS;
}
