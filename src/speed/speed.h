#ifndef SPEED_H
#define SPEED_H
//---------------------------------------------------------------
//  file name:      speed.h
//  author:         Arash Golgol (arash.golgol@gmail.com)
//  description:    Utilities for working with speeds (Kmph, ...)
//---------------------------------------------------------------
#include "strongtype.hpp"

namespace Details {

enum class Types { Meter, KiloMeter, Mile };

/**
 * @brief Mps is a strongly typed float which indicate "Meter Per Second"
 *
 */
using Mps = StrongType<float, Types::Meter>;
constexpr Mps operator""_mps(long double value)
{
    return Mps{ static_cast<float>(value) };
}

/**
 * @brief Kmph is strongly typed float which indicate "Kilo Meters Per hours"
 *
 */
using Kmph = StrongType<float, Types::KiloMeter>;
constexpr Kmph operator""_kmph(long double value)
{
    return Kmph{ static_cast<float>(value) };
}

/**
 * @brief Represent Speed of an object
 * 
 */
class Speed
{
public:
    explicit Speed(Mps mps);
    explicit Speed(Kmph kmph);

    float mps(void) const;
    float kmph(void) const;

    bool operator==(Speed const& other) const;
    bool operator<(Speed const& other) const;

    static float mps2kmph(float mps);
    static float kmph2mps(float kmph);

private:
    float m_mps;
};
}
#endif // SPEED_H