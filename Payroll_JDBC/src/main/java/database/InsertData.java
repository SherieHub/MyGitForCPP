package database;

import java.sql.*;

public class InsertData {
    public static final String URL = "jdbc:mysql://localhost:3306/csit228f1";
    public static final String USERNAME = "root";
    public static final String PASSWORD = "";

    public static void main(String[] args) {
        try (Connection connection = DriverManager.getConnection(URL, USERNAME, PASSWORD);
             PreparedStatement statement = connection.prepareStatement(
                     "INSERT INTO users (name, email) VALUES (?, ?)"
             )){
            String name = "Cherry";
            String email = "jayvince.serato@cit.edu";
            statement.setString(1, name);
            statement.setString(2, email);
            int rowsAffected = statement.executeUpdate();
            if(rowsAffected > 0){
                System.out.println("INSERT SUCCESSFULLY");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}