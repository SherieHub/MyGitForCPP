module com.example.payroll_jdbc {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;


    opens com.example.payroll_jdbc to javafx.fxml;
    exports com.example.payroll_jdbc;
}