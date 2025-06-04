#include <iostream>
using namespace std;

// fungsi buat nukar huruf
void tukar(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

// fungsi buat nukar angka
void tukarAngka(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//insertion sort
void insertionSort(char data[], int panjang) {
    for (int i = 1; i < panjang; i++) {
        char key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

//merge sort
void merge(char data[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;
    char L[50], R[50];

    for (int i = 0; i < n1; i++) L[i] = data[kiri + i];
    for (int j = 0; j < n2; j++) R[j] = data[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) data[k++] = L[i++];
        else data[k++] = R[j++];
    }
    while (i < n1) data[k++] = L[i++];
    while (j < n2) data[k++] = R[j++];
}

void mergeSort(char data[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        mergeSort(data, kiri, tengah);
        mergeSort(data, tengah + 1, kanan);
        merge(data, kiri, tengah, kanan);
    }
}

//shell sort
void shellSort(char data[], int panjang) {
    for(int gap = panjang / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < panjang; i++) {
            char temp = data[i];
            int j;
            for(j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
    }
}

//quick sort
int partisi(int data[], int low, int high) {
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (data[j] < pivot) {
            i++;
            tukarAngka(data[i], data[j]);
        }
    }
    tukarAngka(data[i + 1], data[high]);
    return i + 1;
}

void quickSort(int data[], int low, int high) {
    if (low < high) {
        int pi = partisi(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

//bubble sort
void bubbleSort(int data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                tukarAngka(data[j], data[j + 1]);
            }
        }
    }
}

//selection sort
void selectionSort(int data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[minIdx]) {
                minIdx = j;
            }
        }
        tukarAngka(data[i], data[minIdx]);
    }
}

//nampilkan char array
void tampilkanChar(char data[], int panjang) {
    for (int i = 0; i < panjang; i++) {
        cout << data[i];
    }
    cout << endl;
}

//nampilkan angka array
void tampilkanInt(int data[], int panjang) {
    for (int i = 0; i < panjang; i++) {
        cout << data[i];
    }
    cout << endl;
}

int main() {
    char nama[] = "Nabilla Putri Nugraha";
    char namaBersih[100];
    int panjangNama = 0;

    //hapus spasi dari nama
     for (int i = 0; nama[i] != '\0'; i++) {
        if (nama[i] != ' ') {
             namaBersih[panjangNama++] = nama[i];
        }
     }

     char inputNIM[] = "2410817220009";
     int nim[100], panjangNIM = 0;
     for (int i = 0; inputNIM[i] != '\0'; i++) {
        nim[panjangNIM++] = inputNIM[i] - '0';
     }

     int pilihan;
     do {
        cout << "-------\n";
        cout << "Sorting\n";
        cout << "-------\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Shell Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Bubble Sort\n";
        cout << "6. Selection Sort\n";
        cout << "7. Exit\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            char temp[100];
            cout << "Data sebelum diurutkan: " << nama << endl;
            for (int i = 0; i < panjangNama; i++) temp[i] = namaBersih[i];
            insertionSort(temp, panjangNama);
            cout << "Hasil insertion sort: ";
            tampilkanChar(temp, panjangNama);
        }
        else if (pilihan == 2) {
            char temp[100];
            cout << "Data sebelum diurutkan: " << nama << endl;
            for (int i = 0; i < panjangNama; i++) temp[i] = namaBersih[i];
            mergeSort(temp, 0, panjangNama - 1);
            cout << "Hasil merge sort: ";
            tampilkanChar(temp, panjangNama);
        }
        else if (pilihan == 3) {
            char temp[100];
            cout << "Data sebelum diurutkan: " << nama << endl;
            for (int  = 0; i < panjangNama; i++) temp[i] = namaBersih[i];
            shellSort(temp, panjangNama);
            cout << "Hasil shell sort: ";
            tampilkanChar(temp, panjangNama);
        }
        else if (pilihan == 4) {
            int temp[100];
            cout << "Data sebelum diurutkan: ";
            tampilkanInt(nim, panjangNIM);
            for (int i = 0; i < panjangNIM; i++) temp[i] = nim[i];
            quickSort(temp, 0, panjangNIM - 1);
            cout << "Hasil quick sort: ";
            tampilkanInt(temp, panjangNIM);
        }
        else if (pilihan == 5) {
            int temp[100];
            cout << "Data sebelum diurutkan: ";
            tampilkanInt(nim, panjangNIM);
            for (int i = 0; i < panjangNIM; i++) temp[i] = nim[i];
            bubbleSort(temp, panjangNIM);
            cout << "Hasil bubble sort: ";
            tampilkanInt(temp, panjangNIM);
        }
        else if (pilihan == 6) {
            int temp[100];
            cout << "Data sebelum diurutkan: ";
            tampilkanInt(nim, panjangNIM);
            for (int i = 0; i < panjangNIM; i++) temp[i] = nim[i];
            selectionSort(temp, panjangNIM);
            cout << "Hasil selection sort: ";
            tampilkanInt(temp, panjangNIM);
        }
        else if (pilihan == 7) {
            cout << "Timakasiiii sudah mencobaa\n";
        }
        else {
            cout << "Pilihannya salahh harus 1-7 timakasii\n";
        }
     } while (pilihan != 7);
     return 0;
}
