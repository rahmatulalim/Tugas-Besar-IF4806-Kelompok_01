#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED

#include <iostream>
#include <string>
#include "list_child.h"
using namespace std;

struct infotypePaper {
    string judul;
    string idPaper;
    int tahun;
};

typedef struct elmenPaper *addressPaper;

struct elmenPaper {
    infotypePaper info;
    addressPaper next;
    addressKeyword firstChild;
};

struct ListPaper {
    addressPaper first;
};

void createListPaper(ListPaper &L);
addressPaper alokasiPaper(infotypePaper x);
void insertFirstPaper(ListPaper &L, addressPaper P);
void insertLastPaper(ListPaper &L, addressPaper P);
void insertAfterPaper(ListPaper &L, addressPaper Prec, addressPaper P);

void deleteFirstPaper(ListPaper &L, addressPaper &P);
void deleteLastPaper(ListPaper &L, addressPaper &P);
void deleteAfterPaper(ListPaper &L, addressPaper Prec, addressPaper &P);

void printPaper(ListPaper L);
addressPaper findPaper(ListPaper L, string idPaper);
void printPaperSortedByID(ListPaper L);

void connectKeywordToPaper(addressPaper P, addressKeyword K);
void disconnectKeywordFromPaper(addressPaper P, string namaKeyword);
addressKeyword findChildInPaper(addressPaper P, string namaKeyword);
void printChildOfParent(addressPaper P);
void printParentFromChild(ListPaper LP, string namaKeyword);
void printAllParentWithChild(ListPaper LP);
void countRelationOfParent(ListPaper LP);
void countNoRelationParent(ListPaper LP);
int countChildOfPaper(addressPaper P);

#endif
