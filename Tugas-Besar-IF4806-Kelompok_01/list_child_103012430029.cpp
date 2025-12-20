#include "list_child.h"
void deleteFirstKeyword(ListKeyword &L, addressKeyword &P) {
    P = L.first;
    if (P != nullptr) {
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = P->next;
            L.first->prev = nullptr;
            P->next = nullptr;
            P->prev = nullptr;
        }
    }
}

void deleteLastKeyword(ListKeyword &L, addressKeyword &P) {
    P = L.last;
    if (P != nullptr) {
        if (L.first == L.last) {
            deleteFirstKeyword(L, P);
        } else {
            L.last = P->prev;
            L.last->next = nullptr;
            P->prev = nullptr;
            P->next = nullptr;
        }
    }
}


void deleteAfterKeyword(ListKeyword &L, addressKeyword Prec, addressKeyword &P) {
    addressKeyword target;
    P = nullptr;
    if (L.first != nullptr) {
        if (Prec == nullptr) {
            deleteFirstKeyword(L, P);
        } else {
            target = Prec->next;
            if (target != nullptr) {
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
