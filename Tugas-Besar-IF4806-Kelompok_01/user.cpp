#include <iostream>
#include <string>
#include "user.h"

using namespace std;

void userMenu(ListPaper &LP, ListKeyword &LK, ListRelasi &LR) {
    int pilihan;
    string idPaper, judulPaper, namaKeyword, idKeyword;
    int tahunPaper;
    addressPaper tempP;
    addressKeyword tempK;

    do {
        cout << "\n=== USER MENU ===" << endl;
        cout << "1. Tambah Paper" << endl;
        cout << "2. Tambah Keyword" << endl;
        cout << "3. Lihat Semua Paper" << endl;
        cout << "4. Lihat Semua Keyword" << endl;
        cout << "5. Hubungkan Paper & Keyword" << endl;
        cout << "0. Logout (kembali ke pemilihan role)" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "[ TAMBAH PAPER ]" << endl;
                cout << "Masukkan ID Paper  : "; cin >> idPaper;
                cout << "Masukkan Judul     : "; cin >> judulPaper;
                cout << "Masukkan Tahun     : "; cin >> tahunPaper;
                insertLastPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
                cout << ">> Paper ditambahkan." << endl;
                break;

            case 2:
                cout << "[ TAMBAH KEYWORD ]" << endl;
                cout << "Masukkan ID Keyword: "; cin >> idKeyword;
                cout << "Masukkan Keyword   : "; cin >> namaKeyword;
                insertLastKeyword(LK, alokasiKeyword({namaKeyword, idKeyword}));
                cout << ">> Keyword ditambahkan." << endl;
                break;

            case 3:
                printPaper(LP);
                break;

            case 4:
                printKeyword(LK);
                break;

            case 5:
                printPaper(LP);
                printKeyword(LK);
                cout << "Masukkan ID Paper: "; cin >> idPaper;
                cout << "Masukkan Keyword : "; cin >> namaKeyword;
                connect(LR, LP, LK, idPaper, namaKeyword);
                break;

            case 0:
                cout << "Logout user..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);
}
