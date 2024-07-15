//---------------------------------------------------
//  file name:      main.cpp
//  author:         Arash Golgol (arash.golgol@gmail.com)
//  description:    Main application
//---------------------------------------------------
#include <iostream>
#include <utility>

#include "speed.h"

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    try {
        using namespace Details;
        using namespace std::rel_ops;
        
        Speed d1{ 10.2_mps };
        Speed d2{ 23.2_kmph };

        std::cout << (d1 > d2) << '\n';

    } catch (std::exception& e) {
        std::cerr << e.what();
    }
}