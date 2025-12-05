#include "list_relasi.h"
#include <iostream>
using namespace std;

void createListRelasi(ListRelasi &L) {
    L.first = NULL;
}

addressRelasi alokasiRelasi(addressPaper P, addressKeyword C) {
    addressRelasi R = new elmenRelasi;
    R->parent = P;
    R->child = C;
    R->next = NULL;
    return R;
}

void insertLastRelasi(ListRelasi &L, addressRelasi R) {
    if (L.first == NULL) {
        L.first = R;
    } else {
        addressRelasi Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = R;
    }
}

addressRelasi findRelasi(ListRelasi L, string idPaper, string namaKeyword) {
    addressRelasi R = L.first;
    while (R != NULL) {
        if (R->parent->info.idPaper == idPaper && R->child->info.namaKeyword == namaKeyword) {
            return R;
        }
        R = R->next;
    }
    return NULL;
}

void connect(ListRelasi &LR, ListPaper LP, ListKeyword LK, string idPaper, string namaKeyword) {
    addressPaper P = findPaper(LP, idPaper);
    addressKeyword K = findKeyword(LK, namaKeyword);

    if (P != NULL && K != NULL) {
        // hindari duplikasi relasi
        if (findRelasi(LR, idPaper, namaKeyword) != NULL) {
            cout << "Relasi sudah ada: " << P->info.judul << " <--> " << K->info.namaKeyword << endl;
            return;
        }
        addressRelasi R = alokasiRelasi(P, K);
        insertLastRelasi(LR, R);
        cout << "Berhasil menghubungkan: " << P->info.judul << " <--> " << K->info.namaKeyword << endl;
    } else {
        cout << "Gagal menghubungkan: Data Paper atau Keyword tidak ditemukan." << endl;
    }
}

void disconnect(ListRelasi &LR, string idPaper, string namaKeyword) {
    addressRelasi R = LR.first;
    addressRelasi Prec = NULL;

    while (R != NULL) {
        if (R->parent->info.idPaper == idPaper && R->child->info.namaKeyword == namaKeyword) {
            if (Prec == NULL) {
                LR.first = R->next;
            } else {
                Prec->next = R->next;
            }
            delete R;
            cout << "Putus Relasi Berhasil: " << idPaper << " - " << namaKeyword << endl;
            return;
        }
        Prec = R;
        R = R->next;
    }
    cout << "Relasi tidak ditemukan." << endl;
}

void printRelasi(ListRelasi L) {
    addressRelasi R = L.first;
    cout << "\n=== DAFTAR RELASI (PAPER - KEYWORD) ===" << endl;
    if (R == NULL) {
        cout << "(Tidak ada relasi)" << endl;
    } else {
        while (R != NULL) {
            cout << R->parent->info.judul << " <--> " << R->child->info.namaKeyword << endl;
            R = R->next;
        }
    }
    cout << endl;
}

// Hapus semua relasi yang menunjuk ke idPaper
void removeRelasiByPaper(ListRelasi &LR, string idPaper) {
    addressRelasi R = LR.first;
    addressRelasi Prec = NULL;
    while (R != NULL) {
        if (R->parent->info.idPaper == idPaper) {
            addressRelasi toDelete = R;
            if (Prec == NULL) {
                LR.first = R->next;
                R = LR.first;
            } else {
                Prec->next = R->next;
                R = Prec->next;
            }
            delete toDelete;
        } else {
            Prec = R;
            R = R->next;
        }
    }
}

// Hapus semua relasi yang menunjuk ke namaKeyword
void removeRelasiByKeyword(ListRelasi &LR, string namaKeyword) {
    addressRelasi R = LR.first;
    addressRelasi Prec = NULL;
    while (R != NULL) {
        if (R->child->info.namaKeyword == namaKeyword) {
            addressRelasi toDelete = R;
            if (Prec == NULL) {
                LR.first = R->next;
                R = LR.first;
            } else {
                Prec->next = R->next;
                R = Prec->next;
            }
            delete toDelete;
        } else {
            Prec = R;
            R = R->next;
        }
    }
}
