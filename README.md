                                                                              🔥Multithreaded 60 FPS Engine (C++)🔥
A high-performance multithreaded C++ engine running at a stable 60 FPS, using worker threads for parallel tasks and SQLite database for frame-time logging.
This project demonstrates real-world architecture with clean OOP, separated modules, threading, synchronization, and database integration — ideal for showcasing in a portfolio or resume.

 Features
 Core Engine
```
Stable 60 FPS frame limiter
Accurate frame timing system
Clean modular architecture
```
 Multithreading
```
Dedicated worker threads
std::thread, std::condition_variable, std::mutex
Thread-safe task notification system
Workers simulate heavy CPU load per frame
```
Database Logging
```
Uses SQLite3
Automatically creates a frames table
Stores:
frame delta (seconds)
timestamp
```
Clean Project Structure
engine/         → core engine, frame timer
threads/        → worker thread system
database/       → SQLite wrapper
main.cpp        → application entry

Build (Linux / macOS)
```
mkdir build
cd build
cmake ..
make
```
Run:
```./engine```

Build (Windows - MinGW)
```
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
```

Run:

```engine.exe```
