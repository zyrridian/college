package com.example.bike;

public class MountainBikeAction {
    public static void main(String[] args) {
        
        MountainBike mountainBike = new MountainBike();
        
        mountainBike.setGear(3);
        System.out.println(mountainBike.getGear());

        mountainBike.setSaddle(1);
        System.out.println(mountainBike.getGear());

    }
}
