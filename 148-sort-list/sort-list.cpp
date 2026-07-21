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
    ListNode* sortList(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;
        while (temp != NULL) {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        sort(vec.begin(), vec.end());
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        for (int i=0; i<vec.size(); i++) {
            ListNode* newNode = new ListNode(vec[i]);
            curr->next = newNode;
            curr = newNode;
        }
        return dummy->next;
    }
};