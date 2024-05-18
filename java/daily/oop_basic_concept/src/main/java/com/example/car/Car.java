package com.example.car;

public class Car {

    String color;
    int productionYear;

    public Car(String color, int productionYear) {
        this.color = color;
        this.productionYear = productionYear;
    }

    public Car() {

    }

    void info() {
        System.out.println("Color: " + color);
        System.out.println("Production Year: " + productionYear);
    }

}
