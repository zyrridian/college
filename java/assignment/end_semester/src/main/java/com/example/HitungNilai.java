package com.example;
import java.util.ArrayList;
import java.util.Scanner;

public class HitungNilai {

    public static void main(String[] args) {

        // Deklarasikan variabel
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> nilai = new ArrayList<>();

        System.out.println("Masukkan nilai (pisahkan dengan enter, ketik 'selesai' untuk menghitung):");

        while (true) {

            String input = scanner.nextLine();

            // Hentikan loop jika input adalah "selesai"
            if (input.equalsIgnoreCase("selesai")) {
                break;
            }

            // Masukkan input ke dalam ArrayList
            try {
                nilai.add(Integer.parseInt(input.trim()));
            } catch (NumberFormatException ex) {
                System.out.println("Input salah! Masukkan input yang benar.");
            }
        }

        String hasil = fungsiHitung(nilai);
        System.out.println(hasil);
        
    }

    private static String fungsiHitung(ArrayList<Integer> nilai) {

        // Deklarasikan variabel
        int jumlahNilaiA = 0;
        int jumlahNilaiB = 0;
        int jumlahNilaiC = 0;
        int jumlahNilaiD = 0;
        
        // Lakukan pengulangan untuk mengecek jumlah dan kategori nilai
        for (int n : nilai) {
            if (n >= 76 && n <= 100) {
                jumlahNilaiA++;
            } else if (n >= 51 && n <= 75) {
                jumlahNilaiB++;
            } else if (n >= 26 && n <= 50) {
                jumlahNilaiC++;
            } else if (n >= 0 && n <= 25) {
                jumlahNilaiD++;
            }
        }

        // Kembalikan output untuk ditampilkan
        return String.format("Nilai A: %d, Nilai B: %d, Nilai C: %d, Nilai D: %d.",
                jumlahNilaiA, jumlahNilaiB, jumlahNilaiC, jumlahNilaiD);

    }
}
