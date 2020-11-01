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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        string ans="";
        while(temp)
        {
            ans+=to_string(temp->val);
            temp=temp->next;
        }
        
        int l=ans.length();
        int dec=0;
        int base=1;
        for(int i=l-1;i>=0;i--)
        {
            if(ans[i]=='1')
                dec+=base;
            base*=2;
        }
        
        return dec;
        
    }
};
