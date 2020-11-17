class Solution {
public:
    int longestMountain(vector<int>& ar) {
        int n=ar.size();
        if(n==0)
            return 0;
        int i=0;
        int j=0;
        int ans=0;
        while(i<n && j<n)
        {
            int temp=i;
            while(i<n-1 && ar[i]<ar[i+1])
                i++;
            if(i==temp)
            {
                i++;
                continue;
            }
            j=i;
            while(j<n-1 && ar[j]>ar[j+1])
                j++;
            if(j==i)
            {
                i++;
                continue;
            }
            ans=max(ans,j-temp+1);
            i=j;
        }
        return ans;
    }
};
