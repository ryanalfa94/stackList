#ifndef _ListStack_write_H
#define _ListStack_write_H 1
#include "structs.h"

double ListStackMax(LISTSTACK *pLISTSTACK);
double ListStackMin(LISTSTACK *pLISTSTACK);
double ListStackSum(LISTSTACK *pLISTSTACK);
NODE * ListStackPop(LISTSTACK *pLISTSTACK);
void   ListStackPush(LISTSTACK *pLISTSTACK, NODE *pNODE);
NODE * ListStackSearch(LISTSTACK *pLISTSTACK, double query);
NODE * ListStackDelete(LISTSTACK *pLISTSTACK, double key);

#endif
