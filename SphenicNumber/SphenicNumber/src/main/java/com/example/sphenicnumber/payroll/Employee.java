package com.example.sphenicnumber.payroll;

public class Employee {
    String name;
    double hours;
    double wage;
    int id;
    static int ID = 25000;

    public Employee(String name, double hours, double wage) {
        id = ++ID;
        this.name = name;
        this.hours = hours;
        this.wage = wage;
    }

    public double salary(){
        return hours * wage;
    }

    public String toString(){
        return name + ": $" + String.format("%.2f", salary());
    }
}
