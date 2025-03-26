module com.example.sphenicnumber {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.sphenicnumber to javafx.fxml;
    exports com.example.sphenicnumber;

    opens com.example.sphenicnumber.payroll to javafx.fxml;
    exports com.example.sphenicnumber.payroll;
}