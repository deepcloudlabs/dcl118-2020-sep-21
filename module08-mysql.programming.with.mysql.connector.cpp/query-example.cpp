#include <iostream>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main() {
    cout << endl;
    cout << "Running 'SELECT * from Country'" << endl;

    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "Secret_123");
        con->setSchema("world");
        con->setAutoCommit(true);

        stmt = con->createStatement();
        res = stmt->executeQuery("select co.name as name, ci.name as capital from Country as co , City as ci where co.code = ci.countrycode and co.capital = ci.id");
        while (res->next()) {
            cout << res->getString("name") << "\t"
                 << res->getString("capital") << endl;
        }
        delete res;
        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
        cout << "# ERR: " << e.what() << endl;
        cout << "MySQL error code: " << e.getErrorCode() << endl ;
        cout << "SQLState: " << e.getSQLState() << endl;
    }

    cout << endl;

    return 0;
}
