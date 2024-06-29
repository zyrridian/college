#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>

using namespace std;

class Circle {
protected:
    float x, y; // Titik pusat
    float radius; // Jari-jari

public:
    // Konstruktor
    Circle(float x = 0, float y = 0, float radius = 1) : x(x), y(y), radius(radius) {}

    // Metode untuk menggeser lingkaran
    void geserKiri(float jarak) { x -= jarak; }
    void geserKanan(float jarak) { x += jarak; }
    void geserAtas(float jarak) { y += jarak; }
    void geserBawah(float jarak) { y -= jarak; }

    // Metode untuk mengubah ukuran lingkaran
    void perbesar(float num) { radius += num; }
    void perkecil(float num) { radius -= num; }

    // Metode untuk menghitung luas
    float luas() const { return M_PI * radius * radius; }

    // Metode untuk menghitung keliling
    float keliling() const { return 2 * M_PI * radius; }

    // Metode untuk menampilkan informasi lingkaran
    void tampilkan() const {
        cout << "Titik Pusat: (" << x << ", " << y << ")\n";
        cout << "Jari-jari: " << radius << "\n";
        cout << "Luas: " << luas() << "\n";
        cout << "Keliling: " << keliling() << "\n";
    }
};

class Cylinder : public Circle {
private:
    float tinggi; // Tinggi silinder

public:
    // Konstruktor
    Cylinder(float x = 0, float y = 0, float radius = 1, float tinggi = 1) : Circle(x, y, radius), tinggi(tinggi) {}

	// Getter untuk tinggi
    float getTinggi() const { return tinggi; }

    // Metode untuk mengubah tinggi silinder
    void setTinggi(float tinggi) { this->tinggi = tinggi; }
    
    // Metode untuk menghitung luas permukaan
    float luasPermukaan() const { return 2 * M_PI * radius * (radius + tinggi); }

    // Metode untuk menghitung volume
    float volume() const { return M_PI * radius * radius * tinggi; }

    // Metode untuk menampilkan informasi silinder
    void tampilkan() const {
        Circle::tampilkan();
        cout << "Tinggi: " << tinggi << "\n";
        cout << "Luas Permukaan: " << luasPermukaan() << "\n";
        cout << "Volume: " << volume() << "\n";
    }
};

#endif // CIRCLE_H
