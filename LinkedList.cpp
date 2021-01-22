#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
    ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LinkedList {
public:
    void deleteNode(ListNode* node) {

        while (node->next != nullptr) {
            node->val = node->next->val;
        }

        node = nullptr;
    }

    ListNode* reverseList(ListNode* head) {

        if (head->next == nullptr)
            return head;
        if (head->next->next == nullptr) {
            ListNode* tail = head->next;
            head->next = nullptr;
            tail->next = head;
            return tail;
        }

        ListNode* newHead = nullptr;
        ListNode* newTail = nullptr;

        while (head->next != nullptr) {

            ListNode* temp = head;

            while (temp->next->next != nullptr) {
                temp = temp->next;
            }

            if (newHead == nullptr) {
                newHead = temp->next;
                newTail = temp->next;
                temp->next = nullptr;
            }
            else {
                newTail->next = temp->next;
                temp->next = nullptr;
                newTail = newTail->next;
            }
        }
        newTail->next = head;

        return newHead;
    }
};

int main() {

	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);

	node1.next = &node2;
	node2.next = &node3;

	

	std::cout << "\n ";

    LinkedList ll;

    ListNode * p = ll.reverseList(&node1);

    for (; p != nullptr; p = p->next) {
        std::cout << p->val << ", ";
    }

    getchar();

	return 0;
}