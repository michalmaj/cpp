/*
 * The time duration is a measure of how many ticks have passed since a certain time point.
 * Time duration is the difference between the two time-ponts. Time duration is measured in the number of
 * ticks.
 * template <class Rep, class Period = ratio<1>> class duration;
 * If Rep is a floating-point number, the time duration supports fraction of ticks. The most important time
 * duration are predefined in the chrono library:
 *  typedef duration<signed int, nano> nanoseconds;
 *  typedef duration<signed int, micro> microseconds;
 *  typedef duration<signed int, milli> milliseconds;
 *  typedef duration<signed int> seconds;
 *  typedef duration<signed int, ratio< 60>> minutes;
 *  typedef duration<signed int, ratio<3600>> hours;
 *
 * How long can a time duration be? The C++ standard guarantees that the predefined time durations can store
 * +- 292 years. We can easily define your own time duration liek a Poland shool hour:
 *  typedef std::chrono::duration<double, std::ratio<2700>> MyLessonTick.
 * Time duration in natural numbers have to be explicitly converted to time duration in floating point 
 * numbers. The value will be truncated.
 *
 * std::ratio
 * std::ratio supports arithmetic at compile time with rational numbers. A rational number has two template
 * arguments. One is the nominator, the other the denominator. C++11 predefines lots of rational numbers:
 * https://en.cppreference.com/w/cpp/numeric/ratio/ratio
*/
#include <iostream>
#include <chrono>
#include <ratio>

template <class Rep, class Period = std::ratio<1>>
class duration;

int main(){
    typedef std::chrono::duration<long long, std::ratio<1>> MySecondTick;
    MySecondTick aSecond(1);
    
    std::chrono::milliseconds milli{aSecond};
    std::cout << milli.count() << "ms\n"; // 1000 milli
    
    std::chrono::seconds seconds{aSecond};
    std::cout << seconds.count() << "s\n"; // 1 sec
    
    std::chrono::minutes minutes{std::chrono::duration_cast<std::chrono::minutes>(aSecond)};
    std::cout << minutes.count() << "m\n"; // 0 min
    
    typedef std::chrono::duration<double, std::ratio<2700>> MyLessonTick;
    MyLessonTick myLesson(aSecond);
    std::cout << myLesson.count() << " less\n"; // 0.00037037 less
    
    
    
    return 0;
}
