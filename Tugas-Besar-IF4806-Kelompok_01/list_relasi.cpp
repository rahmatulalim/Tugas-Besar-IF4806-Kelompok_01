#include "list_relasi.h"
#include <iostream>
using namespace std;

void createListRelasi(ListRelasi &L) {
    L.first = nullptr;
}

addressRelasi alokasiRelasi(addressPaper P, addressKeyword C) {
    addressRelasi R = new elmenRelasi;
    R->parent = P;
    R->child = C;
    R->next = nullptr;
    return R;
}

void insertLastRelasi(ListRelasi &L, addressRelasi R) {
    if (L.first == nullptr) {
        L.first = R;
    } else {
        addressRelasi Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = R;
    }
}

addressRelasi findRelasi(ListRelasi L, string idPaper, string namaKeyword) {
    addressRelasi R = L.first;
    while (R != nullptr) {
        if (R->parent->info.idPaper == idPaper && R->child->info.namaKeyword == namaKeyword) {
            return R;
        }
        R = R->next;
    }
    return nullptr;
}

void connect(ListRelasi &LR, ListPaper LP, ListKeyword LK, string idPaper, string namaKeyword) {
    addressPaper P = findPaper(LP, idPaper);
    addressKeyword K = findKeyword(LK, namaKeyword);

    if (P != nullptr && K != nullptr) {
        if (findRelasi(LR, idPaper, namaKeyword) != nullptr) {
            cout << ">> Relasi sudah ada!" << endl;
            return;
        }
        addressRelasi R = alokasiRelasi(P, K);
        insertLastRelasi(LR, R);
        cout << ">> Berhasil menghubungkan: " << P->info.judul << " <--> " << K->info.namaKeyword << endl;
    } else {
        cout << ">> Gagal: ID Paper atau Keyword tidak ditemukan." << endl;
    }
}

void disconnect(ListRelasi &LR, string idPaper, string namaKeyword) {
    addressRelasi R = LR.first;
    addressRelasi Prec = nullptr;

    while (R != nullptr) {
        if (R->parent->info.idPaper == idPaper && R->child->info.namaKeyword == namaKeyword) {
            if (Prec == nullptr) {
                LR.first = R->next;
            } else {
                Prec->next = R->next;
            }
            delete R;
            cout << ">> Putus Relasi Berhasil." << endl;
            return;
        }
        Prec = R;
        R = R->next;
    }
    cout << ">> Relasi tidak ditemukan." << endl;
}

