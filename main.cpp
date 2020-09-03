#include "MySql.h"

int main() {

    MySql mysql;
    int operation;

    do {
        std::cout << "1.Add new user.\n2.Load user.\n3.Delete user." << std::endl;
        std::cin >> operation;

        if (operation == 1) {
            mysql.add_new_user();
        }
        if (operation == 2) {
            mysql.load_from_db();
        }
        if (operation == 3) {
            mysql.delete_user();
        }

    } while (operation != 9);

    return 0;
}
