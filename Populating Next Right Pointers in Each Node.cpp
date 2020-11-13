/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        Node* t=root;
        queue<Node*>q;
        q.push(t);
        while(!q.empty())
        {
            Node* temp=new Node;
            int n=q.size();
            while(n)
            {
                Node* f=q.front();
                q.pop();
                temp->next=f;
                temp=temp->next;
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
                n--;
            }
            temp->next=NULL;
        }
        
        return t;
        
    }
};
