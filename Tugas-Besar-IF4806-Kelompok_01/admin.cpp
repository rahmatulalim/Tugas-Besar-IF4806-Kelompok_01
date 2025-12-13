#include <iostream>
#include <string>
#include "admin.h"

using namespace std;

void adminMenu(ListPaper &LP, ListKeyword &LK, ListRelasi &LR) {
    int pilihan;
    string idPaper, namaKeyword, newKw;
    string idKeyword, judulPaper;
    int tahunPaper;
    addressPaper P;
    addressKeyword K;

    do {
        cout << "\n=============================================" << endl;
        cout << "           ADMIN DASHBOARD (IT A)            " << endl;
        cout << "=============================================" << endl;
        cout << "MANAJEMEN DATA:" << endl;
        cout << "1. Tambah Paper" << endl;
        cout << "2. Tambah Keyword" << endl;
        cout << "3. Hapus Paper (ID)" << endl;
        cout << "4. Hapus Keyword Terakhir" << endl;
        cout << "5. Putus Hubungan (Disconnect)" << endl;
        cout << "6. Edit Relasi (Ganti Keyword)" << endl;

        cout << "\nVIEW & OPERASI:" << endl;
        cout << "7. Lihat Paper (Ringkas)" << endl;
        cout << "8. Lihat Keyword (Ringkas)" << endl;
        cout << "9. Hubungkan (Connect) Paper <-> Keyword" << endl;
        cout << "10. Lihat Semua Paper & Child-nya" << endl;
        cout << "11. Lihat Semua Keyword & Parent-nya" << endl;
        cout << "12. Cari: Child dari Parent Tertentu" << endl;
        cout << "13. Cari: Parent dari Child Tertentu" << endl;

        cout << "\nSTATISTIK:" << endl;
        cout << "14. Hitung Jumlah Relasi (Per Item)" << endl;
        cout << "15. Jumlah Total Paper & Keyword" << endl;

        cout << "0. Kembali" << endl;
        cout << "=============================================" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {

        // 1. TAMBAH PAPER (tanpa getline)
        case 1:
            cout << "ID Paper   : ";
            cin >> idPaper;

            // cek ID paper unik secara manual
            {
                bool ada = false;
                addressPaper cek = LP.first;
                while (cek != nullptr) {
                    if (cek->info.idPaper == idPaper) {
                        ada = true;
                        break;
                    }
                    cek = cek->next;
                }
                if (ada) {
                    cout << ">> Gagal: ID Paper sudah ada." << endl;
                    break;
                }
            }

            cout << "Judul Paper: ";
            cin >> judulPaper;

            cout << "Tahun      : ";
            cin >> tahunPaper;

            insertLastPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
            cout << ">> Paper berhasil ditambahkan." << endl;
            break;

        // 2. TAMBAH KEYWORD (tanpa getline)
        case 2:
            cout << "ID Keyword : ";
            cin >> idKeyword;
            cout << "Keyword    : ";
            cin >> namaKeyword;

            // cek unik ID & nama keyword secara traversal manual
            {
                bool idAda = false;
                bool namaAda = false;
                addressKeyword cek = LK.first;
                while (cek != nullptr) {
                    if (cek->info.idKeyword == idKeyword) idAda = true;
                    if (cek->info.namaKeyword == namaKeyword) namaAda = true;
                    cek = cek->next;
                }
                if (idAda) {
                    cout << ">> Gagal: ID Keyword sudah digunakan." << endl;
                    break;
                }
                if (namaAda) {
                    cout << ">> Gagal: Keyword sudah ada." << endl;
                    break;
                }
            }

            insertLastKeyword(LK, alokasiKeyword({namaKeyword, idKeyword}));
            cout << ">> Keyword berhasil ditambahkan." << endl;
            break;

        // 3. HAPUS PAPER
        case 3:
            cout << "Masukkan ID Paper: ";
            cin >> idPaper;
            {
                addressPaper cur = LP.first;
                addressPaper prec = nullptr;
                while(cur != nullptr && cur->info.idPaper != idPaper) {
                    prec = cur;
                    cur = cur->next;
                }
                if(cur != nullptr) {
                    removeRelasiByPaper(LR, idPaper);
                    addressPaper del;
                    if(prec == nullptr) deleteFirstPaper(LP, del);
                    else deleteAfterPaper(LP, prec, del);
                    delete del;
                    cout << ">> Paper dihapus." << endl;
                } else {
                    cout << "Paper tidak ditemukan." << endl;
                }
            }
            break;

        // 4. HAPUS KEYWORD TERAKHIR
        case 4:
            deleteLastKeyword(LK, K);
            if (K != nullptr) {
                removeRelasiByKeyword(LR, K->info.namaKeyword);
                delete K;
                cout << ">> Keyword terakhir dihapus." << endl;
            } else {
                cout << "List Keyword kosong." << endl;
            }
            break;

        // 5. DISCONNECT
        case 5:
            cout << "ID Paper   : "; cin >> idPaper;
            cout << "Keyword    : "; cin >> namaKeyword;
            disconnect(LR, idPaper, namaKeyword);
            break;

        // 6. EDIT RELASI
        case 6:
            cout << "ID Paper       : "; cin >> idPaper;
            cout << "Keyword Lama   : "; cin >> namaKeyword;
            cout << "Keyword Baru   : "; cin >> newKw;
            editRelasi(LR, LP, LK, idPaper, namaKeyword, newKw);
            break;

        // 7. LIHAT PAPER (ringkas)
        case 7:
            printPaper(LP);
            break;

        // 8. LIHAT KEYWORD (ringkas)
        case 8:
            printKeyword(LK);
            break;

        // 9. HUBUNGKAN (CONNECT) seperti pada USER
        case 9:
            cout << "ID Paper   : "; cin >> idPaper;
            cout << "Keyword    : "; cin >> namaKeyword;
            connect(LR, LP, LK, idPaper, namaKeyword); // fungsi sudah tersedia
            break;

        // 10. Semua Paper & Child-nya
        case 10:
            printAllParentWithChild(LR, LP);
            break;

        // 11. Semua Keyword & Parent-nya
        case 11:
            printAllChildWithParent(LR, LK);
            break;

        // 12. Cari child dari parent
        case 12:
            cout << "ID Paper: "; cin >> idPaper;
            printChildOfParent(LR, LP, idPaper);
            break;

        // 13. Cari parent dari child
        case 13:
            cout << "Keyword: "; cin >> namaKeyword;
            printParentOfChild(LR, LK, namaKeyword);
            break;

        // 14. Statistik relasi (per item)
        case 14:
            cout << "--- Statistik Relasi ---" << endl;
            countRelationOfParent(LR, LP);
            cout << "------------------------" << endl;
            countRelationOfChild(LR, LK);
            break;

        // 15. Jumlah total Paper & Keyword
        case 15:
            {
                int totalPaper = 0;
                addressPaper curP = LP.first;
                while (curP != nullptr) {
                    totalPaper++;
                    curP = curP->next;
                }
                int totalKeyword = 0;
                addressKeyword curK = LK.first;
                while (curK != nullptr) {
                    totalKeyword++;
                    curK = curK->next;
                }
                cout << "\n=== JUMLAH TOTAL DATA ===" << endl;
                cout << "Total Paper   : " << totalPaper << endl;
                cout << "Total Keyword : " << totalKeyword << endl;
            }
            break;

        case 0:
            cout << "Logout..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 0);
}
