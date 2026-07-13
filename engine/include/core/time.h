#ifndef TIME_H
#define TIME_H

#include <chrono>

class Time
{
public:
    Time();

    void beginFrame();
    void endFrame();

    void setFps(int fps);
    float deltaTime() const;

private:
    using Clock = std::chrono::steady_clock;
    Clock::time_point last_time_;
    float time_delta_;
    float target_frame_time_;
};

#endif // TIME_H