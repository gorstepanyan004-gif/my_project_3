cmake_minimum_required(VERSION 3.10)
project(MultithreadedEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)

include_directories(${SQLite3_INCLUDE_DIRS})

add_executable(engine
    main.cpp

    engine/Engine.cpp
    engine/FrameTimer.cpp

    threads/WorkerThread.cpp

    database/Database.cpp
)

target_link_libraries(engine PRIVATE ${SQLite3_LIBRARIES})
