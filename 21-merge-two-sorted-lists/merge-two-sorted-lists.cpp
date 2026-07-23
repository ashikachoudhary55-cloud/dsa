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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != NULL && temp2 != NULL) {
            if(temp1->val <= temp2->val) {
                ListNode* newNode = new ListNode(temp1->val);
                curr->next = newNode;
                curr = newNode;
                temp1 = temp1->next;
            } else if (temp2->val < temp1->val) {
                ListNode* newNode = new ListNode(temp2->val);
                curr->next = newNode;
                curr = newNode;
                temp2 = temp2->next;
            }
        }
        if (temp2 == NULL && temp1 != NULL) {
            while (temp1 != NULL) {
                ListNode* newNode = new ListNode(temp1->val);
                curr->next = newNode;
                curr = newNode;
                temp1 = temp1->next;
            }
        }
        if (temp1 == NULL && temp2 != NULL) {
            while (temp2 != NULL) {
                ListNode* newNode = new ListNode(temp2->val);
                curr->next = newNode;
                curr = newNode;
                temp2 = temp2->next;
            }
        }
        return dummy->next;
    }
};