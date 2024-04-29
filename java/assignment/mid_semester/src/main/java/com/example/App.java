package com.example;

import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;

/**
 * UTS Pemrograman Java
 * Rezky Aditia Fauzan (2241018)
 */
public class App {

    static String golongan;
    static double gaji, totalGaji;
    static double gajiA = 5000000;
    static double gajiB = 6500000;
    static double gajiC = 9500000;
    static boolean inputSalah = false;
    
    public static void main( String[] args ) {

        Scanner input = new Scanner(System.in);

        System.out.println( "======= PROGRAM PERUSAHAAN =======" );
        System.out.print( ">> Masukkan Golongan Karyawan (A, B, C): " );
        golongan = input.nextLine().trim().toLowerCase();

        if (golongan.equals("a")) {
            gaji = gajiA;
        } else if (golongan.equals("b")) {
            gaji = gajiB;
        } else if (golongan.equals("c")) {
            gaji = gajiC;
        } else {
            inputSalah = true;
            System.out.println(">> Golongan tidak valid!");   
        }

        if (!inputSalah) {

            inputSalah = false;
            System.out.print(">> Masukkan Jam Lembur (min. 1 jam): ");

            try {

                int lembur = Integer.parseInt(input.nextLine());

                if (lembur == 1) {
                    totalGaji = gaji + (gaji * 0.3);
                } else if (lembur == 2) {
                    totalGaji = gaji + (gaji * 0.32);
                } else if (lembur == 3) {
                    totalGaji = gaji + (gaji * 0.34);
                } else if (lembur == 4) {
                    totalGaji = gaji + (gaji * 0.36);
                } else if (lembur >= 5) {
                    totalGaji = gaji + (gaji * 0.38);
                } else {
                    inputSalah = true;
                    System.out.println(">> Golongan tidak valid!");   
                }

                if (!inputSalah) {
                    NumberFormat numberFormat = NumberFormat.getCurrencyInstance(new Locale("id", "ID"));
                    String formatRupiah = numberFormat.format(totalGaji);
                    System.out.println(">> Jumlah penghasilan: " + formatRupiah);
                }

            } catch (NumberFormatException e) {
                inputSalah = true;
                System.out.println(">> Jam lembur tidak valid!");
            } finally {
                input.close();
            }
            
        }
            
    }
    
}
