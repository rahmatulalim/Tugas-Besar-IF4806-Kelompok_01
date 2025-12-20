#include "list_parent.h"
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

    if (L.first != nullptr) {
        if (Prec == nullptr) {
            deleteFirstPaper(L, P);
        } else {
            if (Prec->next != nullptr) {
                P = Prec->next;
                Prec->next = P->next;
                P->next = nullptr;
            }
        }
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

void printChildOfParent(addressPaper P) {
    if (P == nullptr) {
        cout << "Paper tidak ditemukan." << endl;
        return;
    }
    cout << "Paper: " << P->info.judul << " memiliki keyword:" << endl;
    addressKeyword K = P->firstChild;
    bool found = false;
    while (K != nullptr) {
        cout << "- " << K->info.namaKeyword << endl;
        found = true;
        K = K->next;
    }
    if (!found) cout << "(Tidak ada keyword)" << endl;
}

void printParentFromChild(ListPaper LP, string namaKeyword) {
    if (LP.first != nullptr) {
        cout << "Keyword: " << namaKeyword << " terdapat pada paper:" << endl;
        addressPaper P = LP.first;
        bool found = false;
        while (P != nullptr) {
            if (findChildInPaper(P, namaKeyword) != nullptr) {
                cout << "- " << P->info.judul << endl;
                found = true;
            }
            P = P->next;
        }
        if (!found) cout << "(Tidak ada paper)" << endl;
    } else {
        cout << "Tidak ada paper." << endl;
    }
}


void printAllParentWithChild(ListPaper LP) {
    addressPaper P = LP.first;
    cout << "\n=== DAFTAR SEMUA PAPER & KEYWORD-NYA ===" << endl;
    while (P != nullptr) {
        cout << "[" << P->info.idPaper << "] " << P->info.judul << ":" << endl;
        addressKeyword K = P->firstChild;
        bool ada = false;
        while (K != nullptr) {
            cout << "   -> " << K->info.namaKeyword << endl;
            ada = true;
            K = K->next;
        }
        if (!ada) cout << "   (Tidak ada relasi)" << endl;
        P = P->next;
    }
}

void countRelationOfParent(ListPaper LP) {
    addressPaper P = LP.first;
    cout << "\n=== JUMLAH KEYWORD PER PAPER ===" << endl;
    while (P != nullptr) {
        int count = 0;
        addressKeyword K = P->firstChild;
        while (K != nullptr) {
            count++;
            K = K->next;
        }
        cout << P->info.judul << ": " << count << " keyword." << endl;
        P = P->next;
    }
}

void countNoRelationParent(ListPaper LP) {
    addressPaper P = LP.first;
    int orphanCount = 0;
    cout << "\n=== PAPER TANPA RELASI ===" << endl;
    while (P != nullptr) {
        if (P->firstChild == nullptr) {
            cout << "- " << P->info.judul << endl;
            orphanCount++;
        }
        P = P->next;
    }
    cout << "Total Paper tanpa keyword: " << orphanCount << endl;
}

int countChildOfPaper(addressPaper P) {
    int count = 0;
    addressKeyword K = P->firstChild;
    while (K != nullptr) {
        count++;
        K = K->next;
    }
    return count;
}
