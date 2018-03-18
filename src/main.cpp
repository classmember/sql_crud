#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <sqlite3.h>
#include "Entity.hpp"

using namespace std;


#define DB_NAME "game.db"

#define USAGE "  Usage: entity create [name]         \n"\
              "         entity read    [id]          \n"\
              "         entity update  [id]  [name]  \n"\
              "         entity delete  [id]          \n"

#define SCHEMA "CREATE TABLE IF NOT EXISTS Entities (\n"\
               "    id integer primary key autoincrement,\n"\
               "    name text not null\n"\
               ");"


void display_usage() {cerr <<USAGE;}


void init_db(sqlite3* db) {
    char** error = NULL;
    if (sqlite3_exec(db, SCHEMA, NULL, NULL, error) == SQLITE_OK) {
        ;  // success
    } else {
        cerr <<"db init error" <<endl
             <<error           <<endl;
    }
}

int main(int argc, char** argv) {

    // initialize
    sqlite3* db;
    sqlite3_open(DB_NAME, &db);
    init_db(db);
    Entity the_entity(db);

    // handle arguments
    if (argc == 3) {
        if (argv[1] == string("create")) { 
            cout << "create" <<endl;
            the_entity.set_name(argv[2]);
            the_entity.create();
            the_entity.output_table();
        } else if (argv[1] == string("read")) { 
            cout << "read" <<endl;
            the_entity.set_id(argv[2]);
            the_entity.read();
            the_entity.output_table();
        } else if (argv[1] == string("delete")) { 
            cout << "delete" <<endl;
            the_entity.set_id(argv[2]);
            the_entity.remove();
            the_entity.output_table();
        } else {
            display_usage();
        }
    } else if (argc == 4) {
        if (argv[1] == string("update")) { 
            cout << "update" <<endl;
            the_entity.set_id(argv[2]);
            the_entity.set_name(argv[3]);
            the_entity.update();
            the_entity.output_table();
        } else {
            display_usage();
        }
    } else {
        display_usage();
    }
}
