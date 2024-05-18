package com.example.math;

public class ModernMath extends Math {
    
    private int modulus;

    void setModulus(int a, int b) {
        modulus = a % b;
    }

    int getModulus() {
        return modulus;
    }

}
