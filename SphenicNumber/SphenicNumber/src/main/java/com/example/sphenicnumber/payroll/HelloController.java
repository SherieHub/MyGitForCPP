package com.example.sphenicnumber.payroll;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;

public class HelloController {
    public ListView<Employee> lvList;
    public HBox hbProgCont;
    public TextField tfWage;
    public TextField tfWorked;
    public TextField tfName;
    public Label lblSalary;
    private Employee current;

    public void initialize(){
        lvList.getFocusModel().focusedItemProperty().addListener(new ChangeListener<Employee>() {
            @Override
            public void changed(ObservableValue<? extends Employee> observableValue, Employee employee, Employee t1) {
                tfName.setText(t1.name);
                tfWage.setText(String.valueOf(t1.wage));
                tfWorked.setText(String.valueOf(t1.hours));
                current = t1;
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
        if(current == null){
            Employee e = new Employee(name, hours, wage);
            lvList.getItems().add(e);
        }else{
            current.name = name;
            current.wage = wage;
            current.hours = hours;
        }
    }

    public void onClearClicked(ActionEvent actionEvent) {
        tfName.setText("");
        tfWorked.setText("");
        tfWage.setText("");
        lblSalary.setVisible(false);
        current = null;
    }
}