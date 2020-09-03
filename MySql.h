//
// Created by pogotsky on 01.09.2020.
//

#ifndef LOAD_UNLOAD_MYSQL_MYSQL_H
#define LOAD_UNLOAD_MYSQL_MYSQL_H

#include <iostream>
#include <mariadb/mysql.h>
#include <sstream>
#include <cstring>


#define HOST "127.0.0.1"
#define ADMINISTRATOR "root"
#define PASSWORD " "
#define DATABASE "test"



class MySql {

    MYSQL *connection;
    std::stringstream strstream;
    std::string query;
    int qstate;

    std::string name;
    int age;
    std::string city;

    void connect();

public:

    MySql(){
        connect();
    }
    void add_new_user();
    void load_from_db();
    void delete_user();

    ~MySql(){};
};


#endif //LOAD_UNLOAD_MYSQL_MYSQL_H
