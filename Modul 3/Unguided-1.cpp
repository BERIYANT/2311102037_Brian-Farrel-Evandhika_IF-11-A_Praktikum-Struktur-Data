#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
    string nama;
    int umur;
    Node* next;
};

Node* head;
Node* tail;

void init() {
    head = NULL;
    tail = NULL;
}

bool isEmpty() {
    return head == NULL;
}

int hitungList() {
    Node* hitung = head;
    int jumlah = 0;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

void insertDepan(string nama, int umur) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string nama, int umur) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void insertTengah(string nama, int umur, int posisi) {
    if (posisi < 2 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        Node* baru = new Node();
        baru->nama = nama;
        baru->umur = umur;

        Node* bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusDepan() {
    if (!isEmpty()) {
        Node* hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

void hapusBelakang() {
    if (!isEmpty()) {
        Node* hapus = tail;
        if (head != tail) {
            Node* bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

void hapusTengah(int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            hapusDepan();
        } else {
            Node* hapus;
            Node* bantu = head;
            int nomor = 1;

            while (nomor < posisi - 1) {
                bantu = bantu->next;
                nomor++;
            }

            hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

void ubahTengah(string nama, int umur, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else {
            Node* bantu = head;
            int nomor = 1;

            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }

            bantu->nama = nama;
            bantu->umur = umur;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

void clearList() {
    Node* hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

void tampil() {
    Node* bantu = head;
    cout << left << setw(20) << "Nama" << setw(20) << "Umur" << endl;
    if (!isEmpty()) {
        while (bantu != NULL){
            cout << left << setw(20) << bantu->nama << setw(20) << bantu->umur << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();

    // Tampilan awal
    insertDepan("Karin", 18);
    insertDepan("Hoshino", 18);
    insertDepan("Akechi", 20);
    insertDepan("Yusuke", 19);
    insertDepan("Michael", 18);
    insertDepan("Jane", 20);
    insertDepan("John", 19);
    tampil();

    while (true) {
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Belakang" << endl;
        cout << "6. Hapus Tengah" << endl;
        cout << "7. Ubah Tengah" << endl;
        cout << "8. Hapus Semua" << endl;
        cout << "9. Tampilkan Data" << endl;
        cout << "10. Exit" << endl;
        int choice;
        cout << "Masukkan pilihan: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string nama;
                int umur;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan umur: ";
                cin >> umur;
                insertDepan(nama, umur);
                cout << "Data berhasil ditambahkan" << endl;
                break;
            }
            case 2: {
                string nama;
                int umur;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan umur: ";
                cin >> umur;
                insertBelakang(nama, umur);
                cout << "Data berhasil ditambahkan" << endl;
                break;
            }
            case 3: {
                string nama;
                int umur, posisi;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan umur: ";
                cin >> umur;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                insertTengah(nama, umur, posisi);
                cout << "Data berhasil ditambahkan" << endl;
                break;
            }
            case 4: {
                hapusDepan();
                cout << "Data berhasil dihapus" << endl;
                break;
            }
            case 5: {
                hapusBelakang();
                cout << "Data berhasil dihapus" << endl;
                break;
            }
            case 6: {
                int posisi;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                hapusTengah(posisi);
                cout << "Data berhasil dihapus" << endl;
                break;
            }
            case 7: {
                string nama;
                int umur, posisi;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan umur: ";
                cin >> umur;
                ubahTengah(nama, umur, posisi);
                cout << "Data berhasil diubah" << endl;
                break;
            }
            case 8: {
                clearList();
                break;
            }
            case 9: {
                tampil();
                break;
            }
            case 10: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak sesuai!" << endl;
                break;
            }
        }
    }
    return 0;
}