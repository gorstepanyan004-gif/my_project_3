#pragma once
#include <chrono>

class FrameTimer {
public:
    void frameStart();
    double frameEnd(double targetFPS);

private:
    std::chrono::high_resolution_clock::time_point start;
};
