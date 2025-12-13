#include "list_parent.h"

void createListPaper(ListPaper &L) {
    L.first = nullptr;
}

addressPaper alokasiPaper(infotypePaper x) {
    addressPaper P = new elmenPaper;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertFirstPaper(ListPaper &L, addressPaper P) {
    P->next = L.first;
    L.first = P;
}

void insertLastPaper(ListPaper &L, addressPaper P) {
    if (L.first == nullptr) {
        insertFirstPaper(L, P);
    } else {
        addressPaper Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterPaper(ListPaper &L, addressPaper Prec, addressPaper P) {
    if (P == nullptr) return;
    if (Prec == nullptr) {
        insertFirstPaper(L, P);
    } else {
        P->next = Prec->next;
        Prec->next = P;
    }
}
