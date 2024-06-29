#include <iostream>
#include "circle.h"

using namespace std;

void menu() {
    cout << "Menu:\n";
    cout << "1. Tampilkan informasi lingkaran\n";
    cout << "2. Geser lingkaran\n";
    cout << "3. Ubah ukuran lingkaran\n";
    cout << "4. Tampilkan informasi silinder\n";
    cout << "5. Ubah tinggi silinder\n";
    cout << "6. Keluar\n";
    cout << "Pilih opsi: ";
}

int main() {
    Circle circle(0, 0, 5);
    Cylinder cylinder(0, 0, 5, 10);
    int pilihan;

    do {
        menu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Informasi Lingkaran:\n";
                circle.tampilkan();
                break;
            case 2: {
                int arah;
                float jarak;
                cout << "Pilih arah (1: Kiri, 2: Kanan, 3: Atas, 4: Bawah): ";
                cin >> arah;
                cout << "Masukkan jarak: ";
                cin >> jarak;
                if (arah == 1) circle.geserKiri(jarak);
                else if (arah == 2) circle.geserKanan(jarak);
                else if (arah == 3) circle.geserAtas(jarak);
                else if (arah == 4) circle.geserBawah(jarak);
                else cout << "Arah tidak valid!\n";
                break;
            }
            case 3: {
                int operasi;
                float num;
                cout << "Pilih operasi (1: Perbesar, 2: Perkecil): ";
                cin >> operasi;
                cout << "Masukkan faktor: ";
                cin >> num;
                if (operasi == 1) circle.perbesar(num);
                else if (operasi == 2) circle.perkecil(num);
                else cout << "Operasi tidak valid!\n";
                break;
            }
            case 4:
                cout << "Informasi Silinder:\n";
                cylinder.tampilkan();
                break;
            case 5: {
                float tinggi_baru;
                cout << "Masukkan tinggi baru untuk silinder: ";
                cin >> tinggi_baru;
                cylinder.setTinggi(tinggi_baru);
                break;
            }
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Opsi tidak valid! Coba lagi.\n";
        }
        cout << "\n";
    } while (pilihan != 6);

    return 0;
}
