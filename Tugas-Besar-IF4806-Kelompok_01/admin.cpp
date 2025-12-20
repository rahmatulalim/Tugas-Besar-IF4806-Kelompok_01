#include <iostream>
#include <string>
#include <cstdlib>
#include "admin.h"

using namespace std;

void adminMenu(ListPaper &LP, ListKeyword &LK) {
    int pilihan = -1;
    string idPaper, judulPaper, namaKeyword, targetID, targetKW;
    int tahunPaper;
    addressPaper P, PrecP;
    addressKeyword K, PrecK;

    while (pilihan != 0) {
        system("cls");
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
        case 1:
            cout << "ID    : "; cin >> idPaper;
            cout << "Judul : "; cin >> judulPaper;
            cout << "Tahun : "; cin >> tahunPaper;
            insertFirstPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
            system("pause");
            break;
        case 2:
            cout << "ID    : "; cin >> idPaper;
            cout << "Judul : "; cin >> judulPaper;
            cout << "Tahun : "; cin >> tahunPaper;
            insertLastPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
            system("pause");
            break;
        case 3:
            cout << "Cari ID Paper sebelumnya: "; cin >> targetID;
            PrecP = findPaper(LP, targetID);
            if (PrecP != nullptr) {
                cout << "ID Baru    : "; cin >> idPaper;
                cout << "Judul Baru : "; cin >> judulPaper;
                cout << "Tahun      : "; cin >> tahunPaper;
                insertAfterPaper(LP, PrecP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
            } else cout << "ID tidak ditemukan!" << endl;
            system("pause");
            break;
        case 4:
            deleteFirstPaper(LP, P);
            cout << ">> Berhasil dihapus." << endl;
            system("pause");
            break;
        case 5:
            deleteLastPaper(LP, P);
            cout << ">> Berhasil dihapus." << endl;
            system("pause");
            break;
        case 6:
            cout << "Cari ID Paper sebelumnya: "; cin >> targetID;
            PrecP = findPaper(LP, targetID);
            deleteAfterPaper(LP, PrecP, P);
            cout << ">> Berhasil dihapus." << endl;
            system("pause");
            break;
        case 7:
            cout << "Keyword: "; cin >> namaKeyword;
            insertFirstKeyword(LK, alokasiKeyword({namaKeyword}));
            system("pause");
            break;
        case 8:
            cout << "Keyword: "; cin >> namaKeyword;
            insertLastKeyword(LK, alokasiKeyword({namaKeyword}));
            system("pause");
            break;
        case 9:
            cout << "Cari Keyword sebelumnya: "; cin >> targetKW;
            PrecK = findKeyword(LK, targetKW);
            if (PrecK != nullptr) {
                cout << "Keyword Baru: "; cin >> namaKeyword;
                insertAfterKeyword(LK, PrecK, alokasiKeyword({namaKeyword}));
            } else cout << "Keyword tidak ditemukan!" << endl;
            system("pause");
            break;
        case 10:
            deleteFirstKeyword(LK, K);
            if (K != nullptr) {
                addressPaper p = LP.first;
                while (p != nullptr) { disconnectKeywordFromPaper(p, K->info.namaKeyword); p = p->next; }
            }
            system("pause");
            break;
        case 11:
            deleteLastKeyword(LK, K);
            if (K != nullptr) {
                addressPaper p = LP.first;
                while (p != nullptr) { disconnectKeywordFromPaper(p, K->info.namaKeyword); p = p->next; }
            }
            system("pause");
            break;
        case 12:
            cout << "Cari Keyword sebelumnya: "; cin >> targetKW;
            PrecK = findKeyword(LK, targetKW);
            deleteAfterKeyword(LK, PrecK, K);
            if (K != nullptr) {
                addressPaper p = LP.first;
                while (p != nullptr) { disconnectKeywordFromPaper(p, K->info.namaKeyword); p = p->next; }
            }
            system("pause");
            break;
        case 0: break;
        }
    }
}
