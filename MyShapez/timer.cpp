#include "timer.h"

void Timer::UpdateRuningTime(time_t max_require_ms)
{
    if (running_ms >= max_require_ms)
    {
        return;
    }
    previous_ms = current_ms;
    current_ms = GetTime();
    // 更新时间间隔
    delta_ms = (current_ms - previous_ms);
    running_ms += delta_ms;
}

void Timer::Reset()
{
    start_ms = GetTime();
    current_ms = start_ms;
    previous_ms = start_ms;
    running_ms = 0;
    delta_ms = 0;
}

long long Timer::GetTime()
{
    // 现在的时间 ms
    using namespace std::chrono;
    return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() / 1000;
}
