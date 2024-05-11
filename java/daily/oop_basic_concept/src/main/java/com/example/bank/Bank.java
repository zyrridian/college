package com.example.bank;

public class Bank {
    
    int initialBalance;

    public Bank(int initialBalance) {
        this.initialBalance = initialBalance;
    }

    void depositMoney(int amount) {
        System.out.println("Deposit money: Rp. " + amount);
        initialBalance = initialBalance + amount;
        getBalance(initialBalance);
        
    }

    void withdrawMoney(int amount) {
        System.out.println("Withdraw money: Rp. " + amount);
        initialBalance = initialBalance - amount;
        getBalance(initialBalance);

    }

    void getBalance(int amount) {
        System.out.println("Current balance: Rp. " + amount + "\n");
    }

}
