#ifndef OBS_BASE_STATS_HPP
#define OBS_BASE_STATS_HPP

// System
#include <cstdint>

namespace obs
{

struct BaseTimeStats
{
    std::int64_t avg{0};   ///< Average value
    std::int64_t min{0};   ///< Min value
    std::int64_t max{0};   ///< Max value
    std::int64_t var{0};   ///< Variance
};

} // namespace obs

#endif // OBS_BASE_STATS_HPP