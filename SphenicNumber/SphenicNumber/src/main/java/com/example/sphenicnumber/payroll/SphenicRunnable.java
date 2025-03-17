package com.example.sphenicnumber.payroll;

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
                    Thread.sleep(5);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }

    private boolean isSphenic(int n) {
        int ctr = 0;
        while(n != 1 && ctr < 3){
            for(int i = 2; i <= n; i++){
                if(n % i == 0){
                    ctr++;
                    n /= i;
                    if(n % i == 0){
                        return false;
                    }
                }
            }
        }
        return ctr == 3 && n == 1;
    }

}
