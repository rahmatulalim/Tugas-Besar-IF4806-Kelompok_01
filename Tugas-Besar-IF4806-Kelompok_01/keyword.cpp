#include "keyword.h"

void createListKeyword(ListKeyword &L) {
    L.first = NULL;
    L.last = NULL;
}

addressKeyword alokasiKeyword(infotypeKeyword x) {
    addressKeyword P = new elmenKeyword;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirstKeyword(ListKeyword &L, addressKeyword P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastKeyword(ListKeyword &L, addressKeyword P) {
    if (L.first == NULL) {
        insertFirstKeyword(L, P);
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteFirstKeyword(ListKeyword &L, addressKeyword &P) {
    P = L.first;
    if (P != NULL) {
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
    }
}

void deleteLastKeyword(ListKeyword &L, addressKeyword &P) {
    P = L.last;
    if (P != NULL) {
        if (L.first == L.last) {
            deleteFirstKeyword(L, P);
        } else {
            L.last = P->prev;
            L.last->next = NULL;
            P->prev = NULL;
        }
    }
}

void printKeyword(ListKeyword L) {
    addressKeyword P = L.first;
    cout << "\n=== LIST KEYWORD ===" << endl;
    while (P != NULL) {
        cout << "ID: " << P->info.idKeyword
             << " | Keyword: " << P->info.namaKeyword << endl;
        P = P->next;
    }
    cout << endl;
}

addressKeyword findKeyword(ListKeyword L, string namaKeyword) {
    addressKeyword P = L.first;
    while (P != NULL) {
        if (P->info.namaKeyword == namaKeyword) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
