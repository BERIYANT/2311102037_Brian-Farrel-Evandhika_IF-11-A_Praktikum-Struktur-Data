#include <iostream> // Include library iostream untuk menggunakan fungsi input output

using namespace std; // Menggunakan namespace std untuk mempersingkat penulisan kode    

int main() 
{
    // Deklarasi variabel maks untuk menyimpan panjang array
    int maks; 
    cout << "Masukkan panjang elemen array: "; 
    cin >> maks; 
    int angka [maks];  // Deklarasi array dengan panjang maks
    
    // Meminta pengguna untuk memasukkan data array
    cout << "Masukkan angka sepanjang " << maks << " elemen: ";
    for (int i = 0; i < maks; ++i) 
    {
        cin >> angka[i];
    }
    
    // Menampilkan data array
    cout << "Data array: ";
    for (int i = 0; i < maks; ++i) 
    {
        cout << angka[i] << " ";
    }
    cout << endl;
    
    // Menampilkan nomor genap
    cout << "Nomor Genap: ";
    for (int i = 0; i < maks; ++i) 
    {
        if (angka[i] % 2 == 0) 
        {
            cout << angka[i] << ", ";
        }
    }
    cout << endl;
    
    // Menampilkan nomor ganjil
    cout << "Nomor Ganjil: ";
    for (int i = 0; i < maks; ++i) 
    {
        if (angka[i] % 2 != 0) 
        {
            cout << angka[i] << ", ";
        }
    }
    cout << endl;

    return 0;
}