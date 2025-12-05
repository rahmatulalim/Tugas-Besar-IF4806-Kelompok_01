#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "paper.h"
#include "keyword.h"

typedef struct elmenRelasi *addressRelasi;

struct elmenRelasi {
    addressRelasi next;
    addressPaper parent;
    addressKeyword child;
};

struct ListRelasi {
    addressRelasi first;
};

void createListRelasi(ListRelasi &L);
addressRelasi alokasiRelasi(addressPaper P, addressKeyword C);
void insertLastRelasi(ListRelasi &L, addressRelasi R);
void printRelasi(ListRelasi L);
addressRelasi findRelasi(ListRelasi L, string idPaper, string namaKeyword);
void connect(ListRelasi &LR, ListPaper LP, ListKeyword LK, string idPaper, string namaKeyword);
void disconnect(ListRelasi &LR, string idPaper, string namaKeyword);

#endif
