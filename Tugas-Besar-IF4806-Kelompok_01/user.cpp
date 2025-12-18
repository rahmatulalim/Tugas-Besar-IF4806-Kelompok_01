#include <iostream>
#include <string>
#include "user.h"

using namespace std;

void userMenu(ListPaper &LP, ListKeyword &LK, ListRelasi &LR) {
    int pilihan;
    string idPaper, namaKeyword, newKw;
    string idKeyword, judulPaper;
    int tahunPaper;
    addressPaper P;
    addressKeyword K;

    do {
        cout << "\n===========================================" << endl;
        cout << "              USER MENU (STUDI KASUS)       " << endl;
        cout << "===========================================" << endl;

        cout << "MANAJEMEN DATA (BERDASARKAN KONDISI):" << endl;
        cout << "1. Tambah Paper" << endl;
        cout << "2. Tambah Keyword" << endl;
        cout << "3. Hapus Paper (berdasarkan ID)" << endl;
        cout << "4. Hapus Keyword (berdasarkan NAMA)" << endl;
        cout << "5. Putus Hubungan (Disconnect)" << endl;
        cout << "6. Edit Relasi (Ganti Keyword)" << endl;

        cout << "\nVIEW & OPERASI (TERURUT):" << endl;
        cout << "7. Lihat Paper (Urut berdasarkan ID)" << endl;
        cout << "8. Lihat Keyword (Urut alfabet A-Z)" << endl;
        cout << "9. Hubungkan (Connect) Paper <-> Keyword" << endl;
        cout << "10. Lihat Semua Paper & Child-nya" << endl;
        cout << "11. Lihat Semua Keyword & Parent-nya" << endl;
        cout << "12. Cari Child dari Parent Tertentu" << endl;
        cout << "13. Cari Parent dari Child Tertentu" << endl;

        cout << "\nSTATISTIK:" << endl;
        cout << "14. Hitung Jumlah Relasi (Per Item)" << endl;
        cout << "15. Jumlah Total Paper & Keyword" << endl;

        cout << "0. Kembali" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {

        // 1. TAMBAH PAPER
        case 1: {
            cout << "ID Paper   : ";
            cin >> idPaper;

            bool ada = false;
            addressPaper cekP = LP.first;
            while (cekP != nullptr) {
                if (cekP->info.idPaper == idPaper) {
                    ada = true;
                    break;
                }
                cekP = cekP->next;
            }
            if (ada) {
                cout << ">> Gagal: ID Paper sudah ada." << endl;
                break;
            }

            cout << "Judul Paper: ";
            cin >> judulPaper;
            cout << "Tahun      : ";
            cin >> tahunPaper;

            insertLastPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
            cout << ">> Paper berhasil ditambahkan." << endl;
            break;
        }

        // 2. TAMBAH KEYWORD
        case 2: {
            cout << "ID Keyword : ";
            cin >> idKeyword;
            cout << "Keyword    : ";
            cin >> namaKeyword;

            bool idAda = false, namaAda = false;
            addressKeyword cekK = LK.first;
            while (cekK != nullptr) {
                if (cekK->info.idKeyword == idKeyword) idAda = true;
                if (cekK->info.namaKeyword == namaKeyword) namaAda = true;
                cekK = cekK->next;
            }

            if (idAda || namaAda) {
                cout << ">> Gagal: ID atau nama keyword sudah ada." << endl;
                break;
            }

            insertLastKeyword(LK, alokasiKeyword({namaKeyword, idKeyword}));
            cout << ">> Keyword berhasil ditambahkan." << endl;
            break;
        }

        // 3. HAPUS PAPER (ID)
        case 3: {
            cout << "Masukkan ID Paper: ";
            cin >> idPaper;

            addressPaper cur = LP.first;
            addressPaper prec = nullptr;

            while (cur != nullptr && cur->info.idPaper != idPaper) {
                prec = cur;
                cur = cur->next;
            }

            if (cur == nullptr) {
                cout << ">> Paper tidak ditemukan." << endl;
                break;
            }

            removeRelasiByPaper(LR, idPaper);

            addressPaper del;
            if (prec == nullptr)
                deleteFirstPaper(LP, del);
            else
                deleteAfterPaper(LP, prec, del);

            delete del;
            cout << ">> Paper berhasil dihapus." << endl;
            break;
        }

        // 4. HAPUS KEYWORD (NAMA)
        case 4: {
            cout << "Masukkan Nama Keyword: ";
            cin >> namaKeyword;

            addressKeyword cur = LK.first;
            addressKeyword prec = nullptr;

            while (cur != nullptr && cur->info.namaKeyword != namaKeyword) {
                prec = cur;
                cur = cur->next;
            }

            if (cur == nullptr) {
                cout << ">> Keyword tidak ditemukan." << endl;
                break;
            }

            removeRelasiByKeyword(LR, namaKeyword);

            if (prec == nullptr)
                deleteFirstKeyword(LK, K);
            else
                deleteAfterKeyword(LK, prec, K);

            delete K;
            cout << ">> Keyword berhasil dihapus." << endl;
            break;
        }

        // 5. DISCONNECT
        case 5:
            cout << "ID Paper : ";
            cin >> idPaper;
            cout << "Keyword  : ";
            cin >> namaKeyword;
            disconnect(LR, idPaper, namaKeyword);
            break;

        // 6. EDIT RELASI
        case 6:
            cout << "ID Paper     : ";
            cin >> idPaper;
            cout << "Keyword Lama : ";
            cin >> namaKeyword;
            cout << "Keyword Baru : ";
            cin >> newKw;
            editRelasi(LR, LP, LK, idPaper, namaKeyword, newKw);
            break;

        // === PERUBAHAN UTAMA ADA DI SINI ===
        case 7:
            printPaperSortedByID(LP);          // TERURUT ID
            break;

        case 8:
            printKeywordSortedAlphabet(LK);    // TERURUT A-Z
            break;

        case 9:
            cout << "ID Paper : ";
            cin >> idPaper;
            cout << "Keyword  : ";
            cin >> namaKeyword;
            connect(LR, LP, LK, idPaper, namaKeyword);
            break;

        case 10:
            printAllParentWithChild(LR, LP);
            break;

        case 11:
            printAllChildWithParent(LR, LK);
            break;

        case 12:
            cout << "ID Paper: ";
            cin >> idPaper;
            printChildOfParent(LR, LP, idPaper);
            break;

        case 13:
            cout << "Keyword: ";
            cin >> namaKeyword;
            printParentOfChild(LR, LK, namaKeyword);
            break;

        case 14:
            countRelationOfParent(LR, LP);
            countRelationOfChild(LR, LK);
            break;

        case 15: {
            int totalPaper = 0, totalKeyword = 0;
            for (addressPaper p = LP.first; p != nullptr; p = p->next) totalPaper++;
            for (addressKeyword k = LK.first; k != nullptr; k = k->next) totalKeyword++;

            cout << "\n=== JUMLAH TOTAL DATA ===" << endl;
            cout << "Total Paper   : " << totalPaper << endl;
            cout << "Total Keyword : " << totalKeyword << endl;
            break;
        }

        case 0:
            cout << "Kembali ke menu utama..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 0);
}
