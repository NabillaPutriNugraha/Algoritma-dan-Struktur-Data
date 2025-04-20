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
int PIL,F,R;
char PILIHAN [1], HURUF;
char Q[n];
int main ()
{
    Inisialisasi();
    do
    {
        cout << "QUEUE" << endl;
        cout << "===============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL)
        {
        case 1  :
            INSERT ();
            break;
        case 2:
            DELETE ();
            break;
        case 3:
            CETAKLAYAR ();
            break;
        default :
            cout << "TERIMA KASIH" << endl;
            break;
        }
        cout << "press any key to continue" << endl;
        getch();
        system("cls");
    }
    while (PIL < 4);
}