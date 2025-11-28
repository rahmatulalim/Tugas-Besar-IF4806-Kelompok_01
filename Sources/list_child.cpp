#include "../Headers/list_child.h"

void createListChild(ListChild &L) {
    L.first = NULL;
    L.last = NULL;
}

addressC alokasiChild(infotypeC x) {
    addressC P = new elmenC;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirstChild(ListChild &L, addressC P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(ListChild &L, addressC P) {
    if (L.first == NULL) {
        insertFirstChild(L, P);
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteFirstChild(ListChild &L, addressC &P) {
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

void deleteLastChild(ListChild &L, addressC &P) {
    P = L.last;
    if (P != NULL) {
        if (L.first == L.last) {
            deleteFirstChild(L, P);
        } else {
            L.last = P->prev;
            L.last->next = NULL;
            P->prev = NULL;
        }
    }
}

void printChild(ListChild L) {
    addressC P = L.first;
    cout << "\n=== LIST KEYWORD (CHILD) ===" << endl;
    while (P != NULL) {
        cout << "ID: " << P->info.idKeyword
             << " | Keyword: " << P->info.namaKeyword << endl;
        P = P->next;
    }
    cout << endl;
}

addressC findChild(ListChild L, string namaKeyword) {
    addressC P = L.first;
    while (P != NULL) {
        if (P->info.namaKeyword == namaKeyword) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
