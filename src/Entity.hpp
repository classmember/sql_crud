#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <sqlite3.h>

using namespace std;


class Entity {
    sqlite3* db;
    string id;
    string name;
public:
    Entity(){};
    Entity(sqlite3 * connection){this->db = connection;};
    ~Entity(){};
    static int getName(void* userData, int columns, char** columnValues, char** columnNames) {
        Entity* _this_ = reinterpret_cast<Entity*>(userData);
        _this_->set_id(columnValues[0]);
        _this_->set_name(columnValues[1]);
        return 0;
    }
    static int getCount(void* userData, int columns, char** columnValues, char** columnNames) {
        Entity* _this_ = reinterpret_cast<Entity*>(userData);
        _this_->set_id(columnValues[0]);
        return 0;
    }
    static int getNextID(void* userData, int columns, char** columnValues, char** columnNames) {
        Entity* _this_ = reinterpret_cast<Entity*>(userData);
        _this_->set_id(columnValues[0]);
        return 0;
    }
    void create();
    void read();
    void update();
    void remove();
    void set_name(string new_name) {this->name = new_name;};
    void set_id(string new_id) {this->id = new_id;};
    void output_table();
    string get_name() {return this->name;};
    string get_id() {return this->id;};
};

#endif  // ENTITY_HPP
