#include "relasi.h"

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

void connect(ListRelasi &LR, ListPaper LP, ListKeyword LK, string idPaper, string namaKeyword) {
    addressPaper P = findPaper(LP, idPaper);
    addressKeyword K = findKeyword(LK, namaKeyword);

    if (P != NULL && K != NULL) {
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
