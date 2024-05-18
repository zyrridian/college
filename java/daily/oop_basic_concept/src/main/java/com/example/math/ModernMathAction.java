package com.example.math;

public class ModernMathAction {
    public static void main(String[] args) {
        ModernMath modernMath = new ModernMath();
        System.out.println("Addition: 20 + 20 = " + modernMath.addition(20, 20));
        System.out.println("Multiplication: 10 * 20 = " + modernMath.multiplication(10, 20));
        modernMath.setModulus(21, 2);
        System.out.println("Modulus: 21 % 2 = " + modernMath.getModulus());
    }
}
