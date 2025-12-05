#include <iostream>
#include <string>
#include "paper.h"
#include "keyword.h"
#include "relasi.h"

using namespace std;

void showMenu() {
    cout << "========================================" << endl;
    cout << "   APLIKASI PENGELOLA PAPER & KEYWORD   " << endl;
    cout << "========================================" << endl;
    cout << "1.  Tambah Paper Baru" << endl;
    cout << "2.  Tambah Keyword Baru" << endl;
    cout << "3.  Lihat Semua Paper" << endl;
    cout << "4.  Lihat Semua Keyword" << endl;
    cout << "5.  Cari Paper (by ID)" << endl;
    cout << "6.  Cari Keyword (by Nama)" << endl;
    cout << "----------------------------------------" << endl;
    cout << "7.  Hubungkan Paper & Keyword (Connect)" << endl;
    cout << "8.  Putus Hubungan (Disconnect)" << endl;
    cout << "9.  Lihat Semua Relasi" << endl;
    cout << "----------------------------------------" << endl;
    cout << "10. Hapus Paper Terawal" << endl;
    cout << "11. Hapus Keyword Terakhir" << endl;
    cout << "0.  Keluar" << endl;
    cout << "========================================" << endl;
    cout << "Pilihan Anda: ";
}

int main() {
    // 1. Deklarasi List
    ListPaper LP;
    ListKeyword LK;
    ListRelasi LR;

    // 2. Inisialisasi List
    createListPaper(LP);
    createListKeyword(LK);
    createListRelasi(LR);

    // Variabel bantuan
    int pilihan;
    string idPaper, judulPaper, namaKeyword, idKeyword;
    int tahunPaper;

    // Pointer bantuan
    addressPaper P;
    addressKeyword K;

    // Loop Menu Utama
    do {
        showMenu();
        cin >> pilihan;

        switch (pilihan) {
        case 1: // Tambah Paper
            cout << "\n[ TAMBAH PAPER ]" << endl;
            cout << "Masukkan ID Paper  : "; cin >> idPaper;
            cout << "Masukkan Judul     : "; cin >> judulPaper; // Ingat: Jangan pakai spasi
            cout << "Masukkan Tahun     : "; cin >> tahunPaper;

            insertLastPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
            cout << ">> Data Paper berhasil disimpan!" << endl;
            break;

        case 2: // Tambah Keyword
            cout << "\n[ TAMBAH KEYWORD ]" << endl;
            cout << "Masukkan ID Keyword: "; cin >> idKeyword;
            cout << "Masukkan Keyword   : "; cin >> namaKeyword; // Ingat: Jangan pakai spasi

            insertLastKeyword(LK, alokasiKeyword({namaKeyword, idKeyword}));
            cout << ">> Data Keyword berhasil disimpan!" << endl;
            break;

        case 3: // Lihat Paper
            printPaper(LP);
            break;

        case 4: // Lihat Keyword
            printKeyword(LK);
            break;

        case 5: // Cari Paper
            cout << "\n[ CARI PAPER ]" << endl;
            cout << "Masukkan ID Paper: "; cin >> idPaper;
            P = findPaper(LP, idPaper);
            if (P != NULL) {
                cout << "Ditemukan! -> " << P->info.judul << " (" << P->info.tahun << ")" << endl;
            } else {
                cout << "Paper dengan ID tersebut TIDAK ditemukan." << endl;
            }
            break;

        case 6: // Cari Keyword
            cout << "\n[ CARI KEYWORD ]" << endl;
            cout << "Masukkan Keyword: "; cin >> namaKeyword;
            K = findKeyword(LK, namaKeyword);
            if (K != NULL) {
                cout << "Ditemukan! ID: " << K->info.idKeyword << endl;
            } else {
                cout << "Keyword tersebut TIDAK ditemukan." << endl;
            }
            break;

        case 7: // Connect
            cout << "\n[ HUBUNGKAN PAPER & KEYWORD ]" << endl;
            printPaper(LP);
            printKeyword(LK);

            cout << "Masukkan ID Paper: "; cin >> idPaper;
            cout << "Masukkan Keyword : "; cin >> namaKeyword;

            connect(LR, LP, LK, idPaper, namaKeyword);
            break;

        case 8: // Disconnect
            cout << "\n[ PUTUS HUBUNGAN ]" << endl;
            cout << "Masukkan ID Paper: "; cin >> idPaper;
            cout << "Masukkan Keyword : "; cin >> namaKeyword;

            disconnect(LR, idPaper, namaKeyword);
            break;

        case 9: // Lihat Relasi
            printRelasi(LR);
            break;

        case 10: // Hapus Paper Pertama
            deleteFirstPaper(LP, P);
            if (P != NULL) {
                cout << ">> Paper '" << P->info.judul << "' berhasil dihapus." << endl;
            } else {
                cout << "List Paper Kosong." << endl;
            }
            break;

        case 11: // Hapus Keyword Terakhir
            deleteLastKeyword(LK, K);
            if (K != NULL) {
                cout << ">> Keyword '" << K->info.namaKeyword << "' berhasil dihapus." << endl;
            } else {
                cout << "List Keyword Kosong." << endl;
            }
            break;

        case 0:
            cout << "Terima kasih." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

        cout << "\n(Tekan karakter apapun lalu Enter untuk lanjut...)";
        char pause;
        cin >> pause;
        cout << endl;

    } while (pilihan != 0);

    return 0;
}
