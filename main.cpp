#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "ListStack_study.h"
#include "ListStack_write.h"

int main(int argc, char **argv){
    FILE *fp;
    LISTSTACK *ListStack;
    LISTSTACK *ListStackB;
    NODE *pNODE;
    double key, max, min, sum;
    int returnV;
    char Word[100];

    if (argc < 3){
        fprintf(stderr, "Usage: %s <ifile> <ofile>\n", argv[0]);
        exit(0);
    }

    fp    = NULL;
    ListStack  = NULL;
    pNODE = NULL;

    fp = fopen(argv[1], "r");
    if (!fp){
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(0);
    }
    // File opened for reading...


    ListStackB = (LISTSTACK *) calloc(1, sizeof(LISTSTACK));
    if (!ListStackB){
        fprintf(stderr, "Error: calloc failed\n");
        exit(0);
    }
    ListStackB->size = 0;
    ListStackB->top  = NULL;
    // Empty stack created...


    while ((returnV = fscanf(fp, "%lf", &key)) == 1){
        pNODE = (NODE *) calloc(1, sizeof(NODE));
        pNODE->next = NULL;
        pNODE->key  = key;
        ListStackPush(ListStackB, pNODE);
    }
    // Read in the list from the file, one node at a time, and push it onto the stack...
    fclose(fp);


    ListStack = (LISTSTACK *) calloc(1, sizeof(LISTSTACK));
    if (!ListStack){
        fprintf(stderr, "Error: calloc failed\n");
        exit(0);
    }
    ListStack->size = 0;
    ListStack->top  = NULL;

    while (ListStackB->size > 0){
        pNODE = ListStackPop(ListStackB);
        ListStackPush(ListStack, pNODE);
    }



    while (1){
        returnV = nextInstruction(Word, &key);

        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction: %s\n", Word);
            continue;
        }


        if (strcmp(Word, "Stop")==0){
            return 0;
        }


        if (strcmp(Word, "Print")==0){
            ListStackPrint(ListStack);
            continue;
        }


        if (strcmp(Word, "Push")==0){
            pNODE = (NODE *) calloc(1, sizeof(NODE));
            pNODE->key  = key;
            ListStackPush(ListStack, pNODE);
            continue;
        }


        if (strcmp(Word, "Pop")==0){
            pNODE = ListStackPop(ListStack);
            if (pNODE){
                free(pNODE);
            }
            continue;
        }


        if (strcmp(Word, "Max")==0){
            max = ListStackMax(ListStack);
            fprintf(stdout, "Max=%lf\n", max);
            continue;
        }


        if (strcmp(Word, "Min")==0){
            min = ListStackMin(ListStack);
            fprintf(stdout, "Min=%lf\n", min);
            continue;
        }


        if (strcmp(Word, "Sum")==0){
            sum = ListStackSum(ListStack);
            fprintf(stdout, "Sum=%lf\n", sum);
            continue;
        }


        if (strcmp(Word, "Top")==0){
            key = ListStackTop(ListStack);
            fprintf(stdout, "Top=%lf\n", key);
            continue;
        }


        if (strcmp(Word, "Write")==0){
            if (ListStack != NULL || ListStack->top != NULL){
                fp = fopen(argv[2], "w");
                if (!fp){
                    fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
                    exit(0);
                }
                pNODE = ListStack->top;
                while (pNODE){
                    fprintf(fp, "%lf\n", pNODE->key);
                    pNODE = pNODE->next;
                }
                fclose(fp);
            }
            continue;
        }


        if (strcmp(Word, "Search")==0){
            pNODE = NULL;
            pNODE = ListStackSearch(ListStack, key);
            if (pNODE){
                fprintf(stdout, "Query %lf FOUND in StackList\n", pNODE->key);
            }else{
                fprintf(stdout, "Query %lf NOT FOUND in StackList\n", key);
            }
            continue;
        }


        if (strcmp(Word, "Delete")==0){
            pNODE = ListStackDelete(ListStack, key);
            if (pNODE){
                fprintf(stdout, "First node with key %lf deleted\n", pNODE->key);
                free(pNODE);
            }else{
                fprintf(stdout, "No node deleted\n");
            }
            continue;
        }


        if (strcmp(Word, "Write")==0){
            if (ListStack != NULL || ListStack->size != 0){
                fp = fopen(argv[2], "w");
                if (!fp){
                    fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
                    exit(0);
                }
                pNODE = ListStack->top;
                while (pNODE){
                    fprintf(fp, "%lf\n", pNODE->key);
                    pNODE = pNODE->next;
                }
                fclose(fp);
            }
            continue;
        }



    }

    return 1;
}
