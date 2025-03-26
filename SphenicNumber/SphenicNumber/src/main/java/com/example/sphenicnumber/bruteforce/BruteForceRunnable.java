package com.example.sphenicnumber.bruteforce;

public class BruteForceRunnable implements Runnable{
    char ch;
    int pos;
    String pass;
    int id;
    static int ID;

    public BruteForceRunnable(char ch, int pos, String pass) {
        id = ++ID;
        this.ch = ch;
        this.pos = pos;
        this.pass = pass;
    }
    @Override
    public void run(){
        int chars = pass.length()-1;
        String brute = "a". repeat(chars);
        String compare = brute.substring(0, pos) + ch + brute.substring(pos, chars);

        while(!compare.equals(pass)){
            if(Thread.currentThread().isInterrupted()){
                return;
            }

            System.out.println("Thread " + id + ": " + compare);
            int i;
            for(i = chars-1; i >= 0; i--){
                if(brute.charAt(i) != '9'){
                    break;
                }
            }
            String newbrute = brute.substring(0, i);
            newbrute += brute.charAt(i) == 'z' ? '0' : (char) (brute.charAt(i)+1);
            newbrute += "a".repeat(chars-i-1);
            brute = newbrute;
            compare = brute.substring(0, pos) + ch + brute.substring(pos, chars);
        }
        System.out.println("FOUND " + compare + " at thread " + id);
    }
}
