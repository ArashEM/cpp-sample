//---------------------------------------------------------------
//  file name:      strongtype.hpp
//  author:         Arash Golgol (arash.golgol@gmail.com)
//  description:    Strongly typed integral type
//---------------------------------------------------------------
#include <type_traits>
namespace Details {

/**
 * @brief Strongly typed integer type
 *
 * @tparam T Integer type (int, float, ...)
 * @tparam K Enum member key to distinguish
 */
template<typename T, auto K>
class StrongType
{
public:
    constexpr explicit StrongType(T t) : m_t{ t } { }

    T value(void) { return m_t; }

    T const& value(void) const { return m_t; }

    static_assert(std::is_arithmetic_v<T>, "T must be arithmetic type!");
    static_assert(std::is_enum_v<decltype(K)>, "K must be enum!");

private:
    T m_t;
};
}