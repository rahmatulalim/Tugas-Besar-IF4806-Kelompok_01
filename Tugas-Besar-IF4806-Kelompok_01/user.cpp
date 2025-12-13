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

        switch (pilihan) {

            // ========================
            // TAMBAH PAPER (versi klasik)
            // ========================
            case 1: {
                cout << "ID Paper   : ";
                cin >> idPaper;

                // cek ID unik manual (tanpa findPaper)
                bool idAda = false;
                addressPaper cek = LP.first;
                while (cek != nullptr) {
                    if (cek->info.idPaper == idPaper) {
                        idAda = true;
                        break;
                    }
                    cek = cek->next;
                }

                if (idAda) {
                    cout << ">> Gagal: ID Paper sudah ada." << endl;
                    break;
                }

                cout << "Judul      : ";
                cin >> judulPaper;

                cout << "Tahun      : ";
                cin >> tahunPaper;

                // bentuk klasik tanpa initializer list
                infotypePaper dataP;
                dataP.idPaper = idPaper;
                dataP.judul = judulPaper;
                dataP.tahun = tahunPaper;

                addressPaper baruP = alokasiPaper(dataP);
                insertLastPaper(LP, baruP);
                cout << ">> Paper disimpan." << endl;
                break;
            }

            // ========================
            // TAMBAH KEYWORD
            // ========================
            case 2: {
                cout << "ID Keyword : ";
                cin >> idKeyword;
                cout << "Keyword    : ";
                cin >> namaKeyword;

                // cek unik keyword (id & nama) secara traversal manual
                bool idAda = false;
                bool namaAda = false;
                addressKeyword cekK = LK.first;
                while (cekK != nullptr) {
                    if (cekK->info.idKeyword == idKeyword) idAda = true;
                    if (cekK->info.namaKeyword == namaKeyword) namaAda = true;
                    cekK = cekK->next;
                }

                if (idAda) {
                    cout << ">> Gagal: ID Keyword sudah digunakan." << endl;
                    break;
                }
                if (namaAda) {
                    cout << ">> Gagal: Keyword sudah ada." << endl;
                    break;
                }

                infotypeKeyword dataK;
                dataK.idKeyword = idKeyword;
                dataK.namaKeyword = namaKeyword;

                addressKeyword baruK = alokasiKeyword(dataK);
                insertLastKeyword(LK, baruK);
                cout << ">> Keyword disimpan." << endl;
                break;
            }

            // ========================
            // LIHAT PAPER
            // ========================
            case 3:
                printPaper(LP);
                break;

            // ========================
            // LIHAT KEYWORD
            // ========================
            case 4:
                printKeyword(LK);
                break;

            // ========================
            // CONNECT PAPER – KEYWORD
            // ========================
            case 5: {
                cout << "ID Paper   : ";
                cin >> idPaper;
                cout << "Keyword    : ";
                cin >> namaKeyword;
                connect(LR, LP, LK, idPaper, namaKeyword);
                break;
            }

            case 0:
                break;

            default:
                cout << "Input salah." << endl;
        }

    } while (pilihan != 0);
}
