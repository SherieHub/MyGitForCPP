module com.example.calculatorguadiana {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.calculatorguadiana to javafx.fxml;
    exports com.example.calculatorguadiana;
}