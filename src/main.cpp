//---------------------------------------------------
//  file name:      main.cpp
//  author:         Arash Golgol (arash.golgol@gmail.com)
//  description:    Main application
//---------------------------------------------------
#include <iostream>
#include <utility>

#include "speed.h"
#include "perceptron.hpp"

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    try {
        using namespace Details::literals;
        using namespace std::rel_ops;

        Details::Speed d1{ 10.2_mps };
        Details::Speed d2{ 23.2_kmph };

        std::cout << (d1 > d2) << '\n';

        // clang-format off
        nn::DataSet<3, 8> dataset{{
            //  x1  x2  x3   y
            { { 1,  0,  0 }, 0 },
            { { 0,  1,  1 }, 0 },
            { { 0,  0,  0 }, 0 },
            { { 1,  1,  1 }, 0 },
            { { 1,  0,  0 }, 0 },
            { { 0,  1,  1 }, 0 },
            { { 0,  0,  0 }, 0 },
            { { 1,  1,  1 }, 1 }
        }};
        // clang-format on
        nn::print(dataset);

    } catch (std::exception& e) {
        std::cerr << e.what();
    }
}