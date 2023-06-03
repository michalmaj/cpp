/*
 * A duration consists of a span of time, defined as some number of ticks of some time unit. A time point
 * consists of a clock and a time duration. This tme duration can be positive or negative.
 *
 * The epoch is not defined for the clocks std::chrono::steady_clock, std::chrono::high_resolution_clock
 * and std::chrono::system. But on the popular platform the epoch of std::chrono::system is usually defined
 * as 1.1.1970. We can calculate the time since 1.1.1970 in the resolution nanoseconds, seconds and minutes.
*/
#include <iostream>
#include <chrono>

int main(){
    auto timeNow = std::chrono::system_clock::now();
    auto duration = timeNow.time_since_epoch();
    std::cout << duration.count() << "ns\n"; // nanoseconds (default)
    
    // duration_cast converts one type into other
    auto durationSeconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
    std::cout << durationSeconds << "s\n"; // seconds
    
    auto durationMinutes = std::chrono::duration_cast<std::chrono::minutes>(duration).count();
    std::cout << durationMinutes << "m\n"; // minutes

    return 0;
}
