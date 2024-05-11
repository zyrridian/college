package com.example.bank;

public class BankAction {
    public static void main(String[] args) {
        Bank bank = new Bank(100000);
        System.out.println("\nWelcome to ABC Bank");
        bank.getBalance(bank.initialBalance);
        bank.depositMoney(500000);;
        bank.withdrawMoney(150000);
    }
}
