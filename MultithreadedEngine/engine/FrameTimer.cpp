#include "FrameTimer.h"
#include <thread>

void FrameTimer::frameStart() {
    start = std::chrono::high_resolution_clock::now();
}

double FrameTimer::frameEnd(double targetFPS) {
    using namespace std::chrono;
    auto end = high_resolution_clock::now();
    double delta = duration<double>(end - start).count();

    double frameDuration = 1.0 / targetFPS;
    if (delta < frameDuration) {
        std::this_thread::sleep_for(duration<double>(frameDuration - delta));
        delta = frameDuration;
    }

    return delta;
}
