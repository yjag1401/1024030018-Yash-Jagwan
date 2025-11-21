// Given a linked list and a positive number k, reverse the nodes in groups of k.
// All the remaining nodes after multiples of k should be left as it is.

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

ListNode* reverseK(ListNode* head, int k) {
    ListNode* curr = head;
    int count = 0;  

    while (curr != NULL && count < k) {
        curr = curr->next;
        count++;
    }
                                        //while loop me check kiya if k nodes he bhi nhi, agr nhi toh bas return head
    if (count < k) return head;

    curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;                 //k nodes ko ab reverse kr rhe he
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    head->next = reverseK(curr, k);  // jo head tha, voh ab reverse hoke last ban gya us k group ke liye, isliye usko aage 
    //ke reverse part se jod diya
    return prev; 
}

int main() {
    // list is 1,2,3,4,5,6,7
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(3);
    h1->next->next->next = new ListNode(4);
    h1->next->next->next->next = new ListNode(5);
    h1->next->next->next->next->next = new ListNode(6);
    h1->next->next->next->next->next->next = new ListNode(7);
    int k = 3;

    ListNode* newHead = reverseK(h1, k);

    //printing
    cout << "list after reversing " << ": ";
    ListNode* temp = newHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}