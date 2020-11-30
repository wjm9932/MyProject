#pragma once
#include <chrono>

class Timer
{
public:
    static Timer* GetTimer()
    {
        static Timer* timer = new Timer();
        return timer;
    }

    void Reset() noexcept
    {
        timeStamp = clock_t::now();
    }

    [[nodiscard]] double GetElapsedSeconds() const noexcept
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - timeStamp).count();
    }

    [[nodiscard]] double GetCurrentTime() const noexcept
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - startTimeStamp).count();
    }

private:
    Timer() : timeStamp(clock_t::now()), startTimeStamp(timeStamp)
    {};

    //  Type aliases to make accessing nested type easier
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration <double, std::ratio<1>>;

    std::chrono::time_point <clock_t> timeStamp;

    std::chrono::time_point<clock_t> startTimeStamp;
};