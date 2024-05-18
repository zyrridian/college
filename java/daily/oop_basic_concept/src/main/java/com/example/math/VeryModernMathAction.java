package com.example.math;

public class VeryModernMathAction {
    public static void main(String[] args) {
        
        VeryModernMath veryModernMath = new VeryModernMath();

        System.out.println("Addition: 20 + 7 = " + veryModernMath.addition(20, 7));
        System.out.println("Multiplication: 20 * 7 = " + veryModernMath.addition(20, 7));

        veryModernMath.setModulus(20, 7);
        System.out.println("Modulus: 20 % 7 = " + veryModernMath.getModulus());

        veryModernMath.setThreeAddition(20, 7, 5);
        System.out.println("Three Addition: 20 + 7 + 5 = " + veryModernMath.getThreeAddition());

    }
}
