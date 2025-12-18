#include "list_child.h"

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
        cout << "- " << P->info.namaKeyword << endl;
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
