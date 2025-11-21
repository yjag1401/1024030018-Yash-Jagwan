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

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    ListNode* p = A;
    ListNode* q = B;

    while (p != q) {
        if (p == NULL) p = B;
        else p = p->next;

        if (q == NULL) q = A;
        else q = q->next;
    }

    return p;
}

int main() {
    
    ListNode* c1 = new ListNode(8);
    ListNode* c2 = new ListNode(10);
    ListNode* c3 = new ListNode(12);
    c1->next = c2;
    c2->next = c3;

    //first list is 3,7,8,10,12
    ListNode* a1 = new ListNode(3);
    ListNode* a2 = new ListNode(7);
    a1->next = a2;
    a2->next = c1;

    //Second list is 99,1,5,8,10,12
    ListNode* b1 = new ListNode(99);
    ListNode* b2 = new ListNode(1);
    ListNode* b3 = new ListNode(5);
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;

    ListNode* inter = getIntersectionNode(a1, b1);

    if (inter != NULL) {
        cout << "common point is at value " << inter->val << endl;
    } else {
        cout << "no intersection" << endl;
    }

    return 0;
}
