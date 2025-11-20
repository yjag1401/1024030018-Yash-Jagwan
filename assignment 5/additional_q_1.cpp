#include <iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val=x;
        next=NULL;
    }
};
ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    ListNode* p = A;
    ListNode* q = B;

    while (p != q) {
        if (p == NULL) {
            p = B;
        } else {
            p = p->next;
        }

        if (q == NULL) {
            q = A;
        } else {
            q = q->next;
        }
    }

    return p;
}
