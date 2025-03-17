package com.example.sphenicnumber;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;

import java.nio.channels.AlreadyBoundException;
import java.util.ArrayList;
import java.util.List;

public class HelloController {
    public TextField tfNumber;
    public TextField tfThread;
    public ListView lvList;
    public HBox hbProgCont;

    public void onOKButtonClicked(ActionEvent actionEvent) {
        try {
            int num = Integer.parseInt(tfNumber.getText());
            int thrd = Integer.parseInt(tfThread.getText());
            List<Thread> threads = new ArrayList<>();
            int each = num/thrd;
            for(int i = 0; i < thrd; i++){
                ProgressIndicator pi = new ProgressIndicator();
                hbProgCont.getChildren().add(pi);
                threads.add(new Thread(new SphenicRunnable(each*i+1, each*(i+1), pi, lvList.getItems())));
            }

            for(Thread t : threads){
                t.start();
            }
        }catch (Exception e){
            Alert a = new Alert(Alert.AlertType.ERROR, e.toString(), ButtonType.OK);
            a.show();
            tfNumber.setText("");
            tfThread.setText("");
        }
    }


}