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

void deleteFirstKeyword(ListKeyword &L, addressKeyword &P) {
    P = L.first;
    if (P != nullptr) {
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = P->next;
            L.first->prev = nullptr;
            P->next = nullptr;
            P->prev = nullptr;
        }
    }
}

void deleteLastKeyword(ListKeyword &L, addressKeyword &P) {
    P = L.last;
    if (P != nullptr) {
        if (L.first == L.last) {
            deleteFirstKeyword(L, P);
        } else {
            L.last = P->prev;
            L.last->next = nullptr;
            P->prev = nullptr;
            P->next = nullptr;
        }
    }
}

void deleteAfterKeyword(ListKeyword &L, addressKeyword Prec, addressKeyword &P) {
    P = nullptr;
    if (L.first == nullptr) return;
    if (Prec == nullptr) {
        deleteFirstKeyword(L, P);
    } else {
        addressKeyword target = Prec->next;
        if (target == nullptr) {
            P = nullptr;
            return;
        }
        if (target == L.last) {
            deleteLastKeyword(L, P);
        } else {
            P = target;
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = nullptr;
            P->prev = nullptr;
        }
    }
}

void printKeyword(ListKeyword L) {
    addressKeyword P = L.first;
    cout << "\n=== LIST KEYWORD ===" << endl;
    while (P != nullptr) {
        cout << "ID: " << P->info.idKeyword
             << " | Keyword: " << P->info.namaKeyword << endl;
        P = P->next;
    }
    cout << endl;
}

addressKeyword findKeyword(ListKeyword L, string namaKeyword) {
    addressKeyword P = L.first;
    while (P != nullptr) {
        if (P->info.namaKeyword == namaKeyword) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
