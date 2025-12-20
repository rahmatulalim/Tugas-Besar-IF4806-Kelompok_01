#include "list_child.h"

void deleteAfterKeyword(ListKeyword &L, addressKeyword Prec, addressKeyword &P) {
    P = nullptr;
    if (L.first == nullptr) return;
    if (Prec == nullptr) {
        deleteFirstKeyword(L, P);
    } else {
        addressKeyword target = Prec->next;
        if (target == nullptr) {
            P = nullptr;
            return;
        }
        if (target == L.last) {
            deleteLastKeyword(L, P);
        } else {
            P = target;
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = nullptr;
            P->prev = nullptr;
        }
    }
}

void printKeyword(ListKeyword L) {
    addressKeyword P = L.first;
    cout << "\n=== LIST KEYWORD ===" << endl;
    while (P != nullptr) {
        cout << "- " << P->info.namaKeyword << endl;
        P = P->next;
    }
    cout << endl;
}

addressKeyword findKeyword(ListKeyword L, string namaKeyword) {
    addressKeyword P = L.first;
    while (P != nullptr) {
        if (P->info.namaKeyword == namaKeyword) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void printKeywordSortedAlphabet(ListKeyword L) {
    cout << "\n=== LIST KEYWORD (URUT A - Z) ===" << endl;

    int total = 0;
    addressKeyword k = L.first;
    while (k != nullptr) {
        total++;
        k = k->next;
    }

    bool printed[100];
    for (int i = 0; i < total; i++) printed[i] = false;

    for (int i = 0; i < total; i++) {
        addressKeyword minK = nullptr;
        int idx = -1;

        k = L.first;
        int j = 0;
        while (k != nullptr) {
            if (!printed[j]) {
                if (minK == nullptr ||
                    k->info.namaKeyword < minK->info.namaKeyword) {
                    minK = k;
                    idx = j;
                }
            }
            k = k->next;
            j++;
        }

        if (minK != nullptr) {
            cout << "Keyword : " << minK->info.namaKeyword << endl;
            cout << "---------------------------" << endl;
            printed[idx] = true;
        }
    }
}

