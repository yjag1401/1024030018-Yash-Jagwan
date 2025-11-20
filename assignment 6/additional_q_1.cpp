#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

pair<Node*, Node*> splitList(Node* head) {
    if (head == NULL) return {NULL, NULL};

    Node* slow = head;
    Node* fast = head;

    // fast ko 2 step aur slow ko 1 step chalaate hain
    // taaki slow middle wale node pe aa jaye
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // agar even nodes hain toh fast ko last node pe le aao
    if (fast->next->next == head) {
        fast = fast->next;
    }

    // first circular list ka head
    Node* head1 = head;

    // second circular list ka head
    Node* head2 = slow->next;

    // pehli list ko circular bana diya
    slow->next = head1;

    // second list ko bhi circular bana diya
    fast->next = head2;

    return {head1, head2};
}
