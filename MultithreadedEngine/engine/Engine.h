#pragma once
#include "../threads/WorkerThread.h"
#include "../database/Database.h"
#include "FrameTimer.h"
#include <vector>

class Engine {
public:
    Engine();
    void run();

private:
    Database db;
    FrameTimer timer;
    std::vector<WorkerThread*> workers;
    bool running = true;

    void initWorkers(int count);
    void update();
    void saveFrameData(double delta);
};
