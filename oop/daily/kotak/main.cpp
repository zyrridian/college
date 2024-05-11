#include <iostream>
using namespace std;

class segiempat {
    private:
        int panjang;
        int lebar;

    public:
        void setpl(int p,int l) {
            panjang = p;
            lebar = l;
        }

        int luas(void) {
            return (panjang*lebar);
        }

        int keliling(void)  {
            return (2*(panjang+lebar));
        }
};
int main () {
    segiempat A;
    A.setpl(3,4);
    cout << "\nLuas : " << A.luas();
    cout << "\nKeliling : " << A.keliling();
    return 0;
}