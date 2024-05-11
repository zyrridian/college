package com.example.car;

public class CarAction {
    public static void main(String[] args) {
        
        // create an object
        Car car = new Car();

        // call an attribute and set values
        car.color = "Black";
        car.productionYear = 2006;

        System.err.println("Color: " + car.color);
        System.err.println("Production Year: " + car.productionYear);

    }
    
}
