package com.example.payroll_jdbc;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.IOException;
import java.sql.*;

public class EmployeePayrollController {

    public TextField tfName;
    public TextArea taName;
    public TextArea taWage;
    public TextArea taHours;
    public TextArea taSalary;
    public Button btn_viewpayroll;
    public Button btn_back;

    public static final String URL = "jdbc:mysql://localhost:3306/csit228f1";
    public static final String USERNAME = "root";
    public static final String PASSWORD = "";

    public void initialize() {
        btn_viewpayroll.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String enteredName = tfName.getText().trim();

                if (enteredName.isEmpty()) {
                    showAlert("Input Error", "Please enter an employee name.");
                    return;
                }

                try (Connection connection = DriverManager.getConnection(URL, USERNAME, PASSWORD);
                     PreparedStatement statement = connection.prepareStatement("SELECT * FROM payroll WHERE employeeName = ?")) {

                    statement.setString(1, enteredName);
                    ResultSet resultSet = statement.executeQuery();

                    if (resultSet.next()) {
                        String name = resultSet.getString("employeeName");
                        double wage = resultSet.getDouble("hourlyWage");
                        double hours = resultSet.getDouble("hoursWorked");
                        double salary = resultSet.getDouble("salary");

                        taName.setText(name);
                        taWage.setText("$" + wage + "/hour");
                        taHours.setText(hours + " hours");
                        taSalary.setText("$" + String.format("%.2f", salary));
                    } else {
                        clearFields();
                        showAlert("Not Found", "No employee found with that name.");
                    }
                } catch (SQLException e) {
                    showAlert("Database Error", "An error occurred while accessing the database.");
                    e.printStackTrace();
                }
            }
        });

        btn_back.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    Stage thisstage = (Stage) ((Button) event.getSource()).getScene().getWindow();
                    thisstage.close();

                    FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("home-view.fxml"));
                    Scene scene = new Scene(fxmlLoader.load());
                    Stage stage = new Stage();
                    stage.setScene(scene);
                    stage.initStyle(StageStyle.TRANSPARENT);
                    scene.setFill(Color.TRANSPARENT);
                    stage.show();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    private void clearFields() {
        taName.clear();
        taWage.clear();
        taHours.clear();
        taSalary.clear();
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.WARNING);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

}
