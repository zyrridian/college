#include <iostream>
#include "coordinate.h"

using namespace std;

int main() {

    // Membuat titik dengan koordinat (5, 7)
    Titik titik;
    titik.x = 5;
    titik.y = 7;

    // Menampilkan titik awal
    cout << "Titik awal: (" << titik.x << ", " << titik.y << ")\n";

    // Menggeser titik berdasarkan koordinat x sebesar 9
    geserX(titik, 9);
    cout << "Setelah digeser berdasarkan x: (" << titik.x << ", " << titik.y << ")\n";

    // Menggeser titik berdasarkan koordinat y sebesar -4
    geserY(titik, -4);
    cout << "Setelah digeser berdasarkan y: (" << titik.x << ", " << titik.y << ")\n";

    // Menggeser titik berdasarkan koordinat x sebesar -10 dan y sebesar 2
    geserXY(titik, -10, 2);
    cout << "Setelah digeser berdasarkan x dan y: (" << titik.x << ", " << titik.y << ")\n";

    return 0;

}
