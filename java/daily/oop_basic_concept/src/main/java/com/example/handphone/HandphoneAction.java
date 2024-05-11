package com.example.handphone;

public class HandphoneAction {
    public static void main(String[] args) {
        Handphone handphone = new Handphone();
        handphone.turnOn();
        handphone.sendCall();
        handphone.sendMessage();
        handphone.turnOff();
    }
}
