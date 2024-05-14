#include <iostream> // Include library iostream untuk menggunakan fungsi input output
using namespace std; // Menggunakan namespace std untuk mempersingkat penulisan kode    

int main() 
{

    int jml, maks, min, sum;    // Deklarasi variabel jml, maks, min, sum
    float avg; // Deklarasi variabel avg
    cout << "Masukkan panjang elemen array: "; 
    cin >> jml; 
    int angka [jml];  // Deklarasi array dengan panjang jml
    
    // Meminta pengguna untuk memasukkan data array
    cout << "Masukkan angka sepanjang " << jml << " elemen: ";
    for (int i = 0; i < jml; ++i) 
    {
        cin >> angka[i];
    }
    
    // Menampilkan data array
    cout << "Data array: ";
    for (int i = 0; i < jml; ++i) 
    {
        cout << angka[i] << " ";
    }
    cout << endl;
    
    // menampilkan nilai maksimum
    maks = angka[0];
    for (int i = 0; i < jml; i++) 
    {
        if (angka[i] > maks) 
        {
            maks = angka[i];
        }
    }
    cout << "Nilai maksimum adalah " << maks << endl;

    // menampilkan nilai minimum
    min = angka[0];
    for (int i = 0; i < jml; i++) 
    {
        if (angka[i] < min) 
        {
            min = angka[i];
        }
    }
    cout << "Nilai minimum adalah " << min << endl;

    // menampilkan nilai rata-rata
    sum = 0;
    for (int i = 0; i < jml; i++) 
    {
        sum += angka[i];
    }
    avg = (float) sum / jml;
    cout << "Nilai rata-rata adalah " << avg << endl;

    return 0;
}