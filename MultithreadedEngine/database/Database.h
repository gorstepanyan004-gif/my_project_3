#pragma once
#include <sqlite3.h>
#include <string>

class Database {
public:
    Database(const std::string& filename);
    ~Database();

    void initSchema();
    void insertFrameTime(double delta);

private:
    sqlite3* db = nullptr;
};
