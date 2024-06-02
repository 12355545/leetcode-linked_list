#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse the linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* tmp = NULL;
    struct ListNode* tmp1 = NULL;

    while (head != NULL) {
        tmp = head->next;
        head->next = tmp1;
        tmp1 = head;
        head = tmp;
    }
    return tmp1;
}

// Function to find the middle of the linked list
struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    struct ListNode* middle = middleNode(head);
    struct ListNode* halflist = reverseList(middle);

    struct ListNode* firstHalf = head;
    struct ListNode* secondHalf = halflist;
    bool isPalindrome = true;

    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val) {
            isPalindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Optional: Restore the second half of the linked list
    reverseList(halflist);

    return isPalindrome;
}
 