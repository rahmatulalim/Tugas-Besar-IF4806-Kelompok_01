#include "paper.h"

void createListPaper(ListPaper &L) {
    L.first = NULL;
}

addressPaper alokasiPaper(infotypePaper x) {
    addressPaper P = new elmenPaper;
    P->info = x;
    P->next = NULL;
    return P;
}

void insertFirstPaper(ListPaper &L, addressPaper P) {
    P->next = L.first;
    L.first = P;
}

void insertLastPaper(ListPaper &L, addressPaper P) {
    if (L.first == NULL) {
        insertFirstPaper(L, P);
    } else {
        addressPaper Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirstPaper(ListPaper &L, addressPaper &P) {
    if (L.first != NULL) {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLastPaper(ListPaper &L, addressPaper &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first->next == NULL) {
        deleteFirstPaper(L, P);
    } else {
        addressPaper Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

void printPaper(ListPaper L) {
    addressPaper P = L.first;
    cout << "\n=== LIST PAPER ===" << endl;
    while (P != NULL) {
        cout << "ID: " << P->info.idPaper
             << " | Judul: " << P->info.judul
             << " | Tahun: " << P->info.tahun << endl;
        P = P->next;
    }
    cout << endl;
}

addressPaper findPaper(ListPaper L, string idPaper) {
    addressPaper P = L.first;
    while (P != NULL) {
        if (P->info.idPaper == idPaper) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
