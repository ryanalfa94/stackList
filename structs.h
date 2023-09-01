/*
Guoliang Xue
8/18/2023
*/
#ifndef _structs_H
#define _structs_H 1

typedef struct TAG_NODE{
    double	key;
    TAG_NODE 	*next;
}NODE;

typedef struct TAG_LISTSTACK{
    NODE *top;
    int   size;
}LISTSTACK;

#endif
