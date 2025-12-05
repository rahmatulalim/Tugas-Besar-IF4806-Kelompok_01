#include <iostream>
#include <string>
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"
#include "user.h"
#include "admin.h"

using namespace std;

void showMenu() {
    cout << "========================================" << endl;
    cout << "   APLIKASI PENGELOLA PAPER & KEYWORD   " << endl;
    cout << "========================================" << endl;
    cout << "1. Masuk sebagai USER" << endl;
    cout << "2. Masuk sebagai ADMIN" << endl;
    cout << "0. Keluar" << endl;
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

    int pilihan;
    do {
        showMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                userMenu(LP, LK, LR);
                break;
            case 2:
                // optional: tambahkan verifikasi password jika mau
                adminMenu(LP, LK, LR);
                break;
            case 0:
                cout << "Terima kasih. Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    // sebelum keluar, sebaiknya bersihkan memory (opsional)
    // Hapus semua relasi
    while (LR.first != NULL) {
        addressRelasi r = LR.first;
        LR.first = r->next;
        delete r;
    }
    // Hapus semua paper
    addressPaper ap;
    while (LP.first != NULL) {
        deleteFirstPaper(LP, ap);
        if (ap != NULL) delete ap;
    }
    // Hapus semua keyword
    addressKeyword ak;
    while (LK.first != NULL) {
        deleteFirstKeyword(LK, ak);
        if (ak != NULL) delete ak;
    }

    return 0;
}
