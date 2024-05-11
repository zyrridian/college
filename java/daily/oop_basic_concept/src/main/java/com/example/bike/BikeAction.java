package com.example.bike;

public class BikeAction {
    public static void main(String[] args) {
        
        Bike bike = new Bike();

        bike.setGear(1);
        System.out.println("Current gear: " + bike.getGear());

        bike.setGear(3);
        System.out.println("Current gear: " + bike.getGear());

    }
}
