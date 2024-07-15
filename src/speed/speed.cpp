//---------------------------------------------------------------
//  file name:      speed.h
//  author:         Arash Golgol (arash.golgol@gmail.com)
//  description:    Utilities for working with speeds (Kmph, ...)
//---------------------------------------------------------------
#include "speed.h"

namespace Details {
Speed::Speed(Mps mps) : m_mps{ mps.value() } { }

Speed::Speed(Kmph kmph) : m_mps{ Speed::kmph2mps(kmph.value()) } { }

float Speed::mps(void) const
{
    return m_mps;
}

float Speed::kmph(void) const
{
    return Speed::mps2kmph(m_mps);
}

bool Speed::operator==(Speed const& other) const
{
    return (m_mps == other.m_mps);
}

bool Speed::operator<(Speed const& other) const
{
    return (m_mps < other.m_mps);
}

float Speed::mps2kmph(float mps)
{
    return (3.6f * mps);
}

float Speed::kmph2mps(float kmph)
{
    return (kmph / 3.6f);
}
}