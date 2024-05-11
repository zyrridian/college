package com.example.math;

public class MathAction {
    public static void main(String[] args) {
        Math math = new Math();
        System.out.println("Addition: 20 + 20 = " + math.addition(20, 20));
        System.out.println("Substraction: 10 - 5 = " + math.substraction(10, 5));
        System.out.println("Multiplication: 10 * 20 = " + math.multiplication(10, 20));
        System.out.println("Division: 21 / 2 = " + math.division(21, 2));
    }
}
