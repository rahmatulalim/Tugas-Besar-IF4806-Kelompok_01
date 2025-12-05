#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED

#include <iostream>
#include <string>
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
};

struct ListPaper {
    addressPaper first;
};

void createListPaper(ListPaper &L);
addressPaper alokasiPaper(infotypePaper x);
void insertFirstPaper(ListPaper &L, addressPaper P);
void insertLastPaper(ListPaper &L, addressPaper P);
void deleteFirstPaper(ListPaper &L, addressPaper &P);
void deleteLastPaper(ListPaper &L, addressPaper &P);
void printPaper(ListPaper L);
addressPaper findPaper(ListPaper L, string idPaper);

#endif
