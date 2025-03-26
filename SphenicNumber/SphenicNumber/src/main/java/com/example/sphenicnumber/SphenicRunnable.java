package com.example.sphenicnumber;

import javafx.beans.Observable;
import javafx.collections.ObservableList;
import javafx.scene.control.ProgressIndicator;

public class SphenicRunnable implements Runnable{
    int start, end;
    ProgressIndicator pi;
    ObservableList<Integer> list;

    public SphenicRunnable(int start, int end, ProgressIndicator pi, ObservableList<Integer> list) {
        this.start = start;
        this.end = end;
        this.pi = pi;
        this.list = list;
    }
    @Override
    public void run(){
        for(int i = start; i <= end; i++){

            pi.setProgress((double) (i-start) / (end-start));

            if(isSphenic(i)) {
                System.out.println(i);
                list.add(i);
                try {
                    Thread.sleep(50);
                } catch (InterruptedException e) {
                    throw new RuntimeException();
                }
            }
        }
    }

    private boolean isSphenic(int i) {
        int ctr = 0;
        while(i != 1 && ctr < 3){
            for(int n = 2; n <= i; n++){
                if(i % n == 0){
                    ctr++;
                    i /= n;
                    if(i % n == 0){
                        return false;
                    }
                    break;
                }
            }
        }
        return ctr == 3 && i == 1;
    }

}
