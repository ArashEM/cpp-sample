//---------------------------------------------------
//  file name:      speedgtest.cpp
//  author:         Arash Golgol (arash.golgol@gmail.com)
//  description:    Unit tests for Details::Speed class
//---------------------------------------------------
#include <gtest/gtest.h>

#include "speed.h"

namespace Tests {

TEST(SpeedTest, ZeroMeterPerSecond) {
    using namespace Details;

    // setup
    Speed s{0_mps};

    // verification
    EXPECT_EQ(s.mps(), 0.0f);
}
} // namespace Tests