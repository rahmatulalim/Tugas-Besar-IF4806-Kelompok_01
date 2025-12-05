#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct infotypeP {
    string judul;
    string idPaper;
    int tahun;
};

typedef struct elmenP *addressP;

struct elmenP {
    infotypeP info;
    addressP next;
};

struct ListParent {
    addressP first;
};

void createListParent(ListParent &L);
addressP alokasiParent(infotypeP x);
void insertFirstParent(ListParent &L, addressP P);
void insertLastParent(ListParent &L, addressP P);
void deleteFirstParent(ListParent &L, addressP &P);
void deleteLastParent(ListParent &L, addressP &P);
void printParent(ListParent L);
addressP findParent(ListParent L, string idPaper);

#endif