void removeRelasiByPaper(ListRelasi &LR, string idPaper) {
    addressRelasi R = LR.first;
    addressRelasi Prec = nullptr;
    while (R != nullptr) {
        if (R->parent->info.idPaper == idPaper) {
            addressRelasi toDelete = R;
            if (Prec == nullptr) {
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

void removeRelasiByKeyword(ListRelasi &LR, string namaKeyword) {
    addressRelasi R = LR.first;
    addressRelasi Prec = nullptr;
    while (R != nullptr) {
        if (R->child->info.namaKeyword == namaKeyword) {
            addressRelasi toDelete = R;
            if (Prec == nullptr) {
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

void printChildOfParent(ListRelasi LR, ListPaper LP, string idPaper) {
    addressPaper P = findPaper(LP, idPaper);
    if (P == nullptr) {
        cout << "Paper tidak ditemukan." << endl;
        return;
    }
    cout << "Paper: " << P->info.judul << " memiliki keyword:" << endl;
    addressRelasi R = LR.first;
    bool found = false;
    while (R != nullptr) {
        if (R->parent == P) {
            cout << "- " << R->child->info.namaKeyword << endl;
            found = true;
        }
        R = R->next;
    }
    if (!found) cout << "(Tidak ada keyword)" << endl;
}

void printParentOfChild(ListRelasi LR, ListKeyword LK, string namaKeyword) {
    addressKeyword K = findKeyword(LK, namaKeyword);
    if (K == nullptr) {
        cout << "Keyword tidak ditemukan." << endl;
        return;
    }
    cout << "Keyword: " << K->info.namaKeyword << " digunakan di paper:" << endl;
    addressRelasi R = LR.first;
    bool found = false;
    while (R != nullptr) {
        if (R->child == K) {
            cout << "- " << R->parent->info.judul << " (" << R->parent->info.tahun << ")" << endl;
            found = true;
        }
        R = R->next;
    }
    if (!found) cout << "(Tidak ada paper)" << endl;
}

void printAllParentWithChild(ListRelasi LR, ListPaper LP) {
    addressPaper P = LP.first;
    cout << "\n=== DAFTAR SEMUA PAPER & KEYWORD-NYA ===" << endl;
    while (P != nullptr) {
        cout << "[" << P->info.idPaper << "] " << P->info.judul << ":" << endl;
        addressRelasi R = LR.first;
        bool ada = false;
        while (R != nullptr) {
            if (R->parent == P) {
                cout << "   -> " << R->child->info.namaKeyword << endl;
                ada = true;
            }
            R = R->next;
        }
        if (!ada) cout << "   (Tidak ada relasi)" << endl;
        P = P->next;
    }
}

void printAllChildWithParent(ListRelasi LR, ListKeyword LK) {
    addressKeyword K = LK.first;
    cout << "\n=== DAFTAR SEMUA KEYWORD & PAPER PENGGUNANYA ===" << endl;
    while (K != nullptr) {
        cout << K->info.namaKeyword << ":" << endl;
        addressRelasi R = LR.first;
        bool ada = false;
        while (R != nullptr) {
            if (R->child == K) {
                cout << "   <- " << R->parent->info.judul << endl;
                ada = true;
            }
            R = R->next;
        }
        if (!ada) cout << "   (Tidak ada relasi)" << endl;
        K = K->next;
    }
}


void countRelationOfParent(ListRelasi LR, ListPaper LP) {
    addressPaper P = LP.first;
    cout << "\n=== JUMLAH KEYWORD PER PAPER ===" << endl;
    while (P != nullptr) {
        int count = 0;
        addressRelasi R = LR.first;
        while (R != nullptr) {
            if (R->parent == P) count++;
            R = R->next;
        }
        cout << P->info.judul << ": " << count << " keyword." << endl;
        P = P->next;
    }
}

void countRelationOfChild(ListRelasi LR, ListKeyword LK) {
    addressKeyword K = LK.first;
    cout << "\n=== JUMLAH PAPER PER KEYWORD ===" << endl;
    while (K != nullptr) {
        int count = 0;
        addressRelasi R = LR.first;
        while (R != nullptr) {
            if (R->child == K) count++;
            R = R->next;
        }
        cout << K->info.namaKeyword << ": " << count << " paper." << endl;
        K = K->next;
    }
}

void countNoRelationChild(ListRelasi LR, ListKeyword LK) {
    addressKeyword K = LK.first;
    int orphanCount = 0;
    cout << "\n=== KEYWORD TANPA RELASI ===" << endl;
    while (K != nullptr) {
        bool connected = false;
        addressRelasi R = LR.first;
        while (R != nullptr) {
            if (R->child == K) {
                connected = true;
                break;
            }
            R = R->next;
        }
        if (!connected) {
            cout << "- " << K->info.namaKeyword << endl;
            orphanCount++;
        }
        K = K->next;
    }
    cout << "Total Keyword tanpa paper: " << orphanCount << endl;
}

void countNoRelationParent(ListRelasi LR, ListPaper LP) {
    addressPaper P = LP.first;
    int orphanCount = 0;
    cout << "\n=== PAPER TANPA RELASI ===" << endl;
    while (P != nullptr) {
        bool connected = false;
        addressRelasi R = LR.first;
        while (R != nullptr) {
            if (R->parent == P) {
                connected = true;
                break;
            }
            R = R->next;
        }
        if (!connected) {
            cout << "- " << P->info.judul << endl;
            orphanCount++;
        }
        P = P->next;
    }
    cout << "Total Paper tanpa keyword: " << orphanCount << endl;
}

void editRelasi(ListRelasi &LR, ListPaper LP, ListKeyword LK, string idPaper, string oldKeyword, string newKeyword) {
    addressRelasi R = findRelasi(LR, idPaper, oldKeyword);
    if (R == nullptr) {
        cout << "Relasi lama tidak ditemukan." << endl;
        return;
    }
    addressKeyword newK = findKeyword(LK, newKeyword);
    if (newK == nullptr) {
        cout << "Keyword baru tidak valid." << endl;
        return;
    }
    if (findRelasi(LR, idPaper, newKeyword) != nullptr) {
        cout << "Gagal: Paper ini sudah memiliki keyword tersebut." << endl;
        return;
    }
    R->child = newK;
    cout << ">> Relasi berhasil diubah!" << endl;
}
