package com.example.bike;

public class Bike {
    
    int gear;

    // method (mutator) with parameter
    void setGear(int gearIncrement) {
        gear = gear + gearIncrement;
    }

    // method (accessor)
    int getGear() {
        return gear;
    }
    
}
