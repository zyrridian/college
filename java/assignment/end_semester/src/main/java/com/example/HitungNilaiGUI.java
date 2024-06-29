package com.example;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class HitungNilaiGUI extends JPanel {

    private JTextArea input;
    private JButton button;
    private JLabel hasil;
    
    private ArrayList<Integer> nilai = new ArrayList<>();

    public HitungNilaiGUI() {

        // Menentukan layout
        setLayout(new FlowLayout());

        // Menambahkan komponen
        input = new JTextArea(25, 30);
        button = new JButton("Hitung nilai");
        hasil = new JLabel("");

        add(new JLabel("Masukkan nilai (pisahkan dengan enter):"));
        add(new JScrollPane(input));
        add(button);
        add(hasil);

        // Tambahkan fungsi hitung
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                // Masukkan nilai ke string array
                String[] inputs = input.getText().split("\\n");
                nilai.clear();

                // Lakukan pengulangan pada string array untuk dimasukkan ke ArrayList pada parameter fungsiHitung()
                try {
                    for (String input : inputs) {
                        nilai.add(Integer.parseInt(input.trim()));
                    }
                    hasil.setText(fungsiHitung(nilai));
                } catch (NumberFormatException ex) {
                    hasil.setText("Input salah! Masukkan input yang benar.");
                }
            }
        });
        
    }

    private String fungsiHitung(ArrayList<Integer> nilai) {

        // Deklarasikan variabel
        int jumlahNilaiA = 0;
        int jumlahNilaiB = 0;
        int jumlahNilaiC = 0;
        int jumlahNilaiD = 0;

        // Lakukan pengulangan untuk mengecek jumlah dan kategori nilai
        for (int n : nilai) {
            if (n >= 0 && n <= 25) {
                jumlahNilaiD++;
            } else if (n >= 26 && n <= 50) {
                jumlahNilaiC++;
            } else if (n >= 51 && n <= 75) {
                jumlahNilaiB++;
            } else if (n >= 76 && n <= 100) {
                jumlahNilaiA++;
            }
        }

        // Kembalikan output untuk ditampilkan
        return String.format("Nilai A: %d, Nilai B: %d, Nilai C: %d, Nilai D: %d.",
                jumlahNilaiA, jumlahNilaiB, jumlahNilaiC, jumlahNilaiD);

    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Hitung Nilai Mahasiswa");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 500);
        frame.add(new HitungNilaiGUI());
        frame.setVisible(true);
    }

}
