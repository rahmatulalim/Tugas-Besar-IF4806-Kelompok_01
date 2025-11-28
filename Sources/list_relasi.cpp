#include "../Headers/list_relasi.h"

void createListRelasi(ListRelasi &L) {
    L.first = NULL;
}

addressR alokasiRelasi(addressP P, addressC C) {
    addressR R = new elmenR;
    R->parent = P;
    R->child = C;
    R->next = NULL;
    return R;
}

void insertFirstRelasi(ListRelasi &L, addressR R) {
    R->next = L.first;
    L.first = R;
}

void insertLastRelasi(ListRelasi &L, addressR R) {
    if (L.first == NULL) {
        insertFirstRelasi(L, R);
    } else {
        addressR Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = R;
    }
}

addressR findRelasi(ListRelasi L, string idPaper, string namaKeyword) {
    addressR R = L.first;
    while (R != NULL) {
        if (R->parent->info.idPaper == idPaper && R->child->info.namaKeyword == namaKeyword) {
            return R;
        }
        R = R->next;
    }
    return NULL;
}

void connect(ListRelasi &LR, ListParent LP, ListChild LC, string idPaper, string namaKeyword) {
    addressP P = findParent(LP, idPaper);
    addressC C = findChild(LC, namaKeyword);

    if (P != NULL && C != NULL) {
        addressR R = alokasiRelasi(P, C);
        insertLastRelasi(LR, R);
        cout << "Berhasil menghubungkan: " << P->info.judul << " <--> " << C->info.namaKeyword << endl;
    } else {
        cout << "Gagal menghubungkan: Data Parent atau Child tidak ditemukan." << endl;
    }
}

void disconnect(ListRelasi &LR, string idPaper, string namaKeyword) {
    addressR R = LR.first;
    addressR Prec = NULL;

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
    addressR R = L.first;
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
