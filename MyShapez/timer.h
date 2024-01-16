#ifndef TIMER_H
#define TIMER_H

#include <chrono>

/**
 * \brief 获取当前时间，计算时间间隔
 */
class Timer
{
public:
    /**
     * \brief 时间节点, ms,计时器启动的时间，上一次的时间，当前的时间
     */
    time_t start_ms = 0, previous_ms = 0, current_ms = 0;

    /**
     * \brief 时间间隔, ms,变化的时间，从计时开始建筑运行的时间
     */
    time_t delta_ms = 0, running_ms = 0;

    /**
     * \brief 推进到下一帧时，runnning_ms增加delta_ms
     */
    void UpdateRuningTime(time_t max_require_ms);

    /**
     * \brief 重置/初始化计时器,重新开始计时
     */
    void Reset();

    /**
     * \brief 通过系统时间获取当前时间，ms
     */
    static time_t GetTime();
};

#endif // TIMER_H
