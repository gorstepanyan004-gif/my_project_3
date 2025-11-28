#include "Database.h"
#include <iostream>

Database::Database(const std::string& filename) {
    if (sqlite3_open(filename.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Database error\n";
    }
}

Database::~Database() {
    if (db) sqlite3_close(db);
}

void Database::initSchema() {
    const char* sql =
        "CREATE TABLE IF NOT EXISTS frames ("
        " id INTEGER PRIMARY KEY AUTOINCREMENT,"
        " delta REAL NOT NULL,"
        " time TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
        ");";

    char* err = nullptr;
    sqlite3_exec(db, sql, nullptr, nullptr, &err);
}

void Database::insertFrameTime(double delta) {
    std::string query = "INSERT INTO frames(delta) VALUES(" + std::to_string(delta) + ");";
    sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);
}
