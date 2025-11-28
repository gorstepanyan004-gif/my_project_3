#include "Engine.h"
#include <iostream>

Engine::Engine() : db("engine_data.db") {
    db.initSchema();
    initWorkers(4);     // 4 worker threads
}

void Engine::initWorkers(int count) {
    for (int i = 0; i < count; i++) {
        workers.push_back(new WorkerThread(i));
        workers[i]->start();
    }
}

void Engine::run() {
    while (running) {
        timer.frameStart();

        update();

        double dt = timer.frameEnd(60.0);  // lock 60 FPS
        saveFrameData(dt);
    }
}

void Engine::update() {
    for (auto& worker : workers) {
        worker->notifyWork();
    }
}

void Engine::saveFrameData(double delta) {
    db.insertFrameTime(delta);
}
