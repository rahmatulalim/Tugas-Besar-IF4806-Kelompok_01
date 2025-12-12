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
    ListPaper LP;
    ListKeyword LK;
    ListRelasi LR;

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
                adminMenu(LP, LK, LR);
                break;
            case 0:
                cout << "Terima kasih. Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    while (LR.first != nullptr) {
        addressRelasi r = LR.first;
        LR.first = r->next;
        delete r;
    }

    addressPaper ap;
    while (LP.first != nullptr) {
        deleteFirstPaper(LP, ap);
        if (ap != nullptr) delete ap;
    }

    addressKeyword ak;
    while (LK.first != nullptr) {
        deleteFirstKeyword(LK, ak);
        if (ak != nullptr) delete ak;
    }

    return 0;
}
