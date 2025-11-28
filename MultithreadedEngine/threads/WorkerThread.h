#pragma once
#include <thread>
#include <atomic>
#include <condition_variable>

class WorkerThread {
public:
    WorkerThread(int id);
    ~WorkerThread();

    void start();
    void notifyWork();

private:
    int id;
    std::thread worker;
    std::atomic<bool> running { true };
    std::condition_variable cv;
    std::mutex mtx;
    bool workRequested = false;

    void loop();
};
