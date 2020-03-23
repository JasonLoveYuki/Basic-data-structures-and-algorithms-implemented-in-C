// Linked list interface ... COMP9024 19T3
#include <stdbool.h>

typedef struct Node *List;

List makeNode(int n);
List appendRR(List L, int n);
List insertLL(List, int);
List deleteLL(List, int);
bool inLL(List, int);
void freeLL(List);
void showLL(List);

// Following functions are to solve exercises or Leetcode questions
List mergeTwoLists(List l1, List l2);
List mergeTwoSortedLists(List l1, List l2);