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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        a = a+1;
        b = b+1;
        ListNode* temp = list1;
        ListNode* y = list1;
        int c = 1, count = 1;
        while (c != a-1) {
            c++;
            temp = temp->next;
        }
        while (count != b) {
            count++;
            y = y->next;
        }
        ListNode* x = list2;
        while (x->next != NULL) {
            x = x->next;
        }
        temp->next = list2;
        x->next = y->next;
        y->next = NULL;
        return list1;
    }
};