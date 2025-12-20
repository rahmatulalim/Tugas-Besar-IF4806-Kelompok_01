#include <iostream>
#include <string>
#include <cstdlib>
#include "list_child.h"
#include "list_parent.h"
#include "user.h"
#include "admin.h"

using namespace std;

int main() {
    ListPaper LP;
    ListKeyword LK;
    createListPaper(LP);
    createListKeyword(LK);

    int pilihan = -1;

    while (pilihan != 0) {
        system("cls");
        cout << "========================================" << endl;
        cout << "   APLIKASI PENGELOLA PAPER & KEYWORD   " << endl;
        cout << "========================================" << endl;
        cout << "1. Masuk sebagai USER" << endl;
        cout << "2. Masuk sebagai ADMIN" << endl;
        cout << "0. Keluar" << endl;
        cout << "========================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            userMenu(LP, LK);
        } else if (pilihan == 2) {
            adminMenu(LP, LK);
        }
    }

    return 0;
}
