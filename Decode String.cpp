class Solution {
public:
    string decodeString(string s) {
        string ans="";
        stack<string>t;
        stack<int>n;
        int num=0;
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
            }
            else if(isalpha(s[i]))
            {
                ans+=s[i];
            }
            else if(s[i]=='[')
            {
                n.push(num);
                t.push(ans);
                num=0;
                ans="";
            }
            else if(s[i]==']')
            {
                int x=n.top();
                string temp=ans;
                for(int j=0;j<x-1;j++)
                    ans+=temp;
                ans=t.top()+ans;
                n.pop();
                t.pop();
            }
        }
        
        return ans;
    }
};
