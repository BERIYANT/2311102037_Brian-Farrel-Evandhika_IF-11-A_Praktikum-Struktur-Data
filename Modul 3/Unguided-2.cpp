#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string produk;
    int harga;
    Node *prev;
    Node *next;
};

class DoublyLinkedList {
public:
    Node *head;
    Node *tail;
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(const string& produk, int harga) {
        Node *newNode = new Node;
        newNode->produk = produk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void insertAt(const string& produk, int harga, int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih dari 0" << endl;
            return;
        }
        if (posisi == 1 || head == nullptr) {
            push(produk, harga);
            return;
        }

        Node *current = head;
        int count = 1;
        while (count < posisi - 1 && current->next != nullptr) {
            current = current->next;
            count++;
        }

        Node *newNode = new Node;
        newNode->produk = produk;
        newNode->harga = harga;
        newNode->prev = current;
        newNode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(const string& oldProduk, const string& newProduk, int newHarga) {
        Node *current = head;
        while (current != nullptr) {
            if (current->produk == oldProduk) {
                current->produk = newProduk;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAt(int posisi) {
        if (posisi <= 0 || head == nullptr) {
            cout << "Posisi tidak valid atau list kosong" << endl;
            return;
        }

        Node *current = head;
        int count = 1;
        while (count < posisi && current != nullptr) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Posisi melebihi ukuran list" << endl;
            return;
        }

        if (current == head) {
            pop();
            return;
        }

        if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            delete current;
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    void deleteAll() {
        Node *current = head;
        while (current != nullptr) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        cout << "Nama Produk\tHarga" << endl;
        Node *current = head;
        while (current != nullptr) {
            cout << current->produk << "\t\t" << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        int choice;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string produk;
                int harga;
                cout << "Masukkan nama produk: ";
                cin >> produk;
                cout << "Masukkan harga: ";
                cin >> harga;
                list.push(produk, harga);
                cout << "Data berhasil ditambahkan" << endl;
                break;
            }
            case 2: {
                list.pop();
                cout << "Data terakhir berhasil dihapus" << endl;
                break;
            }
            case 3: {
                string oldProduk, newProduk;
                int newHarga;
                cout << "Masukkan nama produk yang akan diupdate: ";
                cin >> oldProduk;
                cout << "Masukkan nama produk baru: ";
                cin >> newProduk;
                cout << "Masukkan harga baru: ";
                cin >> newHarga;
                bool updated = list.update(oldProduk, newProduk, newHarga);
                if (updated) {
                    cout << "Data berhasil diupdate" << endl;
                } else {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                string produk;
                int harga, posisi;
                cout << "Masukkan nama produk: ";
                cin >> produk;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                list.insertAt(produk, harga, posisi);
                cout << "Data berhasil ditambahkan di urutan " << posisi << endl;
                break;
            }
            case 5: {
                int posisi;
                cout << "Masukkan posisi data yang ingin dihapus: ";
                cin >> posisi;
                list.deleteAt(posisi);
                cout << "Data pada posisi " << posisi << " berhasil dihapus" << endl;
                break;
            }
            case 6: {
                list.deleteAll();
                cout << "Semua data berhasil dihapus" << endl;
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }

    return 0;
}
