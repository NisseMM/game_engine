#include <core/time.h>

#include <thread>

Time::Time()
    : last_time_{std::chrono::steady_clock::now()},
      time_delta_{0.0f}, target_frame_time_{1 / 60.0}
{
    beginFrame();
}

void Time::beginFrame()
{
    auto now = Clock::now();
    time_delta_ =  std::chrono::duration<float>(now - last_time_).count();
    last_time_ = now;
}

void Time::endFrame()
{
    auto now = Clock::now();
    float frame_time = std::chrono::duration<float>(now - last_time_).count();

    if (frame_time < target_frame_time_)
    {
        auto remaining =
            target_frame_time_ - frame_time;

        std::this_thread::sleep_for(
            std::chrono::duration<float>(remaining)
        );
    }
}

void Time::setFps(int fps)
{
    target_frame_time_ = 1.0/fps;
}

float Time::deltaTime() const
{
    return time_delta_;
}