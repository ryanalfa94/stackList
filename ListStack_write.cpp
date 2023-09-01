
#define _ListStack_write_H 1
#include "structs.h"
#include "stdio.h"
#include "stdlib.h"

double ListStackMax(LISTSTACK *pLISTSTACK){
    // creating a veriable to store the  max 
    double max;
    // creating a new node to copy each node from the list 
    NODE *pNODE;
// check if the list is empty 
if (!pLISTSTACK){
        fprintf(stderr, "Error in ListStackPrint: NULL ListStack\n");
        exit (0);
    }else{
        fprintf(stdout, "Size=%d\n", pLISTSTACK->size);
        // setting pnode to the first nod of the list and store the the first node value as the max. 
        pNODE = pLISTSTACK->top;
        max = pNODE->key; 
        fprintf(stdout, "%lf\n", pNODE->key);
        //make pnode equal the next node 
        pNODE = pNODE->next;
        // looping throgh all the nodes and set max equal he largest num in it 
        while (pNODE!= NULL){
            
            if (max < pNODE->key){
                max = pNODE->key;
            }
            pNODE = pNODE->next;
        }
    }
    return max;
  
}

double ListStackMin(LISTSTACK *pLISTSTACK){
    double min;
 NODE *pNODE;

if (!pLISTSTACK){
        fprintf(stderr, "Error in ListStackPrint: NULL ListStack\n");
        exit (0);
    }else{
        fprintf(stdout, "Size=%d\n", pLISTSTACK->size);
        pNODE = pLISTSTACK->top;
        min = pNODE->key; 
        pNODE = pNODE->next;
        while (pNODE!= NULL){
            
            if (min > pNODE->key){
                min = pNODE->key;
            }
            pNODE = pNODE->next;
        }
    }
    return min;
}

double ListStackSum(LISTSTACK *pLISTSTACK){
        double sum;
        NODE *pNODE;

if (!pLISTSTACK){
        fprintf(stderr, "Error in ListStackPrint: NULL ListStack\n");
        exit (0);
    }else{
        fprintf(stdout, "Size=%d\n", pLISTSTACK->size);
        pNODE = pLISTSTACK->top;
        sum =  pNODE->key; 
        pNODE = pNODE->next;

        while (pNODE!= NULL){
            
           sum = sum +pNODE->key;
            pNODE = pNODE->next;
        }
    }
return sum;
}


NODE * ListStackPop(LISTSTACK *pLISTSTACK){
    // pnode points at top and newNode points at the second node
NODE *pNode = pLISTSTACK->top;
NODE *newNode = pNode ->next;

if (!pLISTSTACK){
        fprintf(stderr, "Error in ListStackPrint: NULL ListStack\n");
        exit (0);
    }else{
        // delete the top node and set top to the next node. 
        
        pLISTSTACK->top = newNode; 
        // decreamenting the size by 1 everytime we pop an element.
        pLISTSTACK ->size = pLISTSTACK ->size -1;
    }


return pNode;    
}



void   ListStackPush(LISTSTACK *pLISTSTACK, NODE *pNODE){

    if (!pLISTSTACK){
        fprintf(stderr, "Error in ListStackPrint: NULL ListStack\n");
        exit (0);
    }else{
        // making the new node points at the previous top node of the list
        pNODE->next = pLISTSTACK->top; 
        // making top points at the new pushed node
        pLISTSTACK -> top = pNODE;
        // increamenting the size by 1 everytime we push an element.
        pLISTSTACK ->size = pLISTSTACK ->size +1;

    }

}



NODE * ListStackSearch(LISTSTACK *pLISTSTACK, double query){
NODE *pNode;
// setting the node to equal the first node in the list  
pNode = pLISTSTACK ->top;

if (!pLISTSTACK){
        fprintf(stderr, "Error in ListStackPrint: NULL ListStack\n");
        exit (0);
    }else{
      while (pNode != NULL){
        // checking if t he value of the node we are pointing at is equal to query's value 
        // if so return it otherwise check the next node 
        if (pNode ->key == query){
            return pNode; 
        }
        pNode=pNode->next; 
      }
    }
// if node not found return a null 
return NULL;  
}




NODE * ListStackDelete(LISTSTACK *pLISTSTACK, double key){
// starting pnode at the second node and prevnode to the first node to keep track of the previous node 
NODE *pNode = pLISTSTACK->top->next;
NODE *prevNode = pLISTSTACK->top; 
if (!pLISTSTACK){
        fprintf(stderr, "Error in ListStackPrint: NULL ListStack\n");
        exit (0);
    }else{
        // looping through all the nodes till we fin or traget node  
   while (pNode != NULL){
    // if we find the target we let previous node points at the node after pnode and delete pnode 
    if (pNode->key == key){
        prevNode -> next = pNode ->next;
       
        break;
    }
    pNode = pNode ->next;
    prevNode = prevNode ->next;
   }
   // decreamenting the size by 1 everytime we delete an element.
        pLISTSTACK ->size = pLISTSTACK ->size -1;
        
    }

return pNode;  
}