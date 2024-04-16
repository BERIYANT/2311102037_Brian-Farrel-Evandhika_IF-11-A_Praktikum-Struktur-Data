#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
    string nama23;
    long long int nim23;
    Node *next;
};

Node *head;
Node *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

bool isEmpty()
{
    return head == NULL;
}

void insertDepan(string nama, long long int nim)
{
    Node *baru = new Node();
    baru->nama23 = nama;
    baru->nim23 = nim;
    baru->next = NULL;

    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string nama, long long int nim)
{
    Node *baru = new Node();
    baru->nama23 = nama;
    baru->nim23 = nim;
    baru->next = NULL;

    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

int hitungList()
{
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

void insertTengah(string nama, long long int nim, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru = new Node();
        baru->nama23 = nama;
        baru->nim23 = nim;

        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusDepan()
{
    if (!isEmpty())
    {
        Node *hapus = head;
        if (head->next != NULL)
        {
            head = head->next;
        }
        else
        {
            head = tail = NULL;
        }
        delete hapus;
    }
    else
    {
        cout << "Linked list masih kosong" << endl;
    }
}

void hapusBelakang()
{
    if (!isEmpty())
    {
        Node *hapus = tail;
        if (head != tail)
        {
            Node *bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        else
        {
            head = tail = NULL;
        }
        delete hapus;
    }
    else
    {
        cout << "Linked list masih kosong" << endl;
    }
}

void hapusTengah(int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *hapus, *bantu, *sebelum;
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

void ubahDepan(string nama, long long int nim)
{
    if (!isEmpty())
    {
        head->nama23 = nama;
        head->nim23 = nim;
    }
    else
    {
        cout << "Linked list masih kosong" << endl;
    }
}

void ubahTengah(string nama, long long int nim, int posisi)
{
    if (!isEmpty())
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            Node *bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->nama23 = nama;
            bantu->nim23 = nim;
        }
    }
    else
    {
        cout << "Linked list masih kosong" << endl;
    }
}

void ubahBelakang(string nama, long long int nim)
{
    if (!isEmpty())
    {
        tail->nama23 = nama;
        tail->nim23 = nim;
    }
    else
    {
        cout << "Linked list masih kosong" << endl;
    }
}

void clearList()
{
    Node *bantu = head;
    while (bantu != NULL)
    {
        Node *hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

void tampilList()
{
    Node *bantu = head;
    cout << "============ TAMPILKAN LIST ============" << endl;
    cout << "----------------------------------------" << endl;
    cout << left << setw(20) << "| Nama"
         << "| NIM" << endl;
    cout << "----------------------------------------" << endl;
    while (bantu != NULL)
    {
        cout << left << setw(20) << "| " + bantu->nama23 << "| " << bantu->nim23 << endl;
        bantu = bantu->next;
    }
    cout << "----------------------------------------" << endl;
}

int main()
{
    string nama;
    long long int nim;
    int posisi;
    init();

    cout << "========== PROGRAM SINGLE LINKED LIST NON-CIRCULAR ==========" << endl;
    while (true)
    {
        cout << "1.  Tambah Depan" << endl;
        cout << "2.  Tambah Belakang" << endl;
        cout << "3.  Tambah Tengah" << endl;
        cout << "4.  Ubah Depan" << endl;
        cout << "5.  Ubah Belakang" << endl;
        cout << "6.  Ubah Tengah" << endl;
        cout << "7.  Hapus Depan" << endl;
        cout << "8.  Hapus Belakang" << endl;
        cout << "9.  Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        int pilihan;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "========== TAMBAH DEPAN ==========" << endl;
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            insertDepan(nama, nim);
            cout << "Data [" << nama << "] berhasil ditambahkan di depan! " << endl;
            break;
        case 2:
            cout << "========== TAMBAH BELAKANG ==========" << endl;
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            insertBelakang(nama, nim);
            cout << "Data [" << nama << "] berhasil ditambahkan di belakang! " << endl;
            break;
        case 3:
            cout << "========== TAMBAH TENGAH ==========" << endl;
            cout << "Masukkan posisi: ";
            cin >> posisi;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            insertTengah(nama, nim, posisi);
            cout << "Data [" << nama << "] berhasil ditambahkan di posisi ke-" << posisi << "!" << endl;
            break;
        case 4:
            cout << "========== UBAH DEPAN ==========" << endl;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            ubahDepan(nama, nim);
            cout << "Data depan berhasil diubah! " << endl;
            break;
        case 5:
            cout << "========== UBAH BELAKANG ==========" << endl;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            ubahBelakang(nama, nim);
            cout << "Data belakang berhasil diubah! " << endl;
            break;
        case 6:
            cout << "========== UBAH TENGAH ==========" << endl;
            cout << "Masukkan posisi: ";
            cin >> posisi;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            ubahTengah(nama, nim, posisi);
            cout << "Data di posisi ke-" << posisi << " berhasil diubah! " << endl;
            break;
        case 7:
            cout << "========== HAPUS DEPAN ==========" << endl;
            hapusDepan();
            cout << "Data depan berhasil dihapus! " << endl;
            break;
        case 8:
            cout << "========== HAPUS BELAKANG ==========" << endl;
            hapusBelakang();
            cout << "Data belakang berhasil dihapus! " << endl;
            break;
        case 9:
            cout << "========== HAPUS TENGAH ==========" << endl;
            cout << "Masukkan posisi: ";
            cin >> posisi;
            hapusTengah(posisi);
            cout << "Data di posisi ke-" << posisi << " berhasil dihapus! " << endl;
            break;
        case 10:
            cout << "========== HAPUS LIST ==========" << endl;
            clearList();
            cout << "Semua data berhasil dihapus! " << endl;
            break;
        case 11:
            cout << "========== TAMPILKAN LIST ==========" << endl;
            tampilList();
            break;
        case 0:
            cout << "Program selesai!" << endl;
            return 0;
        default:
            cout << "Pilihan tidak tersedia!" << endl;
            break;
        }
    }
    return 0;
}
