#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct infotypeC {
    string namaKeyword;
    string idKeyword;
};

typedef struct elmenC *addressC;

struct elmenC {
    infotypeC info;
    addressC next;
    addressC prev;
};

struct ListChild {
    addressC first;
    addressC last;
};

void createListChild(ListChild &L);
addressC alokasiChild(infotypeC x);
void insertFirstChild(ListChild &L, addressC P);
void insertLastChild(ListChild &L, addressC P);
void deleteFirstChild(ListChild &L, addressC &P);
void deleteLastChild(ListChild &L, addressC &P);
void printChild(ListChild L);
addressC findChild(ListChild L, string namaKeyword);

#endif
