class Solution {
public:
    bool canReach(vector<int>& ar, int start) {
        int n=ar.size();
        queue<int>q;
        q.push(start);
        int x;
        vector<int>vis(n,false);
        while(!q.empty())
        {
            x=q.front();
            vis[x]=true;
            //cout<<" x : "<<x<<"\n";
            if(ar[x]==0)
                return true;
            q.pop();
            if(x+ar[x]<n && !vis[x+ar[x]])
                q.push(x+ar[x]);
            if(x-ar[x]>=0 && !vis[x-ar[x]])
                q.push(x-ar[x]);
        }
        
        return false;
        
    }
};
