/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;
        stack <Node*> s;
        Node* temp = head;;
        while (temp != NULL) {
            if (temp->child != NULL) {
                if (temp->next != NULL) {
                    s.push(temp->next);
                }
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;
            }
            if (temp->next == NULL && !s.empty()) {
                Node* front = s.top();
                s.pop();
                temp->next = front;
                front->prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};