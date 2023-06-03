/*
 * The tile library is a kye component of the new multithreading capabilities of C++. So we can put the 
 * current thread by std::this_thread_sleep_for(std::chrono::milliseconds(15) for 15 milliseconds to sleep,
 * or we try acquire a lock for 2 minutes: lock.try_lock_until(now + std::chrono::minutes(2)). Beside that
 * the chrono library makes it easy to perform simple performance tests.
 *
 * The time library consists of the three components: time point, time duration, clock.
 * Time point:
 * Time point is defined by a starting point, the so-called epoch, and an additional time duration.
 * Time duration:
 * Time duration is the difference between two time-points. It is given by the number of ticks.
 * Clock:
 * A clock consists of a starting point (epoch) and a tick, so that the current time point can be 
 * calculated 
*/
#include <iostream>
#include <vector>
#include <chrono>

int main(){
    std::vector<int> myBigVec(10'000'000, 2023);
    std::vector<int> myEmptyVec;
    
    auto begin = std::chrono::high_resolution_clock::now();
    myEmptyVec = myBigVec;
    auto end = std::chrono::high_resolution_clock::now() - begin;

    auto timeInSeconds = std::chrono::duration<double>(end).count();
    std::cout << "Time in seconds: " << timeInSeconds << std::endl;

    return 0;
}
