#include "ListStack_study.h"
#include <stdio.h>
#include <stdlib.h>

void ListStackPrint(LISTSTACK *pLISTSTACK){
    NODE *pNODE;

    if (!pLISTSTACK){
        fprintf(stderr, "Error in ListStackPrint: NULL ListStack\n");
        exit (0);
    }else{
        fprintf(stdout, "Size=%d\n", pLISTSTACK->size);
        pNODE = pLISTSTACK->top;
        while (pNODE){
            fprintf(stdout, "%lf\n", pNODE->key);
            pNODE = pNODE->next;
        }
    }
}


double ListStackTop(LISTSTACK *pLISTSTACK){
    double top;

    if (pLISTSTACK == NULL){
        fprintf(stderr, "Error in ListStackTop: NULL ListStack\n");
        exit(0);
    }else if (pLISTSTACK->top == NULL){
        fprintf(stderr, "Error in ListStackTop: EmptyListStack\n");
        exit(0);
    }else{
        top = pLISTSTACK->top->key;
    }
    return top;
}
