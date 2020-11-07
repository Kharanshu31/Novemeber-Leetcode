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
    ListNode* insert(ListNode* head, int val) {
        if(head == nullptr) {
            head = new ListNode(val);
            return head;
        }
        ListNode* temp = new ListNode(val);
        temp->next = head;
        head = temp;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> st1, st2;
        ListNode* temp = l1;
        while(temp != nullptr) {
            st1.push_back(temp->val);
            temp = temp->next;
        }
        ListNode* temp1 = l2;
        while(temp1 != nullptr) {
            st2.push_back(temp1->val);
            temp1 = temp1->next;
        }
        ListNode* root = nullptr;
        int carry = 0;
        while(!st1.empty() && !st2.empty()) {
            int d = st1.back() + st2.back() + carry;
            if(d > 9) {
                carry = 1;
                d = d % 10;
            }
            else {
                carry = 0;
            }
            root = insert(root, d);
            st1.pop_back();
            st2.pop_back();
        }
        while(!st1.empty()) {
            int d = st1.back() + carry;
            if(d > 9) {
                carry = 1;
                d = d % 10;
            }
            else {
                carry = 0;
            }
            root = insert(root, d);
            st1.pop_back();
        }
        while(!st2.empty()) {
            int d = st2.back() + carry;
            if(d > 9) {
                carry = 1;
                d = d % 10;
            }
            else {
                carry = 0;
            }
            root = insert(root, d);
            st2.pop_back();
        }
        if(carry == 1)
            root = insert(root, 1);
        return root;
    }
};
