cmake_minimum_required(VERSION 3.17)
project(load_unload_mysql)

set(CMAKE_CXX_STANDARD 14)

include_directories("/home/pogotsky/Work/libraries/mysql-connector-c++/include")
include_directories("~/Work/libraries/mariadb-connector-c++/include")

add_executable(load_unload_mysql main.cpp MySql.cpp MySql.h)

target_link_libraries(load_unload_mysql "/home/pogotsky/Work/libraries/mysql-connector-c++/lib64/libmysqlcppconn.so" "/home/pogotsky/Work/libraries/mysql-connector-c++/lib64/libcrypto.so")
target_link_libraries(load_unload_mysql "/home/pogotsky/Work/libraries/mariadb-connector-c++/lib/mariadb/libmariadb.so")