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

void deleteFirstPaper(ListPaper &L, addressPaper &P) {
    if (L.first != nullptr) {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

void deleteLastPaper(ListPaper &L, addressPaper &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first->next == nullptr) {
        deleteFirstPaper(L, P);
    } else {
        addressPaper Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfterPaper(ListPaper &L, addressPaper Prec, addressPaper &P) {
    P = nullptr;
    if (L.first == nullptr) return;
    if (Prec == nullptr) {
        deleteFirstPaper(L, P);
    } else {
        if (Prec->next == nullptr) {
            P = nullptr;
            return;
        }
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}

void printPaper(ListPaper L) {
    addressPaper P = L.first;
    cout << "\n=== LIST PAPER ===" << endl;
    while (P != nullptr) {
        cout << "ID: " << P->info.idPaper
             << " | Judul: " << P->info.judul
             << " | Tahun: " << P->info.tahun << endl;
        P = P->next;
    }
    cout << endl;
}

addressPaper findPaper(ListPaper L, string idPaper) {
    addressPaper P = L.first;
    while (P != nullptr) {
        if (P->info.idPaper == idPaper) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
