/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* f(ListNode* temp, int k) {
        int c = 1;
        while (c != k && temp != NULL) {
            c++;
            temp = temp->next;
        }
        return temp;
    }

    void rev(ListNode* temp) {
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;
        ListNode* kth = NULL;
        while (temp != NULL) {
            kth = f(temp, k);
            if (kth == NULL) {
                if (prevNode != NULL) {
                    prevNode->next = temp;
                }
                break;
            } 
            nextNode = kth->next;
            kth->next = NULL;
            rev(temp);
            if (temp == head) {
                head = kth;
            } else {
                prevNode->next = kth;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};