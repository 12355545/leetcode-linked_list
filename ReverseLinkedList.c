#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};




struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* tmp = NULL;
    struct ListNode* tmp1 = NULL;

    while ( head!= NULL){
    tmp =head-> next;
    head-> next= tmp1;
    tmp1=head;
    head=tmp;
    }
    return tmp1;
} 
