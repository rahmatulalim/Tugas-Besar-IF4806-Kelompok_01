#include "list_child.h"

void createListKeyword(ListKeyword &L) {
    L.first = nullptr;
    L.last = nullptr;
}

addressKeyword alokasiKeyword(infotypeKeyword x) {
    addressKeyword P = new elmenKeyword;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertFirstKeyword(ListKeyword &L, addressKeyword P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastKeyword(ListKeyword &L, addressKeyword P) {
    if (L.first == nullptr) {
        insertFirstKeyword(L, P);
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfterKeyword(ListKeyword &L, addressKeyword Prec, addressKeyword P) {
    if (P == nullptr) return;
    if (Prec == nullptr) {
        insertFirstKeyword(L, P);
    } else if (Prec == L.last) {
        insertLastKeyword(L, P);
    } else {
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next->prev = P;
        Prec->next = P;
    }
}

