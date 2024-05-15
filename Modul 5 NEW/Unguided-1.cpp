#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct MahasiswaITTP {
    string nim;
    int nilai;
    MahasiswaITTP(string nim, int nilai) : nim(nim), nilai(nilai) {}
};

struct HashNode {
    MahasiswaITTP *data;
    HashNode(MahasiswaITTP *data) : data(data) {}
    ~HashNode() {
        delete data;
    }
};

class HashTable {
private:
    const int TABLE_SIZE = 10;
    vector<HashNode *> table[10];

    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

public:
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto node : table[i]) {
                delete node;
            }
        }
    }

    void tambahMahasiswa(string nim, int nilai) {
        int index = hashFunc(nim);
        table[index].push_back(new HashNode(new MahasiswaITTP(nim, nilai)));
    }

    void hapusMahasiswa(string nim) {
        int index = hashFunc(nim);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if ((*it)->data->nim == nim) {
                delete *it;
                table[index].erase(it);
                return;
            }
        }
    }

    MahasiswaITTP *cariMahasiswaByNIM(string nim) {
        int index = hashFunc(nim);
        for (auto node : table[index]) {
            if (node->data->nim == nim) {
                return node->data;
            }
        }
        return nullptr;
    }

    vector<MahasiswaITTP *> cariMahasiswaByNilai() {
        vector<MahasiswaITTP *> result;
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto node : table[i]) {
                if (node->data->nilai >= 80 && node->data->nilai <= 90) {
                    result.push_back(node->data);
                }
            }
        }
        return result;
    }
};

int main() {
    HashTable hashTable;
    int choice;
    string nim;
    int nilai;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Hapus Mahasiswa\n";
        cout << "3. Cari Mahasiswa berdasarkan NIM\n";
        cout << "4. Cari Mahasiswa berdasarkan Nilai (80 - 90)\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Nilai: ";
            cin >> nilai;
            hashTable.tambahMahasiswa(nim, nilai);
            break;
        case 2:
            cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
            cin >> nim;
            hashTable.hapusMahasiswa(nim);
            break;
        case 3:
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> nim;
            {
                MahasiswaITTP *mahasiswa = hashTable.cariMahasiswaByNIM(nim);
                if (mahasiswa != nullptr) {
                    cout << "Mahasiswa ditemukan: NIM = " << mahasiswa->nim << ", Nilai = " << mahasiswa->nilai << endl;
                } else {
                    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
                }
            }
            break;
        case 4:
        {
            vector<MahasiswaITTP *> mahasiswas = hashTable.cariMahasiswaByNilai();
            if (mahasiswas.empty()) {
                cout << "Tidak ada mahasiswa dengan nilai antara 80 - 90." << endl;
            } else {
                cout << "Daftar mahasiswa dengan nilai antara 80 - 90:" << endl;
                for (MahasiswaITTP *mahasiswa : mahasiswas) {
                    cout << "NIM = " << mahasiswa->nim << ", Nilai = " << mahasiswa->nilai << endl;
                }
            }
        }
        break;
        case 5:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
            break;
        }
    } while (choice != 5);
    return 0;
}
