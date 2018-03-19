#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sqlite3.h>
#include "Entity.hpp"

using namespace std;


void Entity::create() {
    char** error = NULL;
    // run query to create new row
    string query = "INSERT INTO Entities (name) "
                   "VALUES ('" + this->name + "');";
    if (sqlite3_exec(
            this->db,
            query.c_str(),
            NULL,
            static_cast<void*>(this),
            error) == SQLITE_OK) {
        ;  // success
    } else {
        cout <<"id out of range" <<endl;
    }
    // get new id from the database's autoincrement id
    string count_rows_query = "SELECT MAX(id) AS max_id "
                              "FROM Entities;";
    if (sqlite3_exec(
            this->db,
            count_rows_query.c_str(),
            getCount,
            static_cast<void*>(this),
            error) == SQLITE_OK) {
        ;  // success
    } else {
        cerr <<"create error" <<endl
             <<error          <<endl;
    }

}

void Entity::update() {
    char** error = NULL;
    string query = "INSERT OR REPLACE INTO Entities (id, name) "
                   "VALUES (" + this->id + ", '" + this->name + "');";
    if (sqlite3_exec(
            this->db,
            query.c_str(),
            NULL,
            static_cast<void*>(this),
            error) == SQLITE_OK) {
        ;  // success
    } else {
        cerr <<"update error" <<endl
             <<error          <<endl;
    }
}

void Entity::read() {
    char** error = NULL;
    string query = "SELECT * "
                   "FROM Entities "
                   "WHERE id = '" + this->id + "';";

    if (sqlite3_exec(
            this->db,
            query.c_str(),
            getName,
            static_cast<void*>(this),
            error) == SQLITE_OK) {
        ;  // success
    } else {
        cerr <<"read error" <<endl
             <<error        <<endl;
    }
}

void Entity::remove() {
    //  create and run query
    char** error = NULL;
    string query = "DELETE "
                   "FROM Entities "
                   "WHERE id='" + this->id + "';";

    if (sqlite3_exec(
            this->db,
            query.c_str(),
            NULL,
            static_cast<void*>(this),
            error) == SQLITE_OK) {
        ;  // success
    } else {
        cerr <<"remove error" <<endl
             <<error          <<endl;
    }
}

void Entity::output_table() {
    cout <<"    id  " <<this->id   <<endl;
    cout <<"  name  " <<this->name <<endl;
}
