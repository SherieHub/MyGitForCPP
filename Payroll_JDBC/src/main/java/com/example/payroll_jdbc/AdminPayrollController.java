package com.example.payroll_jdbc;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.IOException;
import java.sql.*;
import java.util.List;

public class AdminPayrollController {
    public ListView<Employee> lvList;
    public HBox hbProgCont;
    public TextField tfWage;
    public TextField tfWorked;
    public TextField tfName;
    public Label lblSalary;
    public Button btn_back;
    private Employee current;

    public static final String URL = "jdbc:mysql://localhost:3306/csit228f1";
    public static final String USERNAME = "root";
    public static final String PASSWORD = "";

    public void initialize() {
        retrieveData();
        lvList.getFocusModel().focusedItemProperty().addListener(new ChangeListener<Employee>() {
            @Override
            public void changed(ObservableValue<? extends Employee> observableValue, Employee oldValue, Employee newValue) {
                if (newValue != null) {
                    tfName.setText(newValue.name);
                    tfWage.setText(String.valueOf(newValue.wage));
                    tfWorked.setText(String.valueOf(newValue.hours));
                    current = newValue;
                } else {
                    tfName.clear();
                    tfWage.clear();
                    tfWorked.clear();
                    current = null;
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

    public void onCalculateButtonClicked(ActionEvent actionEvent) {
        double wage = Double.parseDouble(tfWage.getText());
        double hours = Double.parseDouble(tfWorked.getText());
        String name = tfName.getText();

        double salary = wage * hours;
        lblSalary.setText("SALARY: $" + String.format("%.2f", salary));
        lblSalary.setVisible(true);
    }

    public void onSavePayrollClicked(ActionEvent actionEvent) {
        double wage = Double.parseDouble(tfWage.getText());
        double hours = Double.parseDouble(tfWorked.getText());
        String name = tfName.getText();

        if (current == null) {  // New employee
            Employee e = new Employee(name, hours, wage);
            insertData(e);
            lvList.getItems().clear();  // Clear the ListView
            retrieveData();  // Reload all data from DB
        } else {  // Updating existing employee
            int index = lvList.getItems().indexOf(current);
            if (index != -1) {
                Employee updatedEmployee = new Employee(name, hours, wage);
                updatedEmployee.id = current.id;
                updateData(updatedEmployee, updatedEmployee.id);

                lvList.getItems().set(index, updatedEmployee);
                lvList.refresh();
            }
        }
    }


    public void onClearClicked(ActionEvent actionEvent) {
        tfName.setText("");
        tfWorked.setText("");
        tfWage.setText("");
        lblSalary.setVisible(false);
        current = null;
    }

    public void onDeleteClicked(ActionEvent actionEvent) {
        Employee employee = lvList.getSelectionModel().getSelectedItem();
        if (employee == null) {
            System.out.println("No employee selected.");
            return;
        }
        deleteData(employee.id);
        lvList.getItems().remove(employee);
        lvList.getSelectionModel().clearSelection();
        lvList.refresh();
    }

    public void onUpdateClicked(ActionEvent actionEvent) {
        Employee employee = lvList.getSelectionModel().getSelectedItem();
        if (employee != null) {
            onClearClicked(actionEvent);
            current = employee;
        }
    }

    public void insertData(Employee employee){
        try (Connection connection = DriverManager.getConnection(URL, USERNAME, PASSWORD);
             PreparedStatement statement = connection.prepareStatement(
                     "INSERT INTO payroll (employeeName, hourlyWage, hoursWorked, salary) VALUES (?, ?, ?, ?)",
                     Statement.RETURN_GENERATED_KEYS)) { // Retrieve generated keys
            statement.setString(1, employee.name);
            statement.setDouble(2, employee.wage);
            statement.setDouble(3, employee.hours);
            statement.setDouble(4, employee.salary());

            int rowsAffected = statement.executeUpdate();
            if(rowsAffected > 0){
                ResultSet rs = statement.getGeneratedKeys();
                if (rs.next()) {
                    employee.id = rs.getInt(1);
                }
                System.out.println("INSERT SUCCESSFULLY: ID = " + employee.id);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }


    public void deleteData(int id){
        try (Connection connection = DriverManager.getConnection(URL, USERNAME, PASSWORD);
             PreparedStatement statement = connection.prepareStatement(
                     "DELETE FROM payroll WHERE id=?"
             )){
            statement.setInt(1, id);
            int rowsAffected = statement.executeUpdate();
            if(rowsAffected > 0){
                System.out.println("DELETED SUCCESSFULLY");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void retrieveData(){
        try (Connection connection = DriverManager.getConnection(URL, USERNAME, PASSWORD);
             Statement statement = connection.createStatement()){
            String query = "SELECT * FROM payroll";
            ResultSet resultSet = statement.executeQuery(query);
            while(resultSet.next()){
                String name = resultSet.getString("employeeName");
                int id = resultSet.getInt(1);
                double wage = resultSet.getDouble(3);
                double hours = resultSet.getDouble(4);
                double salary = resultSet.getDouble(5);

                Employee employee = new Employee(name, hours, wage);
                employee.id = id;
                lvList.getItems().add(employee);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void updateData(Employee employee, int id){
        try (Connection connection = DriverManager.getConnection(URL, USERNAME, PASSWORD);
             PreparedStatement statement = connection.prepareStatement(
                     "UPDATE payroll SET employeeName=?, hourlyWage=?, hoursWorked=?, salary=? WHERE id=?"
             )){
            statement.setString(1, employee.name);
            statement.setDouble(2, employee.wage);
            statement.setDouble(3, employee.hours);
            statement.setDouble(4, employee.salary());
            statement.setInt(5, id);

            int rowsAffected = statement.executeUpdate();
            if(rowsAffected > 0){
                System.out.println("UPDATED SUCCESSFULLY");
            } else {
                System.out.println("UPDATE FAILED: No rows affected.");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
