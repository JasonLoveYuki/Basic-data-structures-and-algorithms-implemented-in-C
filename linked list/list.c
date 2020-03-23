// Linked list implementation ... COMP9024 19T3
#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
   int         v;
   struct Node *next; 
} Node;

List makeNode(int n) {
   List new = malloc(sizeof(Node));
   assert(new != NULL);
   new->v = n;
   new->next = NULL;
   return new;
}

List appendRR(List L, int n) {
    if (L == NULL) {
        return makeNode(n);
    }
    L->next = appendRR(L->next, n);
    return L;
}

List insertLL(List L, int n) {
   if (inLL(L, n))
      return L;

   // add new node at the beginning
   Node *new = makeNode(n);
   new->next = L;
   return new;
}

List deleteLL(List L, int n) {
   if (L == NULL)
      return L;
   if (L->v == n) {
      List temp = L->next;
      free(L);
      return temp;
   }
   L->next = deleteLL(L->next, n);
   return L;

}

bool inLL(List L, int n) {
   if (L == NULL)
      return false;
   if (L->v == n)
     return true;

   return inLL(L->next, n);
}

void showLL(List L) {
   if (L == NULL)
      putchar('\n');
   else {
      printf("%d ", L->v);
      showLL(L->next);
   }
}

void freeLL(List L) {
   if (L != NULL) {
      // 必须先call否则用不了L作为reference
      freeLL(L->next);
      free(L);
   }
}


// Following functions are to solve exercises or Leetcode questions
// 把两个list交错成一个list，再把多余项也添加到新list中
List mergeTwoLists(List l1, List l2) {
   int counter = 1;
   List pt1 = l1;
   List pt2 = l2;
   List new = NULL;
   while (pt1 != NULL && pt2 != NULL) {
      if (counter % 2) {
         new = appendRR(new, pt1->v);
         pt1 = pt1->next;
      }
      else {
         new = appendRR(new, pt2->v);
         pt2 = pt2->next;
      }
      counter++;
   }
   
   while (pt2 != NULL) {
      new = appendRR(new, pt2->v);
      pt2 = pt2->next;
   }
   while (pt1 != NULL) {
      new = appendRR(new, pt1->v);
      pt1 = pt1->next;
   }
   return new;
}
// 把两个有序list合并成一个有序list
List mergeTwoSortedLists(List l1, List l2) {
   List pt1 = l1;
   List pt2 = l2;
   List new = NULL;
   while (pt1 != NULL && pt2 != NULL) {
      if (pt1->v <= pt2->v) {
         new = appendRR(new, pt1->v);
         pt1 = pt1->next;
      }
      else {
         new = appendRR(new, pt2->v);
         pt2 = pt2->next;
      }
   }
   
   while (pt2 != NULL) {
      new = appendRR(new, pt2->v);
      pt2 = pt2->next;
   }
   while (pt1 != NULL) {
      new = appendRR(new, pt1->v);
      pt1 = pt1->next;
   }
   return new;
}
