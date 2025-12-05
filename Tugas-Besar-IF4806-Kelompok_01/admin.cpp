#include <iostream>
#include <string>
#include "admin.h"

using namespace std;

void adminMenu(ListPaper &LP, ListKeyword &LK, ListRelasi &LR) {
    int pilihan;
    string idPaper, namaKeyword;
    addressPaper P;
    addressPaper prev;
    addressKeyword K;

    do {
        cout << "\n=== ADMIN MENU ===" << endl;
        cout << "1. Hapus Paper (by ID atau '-' untuk hapus pertama)" << endl;
        cout << "2. Hapus Keyword Terakhir" << endl;
        cout << "3. Putus Hubungan (Disconnect)" << endl;
        cout << "4. Lihat Semua Relasi" << endl;
        cout << "5. Lihat Semua Paper" << endl;
        cout << "6. Lihat Semua Keyword" << endl;
        cout << "0. Logout (kembali ke pemilihan role)" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "[ HAPUS PAPER ]" << endl;
                cout << "Masukkan ID Paper yang ingin dihapus (masukkan '-' untuk hapus pertama): ";
                cin >> idPaper;
                if (idPaper == "-") {
                    deleteFirstPaper(LP, P);
                    if (P != NULL) {
                        // bersihkan relasi dulu
                        removeRelasiByPaper(LR, P->info.idPaper);
                        cout << ">> Paper '" << P->info.judul << "' dihapus." << endl;
                        delete P;
                    } else {
                        cout << "List Paper kosong." << endl;
                    }
                } else {
                    // cari node dan prev
                    addressPaper cur = LP.first;
                    addressPaper prec = NULL;
                    while (cur != NULL && cur->info.idPaper != idPaper) {
                        prec = cur;
                        cur = cur->next;
                    }
                    if (cur == NULL) {
                        cout << "Paper dengan ID tersebut tidak ditemukan." << endl;
                    } else {
                        if (prec == NULL) {
                            deleteFirstPaper(LP, P);
                        } else {
                            deleteAfterPaper(LP, prec, P);
                        }
                        if (P != NULL) {
                            removeRelasiByPaper(LR, P->info.idPaper);
                            cout << ">> Paper '" << P->info.judul << "' dihapus." << endl;
                            delete P;
                        }
                    }
                }
                break;

            case 2:
                cout << "[ HAPUS KEYWORD TERAKHIR ]" << endl;
                deleteLastKeyword(LK, K);
                if (K != NULL) {
                    // bersihkan relasi
                    removeRelasiByKeyword(LR, K->info.namaKeyword);
                    cout << ">> Keyword '" << K->info.namaKeyword << "' dihapus." << endl;
                    delete K;
                } else {
                    cout << "List Keyword kosong." << endl;
                }
                break;

            case 3:
                cout << "[ PUTUS HUBUNGAN ]" << endl;
                cout << "Masukkan ID Paper: "; cin >> idPaper;
                cout << "Masukkan Keyword : "; cin >> namaKeyword;
                disconnect(LR, idPaper, namaKeyword);
                break;

            case 4:
                printRelasi(LR);
                break;

            case 5:
                printPaper(LP);
                break;

            case 6:
                printKeyword(LK);
                break;

            case 0:
                cout << "Logout admin..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);
}
