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
    if (P != nullptr) {
        if (Prec == nullptr) {
            insertFirstPaper(L, P);
        } else {
            P->next = Prec->next;
            Prec->next = P;
        }
    }
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
    if (P != nullptr && K != nullptr) {

        bool sudahAda = false;
        addressKeyword cek = P->firstChild;

        while (cek != nullptr && !sudahAda) {
            if (cek->info.namaKeyword == K->info.namaKeyword) {
                sudahAda = true;
            } else {
                cek = cek->next;
            }
        }

        if (sudahAda) {
            cout << ">> Relasi sudah ada!" << endl;
        } else {
            K->next = P->firstChild;
            if (P->firstChild != nullptr) {
                P->firstChild->prev = K;
            }
            P->firstChild = K;
            K->prev = nullptr;

            cout << ">> Berhasil menghubungkan: "
                 << P->info.judul << " <--> "
                 << K->info.namaKeyword << endl;
        }

    } else {
        cout << ">> Gagal: Paper atau Keyword tidak valid." << endl;
    }
}

void disconnectKeywordFromPaper(addressPaper P, string namaKeyword) {
    if (P != nullptr) {
        addressKeyword curr = P->firstChild;
        bool found = false;
        while (curr != nullptr && !found) {
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
                found = true;
            } else {
                curr = curr->next;
            }
        }
        if (!found) {
            cout << ">> Relasi tidak ditemukan." << endl;
        }
    } else {
        cout << ">> Paper tidak valid." << endl;
    }
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
