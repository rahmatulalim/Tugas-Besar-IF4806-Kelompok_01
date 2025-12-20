#include <iostream>
#include <string>
#include "user.h"

using namespace std;

void userMenu(ListPaper &LP, ListKeyword &LK) {
    int pilihan = -1;
    string idPaper, namaKeyword, judulPaper;
    int tahunPaper;
    addressPaper P;
    addressKeyword K;

    while (pilihan != 0) {
        cout << "\n===========================================" << endl;
        cout << "               USER MENU                   " << endl;
        cout << "===========================================" << endl;
        cout << " [ DATA MANAJEMEN ]" << endl;
        cout << " 1. Tambah Paper Baru" << endl;
        cout << " 2. Tambah Keyword Baru" << endl;
        cout << " 3. Hapus Paper (ID)" << endl;
        cout << " 4. Hapus Keyword (Nama)" << endl;
        cout << "\n [ MANAJEMEN RELASI ]" << endl;
        cout << " 5. Hubungkan Paper ke Keyword" << endl;
        cout << " 6. Putus Hubungan Paper - Keyword" << endl;
        cout << "\n [ PENELUSURAN & VIEW ]" << endl;
        cout << " 7. Daftar Paper (Urut ID)" << endl;
        cout << " 8. Daftar Keyword (Urut A-Z)" << endl;
        cout << " 9. Tampilkan Semua Paper & Keywordnya" << endl;
        cout << " 10. Cari Keyword dari Paper Tertentu" << endl;
        cout << " 11. Cari Paper dari Keyword Tertentu" << endl;
        cout << "\n [ INFORMASI & STATISTIK ]" << endl;
        cout << " 12. Statistik Keyword per Paper" << endl;
        cout << " 13. Total Akumulasi Data" << endl;
        cout << " 0. Kembali ke Menu Utama" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            cout << "\n[ Tambah Paper ]" << endl;
            cout << "ID Paper   : "; cin >> idPaper;
            if (findPaper(LP, idPaper) == nullptr) {
                cout << "Judul Paper: "; cin.ignore(); getline(cin, judulPaper);
                cout << "Tahun Terbit: "; cin >> tahunPaper;
                insertLastPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
                cout << ">> Berhasil ditambahkan." << endl;
            } else {
                cout << ">> Gagal: ID Paper sudah terdaftar." << endl;
            }
            break;
        }
        case 2: {
            cout << "\n[ Tambah Keyword ]" << endl;
            cout << "Nama Keyword: "; cin >> namaKeyword;
            if (findKeyword(LK, namaKeyword) == nullptr) {
                insertLastKeyword(LK, alokasiKeyword({namaKeyword}));
                cout << ">> Keyword ditambahkan." << endl;
            } else {
                cout << ">> Gagal: Keyword sudah ada." << endl;
            }
            break;
        }
        case 3: {
            cout << "\n[ Hapus Paper ]" << endl;
            cout << "Masukkan ID Paper: "; cin >> idPaper;
            addressPaper cur = LP.first, prec = nullptr;
            while (cur != nullptr && cur->info.idPaper != idPaper) {
                prec = cur;
                cur = cur->next;
            }
            if (cur != nullptr) {
                addressPaper del;
                if (prec == nullptr) deleteFirstPaper(LP, del);
                else deleteAfterPaper(LP, prec, del);
                cout << ">> Paper " << idPaper << " berhasil dihapus." << endl;
            } else {
                cout << ">> Paper tidak ditemukan." << endl;
            }
            break;
        }
        case 4: {
            cout << "\n[ Hapus Keyword ]" << endl;
            cout << "Nama Keyword: "; cin >> namaKeyword;
            addressKeyword curK = LK.first, precK = nullptr;
            while (curK != nullptr && curK->info.namaKeyword != namaKeyword) {
                precK = curK;
                curK = curK->next;
            }
            if (curK != nullptr) {
                addressPaper p = LP.first;
                while (p != nullptr) {
                    disconnectKeywordFromPaper(p, namaKeyword);
                    p = p->next;
                }
                if (precK == nullptr) deleteFirstKeyword(LK, K);
                else deleteAfterKeyword(LK, precK, K);
                cout << ">> Keyword dihapus dari sistem." << endl;
            } else {
                cout << ">> Keyword tidak ditemukan." << endl;
            }
            break;
        }
        case 5: {
            cout << "\n[ Hubungkan Paper - Keyword ]" << endl;
            cout << "ID Paper: "; cin >> idPaper;
            cout << "Keyword : "; cin >> namaKeyword;
            P = findPaper(LP, idPaper);
            K = findKeyword(LK, namaKeyword);
            if (P && K) {
                connectKeywordToPaper(P, alokasiKeyword(K->info));
            } else {
                cout << ">> Gagal: ID Paper atau Keyword tidak valid." << endl;
            }
            break;
        }
        case 6: {
            cout << "\n[ Putus Hubungan ]" << endl;
            cout << "ID Paper: "; cin >> idPaper;
            cout << "Keyword : "; cin >> namaKeyword;
            P = findPaper(LP, idPaper);
            if (P) disconnectKeywordFromPaper(P, namaKeyword);
            else cout << ">> Paper tidak ditemukan." << endl;
            break;
        }
        case 7: printPaperSortedByID(LP); break;
        case 8: printKeywordSortedAlphabet(LK); break;
        case 9: printAllParentWithChild(LP); break;
        case 10: {
            cout << "\n[ Cari Keyword per Paper ]" << endl;
            cout << "ID Paper: "; cin >> idPaper;
            printChildOfParent(findPaper(LP, idPaper));
            break;
        }
        case 11: {
            cout << "\n[ Cari Paper per Keyword ]" << endl;
            cout << "Nama Keyword: "; cin >> namaKeyword;
            printParentFromChild(LP, namaKeyword);
            break;
        }
        case 12: countRelationOfParent(LP); break;
        case 13: {
            int tp = 0, tk = 0;
            for (addressPaper p = LP.first; p; p = p->next) tp++;
            for (addressKeyword k = LK.first; k; k = k->next) tk++;
            cout << "\n=== TOTAL DATA ===" << endl;
            cout << "Jumlah Paper   : " << tp << endl;
            cout << "Jumlah Keyword : " << tk << endl;
            break;
        }
        case 0: cout << ">> Kembali..." << endl; break;
        default: cout << ">> Pilihan tidak tersedia." << endl; break;
        }
    }
}
