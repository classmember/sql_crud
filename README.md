# sql_crud

![build status](https://api.travis-ci.org/classmember/sql_crud.svg?branch=master)

CRUD (Create, Read, Update, Delete) Operations using the sqlite3 database library in the C++ programming language.

## entity crud operations

```
  Usage: entity create [name]         
         entity read    [id]          
         entity update  [id]  [name]  
         entity delete  [id]         
```

## build requirements
git
g++
libsqlite3-dev

## build

##### git clone the repo and run make

```sh
git clone https://github.com/classmember/cpp_sqlite_crud.git
cd sql_crud
make
./build/entity
```

## usage

### create

##### creates a database entry

```
$ entity create 'Mysterious Entry'
create
    id  1
  name  Mysterious Entry
```

### read

##### reads an entry from the database

```
$ entity read 1
read
    id  1
  name  Mysterious Entry
```

### update

##### updates a database entry

```
$ entity update 1 'Jelly Donut'
update
    id  1
  name  Jelly Donut
```

### delete

##### removes a database entry

```
$ entity destroy 1
destroy
    id  1
  name
```
