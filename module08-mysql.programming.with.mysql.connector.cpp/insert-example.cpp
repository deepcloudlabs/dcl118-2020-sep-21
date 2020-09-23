#include <iostream>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

using namespace std;

int main() {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::ResultSet *res;
        sql::PreparedStatement *pstmt;

        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "Secret_123");
        /* Connect to the MySQL test database */
        con->setSchema("world");

        pstmt = con->prepareStatement("UPDATE Country set population=population+1 where continent='Asia'");
		auto rowsEffected = 0;
        rowsEffected = pstmt->executeUpdate() ;
        cout << rowsEffected << " rows are affected!" << endl;
        delete pstmt;

        /* Select in ascending order */
        pstmt = con->prepareStatement("SELECT code,name,population FROM Country where continent='Asia'");
        res = pstmt->executeQuery();

        res->afterLast();
        while (res->previous())
            cout << res->getString("code")
                 << "\t"
                 << res->getString("name")
                 << "\t"
                 << res->getInt("population") << endl;
        delete res;
        delete pstmt;
        delete con;

    } catch (sql::SQLException &e) {
        cout << "# ERR: " << e.what();
        cout << "MySQL error code: " << e.getErrorCode();
        cout << "SQLState: " << e.getSQLState() << endl;
    }

    cout << endl;
    return 0;
}
