#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* rotateLeft(ListNode* head, int k) {
    if (head == NULL || head->next == NULL) return head;

    // pehle length of linked list aur last tail pr ja rhe he
    int n = 1;
    ListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        n++;
    }

    // ho skta hai k zyada ho length of linked list se, but farak nahi padta kyuki fir circular hi ghum rhe hai ham
    k = k % n;   
    if (k == 0) return head;

    // kth node pr ja rhe he
    ListNode* kth = head;
    for (int i = 1; i < k; i++) {
        kth = kth->next;
    }

    // new head kth ke next pe hai
    ListNode* newHead = kth->next;

    // tail ko old head se jod do, aur kth->next ko NULL kar do
    tail->next = head;
    kth->next = NULL;

    return newHead;
}
