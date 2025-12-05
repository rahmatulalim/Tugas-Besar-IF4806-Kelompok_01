#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_parent.h"
#include "list_child.h"

typedef struct elmenR *addressR;

struct elmenR {
    addressR next;
    addressP parent;
    addressC child;
};

struct ListRelasi {
    addressR first;
};

void createListRelasi(ListRelasi &L);
addressR alokasiRelasi(addressP P, addressC C);
void insertFirstRelasi(ListRelasi &L, addressR R);
void insertLastRelasi(ListRelasi &L, addressR R);
void deleteFirstRelasi(ListRelasi &L, addressR &R);
void deleteLastRelasi(ListRelasi &L, addressR &R);
void printRelasi(ListRelasi L);
addressR findRelasi(ListRelasi L, string idPaper, string namaKeyword);
void connect(ListRelasi &LR, ListParent LP, ListChild LC, string idPaper, string namaKeyword);
void disconnect(ListRelasi &LR, string idPaper, string namaKeyword);

#endif
