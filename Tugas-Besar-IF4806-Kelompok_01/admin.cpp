#include <iostream>
#include <string>
#include "admin.h"

using namespace std;

void adminMenu(ListPaper &LP, ListKeyword &LK, ListRelasi &LR) {
    int pilihan = -1;   // WAJIB diinisialisasi
    string idPaper, judulPaper, namaKeyword, targetID, targetKW;
    int tahunPaper;
    addressPaper P, PrecP;
    addressKeyword K, PrecK;

    while (pilihan != 0) {
        cout << "===========================================" << endl;
        cout << "          ADMIN DASHBOARD (PRIMITIF)       " << endl;
        cout << "===========================================" << endl;
        cout << "1.  Tambah Paper (First)" << endl;
        cout << "2.  Tambah Paper (Last)" << endl;
        cout << "3.  Tambah Paper (After)" << endl;
        cout << "4.  Hapus Paper (First)" << endl;
        cout << "5.  Hapus Paper (Last)" << endl;
        cout << "6.  Hapus Paper (After)" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "7.  Tambah Keyword (First)" << endl;
        cout << "8.  Tambah Keyword (Last)" << endl;
        cout << "9.  Tambah Keyword (After)" << endl;
        cout << "10. Hapus Keyword (First)" << endl;
        cout << "11. Hapus Keyword (Last)" << endl;
        cout << "12. Hapus Keyword (After)" << endl;
        cout << "0.  Kembali" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {

        // ===== PAPER =====
        case 1:
            cout << "ID    : "; cin >> idPaper;
            cout << "Judul : "; cin >> judulPaper;
            cout << "Tahun : "; cin >> tahunPaper;
            insertFirstPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
            break;

        case 2:
            cout << "ID    : "; cin >> idPaper;
            cout << "Judul : "; cin >> judulPaper;
            cout << "Tahun : "; cin >> tahunPaper;
            insertLastPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
            break;

        case 3:
            cout << "Cari ID Paper sebelumnya: ";
            cin >> targetID;
            PrecP = findPaper(LP, targetID);
            if (PrecP != nullptr) {
                cout << "ID Baru    : "; cin >> idPaper;
                cout << "Judul Baru : "; cin >> judulPaper;
                cout << "Tahun      : "; cin >> tahunPaper;
                insertAfterPaper(LP, PrecP,
                    alokasiPaper({judulPaper, idPaper, tahunPaper}));
            } else {
                cout << "ID tidak ditemukan!" << endl;
            }
            break;

        case 4:
            deleteFirstPaper(LP, P);
            if (P != nullptr) {
                removeRelasiByPaper(LR, P->info.idPaper);
                delete P;
            }
            break;

        case 5:
            deleteLastPaper(LP, P);
            if (P != nullptr) {
                removeRelasiByPaper(LR, P->info.idPaper);
                delete P;
            }
            break;

        case 6:
            cout << "Cari ID Paper sebelumnya: ";
            cin >> targetID;
            PrecP = findPaper(LP, targetID);
            deleteAfterPaper(LP, PrecP, P);
            if (P != nullptr) {
                removeRelasiByPaper(LR, P->info.idPaper);
                delete P;
            }
            break;

        // ===== KEYWORD (TANPA ID) =====
        case 7:
            cout << "Keyword: ";
            cin >> namaKeyword;
            insertFirstKeyword(LK, alokasiKeyword({namaKeyword}));
            break;

        case 8:
            cout << "Keyword: ";
            cin >> namaKeyword;
            insertLastKeyword(LK, alokasiKeyword({namaKeyword}));
            break;

        case 9:
            cout << "Cari Keyword sebelumnya: ";
            cin >> targetKW;
            PrecK = findKeyword(LK, targetKW);
            if (PrecK != nullptr) {
                cout << "Keyword Baru: ";
                cin >> namaKeyword;
                insertAfterKeyword(LK, PrecK, alokasiKeyword({namaKeyword}));
            } else {
                cout << "Keyword tidak ditemukan!" << endl;
            }
            break;

        case 10:
            deleteFirstKeyword(LK, K);
            if (K != nullptr) {
                removeRelasiByKeyword(LR, K->info.namaKeyword);
                delete K;
            }
            break;

        case 11:
            deleteLastKeyword(LK, K);
            if (K != nullptr) {
                removeRelasiByKeyword(LR, K->info.namaKeyword);
                delete K;
            }
            break;

        case 12:
            cout << "Cari Keyword sebelumnya: ";
            cin >> targetKW;
            PrecK = findKeyword(LK, targetKW);
            deleteAfterKeyword(LK, PrecK, K);
            if (K != nullptr) {
                removeRelasiByKeyword(LR, K->info.namaKeyword);
                delete K;
            }
            break;

        case 0:
            cout << "Kembali ke menu utama..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }
    }
}
