#include <iostream>
using namespace std;

const int maks = 10; // untuk batas maksimum stack

struct stack {
    int atas;
    int data[maks];
} Tumpuk;

// fungsi untuk cek stack kosong atau tidaa
int kosong() {
    if (Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

// fungsi untuk cek stack penuh atau tidaa
int penuh() {
    if (Tumpuk.atas == maks - 1)
        return 1;
    else
        return 0;
}

// fungsi untuk menambah data ke stack
void input(int data) {
    if (kosong() == 1) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack\n";
    }
    else if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack\n";
    }
    else
    cout << "Tumpukkan Penuh \n";
}

// fungsi untuk ngapus data dari stack
void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil : " << Tumpuk.data[Tumpuk.atas] << endl;
        Tumpuk.atas--;
    }
    else
        cout << "Data Kosong\n";
}

//fungsi buat nampilin isi stack
void tampil() {
    if(kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = "
                 << Tumpuk.data[i] << endl;
        }
    }
    else
        cout << "Tumpukan Kosong\n";
}

//fungsi untuk membersihkan stack
void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukam Kosong!\n";
}

// fungsi utamanya
int main() {
    int pilihan, nilai;
    Tumpuk.atas = -1;

    do {
        cout << "\n STACK \n";
        cout << "===============\n";
        cout << "1. INSERT\n";
        cout << "2. DELETE\n";
        cout << "3. CETAK STACK\n";
        cout << "4. QUIT\n";
        cout << "PILIHAN : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukin Data: ";
                cin >> nilai;
                input(nilai);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                cout << "Keluar dari program. Timakasiii\n";
                break;
            default:
                cout << "Pilihan tidak benar!\n";
        }
    }
    while(pilihan != 4);
    return 0;
}