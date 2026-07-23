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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {
                curr->next = temp1;
                curr = temp1;
                temp1 = temp1->next;
            } else {
                curr->next = temp2;
                curr = temp2;
                temp2 = temp2->next;
            }
        }

        if (temp1 != NULL) curr->next = temp1;
        if (temp2 != NULL) curr->next = temp2;

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;

        ListNode* ans = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            ans = merge(ans, lists[i]);
        }
        return ans;
    }
};