#include "MySql.h"

using namespace std;

void MySql::connect() {

    connection = mysql_init(0);
    connection = mysql_real_connect(connection, HOST, ADMINISTRATOR, PASSWORD, DATABASE, 0, NULL, 0);
    if (!connection) {
        cerr << "Failed to connect to Mysql server." << endl;
    } else {
        cout << "Connected to Mysql server" << endl;
    }
}

void MySql::add_new_user() {

    cout << "Please, enter user name:" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Please, enter user age:" << endl;
    cin >> age;
    cout << "Please, enter user city:" << endl;
    cin.ignore();
    getline(cin, city);

    strstream << "INSERT INTO user(name, age, city) VALUES('" << name << "','" << age << "','" << city << "');";

    query = strstream.str();
    const char *q = query.c_str();
    qstate = mysql_query(connection, q);

    strstream.str("");

    if (qstate == 1) {
        cerr << "Error while loading data:" << endl;
        cerr << mysql_error(connection) << endl;
    } else {
        cout << "Record inserted." << endl;
    }
}

void MySql::load_from_db() {

    MYSQL_RES *result;
    MYSQL_ROW row;

    cout << "Enter user name: " << endl;
    getline(cin, name);

    strstream << "SELECT * FROM user WHERE name LIKE '" << name << "';";
    query = strstream.str();
    const char *q = query.c_str();
    qstate = mysql_query(connection, q);

    if (qstate != 0) {
        cout << mysql_error(connection);
        return;
    }

    result = mysql_store_result(connection);
    row = mysql_fetch_row(result);

    for (int i = 0; i < mysql_num_fields(result); i++) {
        cout << row[i] << endl;
    }

}

void MySql::delete_user() {

    cout << "Enter user name you want to delete: " << endl;
    cin >> name;
    strstream << "DELETE FROM user WHERE user = '" << name << "';";
    query = strstream.str();
    const char *q = query.c_str();
    qstate = mysql_query(connection, q);

    if (qstate == 1) {
        cout << "Deleted successfully." << endl;
    } else {
        cerr << mysql_error(connection) << endl;
        return;
    }
}