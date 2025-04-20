#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10
using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
void RESET();

int PIL, F, R;
char PILIHAN[1], HURUF;
char Q[n];

// fungsi buat ngeinisialisasikan queue
void Inisialisasi() {
    F = -1;
    R = -1;
}

// fungsi buat nambah elemen ke queue
void INSERT() {
    if (R == n - 1) {
        cout << " Queue udah penuhh\n";
    }
    else {
        cout << "Masukkan satu huruf: ";
        cin >> HURUF;

        if (F == -1) F = 0;
        R++;
        Q[R] = HURUF;
        cout << "Data " << HURUF << " dimasukkan ke queue\n";
    }
}

void DELETE() {
    if (F == -1 || F > R) {
        cout << "Queue nya kosong\n";
    }
    else {
        cout << "Data " << Q[F] << " dihapus dari queue\n";
        F++;
        if (F > R) {
            RESET(); //karena queue jd kosong, reset kembali
        }
    }
}

// fungsi buat nyetak isi queue
void CETAKLAYAR() {
    if (F == -1 || F > R) {
        cout << "Queue nya kosong\n";
    }
    else {
        cout << "Isi Queue: \n";
        for (int i = F; i <= R; i++) {
            cout << "Queue[" << i << "] = " << Q[i] << endl;
        }
    }
}

// fungsi buta ngereset queue
void RESET() {
    F = -1;
    R = -1;
}

int main() {
    Inisialisasi();
    do {
        cout << "QUEUE" << endl;
        cout << "===============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            default:
                cout << "TERIMA KASIHH" << endl;
                break;
        }
        cout << "Press any key to continue..." << endl;
        getch(); // cuman berfungsi di windows
        system("cls"); //untuk membersihkan layar
    }
    while (PIL < 4);

    return 0;
}
