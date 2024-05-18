package com.example.math;

public class MathAction {
    public static void main(String[] args) {

        Math math = new Math();

        // System.out.println("Addition: 20 + 20 = " + math.addition(20, 20));
        // System.out.println("Substraction: 10 - 5 = " + math.substraction(10, 5));
        // System.out.println("Multiplication: 10 * 20 = " + math.multiplication(10, 20));
        // System.out.println("Division: 21 / 2 = " + math.division(21, 2));
    
        System.out.println("Addition: 12.5 + 28.7 + 14.2 = " + math.addition(12.5, 28.7, 14.2));
        System.out.println("Addition: 23 + 34 = " + math.addition(23, 34));
        System.out.println("Addition: 12 + 28 + 14 = " + math.addition(12, 28, 14));
        System.out.println("Addition: 3.4 + 4.9 = " + math.addition(3.4, 4.9));

    }
}
