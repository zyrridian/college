package com.example.car;

public class CarConstructor {
    public static void main(String[] args) {
        
        Car myCar = new Car("Red", 2003);
        myCar.info();

        Car youCar = new Car();
        youCar.info();

    }
}
