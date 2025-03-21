package database;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class CreateDataBase {
    public static final String URL = "jdbc:mysql://localhost:3306/csit228f1";
    public static final String USERNAME = "root";
    public static final String PASSWORD = "";

    public static void main(String[] args) {
        Connection connection = null;
        try {
            connection = DriverManager.getConnection(URL, USERNAME, PASSWORD);
            System.out.println("DATABASE CONNECTION SUCCESSFUL");

            String query = "CREATE TABLE payroll (id INT(11) NOT NULL AUTO_INCREMENT , employeeName VARCHAR(50) NOT NULL , hourlyWage DOUBLE NOT NULL , hoursWorked DOUBLE NOT NULL , salary DOUBLE NOT NULL , PRIMARY KEY (id))";

            Statement statement = connection.createStatement();
            statement.execute(query);
            System.out.println("TABLE CREATED SUCCESSFULLY");

        } catch (SQLException e) {
            System.err.println("Database error: " + e.getMessage());
        } finally {
            if (connection != null) {
                try {
                    connection.close();
                    System.out.println("CONNECTION CLOSED");
                } catch (SQLException e) {
                    System.err.println("Error closing connection: " + e.getMessage());
                }
            }
        }
    }
}
