#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "list_parent.h"
#include "list_child.h"

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
addressRelasi findRelasi(ListRelasi L, string idPaper, string namaKeyword);
void connect(ListRelasi &LR, ListPaper LP, ListKeyword LK, string idPaper, string namaKeyword);
void disconnect(ListRelasi &LR, string idPaper, string namaKeyword);
void removeRelasiByPaper(ListRelasi &LR, string idPaper);
void removeRelasiByKeyword(ListRelasi &LR, string namaKeyword);

void printChildOfParent(ListRelasi LR, ListPaper LP, string idPaper);
void printParentOfChild(ListRelasi LR, ListKeyword LK, string namaKeyword);
void printAllParentWithChild(ListRelasi LR, ListPaper LP);
void printAllChildWithParent(ListRelasi LR, ListKeyword LK);
void countRelationOfParent(ListRelasi LR, ListPaper LP);
void countRelationOfChild(ListRelasi LR, ListKeyword LK);
void countNoRelationChild(ListRelasi LR, ListKeyword LK);
void countNoRelationParent(ListRelasi LR, ListPaper LP);
void editRelasi(ListRelasi &LR, ListPaper LP, ListKeyword LK, string idPaper, string oldKeyword, string newKeyword);

#endif
