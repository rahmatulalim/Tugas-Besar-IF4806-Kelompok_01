#include <iostream>
#include <string>
#include <cstdlib>
#include "user.h"

using namespace std;

void userMenu(ListPaper &LP, ListKeyword &LK) {
    int pilihan = -1;
    string idPaper, namaKeyword, judulPaper;
    int tahunPaper;
    addressPaper P;
    addressKeyword K;

    while (pilihan != 0) {
        system("cls");
        cout << "===========================================" << endl;
        cout << "           USER MENU                       " << endl;
        cout << "===========================================" << endl;
        cout << "1. Tambah Paper" << endl;
        cout << "2. Tambah Keyword (ke Master)" << endl;
        cout << "3. Hapus Paper (berdasarkan ID)" << endl;
        cout << "4. Hapus Keyword (dari Master)" << endl;
        cout << "\nRELASI:" << endl;
        cout << "5. Hubungkan Paper <-> Keyword" << endl;
        cout << "6. Putus Hubungan (Disconnect)" << endl;
        cout << "\nVIEW:" << endl;
        cout << "7. Lihat Paper (Urut ID)" << endl;
        cout << "8. Lihat Keyword (Urut A-Z)" << endl;
        cout << "9. Lihat Semua Paper & Child" << endl;
        cout << "10. Cari Keyword dari Paper Tertentu" << endl;
        cout << "11. Cari Paper dari keyword Tertentu" << endl;
        cout << "\nSTATISTIK:" << endl;
        cout << "12. Hitung Jumlah Relasi" << endl;
        cout << "13. Jumlah Total Data" << endl;
        cout << "0. Kembali" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            cout << "ID    : "; cin >> idPaper;
            if (findPaper(LP, idPaper) == nullptr) {
                cout << "Judul : "; cin >> judulPaper;
                cout << "Tahun : "; cin >> tahunPaper;
                insertLastPaper(LP, alokasiPaper({judulPaper, idPaper, tahunPaper}));
            } else cout << "ID sudah ada!" << endl;
            system("pause");
            break;
        }
        case 2: {
            cout << "Keyword: "; cin >> namaKeyword;
            if (findKeyword(LK, namaKeyword) == nullptr) {
                insertLastKeyword(LK, alokasiKeyword({namaKeyword}));
            } else cout << "Keyword sudah ada!" << endl;
            system("pause");
            break;
        }
        case 3: {
            cout << "ID Paper: "; cin >> idPaper;
            addressPaper cur = LP.first, prec = nullptr; // Deklarasi di dalam blok { }
            while (cur != nullptr && cur->info.idPaper != idPaper) { prec = cur; cur = cur->next; }
            if (cur != nullptr) {
                addressPaper del;
                if (prec == nullptr) deleteFirstPaper(LP, del);
                else deleteAfterPaper(LP, prec, del);
                cout << ">> Terhapus." << endl;
            } else cout << "Tidak ketemu." << endl;
            system("pause");
            break;
        }
        case 4: {
            cout << "Keyword: "; cin >> namaKeyword;
            addressKeyword curK = LK.first, precK = nullptr; // Deklarasi di dalam blok { }
            while (curK != nullptr && curK->info.namaKeyword != namaKeyword) { precK = curK; curK = curK->next; }
            if (curK != nullptr) {
                addressPaper p = LP.first;
                while (p != nullptr) { disconnectKeywordFromPaper(p, namaKeyword); p = p->next; }
                if (precK == nullptr) deleteFirstKeyword(LK, K);
                else deleteAfterKeyword(LK, precK, K);
                cout << ">> Terhapus." << endl;
            }
            system("pause");
            break;
        }
        case 5: {
            cout << "ID Paper: "; cin >> idPaper;
            cout << "Keyword : "; cin >> namaKeyword;
            P = findPaper(LP, idPaper);
            K = findKeyword(LK, namaKeyword);
            if (P && K) connectKeywordToPaper(P, alokasiKeyword(K->info));
            system("pause");
            break;
        }
        case 6: {
            cout << "ID Paper: "; cin >> idPaper;
            cout << "Keyword : "; cin >> namaKeyword;
            P = findPaper(LP, idPaper);
            if (P) disconnectKeywordFromPaper(P, namaKeyword);
            system("pause");
            break;
        }
        case 7: printPaperSortedByID(LP); system("pause"); break;
        case 8: printKeywordSortedAlphabet(LK); system("pause"); break;
        case 9: printAllParentWithChild(LP); system("pause"); break;
        case 10: {
            cout << "ID Paper: "; cin >> idPaper;
            printChildOfParent(findPaper(LP, idPaper));
            system("pause");
            break;
        }
        case 11: {
            cout << "Keyword: ";
            cin >> namaKeyword;
            printParentFromChild(LP, namaKeyword);
            system("pause");
            break;
        }
        case 12: countRelationOfParent(LP); system("pause"); break;
        case 13: {
            int tp = 0, tk = 0;
            for (addressPaper p = LP.first; p; p = p->next) tp++;
            for (addressKeyword k = LK.first; k; k = k->next) tk++;
            cout << "Total Paper: " << tp << "\nTotal Keyword: " << tk << endl;
            system("pause");
            break;
        }
        case 0: break;
        default: cout << "Pilihan salah." << endl; system("pause");
        }
    }
}
