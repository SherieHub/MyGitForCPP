package com.example.sphenicnumber.bruteforce;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Password: ");
        String pass = sc.next();
        List<Thread> threads = new ArrayList<>();
        char[] items = {'0', '1', '2', 'a', 'b'};
        for(char c : items){
            for(int i = pass.length()-1; i >= 0; i--){
                threads.add(new Thread(new BruteForceRunnable(c, i, pass)));
            }
        }
        for(Thread t : threads){
            t.start();
        }

        while(true) {
            for (Thread t : threads) {
                if (!t.isAlive()) {
                    for (Thread t1 : threads) {
                        t1.interrupt();
                    }
                    return;
                }
            }
        }
    }
}
