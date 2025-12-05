#ifndef KEYWORD_H_INCLUDED
#define KEYWORD_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct infotypeKeyword {
    string namaKeyword;
    string idKeyword;
};

typedef struct elmenKeyword *addressKeyword;

struct elmenKeyword {
    infotypeKeyword info;
    addressKeyword next;
    addressKeyword prev;
};

struct ListKeyword {
    addressKeyword first;
    addressKeyword last;
};

void createListKeyword(ListKeyword &L);
addressKeyword alokasiKeyword(infotypeKeyword x);
void insertFirstKeyword(ListKeyword &L, addressKeyword P);
void insertLastKeyword(ListKeyword &L, addressKeyword P);
void insertAfterKeyword(ListKeyword &L, addressKeyword Prec, addressKeyword P);

void deleteFirstKeyword(ListKeyword &L, addressKeyword &P);
void deleteLastKeyword(ListKeyword &L, addressKeyword &P);
void deleteAfterKeyword(ListKeyword &L, addressKeyword Prec, addressKeyword &P);

void printKeyword(ListKeyword L);
addressKeyword findKeyword(ListKeyword L, string namaKeyword);

#endif
