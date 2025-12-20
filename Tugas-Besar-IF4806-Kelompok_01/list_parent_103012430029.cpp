#include "list_parent.h"

void disconnectKeywordFromPaper(addressPaper P, string namaKeyword) {
    if (P == nullptr) {
        cout << ">> Paper tidak valid." << endl;
        return;
    }
    addressKeyword curr = P->firstChild;
    while (curr != nullptr) {
        if (curr->info.namaKeyword == namaKeyword) {
            if (curr->prev != nullptr) {
                curr->prev->next = curr->next;
            } else {
                P->firstChild = curr->next;
            }
            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }
            curr->next = nullptr;
            curr->prev = nullptr;
            cout << ">> Putus Relasi Berhasil." << endl;
            return;
        }
        curr = curr->next;
    }
    cout << ">> Relasi tidak ditemukan." << endl;
}

addressKeyword findChildInPaper(addressPaper P, string namaKeyword) {
    if (P == nullptr) return nullptr;
    addressKeyword curr = P->firstChild;
    while (curr != nullptr) {
        if (curr->info.namaKeyword == namaKeyword) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
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
    if (LP.first == nullptr) {
        cout << "Tidak ada paper." << endl;
        return;
    }

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


