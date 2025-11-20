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

void removeLoop(ListNode* head) {
    if (head == NULL || head->next == NULL) return;

    ListNode* slow = head;
    ListNode* fast = head;

    // ham slow aur fast pointer use krte he, agr cycle hui toh voh kbhi na kbhi meet krenge. fast wala 2 se increment, 
    //slow wala 1 se increment
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // agar kabhi meet hi nahi hua toh loop nahi hai
    if (slow != fast) return;
    slow = head;
    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
        return;
    }
    //dono next pointers match hone tak aage badhte hain
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    // fast ab loop ke last node pe hai, uska next hata do
    fast->next = NULL;
}
