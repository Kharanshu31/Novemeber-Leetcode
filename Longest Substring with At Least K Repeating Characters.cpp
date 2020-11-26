class Solution {
public:
    int longestSubstring_rec(string s,int beg,int last,int k)
    {
        vector<int>h(26,0);
        for(int i=beg;i<last;i++)
            h[s[i]-'a']++;
        
        int ans=0;
        for(int i=beg;i<last;)
        {
            while(i<last && h[s[i]-'a']<k)
                i++;
            if(i==last)
                break;
            int l=i;
            while(l<last && h[s[l]-'a']>=k)
                l++;
            if(i==beg&& l==last)
                return l-i;
            
            ans=max(ans,longestSubstring_rec(s,i,l,k));
            i=l;
        }
        
        return ans;
    }
        
        
    int longestSubstring(string s, int k) {
        return longestSubstring_rec(s,0,s.length(),k);                                                
    }
};
