class Solution {
public:
    int maxPower(string s) {
        if(s.empty())
            return 0;
        int ans=1;
        int ct=1;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
                ct++;
            else
            {
                ans=max(ans,ct);
                ct=1;
            }
        }
        ans=max(ans,ct);
        
        return ans;
    }
};
