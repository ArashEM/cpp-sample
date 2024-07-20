#ifndef PERCEPTRON_H
#define PERCEPTRON_H
//---------------------------------------------------------------
//  file name:      perceptron.h
//  author:         Arash Golgol (arash.golgol@gmail.com)
//  description:    Simple implementation of perceptron network
//---------------------------------------------------------------
#include <iostream>
#include <array>
#include <tuple>
#include <type_traits>
#include <limits>
#include <exception>

/**
 * @brief Neural Network
 *
 */
namespace nn {

/**
 * @brief Limits acceptable range of input values
 *
 * @tparam T Integral type which it's boundary is about to limit
 * @tparam MIN Minimum acceptable value for T
 * @tparam MAX Maximum acceptable value for T
 */
template<typename T, T MIN = std::numeric_limits<T>::min(), T MAX = std::numeric_limits<T>::max()>
class RangedType
{
public:
    constexpr RangedType(T t) : m_t{ t }
    {
        if (t < MIN || t > MAX)
            throw std::out_of_range("");
    }

    T value(void) { return m_t; }
    T const& value(void) const { return m_t; }

    static_assert(std::is_integral<T>::value, "T must be integral type");

private:
    T m_t;
};

/**
 * @brief Overload insertion operator for RangedType for sake of debugging
 *
 * @tparam T
 * @tparam MIN
 * @tparam MAX
 * @param stream
 * @param v
 * @return std::ostream&
 */
template<typename T, T MIN, T MAX>
std::ostream& operator<<(std::ostream& stream, RangedType<T, MIN, MAX> const& v)
{
    stream << v.value();
    return stream;
}

/**
 * @brief Used for network training and response calculation
 *
 * @tparam T
 * @tparam MIN
 * @tparam MAX
 * @param arg1
 * @param arg2
 * @return float
 */
template<typename T, T MIN, T MAX>
float operator*(RangedType<T, MIN, MAX> arg1, float arg2)
{
    return (arg1.value() * arg2);
}

/**
 * @brief Only [-1, 0, 1] are acceptable in ctor
 *
 */
using BipolarFeature = RangedType<int32_t, -1, 1>;
using BipolarLabel = RangedType<int32_t, -1, 1>;

/**
 * @brief Activation of network
 *
 * @tparam N Number of element in activation vector (array)
 */
template<std::size_t N>
using FeatureList = std::array<BipolarFeature, N>;

/**
 * @brief Supervised training data including activation (features) and expected response (label)
 *
 * @tparam N Number of element in activation vector (array)
 */
template<std::size_t N>
using Input = std::pair<FeatureList<N>, BipolarLabel>;
enum InputItems { FEATURES, LABEL };

/**
 * @brief Array of training data
 *
 * @tparam N Number of element in activation vector (array)
 * @tparam M Number of training data in dataset
 */
template<std::size_t N, std::size_t M>
using DataSet = std::array<Input<N>, M>;

/**
 * @brief Describe perceptron network including bias, weights and threshold
 *
 * @tparam N Number of input cells
 */
template<std::size_t N>
using PerceptronNetwork = std::tuple<float, std::array<float, N>, float>;
enum PerceptronNetworkItems { BIAS, WEIGHTS, ThRESHOLD };

BipolarLabel heviside(float value, float threshold)
{
    // clang-format off
    return (  (value > threshold) ? BipolarLabel{ +1 }
             :(value < threshold) ? BipolarLabel{ -1 }
                                  : BipolarLabel{ 0 });
    // clang-format on
}

template<std::size_t N>
float loss(Input<N> const& input, PerceptronNetwork<N> const& net)
{
    auto const& [features, label] = input;
    auto const& [bias, weights, threshold] = net;

    auto tmp{ bias };
    for (std::size_t i{}; i < N; i++) {
        tmp += (features.at(i) * weights.at(i));
    }

    auto clipped{ heviside(tmp, threshold) };
    return (label.value() - clipped.value());
}

template<std::size_t N, std::size_t M>
void print(DataSet<N, M> const& dataset)
{
    for (const auto& data : dataset) {
        const auto& [features, label] = data;
        for (const auto& feature : features) {
            std::cout << feature << ", ";
        }
        std::cout << ": " << label << '\n';
    }
}

} // namespace nn

#endif // PERCEPTION_H