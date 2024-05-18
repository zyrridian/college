package com.example.bike;

public class MountainBike extends Bike {

    private int saddle;

    void setSaddle(int result) {
        saddle = getGear() - result;
    }

    int getSaddle() {
        return saddle;
    }

}
