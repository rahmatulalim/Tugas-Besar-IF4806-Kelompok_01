#include <iostream>
#include "list_parent.h"
#include "list_child.h"
#include "list_relasi.h"

using namespace std;

int main() {
    ListParent LP;
    ListChild LC;
    ListRelasi LR;

    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);

    infotypeP p1 = {"Machine Learning", "P001", 2023};
    infotypeP p2 = {"Data Structures", "P002", 2024};
    insertLastParent(LP, alokasiParent(p1));
    insertLastParent(LP, alokasiParent(p2));

    infotypeC c1 = {"AI", "K001"};
    infotypeC c2 = {"Algo", "K002"};
    insertLastChild(LC, alokasiChild(c1));
    insertLastChild(LC, alokasiChild(c2));

    printParent(LP);
    printChild(LC);

    cout << "=== TESTING RELASI ===" << endl;
    connect(LR, LP, LC, "P001", "AI");
    connect(LR, LP, LC, "P002", "Algo");
    printRelasi(LR);

    return 0;
}
