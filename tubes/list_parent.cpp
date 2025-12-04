#include "list_parent.h"

void createListParent(ListParent &L) {
    L.first = NULL;
}

addressP alokasiParent(infotypeP x) {
    addressP P = new elmenP;
    P->info = x;
    P->next = NULL;
    return P;
}

void insertFirstParent(ListParent &L, addressP P) {
    P->next = L.first;
    L.first = P;
}

void insertLastParent(ListParent &L, addressP P) {
    if (L.first == NULL) {
        insertFirstParent(L, P);
    } else {
        addressP Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirstParent(ListParent &L, addressP &P) {
    if (L.first != NULL) {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLastParent(ListParent &L, addressP &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first->next == NULL) {
        deleteFirstParent(L, P);
    } else {
        addressP Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

void printParent(ListParent L) {
    addressP P = L.first;
    cout << "\n=== LIST PAPER (PARENT) ===" << endl;
    while (P != NULL) {
        cout << "ID: " << P->info.idPaper
             << " | Judul: " << P->info.judul
             << " | Tahun: " << P->info.tahun << endl;
        P = P->next;
    }
    cout << endl;
}

addressP findParent(ListParent L, string idPaper) {
    addressP P = L.first;
    while (P != NULL) {
        if (P->info.idPaper == idPaper) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
