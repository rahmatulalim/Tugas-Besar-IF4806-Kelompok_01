#include "list_parent.h"

void createListPaper(ListPaper &L) {
    L.first = nullptr;
}

addressPaper alokasiPaper(infotypePaper x) {
    addressPaper P = new elmenPaper;
    P->info = x;
    P->next = nullptr;
    P->firstChild = nullptr;
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

void printPaperSortedByID(ListPaper L) {
    cout << "\n=== LIST PAPER (URUT BERDASARKAN ID) ===" << endl;
    int total = 0;
    addressPaper p = L.first;
    while (p != nullptr) {
        total++;
        p = p->next;
    }
    bool printed[100];
    for (int i = 0; i < total; i++) printed[i] = false;
    for (int i = 0; i < total; i++) {
        addressPaper minP = nullptr;
        int idx = -1;
        p = L.first;
        int j = 0;
        while (p != nullptr) {
            if (!printed[j]) {
                if (minP == nullptr ||
                    p->info.idPaper < minP->info.idPaper) {
                    minP = p;
                    idx = j;
                }
            }
            p = p->next;
            j++;
        }
        if (minP != nullptr) {
            cout << "ID    : " << minP->info.idPaper << endl;
            cout << "Judul : " << minP->info.judul << endl;
            cout << "Tahun : " << minP->info.tahun << endl;
            cout << "---------------------------" << endl;
            printed[idx] = true;
        }
    }
}

void connectKeywordToPaper(addressPaper P, addressKeyword K) {
    if (P == nullptr || K == nullptr) {
        cout << ">> Gagal: Paper atau Keyword tidak valid." << endl;
        return;
    }
    addressKeyword cek = P->firstChild;
    while (cek != nullptr) {
        if (cek->info.namaKeyword == K->info.namaKeyword) {
            cout << ">> Relasi sudah ada!" << endl;
            return;
        }
        cek = cek->next;
    }
    K->next = P->firstChild;
    if (P->firstChild != nullptr) {
        P->firstChild->prev = K;
    }
    P->firstChild = K;
    K->prev = nullptr;
    cout << ">> Berhasil menghubungkan: " << P->info.judul << " <--> " << K->info.namaKeyword << endl;
}


