#include <stdio.h>
#include "list.h"
int main(int argc, char *argv[]) {
    List l1;
    List l2;
    l1 = appendRR(l1, 1);
    l1 = appendRR(l1, 2);
    l1 = appendRR(l1, 3);
    l2 = appendRR(l2, 1);
    l2 = appendRR(l2, 3);
    l2 = appendRR(l2, 4);
    l2 = appendRR(l2, 5);
    l2 = appendRR(l2, 6);
    showLL(l1);
    showLL(l2);
    List l3 = mergeTwoSortedLists(l1, l2);
    showLL(l3);
    freeLL(l1);
    freeLL(l2);
    freeLL(l3);
    return 0;
}
