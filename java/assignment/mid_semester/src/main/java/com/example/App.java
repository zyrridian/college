package com.example;

import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;

/**
 * Mid-Semester Java Exam
 * Rezky Aditia Fauzan (2241018)
 */
public class App {

    static String grade;
    static double salary, totalSalary;
    static double salaryA = 500;
    static double salaryB = 650;
    static double salaryC = 950;
    static boolean invalidInput = false;
    
    public static void main( String[] args ) {

        Scanner input = new Scanner(System.in);

        System.out.println( "======= COMPANY PROGRAM =======\n" );
        System.out.print( ">> Enter Employee Grade (A, B, C): " );
        grade = input.nextLine().trim().toLowerCase();

        if (grade.equals("a")) {
            salary = salaryA;
        } else if (grade.equals("b")) {
            salary = salaryB;
        } else if (grade.equals("c")) {
            salary = salaryC;
        } else {
            invalidInput = true;
            System.out.println(">> Invalid Grade!");   
        }

        if (!invalidInput) {

            invalidInput = false;
            System.out.print(">> Enter Overtime Hours (min. 1 hour): ");

            try {

                int overtimeHours = Integer.parseInt(input.nextLine());

                if (overtimeHours == 1) {
                    totalSalary = salary + (salary * 0.3);
                } else if (overtimeHours == 2) {
                    totalSalary = salary + (salary * 0.32);
                } else if (overtimeHours == 3) {
                    totalSalary = salary + (salary * 0.34);
                } else if (overtimeHours == 4) {
                    totalSalary = salary + (salary * 0.36);
                } else if (overtimeHours >= 5) {
                    totalSalary = salary + (salary * 0.38);
                } else {
                    invalidInput = true;
                    System.out.println(">> Invalid Grade!");   
                }

                if (!invalidInput) {
                    @SuppressWarnings("deprecation")
                    NumberFormat numberFormat = NumberFormat.getCurrencyInstance(new Locale("en", "US"));
                    String formattedSalary = numberFormat.format(totalSalary);
                    System.out.println(">> Total Income: " + formattedSalary);
                }

            } catch (NumberFormatException e) {
                invalidInput = true;
                System.out.println(">> Invalid Overtime Hours!");
            } finally {
                input.close();
            }
            
        }
            
    }
    
}
