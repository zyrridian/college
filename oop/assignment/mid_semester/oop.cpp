#include <iostream>

using namespace std;

class Titik {
private:
    int x;
    int y;

public:
    // Constructor
    Titik(int x, int y): x(x), y(y) {}

    // Getter untuk x
    int getX() const {
        return x;
    }

    // Getter untuk y
    int getY() const {
        return y;
    }

    // Menggeser titik berdasarkan koordinat x
    void geserX(int x) {
        this->x += x;
    }

    // Menggeser titik berdasarkan koordinat y
    void geserY(int y) {
        this->y += y;
    }

    // Menggeser titik berdasarkan koordinat x dan y
    void geserXY(int x, int y) {
        this->x += x;
        this->y += y;
    }
};

int main() {
    // Membuat objek titik dengan koordinat (5, 7)
    Titik titik(5, 7);

    // Menampilkan titik awal
    cout << "Titik awal: (" << titik.getX() << ", " << titik.getY() << ")\n";

    // Menggeser titik berdasarkan koordinat x sebesar 9
    titik.geserX(9);
    cout << "Setelah digeser berdasarkan x: (" << titik.getX() << ", " << titik.getY() << ")\n";

    // Menggeser titik berdasarkan koordinat y sebesar -4
    titik.geserY(-4);
    cout << "Setelah digeser berdasarkan y: (" << titik.getX() << ", " << titik.getY() << ")\n";

    // Menggeser titik berdasarkan koordinat x sebesar -10 dan y sebesar 2
    titik.geserXY(-10, 2);
    cout << "Setelah digeser berdasarkan x dan y: (" << titik.getX() << ", " << titik.getY() << ")\n";

    return 0;
}
