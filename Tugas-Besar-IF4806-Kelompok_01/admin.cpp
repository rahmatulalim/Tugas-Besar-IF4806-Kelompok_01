#include <iostream>
#include <string>
#include "admin.h"

using namespace std;

void adminMenu(ListPaper &LP, ListKeyword &LK, ListRelasi &LR) {
    int pilihan;
    string idPaper, judulPaper, namaKeyword, idKeyword, targetID, targetKW;
    int tahunPaper;
    addressPaper P, PrecP, targetP;
    addressKeyword K, PrecK, targetK;

    do {
        cout << "\n=============================================" << endl;
        cout << "           ADMIN DASHBOARD (PRIMITIF)        " << endl;
        cout << "=============================================" << endl;
        cout << "1.  Tambah Paper (First)" << endl;
        cout << "2.  Tambah Paper (Last)" << endl;
        cout << "3.  Tambah Paper (After)" << endl;
        cout << "4.  Hapus Paper (First)" << endl;
        cout << "5.  Hapus Paper (Last)" << endl;
        cout << "6.  Hapus Paper (After)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "7.  Tambah Keyword (First)" << endl;
        cout << "8.  Tambah Keyword (Last)" << endl;
        cout << "9.  Tambah Keyword (After)" << endl;
        cout << "10. Hapus Keyword (First)" << endl;
        cout << "11. Hapus Keyword (Last)" << endl;
        cout << "12. Hapus Keyword (After)" << endl;
        cout << "0.  Kembali" << endl;
        cout << "=============================================" << endl;
        cout << "Pilih: "; cin >> pilihan;

        switch (pilihan) {
            // --- MANAJEMEN PAPER (PARENT) ---
            case 1: // Insert First Paper
                cout << "ID: "; cin >> idPaper; cout << "Judul: "; cin >> judulPaper; cout << "Tahun: "; cin >> tahunPaper;
                insertFirstPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
                break;
            case 2: // Insert Last Paper
                cout << "ID: "; cin >> idPaper; cout << "Judul: "; cin >> judulPaper; cout << "Tahun: "; cin >> tahunPaper;
                insertLastPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
                break;
            case 3: // Insert After Paper
                cout << "Cari ID Paper sebelumnya: "; cin >> targetID;
                PrecP = findPaper(LP, targetID);
                if (PrecP != nullptr) {
                    cout << "ID Baru: "; cin >> idPaper; cout << "Judul: "; cin >> judulPaper; cout << "Tahun: "; cin >> tahunPaper;
                    insertAfterPaper(LP, PrecP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
                } else cout << "ID Target tidak ketemu!" << endl;
                break;
            case 4: // Delete First Paper
                deleteFirstPaper(LP, P);
                if (P != nullptr) { removeRelasiByPaper(LR, P->info.idPaper); delete P; }
                break;
            case 5: // Delete Last Paper
                deleteLastPaper(LP, P);
                if (P != nullptr) { removeRelasiByPaper(LR, P->info.idPaper); delete P; }
                break;
            case 6: // Delete After Paper
                cout << "Cari ID Paper sebelum yang akan dihapus: "; cin >> targetID;
                PrecP = findPaper(LP, targetID);
                deleteAfterPaper(LP, PrecP, P);
                if (P != nullptr) { removeRelasiByPaper(LR, P->info.idPaper); delete P; }
                break;

            // --- MANAJEMEN KEYWORD (CHILD) ---
            case 7: // Insert First Keyword
                cout << "Keyword: "; cin >> namaKeyword; cout << "ID: "; cin >> idKeyword;
                insertFirstKeyword(LK, alokasiKeyword({namaKeyword, idKeyword}));
                break;
            case 8: // Insert Last Keyword
                cout << "Keyword: "; cin >> namaKeyword; cout << "ID: "; cin >> idKeyword;
                insertLastKeyword(LK, alokasiKeyword({namaKeyword, idKeyword}));
                break;
            case 9: // Insert After Keyword
                cout << "Cari Nama Keyword sebelumnya: "; cin >> targetKW;
                PrecK = findKeyword(LK, targetKW);
                if (PrecK != nullptr) {
                    cout << "Keyword Baru: "; cin >> namaKeyword; cout << "ID: "; cin >> idKeyword;
                    insertAfterKeyword(LK, PrecK, alokasiKeyword({namaKeyword, idKeyword}));
                } else cout << "Keyword Target tidak ketemu!" << endl;
                break;
            case 10: // Delete First Keyword
                deleteFirstKeyword(LK, K);
                if (K != nullptr) { removeRelasiByKeyword(LR, K->info.namaKeyword); delete K; }
                break;
            case 11: // Delete Last Keyword
                deleteLastKeyword(LK, K);
                if (K != nullptr) { removeRelasiByKeyword(LR, K->info.namaKeyword); delete K; }
                break;
            case 12: // Delete After Keyword
                cout << "Cari Nama Keyword sebelum yang akan dihapus: "; cin >> targetKW;
                PrecK = findKeyword(LK, targetKW);
                deleteAfterKeyword(LK, PrecK, K);
                if (K != nullptr) { removeRelasiByKeyword(LR, K->info.namaKeyword); delete K; }
                break;
        }
    } while (pilihan != 0);
}
