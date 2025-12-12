#include <iostream>
#include <string>
#include "admin.h"

using namespace std;

void adminMenu(ListPaper &LP, ListKeyword &LK, ListRelasi &LR) {
    int pilihan;
    string idPaper, namaKeyword, newKw;
    addressPaper P;
    addressKeyword K;

    do {
        cout << "\n=============================================" << endl;
        cout << "           ADMIN DASHBOARD (IT A)            " << endl;
        cout << "=============================================" << endl;
        cout << "MANAJEMEN DATA:" << endl;
        cout << "1. Hapus Paper (ID)" << endl;
        cout << "2. Hapus Keyword Terakhir" << endl;
        cout << "3. Putus Hubungan (Disconnect)" << endl;
        cout << "4. Edit Relasi (Ganti Keyword)" << endl;

        cout << "\nLAPORAN & VIEW:" << endl;
        cout << "5. Lihat Semua Paper & Child-nya" << endl;
        cout << "6. Lihat Semua Keyword & Parent-nya" << endl;
        cout << "7. Cari: Child dari Parent Tertentu" << endl;
        cout << "8. Cari: Parent dari Child Tertentu" << endl;

        cout << "\nSTATISTIK:" << endl;
        cout << "9. Hitung Jumlah Relasi (Per Item)" << endl;
        cout << "10. Cek Data Tanpa Relasi (Orphan)" << endl;

        cout << "0. Kembali" << endl;
        cout << "=============================================" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan ID Paper: "; cin >> idPaper;
                {
                   addressPaper cur = LP.first;
                   addressPaper prec = nullptr;
                   while(cur != nullptr && cur->info.idPaper != idPaper) {
                       prec = cur; cur = cur->next;
                   }
                   if(cur != nullptr) {
                       removeRelasiByPaper(LR, idPaper);
                       addressPaper del;
                       if(prec == nullptr) deleteFirstPaper(LP, del);
                       else deleteAfterPaper(LP, prec, del);
                       delete del;
                       cout << ">> Paper dihapus." << endl;
                   } else cout << "Paper tidak ditemukan." << endl;
                }
                break;

            case 2:
                deleteLastKeyword(LK, K);
                if (K != nullptr) {
                    removeRelasiByKeyword(LR, K->info.namaKeyword);
                    delete K;
                    cout << ">> Keyword terakhir dihapus." << endl;
                } else {
                    cout << "List Keyword kosong." << endl;
                }
                break;

            case 3:
                cout << "ID Paper   : "; cin >> idPaper;
                cout << "Keyword    : "; cin >> namaKeyword;
                disconnect(LR, idPaper, namaKeyword);
                break;

            case 4:
                cout << "ID Paper       : "; cin >> idPaper;
                cout << "Keyword Lama   : "; cin >> namaKeyword;
                cout << "Keyword Baru   : "; cin >> newKw;
                editRelasi(LR, LP, LK, idPaper, namaKeyword, newKw);
                break;

            case 5:
                printAllParentWithChild(LR, LP);
                break;

            case 6:
                printAllChildWithParent(LR, LK);
                break;

            case 7:
                cout << "ID Paper: "; cin >> idPaper;
                printChildOfParent(LR, LP, idPaper);
                break;

            case 8:
                cout << "Keyword: "; cin >> namaKeyword;
                printParentOfChild(LR, LK, namaKeyword);
                break;

            case 9:
                cout << "--- Statistik Relasi ---" << endl;
                countRelationOfParent(LR, LP);
                cout << "------------------------" << endl;
                countRelationOfChild(LR, LK);
                break;

            case 10:
                countNoRelationParent(LR, LP);
                countNoRelationChild(LR, LK);
                break;

            case 0:
                cout << "Logout..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);
}
