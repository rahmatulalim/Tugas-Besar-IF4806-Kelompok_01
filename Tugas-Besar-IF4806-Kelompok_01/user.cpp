#include <iostream>
#include <string>
#include "user.h"

using namespace std;

void userMenu(ListPaper &LP, ListKeyword &LK, ListRelasi &LR) {
    int pilihan;
    string idPaper, judulPaper, namaKeyword, idKeyword;
    int tahunPaper;

    do {
        cout << "\n=== USER MENU ===" << endl;
        cout << "1. Tambah Paper" << endl;
        cout << "2. Tambah Keyword" << endl;
        cout << "3. Lihat Paper (Ringkas)" << endl;
        cout << "4. Lihat Keyword (Ringkas)" << endl;
        cout << "5. Hubungkan (Connect)" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "ID Paper   : "; getline(cin, idPaper);
                cout << "Judul      : "; getline(cin, judulPaper);
                cout << "Tahun      : "; cin >> tahunPaper;
                insertLastPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
                cout << ">> Paper disimpan." << endl;
                break;

            case 2:
                cout << "ID Keyword : "; getline(cin, idKeyword);
                cout << "Keyword    : "; getline(cin, namaKeyword);
                insertLastKeyword(LK, alokasiKeyword({namaKeyword, idKeyword}));
                cout << ">> Keyword disimpan." << endl;
                break;

            case 3:
                printPaper(LP);
                break;

            case 4:
                printKeyword(LK);
                break;

            case 5:
                cout << "ID Paper   : "; getline(cin, idPaper);
                cout << "Keyword    : "; getline(cin, namaKeyword);
                connect(LR, LP, LK, idPaper, namaKeyword);
                break;

            case 0:
                break;
            default:
                cout << "Input salah." << endl;
        }
    } while (pilihan != 0);
}
