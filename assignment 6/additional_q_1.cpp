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
int main() {
    // circular list 1,2,3,4,5,1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head;  

    pair<Node*, Node*> res = splitList(head);
    Node* head1 = res.first;
    Node* head2 = res.second;

    // first list
    cout << "first list: ";
    Node* temp = head1;
    if (temp != NULL) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head1);
    }
    cout << endl;

    // 2nd list
    cout << "second list: ";
    temp = head2;
    if (temp != NULL) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head2);
    }
    cout << endl;

    return 0;
}
