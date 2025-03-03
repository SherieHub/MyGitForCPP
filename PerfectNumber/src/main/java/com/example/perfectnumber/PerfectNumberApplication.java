package com.example.perfectnumber;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class PerfectNumberApplication extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("PerfectNumberUI.fxml"));
        Parent root = loader.load();
        stage.setTitle("Perfect Number Finder");
        stage.setScene(new Scene(root));
        stage.show();
    }
    public static void main(String[] args) {
        launch();
    }
}