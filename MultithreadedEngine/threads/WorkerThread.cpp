#include "WorkerThread.h"
#include <iostream>

WorkerThread::WorkerThread(int id) : id(id) {}

WorkerThread::~WorkerThread() {
    running = false;
    cv.notify_all();
    if (worker.joinable()) worker.join();
}

void WorkerThread::start() {
    worker = std::thread(&WorkerThread::loop, this);
}

void WorkerThread::notifyWork() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        workRequested = true;
    }
    cv.notify_one();
}

void WorkerThread::loop() {
    while (running) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return workRequested || !running; });

        if (!running) break;
        workRequested = false;

        // Simulate heavy CPU work
        std::cout << "Worker " << id << " processing\n";
    }
}
