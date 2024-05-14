#include <iostream>

using namespace std;
int main ()
{

    int maks, a, i = 1, lokasi; //deklarasi variabel
    cout << "Masukkan panjang array: "; 
    cin >> a;
    int array[a]; //deklarasi array
    cout << "Masukkan " << a << " angka: " << endl; //input array
    for (int i = 0; i < a; i++) //perulangan untuk input array
    {
        cout << "Array ke-" << i << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (int i = 0; i < a; i++) //perulangan untuk mencari nilai maksimum
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " yang terdapat pada array ke-" << lokasi << endl;
}